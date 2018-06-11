#include "librY.h"

void modD_toString(int n) {
	for (int i = 0; i < n; i++)
		printf("\t");
	printf("modD\n");
	librY_toString(n + 1);
};