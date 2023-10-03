#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

int main() {
  struct sockaddr_storage incoming;
  struct addrinfo hints, *res;

  memset(&hints, 0, sizeof hints);
  hints.ai_family = PF_INET;
  hints.ai_socktype = SOCK_STREAM;
  hints.ai_flags = AI_PASSIVE;

  getaddrinfo(NULL, "80", &hints, &res);

  // open tcp connection
  int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  fprintf(stdout, "Socket created \n");

  bind(sockfd, res->ai_addr, res->ai_addrlen);
  printf("%s \n", "File descriptor bound");

  listen(sockfd, 10);
  printf("%s \n", "File descriptor listening");

  socklen_t incoming_size = sizeof(incoming);
  int new_fd = accept(sockfd, (struct sockaddr *)&incoming, &incoming_size);

  return 0;
}