#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

int create_socket(int *domain, int *type, int *protocol) {
  int s;

  if ((s = socket(domain, type, protocol)) == -1) {
    fprintf(stderr, "Error creating socket \n");
    fprintf(stderr, errno);
    return -1;
  }

  return s;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Expected port number as argument \n");
    return 1;
  }

  // open tcp connection
  int conn = create_socket(PF_INET, SOCK_STREAM, 0);
  fprintf(stdout, "Socket created on port: %s \n", argv[1]);

  return 0;
}