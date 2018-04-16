#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fun_a(int rozmiar, void **p);
void fun_b(void **p);
void add(struct student** phead, char* nazwisko);
void print_and_destroy(struct student** pHead);

//zad7
// void(float * A,float * B, float * C,int n,float(*op)(float,float))

struct student {
	char* nazwisko;
	struct student* next;
};
int main()
{
	void *b = NULL;
	fun_a(100, &b);
	//scanf("%s", b);
	//printf("%s", b);
	fun_b(&b);
	struct student* Head = NULL;
	add(&Head,"Nowak");

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



}