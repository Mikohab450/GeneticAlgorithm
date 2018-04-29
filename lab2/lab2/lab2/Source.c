#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fun_a(int rozmiar, void **p);
void fun_b(void **p);
void add(struct student** phead, char* nazwisko);
void print_and_destroy(struct student** pHead);


void fun_7(float * A, float * B, float * C, int n, float(*operacja)(float, float));
float op(float a, float b);

struct student {
	char* nazwisko;
	struct student* next;
};
int main()
{
	void *b = NULL;
	fun_a(100, &b);
	scanf("%s", b);
	printf("%s", b);
	fun_b(&b);
	struct student* Head = NULL;
	add(&Head,"Nowak");
	add(&Head, "Kowalski");
	print_and_destroy(&Head);
	
	int n = 3;
	float *A = (float*)malloc(n * sizeof(float));
	A[0] = 0.65f;
	A[1] = 1.34f;
	A[2] = 5.23f;
	float *B= (float*)malloc(n * sizeof(float));
	B[0] = 6.4f;
	B[1] = 4.12f;
	B[2] = 3.12f;
	float *C = (float*)malloc(n * sizeof(float));
	fun_7(A, B, C,n, op);
	free(A);
	free(B);
	free(C);
	return 0;
}


void fun_a(int rozmiar, void **p)
{
	void* b = malloc(rozmiar);
	*p = b;
}

void fun_b(void **p)
{
	free(*p);
	*p = NULL;
}


void add(struct student** phead, char* nazwisko)
{
	struct student* nowy = malloc(sizeof(struct student));
	nowy->next = *phead;
	nowy->nazwisko = strdup(nazwisko);
	*phead = nowy;
}

void print_and_destroy(struct student** pHead)
{
	struct student* pom2= *pHead;
	struct student *pom=pom2;
	while (pom2)
	{
		pom = pom2;
		printf("%s", pom->nazwisko);
		free(pom->nazwisko);
		pom2 = pom->next;
		free(pom);
	}
}


typedef  float(*operacja_fff)(float, float);

void fun_7(float * A, float * B, float * C, int n, float(*operacja)(float, float)) {
	float result;
	for (int i = 0; i < n; i++)
	{
		result = operacja(A[i], B[i]);
		C[i] = result;
	}
}
float op(float a, float b)
{
	return a * b;
}
