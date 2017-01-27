/**
  * Holds client specific connection functions.
  */
#ifndef CLIENT_H
#define CLIENT_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

using namespace std;

#define PORT 1337 /**<Macro for the port.*/
#define ADDRESS "127.0.0.1" /**<Macro for the server address.*/

extern int errno; /**<Error code macro. */

/**
 * @brief function that connects at ADDRESS using PORT
 * @return a socket to the server
 */
int startConnection(){
  int sd;
  struct sockaddr_in server;
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1){
      perror ("socket() error.\n");
      return errno;
  }
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(ADDRESS);
  server.sin_port = htons (PORT);
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1){
      perror ("connect() error.\n");
      return -1;
  }
  return sd;
}



#endif // CLIENT_H
