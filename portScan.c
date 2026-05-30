#include <stdio.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

int valid_ip(const char argv[]);

int main(int argc, char *argv[])
{
    if(valid_ip(argv[1]) == 1)
    {
        printf("incompatible IP\n(must have IPv4 format)\n");
        return 1;
    }
    char* destiny = argv[1];

	int socketScan;
	int connectScan;

	struct sockaddr_in target;

	for(int port=0; port<65535; port++){

		socketScan = socket(AF_INET, SOCK_STREAM, 0);
		target.sin_family = AF_INET;
		target.sin_port = htons(port);
		target.sin_addr.s_addr = inet_addr(destiny);

		connectScan = connect(socketScan, (struct sockaddr *)&target, sizeof target);

		if(connectScan == 0)
		{
			printf("open %d - status: [OPEN] \n", port);
			close(socketScan);
		}else{
			close(socketScan);
		}
 	}
}

int valid_ip(const char test[1])
{
    int a,b,c,d;
    if(sscanf(&test[1], "%d.%d.%d.%d", &a,&b,&c,&d) == 4)
    {
        if(a < 0 || a > 255) return 1;
        if(b < 0 || b > 255) return 1;
        if(c < 0 || c > 255) return 1;
        if(d < 0 || d > 255) return 1;
        return 0;
    }
    return 1;
}
