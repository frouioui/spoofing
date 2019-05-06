#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(void)
{
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_UDP);

    if (sock <= 0) {
        perror("socket");
        return (1);
    }
    return (0);
}