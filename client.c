#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include <sys/un.h>
#include <sys/socket.h>

int main(){
 // create socket
 int fd=socket(AF_UNIX,SOCK_STREAM,0);
 if(fd==-1){
   printf("Client socket could not be created\n");
 }
 
 //connect
 struct sockaddr_un addr;
 memset(&addr,0,sizeof(struct sockaddr_un));
 addr.sun_family=AF_UNIX;
 strcpy(addr.sun_path,"/tmp/myserver");
 if(connect(fd,(struct sockaddr *)&addr,sizeof(struct sockaddr_un))==-1){
  printf("Error connecting to server\n");
  return -1;
 }
 write(fd,"Hello, I am the Client\n",24);
 //close
}
