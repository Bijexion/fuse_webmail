#pragma once
#include <stdlib.h>

int parse_select_exists(const char* line, int* out);
int parse_list(char** line, char* name, const char* end);
int parse_size(const char* answer, size_t len);
int parse_header(const char* answer, char* subject, char* sender, char* receivers, char* CC);