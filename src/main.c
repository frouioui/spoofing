/*
** EPITECH PROJECT, 2019
** ARP SPOOFING
** File description:
** Main file
*/

#include <stdlib.h>
#include <stdio.h>
#include "argument.h"
#include "errorsys.h"

int main(const int argc, const char **argv)
{
    argument_t args = {0};
    error_t err = get_argument(&args, argc, argv);

    if (err.msg) {
        printf("Error: %s\n", err.msg);
        return (84);
    }
    return (0);
}