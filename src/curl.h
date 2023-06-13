#pragma once

#include <curl/curl.h>

char userpwd[64];
#define USER_NAME "justin.filipozzi@etu.unistra.fr"
#define ROOT_URL "imaps://webmail.partage.renater.fr"

CURL* my_curl_init();
void parse_userpwd();
int check_userpwd();