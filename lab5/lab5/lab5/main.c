#include<stdio.h>
#include "librX.h"
#include "modA.h"
#include "modB.h"
#include "modC.h"
#include "modD.h"


void program_toString(int n) {
	for (int i = 0; i < n; i++)
		printf("\t");
	printf("program\n");
	librX_toString(n + 1);
	modA_toString(n + 1);
	modB_toString(n + 1);
	modC_toString(n + 1);
	modD_toString(n + 1);
}

int main()
{
	program_toString(1);


	return 0;
}