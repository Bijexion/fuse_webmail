#ifndef __CURL_H__
#define __CURL_H__

#include <curl/curl.h>

#define USER_NAME "justin.filipozzi@etu.unistra.fr"
#define ROOT_URL "imaps://webmail.partage.renater.fr"

CURL* my_curl_init();
void parse_userpwd();
int check_userpwd();

#endif