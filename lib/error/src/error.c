/*
** EPITECH PROJECT, 2019
** ARP_Spoofing
** File description:
** Main file of the error library, core features
*/

#include <stdlib.h>
#include <string.h>
#include "errorsys.h"

error_t create_error(error_str_t msg)
{
    error_t err = {0};

    err.msg = strdup(msg);
    return (err);
}

void destroy_error(error_t err)
{
    if (err.msg)
        free(err.msg);
    if (err.where)
        free(err.where);
}