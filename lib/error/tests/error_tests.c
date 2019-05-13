/*
** EPITECH PROJECT, 2019
** ARP_Spoofing
** File description:
** Test of the main feature of error lib
*/

#include <criterion/criterion.h>
#include <stdlib.h>
#include "errorsys.h"

Test(error_library, create_error)
{
    error_t err = create_error("this is an error");

    cr_assert_null(err.where);
    cr_assert_str_eq(err.msg, "this is an error");
    cr_assert_eq(err.type, DEFAULT);
    destroy_error(err);
}

Test(error_library, set_where_attribut)
{
    error_t err = create_error("this is an error");

    set_where(&err, "over there");
    cr_assert_str_eq(err.where, "over there");
}

Test(error_library, set_type_attribut)
{
    error_t err = create_error("this is an error");

    set_type(&err, FATAL);
    cr_assert_eq(err.type, FATAL);
}

Test(error_library, set_where_attribut_return)
{
    error_t err = create_error("this is an error");

    err = set_where(&err, "over there");
    cr_assert_str_eq(err.where, "over there");
}

Test(error_library, set_type_attribut_return)
{
    error_t err = create_error("this is an error");

    err = set_type(&err, FATAL);
    cr_assert_eq(err.type, FATAL);
}
