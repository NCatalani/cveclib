#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "cveclib.h"

Cvec cvecNew() {

    Cvec cv;

    cv = (Cvec) malloc(sizeof(*cv));

    assert(cv != NULL);

    cv->data = NULL;
    cv->size = 0;
    cv->step = CVEC_INIT_STEP;

    return cv;
}

void cvecPush(Cvec cv, void *data) {
    assert(cv != NULL && data != NULL);

    cv->data			=	realloc(
                                        cv->data,
                                        (cv->size + cv->step) * sizeof(void *)
                                    );
    cv->data[cv->size]   =	data;
    cv->size++;
}

void cvecFree(Cvec cv, void(*func)(void *)) {
    int i;

    assert(cv != NULL);

    for (i = 0; i < cv->size; i++) {

        if (cv->data[i] == NULL)
            continue;

        func(cv->data[i]);
		cv->data[i] = NULL;

    }

    free(cv->data);
    free(cv);
    cv = NULL;
}

void cvecSort(Cvec cv, int(*compare)(const void **, const void **)) {
	qsort(
            cv->data,
            cv->size,
            sizeof(void *),
            (int(*)(const void *, const void *))(compare)
        );
}

int cvecSearch(Cvec cv, void *data, int(*compare)(const void *, const void *)) {
    int lower_limit, upper_limit, middle, cmp;

	lower_limit	=	0;
	middle		=	0;
    cmp         =   0;
	upper_limit	=	cv->size - 1;

	while (lower_limit <= upper_limit) {
        // Bitwise operator used to get floor from division by two.
		middle	=	lower_limit	+	((upper_limit - lower_limit) >> 1);
		cmp		=	compare(data, cv->data[middle]);

		if (cmp > 0) {
			lower_limit	=	middle + 1;
			continue;
		}

		if (cmp < 0) {
			upper_limit	=	middle - 1;
			continue;
		}
	}

	return middle;
}
