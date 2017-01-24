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

#define PORT 1337
#define ADDRESS "192.168.100.8"

/* codul de eroare returnat de anumite apeluri */
extern int errno;

int startConnection(){
  int sd;
  struct sockaddr_in server;
  if ((sd = socket (AF_INET, SOCK_STREAM, 0)) == -1){
      perror ("Eroare la socket().\n");
      return errno;
  }
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = inet_addr(ADDRESS);
  server.sin_port = htons (PORT);
  if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1){
      printf("[client]Eroare la connect().\n");
      return -1;
  }
  return sd;
}



#endif // CLIENT_H
