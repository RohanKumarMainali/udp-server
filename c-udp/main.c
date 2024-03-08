#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/types.h>

int main(int argc, char *argv[]) {
  int port = 5000;
  int sockfd;
  struct sockaddr_in myAddr, remoteAddr;
  char buffer[1024];
  socklen_t addr_size;

  sockfd = socket(AF_INET, SOCK_DGRAM, 0);

  memset(&myAddr, 0, sizeof(myAddr));
  myAddr.sin_family = AF_INET;
  myAddr.sin_port = htons(port);
  myAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

  bind(sockfd, (struct sockaddr *) &myAddr, sizeof(myAddr));
  addr_size = sizeof(remoteAddr);
  recvfrom(sockfd, buffer, 1024, 0, (struct sockaddr *) &remoteAddr, &addr_size);
  printf("Data received: %s", buffer);
  return 0;
}
