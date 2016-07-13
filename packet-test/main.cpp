#include <iostream>

#include "Packet.hpp"

using namespace std;

int main()
{
    Packet packet;
    packet.x = 123;
    packet.y = 1023;

    string str = packet.serialize();
    cout << str << endl;

    Packet packet2 = Packet::deserialize(str);
    cout << packet2.x << " " << packet2.y << endl;
    return 0;
}