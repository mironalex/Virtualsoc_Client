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
 * @brief readInt a function that reads an integer from a socket
 * @param sock holds a socket to the server
 * @return the integer that was read
 */
int readInt (int sock);

/**
 * @brief sendMessage a function that sends a string to a socket
 * @param sock holds a socket to the server
 * @param message the message that will be sent.
 */
void sendMessage(int sock, std::string message);

#endif // UTILITIES_H
