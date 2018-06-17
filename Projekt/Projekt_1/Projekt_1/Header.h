#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define population 100
#define len 14
#define mutation_propability 0.05
enum bool{
	FALSE,
	TRUE
};

struct osobnik {
	struct chromosom* genotyp;
	int rank;
	double fitness;

};

struct chromosom {
	enum bool gen;
	struct chromosom* next;
};
void cross(struct osobnik p[]);
void crossover(struct chromosom* p1, struct chromosom*p2, int k);
void set_base_population(struct osobnik base[]);
void judge_population(struct osobnik pop[]);
double fitness_function(struct chromosom* chrom);
double function_(double x);
void choose_population(struct osobnik parents[], struct osobnik offspring[]);
void sort(struct osobnik p[], int left, int right);
void mutate(struct osobnik m[]);
void copy(struct osobnik parents[], struct osobnik offspring[]);
void delete_list(struct osobnik populacja[]);
