#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;

void buildPacket (byte byteBuffer[], string command){

    // Build Packets for transmission
    int header1 = 0, header2 = 1, packetID = 2, length = 3;

    byteBuffer[header1] = bitset<8>(255);
    byteBuffer[header2] = bitset<8>(255);
    byteBuffer[packetID]; // Broadcast ID = 0xFE

    if (command == "write"){
        byteBuffer[length]; // Parameters + 2
    }

}

int main (void){

    byte byteBuffer[15];
    int* buffLen;

    buildPacket(byteBuffer, "write");

}
