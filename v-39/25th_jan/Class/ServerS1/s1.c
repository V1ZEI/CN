
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 

#include<string.h>

char buffer[1024]; 

void captilize(){
     for(int i=0;buffer[i]!='\0';i++){
          if(buffer[i]>='a' && buffer[i]<='z'){
              buffer[i]=buffer[i]-32;
          }
     }
}
int main(){
    
     memset(buffer,'\0',sizeof(buffer));
	 read(0,buffer,sizeof(buffer));
     //printf("message recieved by S1 : %s",buffer);

     captilize();

	 write(1,buffer,sizeof(buffer));
	 	
}