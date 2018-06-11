#include "librX.h"


void podmodA1_toString(int n) {
	for (int i = 0; i < n; i++)
		printf("\t");
	printf("podmodA1\n");
	librX_toString(n + 1);
};