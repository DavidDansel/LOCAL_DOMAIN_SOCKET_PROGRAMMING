#include<stdio.h>
#include <unistd.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <string.h>
 

int main(){
 //socket
 int fd=socket(AF_UNIX,SOCK_STREAM,0);
 if(fd==-1){
   printf("Server socket could not be created\n");
 }
 
 //bind 
 struct sockaddr_un addr;
 memset(&addr,0,sizeof(struct sockaddr_un));
 addr.sun_family=AF_UNIX;
 strcpy(addr.sun_path,"/tmp/myserver");
 int ret=bind(fd,(struct sockaddr *)&addr,sizeof(struct sockaddr));
 if(ret==-1){
   printf("error binding socket");
   return -1;
 }

 //listen
 listen(fd,5);
  
 //accept
 int cfd=accept(fd,NULL,NULL);
 if(cfd==-1){
   printf("error accepting connection");
   return -1;
 }

 char buff[1000];
    read(cfd,buff,24);
    write(1,buff,24);
 //close 
}
