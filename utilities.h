#ifndef UTILITIES_H
#define UTILITIES_H
#include<unistd.h>
#include <string.h>
#include <string>

int readInt (int fd);

void sendMessage(int fd, std::string message);

#endif // UTILITIES_H
