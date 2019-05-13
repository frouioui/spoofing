/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** packet_send
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <stdio.h>
#include "packet.h"

bool packet_send(int fd, packet_t *packet, struct sockaddr *address, \
                socklen_t addr_len)
{
    if (fd == -1 || packet == NULL || address == NULL)
        return (false);
    if (sendto(fd, packet->buffer, \
                sizeof(arp_header_t) + sizeof(ethernet_header_t), 0, \
                address, addr_len) < 0) {
        printf("Error: failed to send the packet\n");
        return (false);
    }
    return (true);
}
