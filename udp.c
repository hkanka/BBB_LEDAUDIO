

#include <netinet/in.h>
#include <string.h>
#include <printf.h>
#include <fcntl.h>
#include <stdio.h>
#include <arpa/inet.h>
#define BUFLEN 64
#define IPADDRESS "192.168.10.107"

int udpsockfd;
struct sockaddr_in recvaddr;

int udp_setup_socket(int port) {

    udpsockfd = socket(PF_INET, SOCK_DGRAM, 0);
	if (udpsockfd<0) {
            perror("error, could not create socket");
            return -1;
        }
        printf("Socket created\n");
	    fflush(stdout);

	// Setup socket, specify listening interfaces etc
        recvaddr.sin_family = AF_INET;
        recvaddr.sin_port = htons((uint16_t) port);
        recvaddr.sin_addr.s_addr = inet_addr(IPADDRESS);
        memset(recvaddr.sin_zero,'\0',sizeof (recvaddr.sin_zero));

	// Put socket in non blcoking mode
//	int flags = fcntl(udpsockfd, F_GETFL);				// Get the sockets flags
//	flags |= O_NONBLOCK;								// Set NONBLOCK flag
//	if (fcntl(udpsockfd, F_SETFL, flags) == -1){		// Write flags back
//        //perror("error,fcnctl failed - could not set socket to nonblocking");
//        return -1;
//	}

	// Bind to socket, start socket listening
		int bret;
        	bret = bind(udpsockfd, (struct sockaddr*) &recvaddr, sizeof (recvaddr));
		if (bret < 0)
        	{
			printf("(%d) for port (%d)\n",bret,port);
                perror("bind failed, only one process can bind at a time");
                return -1;
        	}
        	fprintf(stderr,"Listening for UDP data on port %d \n",port);
		fflush(stderr);
    return 0;
}
int receivefb(unsigned char *ubuffe){
    int addr_len = sizeof(recvaddr);

    if(recvfrom (udpsockfd, ubuffe, BUFLEN, 0, (struct sockaddr *) &recvaddr, (socklen_t *) &addr_len) < 0) {
        perror("recv");
        return -1;
    }else{
        return 0;
    }
}