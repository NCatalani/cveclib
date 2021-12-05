#ifndef _CVEC_HEADER_
#define _CVEC_HEADER_
#include <stdio.h>

#define CVEC_INIT_STEP 8

struct Cvec {
    int     size;
    int     step;
    void    **data;
};
typedef struct Cvec *Cvec;

/**
 * @brief Instanciates new CVector object.
 *
 * @return Cvec
 */
Cvec        cvecNew();

/**
 * @brief Pushes data into CVector object.
 *
 * @param cv Cvector object
 * @param data Data pointer
 */
void        cvecPush(Cvec cv, void *data);

/**
 * @brief  Frees a CVector object using a custom function.
 *
 * @param cv CVector object
 * @param func Custom function
 */
void        cvecFree(Cvec cv, void(*func)(void *));

/**
 * @brief Sorts a CVector object using a custom function.
 *
 * @param cv CVector object
 * @param compare Custom compare function
 */
void        cvecSort(Cvec cv, int(*compare)(const void **, const void **));

/**
 * @brief Searches for data using a compare function inside CVector.
 *
 * @param cv CVector object
 * @param data Data being searched
 * @param compare Custom compare function
 * @return int Array index of match
 */
int         cvecSearch(Cvec cv, void *data, int(*compare)(const void *, const void *));

#endif
