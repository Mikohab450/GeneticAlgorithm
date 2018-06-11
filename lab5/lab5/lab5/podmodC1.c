#include "librY.h"
void podmodC1_toString(int n) {
	for (int i = 0; i < n; i++)
		printf("\t");
	printf("podmodC1\n");
	librY_toString(n + 1);
};