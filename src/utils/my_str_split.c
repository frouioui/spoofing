/*
** EPITECH PROJECT, 2019
** my_str_split
** File description:
** Split a string by a delimiter
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

static size_t count_tokens(char *str, char *delimiter)
{
    size_t nbr_token = 0;
    char *str_tmp = NULL;

    if (str == NULL || delimiter == NULL)
        return (0);
    str_tmp = str;
    str_tmp = strstr(str_tmp, delimiter);
    while (str_tmp) {
        if (str_tmp - str >= (int)strlen(str))
            break;
        nbr_token++;
        str_tmp += strlen(delimiter);
        str_tmp = strstr(str_tmp, delimiter);
    }
    return (nbr_token);
}

static bool is_delimiter(char *str, char *delimiter, size_t index)
{
    size_t str_length = 0;
    size_t delimiter_length = 0;

    if (str == NULL || delimiter == NULL)
        return (false);
    str_length = strlen(str);
    delimiter_length = strlen(delimiter);
    if (index > str_length || index + delimiter_length > str_length)
        return (false);
    for (size_t i = 0; i < delimiter_length; i++) {
        if (str[index + i] != delimiter[i])
            return (false);
    }
    return (true);
}

static size_t get_size(char *str, char *delimiter, size_t index)
{
    size_t str_length = 0;
    size_t size = 0;

    if (str == NULL || delimiter == NULL)
        return (0);
    str_length = strlen(str);
    for (size_t i = index; i < str_length; i++, size++) {
        if (is_delimiter(str, delimiter, i) == true)
            return (size);
    }
    return (size);
}

static char *strcpy_a_b(char *dest, char *src, size_t start, size_t end)
{
    size_t j = 0;

    if (dest == NULL || src == NULL)
        return (NULL);
    for (size_t i = start; i < end; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return (dest);
}

char **my_str_split(char *str, char *delim)
{
    char **tokens = NULL;
    size_t size = 0;
    size_t curr_word = 0;

    tokens = malloc((count_tokens(str, delim) + 2) * sizeof(char *));
    for (size_t i = 0; i < strlen(str);) {
        size = get_size(str, delim, i);
        if (size == 0) {
            i += size + strlen(delim);
            continue;
        }
        tokens[curr_word] = calloc((size + 1), sizeof(char));
        if (tokens[curr_word] == NULL)
            return (NULL);
        tokens[curr_word] = strcpy_a_b(tokens[curr_word], str, i, i + size);
        i += size + strlen(delim);
        curr_word++;
    }
    tokens[curr_word] = NULL;
    return (tokens);
}