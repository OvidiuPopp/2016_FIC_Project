    #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
  
      int main()
      {
          int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    portno = 20231;
      sockfd = socket(AF_INET, SOCK_STREAM, 0);
        server = gethostbyname("193.226.12.217");
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr,(char *)&serv_addr.sin_addr.s_addr,server->h_length);
    serv_addr.sin_port = htons(portno);
    
  if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        printf("ERROR connecting");
    n = write(sockfd,"f\ns\n",1);
        if (n < 0) 
         printf("ERROR writing to socket");
         }