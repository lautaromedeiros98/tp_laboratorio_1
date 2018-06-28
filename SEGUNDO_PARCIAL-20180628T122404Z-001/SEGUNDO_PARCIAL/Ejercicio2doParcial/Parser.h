#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "ArrayList.h"

int parser_load(char* path, ArrayList* empleados);
void parse_print(ArrayList* empleados, char* path);


#endif // PARSER_H_INCLUDED
