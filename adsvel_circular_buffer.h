/**
***************************************************************************************************************************************************************
* @file     adsvel_circular_buffer.h
* @author   Kuznetcov.A (Rivand) 
* @version  v 0.0.4
* @date     6 June 2018 ã.
* @brief    Implementation of the ñircular buffer container class.
***************************************************************************************************************************************************************
*/
#pragma once

namespace adsvel {
    template <class T, size_t size_>
    class CircularBuffer {
       public:
        inline void push_back(T in_val);
        inline T& front();
        inline void pop_front();
        inline T&& take_front();
        inline bool empty() const noexcept;
        inline constexpr size_t size() const noexcept { return size_; };

       private:
        size_t end_cursor_{0};
        size_t begin_cursor_{0};
        T data_container_[size_]{};
    };

    template <class T, size_t size_>
    inline void CircularBuffer<T, size_>::push_back(T in_val) {
        data_container_[end_cursor_++] = in_val;
        if (end_cursor_ == size_) {
            end_cursor_ = 0;
        }
    }

    template <class T, size_t size_>
    inline T& CircularBuffer<T, size_>::front() {
        return data_container_[begin_cursor_];
    }

    template <class T, size_t size_>
    inline void CircularBuffer<T, size_>::pop_front() {
        if (++begin_cursor_ == size_) {
            begin_cursor_ = 0;
        }
    }

    template <class T, size_t size_>
    inline T&& CircularBuffer<T, size_>::take_front() {
        if (++begin_cursor_ != size_) {
            return std::move(data_container_[begin_cursor_ - 1]);
        } else {
            begin_cursor_ = 0;
            return std::move(data_container_[size_ - 1]);
        }
    }

    template <class T, size_t size_>
    inline bool CircularBuffer<T, size_>::empty() const noexcept {
        if (end_cursor_ != begin_cursor_)
            return false;
        else
            return true;
    };

}  // namespace adsvel
