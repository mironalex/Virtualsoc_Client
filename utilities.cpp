#include "utilities.h"

int readInt (int sock){
    int value = 0;
    ssize_t size;
    size = read(sock, &value, 4);
    if(size != 4) throw("Failed to read an int");
    return value;
}

void sendMessage(int sock, std::string message){
    unsigned long messageSize = message.size();
    write(sock, (char *)&messageSize, 4);
    dprintf(sock,"%s",message.c_str());
}
