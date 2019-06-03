#include <iostream>
#include "../adsvel_circular_buffer.h"
using adsvel::CircularBuffer;
using std::cout;
using std::endl;
int main() {
    CircularBuffer<int16_t, 32> cb;
    cout << "This is adsvel::CircularBuffer." << endl;
    cb.push_back(1);
    cb.push_back(2);
    cb.push_back(3);
    cb.push_back(4);
    cb.push_back(5);
    cout << cb.front() << " ";
    for (int i = 0; i < 5; i++) cout << cb.take_front() << " ";
    cout << endl;
    return 0;
}
