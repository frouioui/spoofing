/*
** EPITECH PROJECT, 2019
** ARP_Spoofing
** File description:
** Contains setters for the error struct
*/

#include <stdlib.h>
#include <string.h>
#include "errorsys.h"

error_t set_where(error_t *err, error_str_t where)
{
    if (where == NULL)
        return (*err);
    if (err->where)
        free(err->where);
    err->where = strdup(where);
    return (*err);
}

error_t set_type(error_t *err, error_type_t type)
{
    err->type = type;
    return (*err);
}