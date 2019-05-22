/*
** EPITECH PROJECT, 2019
** packet_init
** File description:
** Init the packet
*/

#include <stdlib.h>
#include "packet.h"

packet_t *packet_init(void)
{
    packet_t *packet = malloc(sizeof(packet_t));

    if (packet == NULL)
        return (NULL);
    return (packet);
}