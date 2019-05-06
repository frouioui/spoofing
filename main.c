#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(void)
{
    int sock = socket(AF_PACKET, SOCK_RAW, IPPROTO_UDP);

    if (sock <= 0) {
        #if defined(_DEBUG)
            printf("Something went wrong with the socket\n");
        #endif
        perror("socket");
        return (1);
    }
    return (0);
}