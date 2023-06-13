#pragma once
#include <stdlib.h>

int parse_select_exists(const char* line, int* out);
int parse_list(char** line, char* name, const char* end);
int parse_size(const char* answer, size_t len);
//int list_number_sub_dir(const char* respond);