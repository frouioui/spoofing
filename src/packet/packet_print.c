/*
** EPITECH PROJECT, 2019
** spoofing
** File description:
** packet_print
*/

#include <stdlib.h>
#include <stdio.h>
#include "packet.h"

bool packet_print(packet_t *packet)
{
    if (packet == NULL)
        return (false);
    for (unsigned int i = 0; i < sizeof(arp_header_t) + \
        sizeof(ethernet_header_t); i++) {
        printf("%x", packet->buffer[i]);
        printf(" ");
    }
    printf("\n");
    return (true);
}