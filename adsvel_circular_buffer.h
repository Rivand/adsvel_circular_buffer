#pragma once

namespace adsvel {
    template <class T, size_t size>
    class CircularBuffer {
       public:
        void push_back(T in_val);
        T& front();
        void pop_front();
        T&& take_front();

       private:
        size_t end_cursor_{0};
        size_t begin_cursor_{0};
        T data_container_[size]{};
    };

    template <class T, size_t size>
    inline void CircularBuffer<T, size>::push_back(T in_val) {
		data_container_[end_cursor_++] = in_val;
        if (end_cursor_ == size) {
            end_cursor_ = 0;
        }
    }

    template <class T, size_t size>
    inline T& CircularBuffer<T, size>::front() {
        return data_container_[begin_cursor_];
    }

    template <class T, size_t size>
    inline void CircularBuffer<T, size>::pop_front() {
        if (++begin_cursor_ == size) {
            begin_cursor_ = 0;
        }
    }

    template <class T, size_t size>
    inline T&& CircularBuffer<T, size>::take_front() {
        if (++begin_cursor_ != size) {
            return std::move(data_container_[begin_cursor_ - 1]);
        } else {
            begin_cursor_ = 0;
            return std::move(data_container_[size - 1]);
        }
    }
}  // namespace adsvel
