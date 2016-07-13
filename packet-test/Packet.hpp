#ifndef PACKET_TEST_PACKET_HPP
#define PACKET_TEST_PACKET_HPP

#include <string>

class Packet
{
public:
    std::string serialize() const;
    static Packet deserialize(std::string str);

    int x, y;

private:
    static int hex2int(std::string str);
};


#endif //PACKET_TEST_PACKET_HPP
