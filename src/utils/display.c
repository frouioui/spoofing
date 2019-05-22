/*
** EPITECH PROJECT, 2019
** diplay functions
** File description:
** Functions to print the mac/ip address
*/

#include <stdio.h>
#include "utils.h"

void print_mac_address(uint8_t *mac)
{
    printf("%02X:%02X:%02X:%02X:%02X:%02X", mac[0], mac[1], mac[2], \
            mac[3], mac[4], mac[5]);
}

void print_ip_address(uint8_t *ip)
{
    printf("%02d.%02d.%02d.%02d", ip[0], ip[1], ip[2], ip[3]);
}
