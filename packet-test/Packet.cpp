#include "Packet.hpp"

#include <cstdio>
#include <cassert>
#include <cstdlib>

std::string Packet::serialize() const
{
    assert(0 <= x && x < 1024);
    assert(0 <= y && y < 1024);

    char str[13];
    std::snprintf(str, sizeof(str), "a%.3X%.3X-----", x, y);

    std::string string(str);
    assert(string.size() == 12);

    return string;
}

Packet Packet::deserialize(std::string str)
{
    assert(str.size() == 12);
    assert(str[0] == 'a');

    Packet packet;
    packet.x = hex2int(str.substr(1, 3));
    packet.y = hex2int(str.substr(1 + 3, 3));

    return packet;
}

int Packet::hex2int(std::string str)
{
    return std::strtol(str.c_str(), nullptr, 16);
}