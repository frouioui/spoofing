/*
** EPITECH PROJECT, 2019
** ARP_Spoofing
** File description:
** Main include of the error library, core features
*/

#if !defined(_ERROR_SYS_HPP)
#define _ERROR_SYS_HPP

typedef char * error_str_t;

enum type_error_e {
    DEFAULT,
    WARNING,
    FATAL
};

typedef enum type_error_e error_type_t;

struct error_s {
    error_str_t msg;
    error_str_t where;
    error_type_t type;
};

typedef struct error_s error_t;

error_t create_error(error_str_t msg);

error_t set_where(error_t *err, error_str_t where);
error_t set_type(error_t *err, error_type_t type);

void destroy_error(error_t err);

#endif // _ERROR_SYS_HPP
