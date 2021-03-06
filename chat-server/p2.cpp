#include<iostream>
#include<pthread.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<cstring>
#include<stdlib.h>

using namespace std;

const char* name = "Client2";

void *reader(void* args){
	while(1){
		int rfd = open(name, O_RDONLY);
		char c, msg[1024];
		int j=0;
		while(read(rfd, &c, 1)) msg[j++] = c;
		msg[j] = '\0';
		int size = sizeof(name);
		// if(!strcmp(name, msg.substr(0, size))) //uncomment this line to check for sender of msg and printing the msg to all clients
			cout<<msg<<"\n";
		close(rfd);
	}
}

void* writer(void *args){
	while(1){
		char c, msg[1024], buffer[1024];
		int j=0;
		read(STDIN_FILENO, &c, 1);
		while(c != '\n'){
			msg[j++] = c;
			read(STDIN_FILENO, &c, 1);
		}
		msg[j] = '\0';
		buffer[0] = '\0';
		strcat(buffer, name);
		strcat(buffer, ":");
		strcat(buffer, msg);
		strcat(buffer, "$\n");
		int wfd = open("server", O_WRONLY);
		write(wfd, &buffer, 1024);
		close(wfd);
	}
}

int main(){
	cout<<name<<" Client started..\n";
	mkfifo(name, 0666);
	pthread_t write_th, read_th;
	pthread_create(&write_th, NULL, writer, NULL);
	pthread_create(&read_th, NULL, reader, NULL);
	pthread_join(write_th, NULL);
	pthread_join(read_th, NULL);
}
