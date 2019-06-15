#include <array>
#include <chrono>
#include <iostream>
#include "../adsvel_circular_buffer.h"
#include "boost/circular_buffer.hpp"
using std::cin;
using std::cout;
using std::endl;
using std::chrono::high_resolution_clock;
using std::chrono::time_point;
int main() {
    constexpr size_t kSizeOfTestSet{1000};
    constexpr size_t kSizeOfTestBuffers{1000};
    typedef int tTestType;
    srand(static_cast<int>(high_resolution_clock::now().time_since_epoch().count()));
    std::array<tTestType, kSizeOfTestSet> test_data{};
    for (auto& c : test_data) c = rand();

    uint64_t amountr_of_test_iterations{0};
    cout << "Enter the number of iterations in the test: ";
    cin >> amountr_of_test_iterations;
    // fill test
	{
		adsvel::CircularBuffer<tTestType, kSizeOfTestBuffers> buff{};
		time_point<high_resolution_clock> start_time = high_resolution_clock::now();
		for (uint64_t iter = 0; iter < amountr_of_test_iterations; iter++) {
			for (uint64_t i = 0; i < kSizeOfTestSet; i++) {
				buff.push_back(test_data[i]);
			}
		}
		uint64_t test_time_mk = std::chrono::duration_cast<std::chrono::microseconds>(high_resolution_clock::now() - start_time).count();
		cout << " adsvel::CircularBuffer fill time: " << test_time_mk << "mks" << endl;
	}
    {
        boost::circular_buffer<tTestType> buff{kSizeOfTestBuffers};
        time_point<high_resolution_clock> start_time = high_resolution_clock::now();
        for (uint64_t iter = 0; iter < amountr_of_test_iterations; iter++) {
            for (uint64_t i = 0; i < kSizeOfTestSet; i++) {
                buff.push_back(test_data[i]);
            }
        }
        uint64_t test_time_mk = std::chrono::duration_cast<std::chrono::microseconds>(high_resolution_clock::now() - start_time).count();
        cout << " boost::circular_buffer fill time: " << test_time_mk << "mks" << endl;
    }
    cout << endl;
    return 0;
}
