#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include <stdint.h>
#include<stdio.h>
#include<string.h>
#define size_64 64


struct osobnik {
	int64_t chromosom;
	int rank;
	double fitness;
};

void set_base_population(struct osobnik * base, int population);
/*  ________________________________________________________________________________________
	Funkcja ustawia poczatkowa populacje osobnikow przechowywana w dynamicznej tablicy base
	Dla kazdego osobnika populacji funkcja losuje wartosc jego chromosomu 
	________________________________________________________________
	Paramtery funkcji:
		-base -tablica osobnikow, ktorym mja zostac przydzielone chromosomy
		-population- liczebnosc populacji
	____________________________________________________

		

*/
void shuffle(struct osobnik* p, int population);
/*   _____________________________________________
		Funkcja miesza elementy tablicy p zawierajacej elementy typu osobnik
	__________________________________________
	Parametry funkcji:
		-p -tablica, ktorej elementy trzeba przemieszac
		-population- liczebnosc populacji
	__________________________________________
*/
void choose_and_cross(struct osobnik *p,int population);
/*_______________________________________
	Funkcja wybiera losowe rozlaczne pary osobnikow a nastepnie je krzyzuje
	Losowanie rozlaczne wykonywane jest przy pomocy funkcji shuffle a nastepnie
	na chromosomach kolejnych elementow tablicy wykonywana jest funkcja crossover
	_________________________________________________________________
	Parametry funkcji:
		-p -tablica, ktorej elementy trzeba krzyzowac
		-population- liczebnosc populacji
	_____________________________________________
	*/
void crossover(int64_t* p1, int64_t* p2, int cross_point);
/*_____________________________________________________
	Funkcja krzyzuje dwa chromosomy reprezentowane jako liczby typu int64_t w punkcie cross_point
	Chromosomy sa przekazywane przez wskaznik, aby ich wartosci wewnatrz funkcji mogly byc modyfikowane
	__________________________________________
	Parametry funkcji:
		-p1 pierwszy z pary chromosomow do krzyzowania,
		-p2 drugi z pary chromosomow do krzyzowania,
		-cross_point punkt, w ktorym sa krzyzowane chromosomy
		______________________________________________


*/
void judge_population(struct osobnik *pop,int population);
/*__________________________________
	Funkcja ocenia populacja osobnikow na podstawie funkcji przystosowania fitness_function
	Wartosc funkcji przystosowania zapisywana jest do zmiennej fitness kazdego osobnika
	_________________________________
	Parametry funkcji:
	-p -tablica, ktorej elementy podlegaja ocenie
	-population- liczebnosc populacji
	______________________________________
*/
double fitness_function(int64_t chrom);
/*
	Funkcja wylicza wartosc przystosowania osobnika o danym chromosomie
	__________________________________________
	Parametry funkcji:
		-chrom- chromosom osobnika podlegajacego ocenie
	___________________________________________
	Wartosc zwracana:
		wartosc funkcji przystosowania danego osobnika
*/
double function_1(double x);
/*____________
Przyk³adowa funkcja ciagla, uzywana do testowania programu
*/


void choose_population(struct osobnik* parents, struct osobnik* offspring, int population);
/*___________________________
	Funkcja dokonujaca wybory przyszlej populacji
	_____________________________________________
	Parametry funkcji:
		-parents - tablica osobnikow, z ktorej nalezy wybrac przyszla populacje
		-offspring- tablica wybranych osobnikow
		-population- liczebnosc populacji
	___________________________________________

	*/
void sort(struct osobnik *p, int left, int right);
/*________________________
	Funkcja sortuje niemalejaco tablice p o podanym lweym i prawym indeksie
	Sortowanie odbywa sie rekurencyjnie z wykorzystaniem algorytmu sortowania szybkiego
	______________________________________________
	Parametry funkcji:
		-p - tablica elementow do posortowania
		-left- lewy indeks tablicy
		-right - prawy indeks tablicy
	_______________________________________
	*/
void mutate(struct osobnik* m,double probability, int population);
/*________________________________
	Funkcja wykonuje z pewnym prawdopodobiestwem operacje mutacji na populacji m
	___________________________________________
	Parametry funkcji:
		-m -populacja osobnikow podlegajach operacji
		-population- liczebnosc populacji
		-probability - prawdopodobienstwo zajscia mutacji na pojedynczym genie
________________________________________________

*/
void copy(struct osobnik* parents, struct osobnik* offspring, int population);
/*___________________________________
	Funkcja kopiuje talice offspring do talbicy parents
	______________________________________________
	Parametry funkcji:
		-parents - tablica, do ktorej ma zostac przekopiowane nowe pokolenie
		-offspring - talbica zawierajaca elementy, ktore maja zostac przekopiowane
		-population - ilosc elementow tablicy
		_____________________________________
	*/

