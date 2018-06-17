#include<stdio.h>
#include"Header.h"


int main()
{
	srand(time(NULL));
	struct osobnik base_population[population] = { NULL };
	struct osobnik next_population[population] = { NULL };
	set_base_population(base_population);
	int generation = 500;
	for(int m=0; m<generation;m++)
	{

		judge_population(base_population);
		choose_population(base_population, next_population);
		cross(next_population);
		mutate(next_population);
		copy(base_population, next_population);

	};
	sort(base_population,0 ,population-1);
	double best = -base_population[population - 1].fitness;
	struct chromosom* best_chromosom = base_population[population - 1].genotyp;
	//	delete_list(base_population);
	return 0;
}