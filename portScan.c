#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int socketScan;
	int connectScan;

	char * destiny;
	destiny = argv[1];

	struct sockaddr_in target;

	for(int port=1; port<65535; port++){

		socketScan = socket(AF_INET, SOCK_STREAM, 0);
		target.sin_family = AF_INET;
		target.sin_port = htons(port);
		target.sin_addr.s_addr = inet_addr(destiny);

		connectScan = connect(socketScan, (struct sockaddr *)&target, sizeof target);

		if(connectScan == 0)
		{
			printf("open %d - status: [OPEN] \n", port);
			close(socketScan);
			close(connectScan);
		}else{
			close(socketScan);
			close(connectScan);
		}
 	}
}
