#include "librX.h"


void librY_toString(int n) {
	for (int i = 0; i < n; i++)
		printf("\t");
	printf("librY\n");
	librX_toString(n + 1);

};