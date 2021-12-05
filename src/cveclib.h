#ifndef _CVEC_HEADER_
#define _CVEC_HEADER_
#include <stdio.h>

//CONSTANTS
#define CVEC_INIT_STEP 8

//STRUCTURES
struct Cvec {
    void    **data;
    int     size;
    int     step;
};
typedef struct Cvec *Cvec;

//FUNCTION PROTOTYPES

Cvec        cvecNew();
void        cvecPush(Cvec cv, void *data);
void        cvecFree(Cvec cv, void(*func)(void *));
void        cvecSort(Cvec cv, int(*compare)(const void **, const void **));
int         cvecSearch(Cvec cv, void *data, int(*compare)(const void *, const void *));

#endif
