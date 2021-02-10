#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

#define PORT 27993
#define ADDRESS 128.119.243.147

int main(int argc, char *argv[]) {
	int socket_desc;
	struct sockaddr_in server;
	char start[2000], server_reply[2000];
	char *numHolder;
	int firstNum, secondNum, result;
	const char delim[] = "";
	char end[2000] = "BYE";
	char *oper;
	char newString[200][200];
	char sendBack[2000];
	char header[2000];
	char toKeep[2000];
	int port;

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_desc == -1) {
		printf("Could not create socket");
	}

	port = atoi(argv[2]);

	server.sin_addr.s_addr = inet_addr(argv[3]);
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	if(connect(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
		puts("connect error");
		return 1;
	}
	
	

	strcpy(start, "cs230 HELLO ");
	strcat(start, argv[1]);
	strcat(start, "\n");
	if(send(socket_desc, start, strlen(start), 0) < 0) {
		puts("Send failed");
		return 1;
	}
	while(1 == 1) {
		//bad reception
		// puts("here somehow");
		if(recv(socket_desc, server_reply, 2000, 0) < 0) {
			puts("recv failed");
			return 1;
		}
		//end of the cycle
		// puts(server_reply);
		if(strstr(server_reply, end) != NULL) {
			// puts("killed");
			return 0;
		}

		// //math
		// toKeep = "cs230 ";
		int i=0;
		int j=0;
		int ctr=0;
		for(i=0;i<=(strlen(server_reply));i++)
		{
		    if(server_reply[i]==' '||server_reply[i]=='\0')
		    {
		        newString[ctr][j]='\0';
		        ctr++; 
		        j=0;
		    }
		    else
		    {
		        newString[ctr][j]=server_reply[i];
		        j++;
		    }
		}

		for(i=0; i <= 4; i++) {
			if(i == 2) {
				firstNum = atoi(newString[i]);
				// puts(newString[i]);

			}
			else if(i == 3) {
				oper = newString[i];
				
			}
			else if(i == 4) {
				secondNum = atoi(newString[i]);
				// sprintf(sendBack, "%d", secondNum);
				// puts(sendBack);
			}
		}

		char theOp = oper[0];
		// printf("%c", theOp);
		if(theOp == '/') {
			result = firstNum / secondNum;
		}
		else if(theOp == '-') {
			result = firstNum - secondNum;
		}
		else if(theOp == '+'){
			result = firstNum + secondNum;
		}
		else if(theOp == '*') {
			result = firstNum * secondNum;
		}
		

		// printf("Result = %d\n", j);

		// puts((char*)result);

		sprintf(sendBack, "%d", result);

		strcpy(header, "");

		strcat(header, sendBack);

		strcat(header, "\n");

		char *newResult = (char*) malloc(strlen("cs230 ") + strlen(header) + 1);
    	strcpy(newResult, "cs230 ");
   		strcat(newResult, header);

		puts(newResult);

		if(send(socket_desc, newResult, strlen(newResult), 0) < 0) {
			puts("Send failed");
			return 1;
		}



	}



	return 0;
}





// socket(int domain, int type, int protocol);
// ssize_t send(int socket, const void * buffer, size_t length, int flags);
// ssize_t recv(int socket, void * buffer, size_t length, int flags);
// ssize_t connect(int socket, const struct sockaddr *address, socklen_t address_len);
// int close(int fildes);

