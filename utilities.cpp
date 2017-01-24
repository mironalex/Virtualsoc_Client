#include "utilities.h"

int readInt (int fd){
    int x = 0;
    ssize_t size;
    size = read(fd, &x, 4);
    if(size != 4) throw("Failed to read an int");
    return x;
}

void sendMessage(int fd, std::string message){
    unsigned long messageSize = message.size();
    if( write(fd, (char *)&messageSize, 4) != 4) throw("Failed to write message size");
    dprintf(fd,"%s",message.c_str());
}
