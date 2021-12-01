#pragma once
#include <stdlib.h>

#define JMENO_ALBA 21
#define JMENO_INTERPRETA 21

struct t_album
{
    char  jmeno_alba[JMENO_ALBA];
    char  jmeno_interpreta[JMENO_INTERPRETA];
    int   rok;
    struct t_album* dalsi;
};

void add(char* Jmeno, int rok_vydani, char* Jmeno_I, struct t_album** uk_prvni);
void del(int rok, struct t_album** uk_prvni);