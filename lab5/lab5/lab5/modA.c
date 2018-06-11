#include "librX.h"
#include "podmodA1.h"
#include "podmodA2.h"



void modA_toString(int n) {
	for (int i = 0; i < n; i++)
		printf("\t");
	printf("modA\n");
	librX_toString(n + 1);
	podmodA1_toString(n+1);
	podmodA2_toString(n+1);
};