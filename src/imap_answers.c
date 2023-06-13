#include "imap_answers.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int parse_select_exists(const char* line, int* out)
{
    char* ptr = strstr(line, "EXISTS");
    if (!ptr)
        return -1;
    ptr--;
    *ptr = '\0';
    while (*(ptr--) != ' ')
    {

    }
    *out = atoi(ptr + 2);
    return 0;
}

int parse_list(char** line, char* res, const char* end)
{
    char* cur = *line;
    do
    {
        ++cur;
        if (cur == end)
            return -1;
    }
    while(*cur != '\r' && *cur != '\n');

    cur--;
    if (*cur != '\"') {
        return -1;
    }
    *line = cur + 2;

    size_t len;
    for (len = 0; *(--cur) != '\"'; ++len) {

    }
    strncpy(res, cur + 1, len);
    res[len] = '\0';
    return 0;
}

int parse_size(const char* answer, size_t len)
{
    if (answer[len - 1] != ')')
        return -1;
    char str_to_find[] = "FETCH (RFC822.SIZE ";
    char* n = strstr(answer, str_to_find);
    if (!n) {
        return -1;
    }
    n += strlen(str_to_find);

    char* str = malloc(answer + len - n);
    snprintf(str, answer + len - n, "%s", n);
    int res = atoi(str);
    free(str);
    return res;
}

static int get_header_attr(const char* answer, char* sub, char* str_to_search)
{
    char* start = strstr(answer, str_to_search);
    if (!start)
        return -1;
    start += strlen(str_to_search);

    char* end = strstr(start, "\n");
    size_t len = end - start;
    sub = malloc(len);
    strncpy(sub, start, len);
    return len;
}

#define GET_HEADER_ATTR(res, str_to_search) \
    a1 = get_header_attr(answer, res, str_to_search); \
    if (a1 < 0)                                        \
        return -1;                                            \
    res += a1;

int parse_header(const char* answer, char* subject, char* sender, char* receivers, char* CC)
{
    size_t res = 0;
    int a1;

    GET_HEADER_ATTR(subject, "Subject: ")
    GET_HEADER_ATTR(sender, "From: ")
    GET_HEADER_ATTR(receivers, "To: ")
    GET_HEADER_ATTR(CC, "CC: ")

    return res;
}