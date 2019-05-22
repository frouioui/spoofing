/*
** EPITECH PROJECT, 2019
** arp_fill
** File description:
** Fill the stucture arp (socket, interface_id, mac_address)
*/

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <linux/if_ether.h>
#include <linux/if_packet.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include "arp.h"

static bool arp_fill_socket(arp_t *arp, bool is_sudo)
{
    if (arp == NULL)
        return (false);
    if (is_sudo == false)
        arp->fd = socket(PF_INET, SOCK_DGRAM, IPPROTO_IP);
    else
        arp->fd = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ARP));
    if (arp->fd == -1) {
        printf("Error: failed to initialize the socket !\n");
        return (false);
    }
    return (true);
}

static bool arp_fill_interface_and_mac(arp_t *arp, char *interface)
{
    struct ifreq ifr;

    if (arp == NULL || interface == NULL)
        return (false);
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);
    if (ioctl(arp->fd, SIOCGIFINDEX, &ifr) == -1) {
        printf("Error: invalid interface.\n");
        return (false);
    }
    arp->interface_id = ifr.ifr_ifindex;
    arp->address->sll_ifindex = arp->interface_id;
    if (ioctl(arp->fd, SIOCGIFHWADDR, &ifr) == -1) {
        printf("Error: unable to retrieve the mac address.\n");
        return (false);
    }
    arp->src_mac_address = calloc(6, sizeof(uint8_t));
    if (arp->src_mac_address == NULL)
        return (false);
    memcpy(arp->src_mac_address, ifr.ifr_hwaddr.sa_data, 6);
    return (true);
}

static bool arp_fill_target_and_sender(arp_t *arp, char *target_ip, \
                                        char *sender_ip)
{
    if (arp == NULL || target_ip == NULL || sender_ip == NULL)
        return (false);
    arp->sender_ip_address = calloc(strlen(target_ip), sizeof(uint8_t));
    if (arp->sender_ip_address == NULL)
        return (false);
    arp->target_ip_address = calloc(strlen(sender_ip), sizeof(uint8_t));
    if (arp->target_ip_address == NULL)
        return (false);
    if (inet_pton(AF_INET, target_ip, arp->sender_ip_address) != 1)
        return (false);
    if (inet_pton(AF_INET, sender_ip, arp->target_ip_address) != 1)
        return (false);
    return (true);
}

bool arp_fill(arp_t *arp, argument_t *args, bool is_sudo)
{
    if (arp == NULL || args->interface == NULL || \
        args->src_ip == NULL || args->dest_ip == NULL)
        return (false);
    if (arp_fill_socket(arp, is_sudo) == false)
        return (false);
    if (arp_fill_interface_and_mac(arp, args->interface) == false)
        return (false);
    if (arp_fill_target_and_sender(arp, args->src_ip, args->dest_ip) == false)
        return (false);
    arp->args = args;
    return (true);
}