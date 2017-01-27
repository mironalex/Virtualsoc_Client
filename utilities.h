/**
  * Holds different utilities functions.
  */
#ifndef UTILITIES_H
#define UTILITIES_H
#include<unistd.h>
#include <cstdio>
#include <string.h>
#include <string>

/**
 * @brief readInt a function that reads an integer from a file descriptor / socket
 * @param fd holds a file descriptor / socket
 * @return the integer that was read
 */
int readInt (int fd);

/**
 * @brief sendMessage a function that sends a string to a socket / file descriptor
 * @param fd holds a file descriptor / socket
 * @param message the message that will be sent.
 */
void sendMessage(int fd, std::string message);

#endif // UTILITIES_H
