#include "podmodC1.h"


void modC_toString(int n) {
	for (int i = 0; i < n; i++)
		printf("\t");
	printf("modC\n");
	podmodC1_toString(n+1);
};