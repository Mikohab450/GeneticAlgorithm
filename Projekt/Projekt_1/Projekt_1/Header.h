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

double function_2(double x);
void shuffle(struct osobnik p[], int population);
void cross(struct osobnik p[],int population);
void crossover(int64_t* p1, int64_t* p2, int k);
void set_base_population(struct osobnik base[], int population);
void judge_population(struct osobnik pop[],int population);
double fitness_function(int64_t chrom);
double function_1(double x);
void choose_population(struct osobnik parents[], struct osobnik offspring[], int population);
void sort(struct osobnik p[], int left, int right);
void mutate(struct osobnik m[],double probability);
void copy(struct osobnik parents[], struct osobnik offspring[], int population);

