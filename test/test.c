#include <stdio.h>
#include <stdlib.h>
#include "../src/cveclib.h"

int main () {
    fprintf(stderr, "Creating new CVec object...\n");
    Cvec cv = cvecNew();
    fprintf(stderr, "Object was created! -- Cvec cv (pointer: [%p])\n", (void *) cv);

    fprintf(stderr, "Freeing object...\n");
    cvecFree(cv, free);
    fprintf(stderr, "Object is free!\n");
    return 0;
}
