
#include"Header.h"


int main(int argc, char** argv[])
{	
	//srand(time(NULL));
	int population;
	int gen_check = 0, mut_check = 0, pop_check = 0;//zmienne pzechowujace informacje o tym, czy parametry zostaly odczytane poprawnie
	char* temp;
	double mutation_probability ;
	int generation;
	for (int i = 1; i < argc-1; i++)
	{
		temp = argv[i];
		if (!strcmp(temp,"-p"))
		{
			population = atoi(argv[i + 1]);
			pop_check = 1;
		}
			else if (!strcmp(temp, "-m"))
			{	
				mutation_probability = atof(argv[i + 1]);
				mut_check = 1;
				
			}
			else if (!strcmp(temp, "-g"))
			{

				generation = atoi(argv[i + 1]);
				gen_check = 1;
			}
				
		}
	
		FILE* fp;
		fp = fopen("da.txt", "w");
		struct osobnik* base_population = (struct osobnik*)malloc(population * sizeof(struct osobnik));
		struct osobnik* next_population = (struct osobnik*)malloc(population * sizeof(struct osobnik));;
		set_base_population(base_population, population);

		for (int m = 0; m < generation; m++)
		{
			
			judge_population(base_population, population);
			choose_population(base_population, next_population, population);
			fprintf(fp, "%d\t %f\n", m, base_population[population - 1].fitness);
			choose_and_cross(next_population, population);
			mutate(next_population, mutation_probability, population);
			copy(base_population, next_population, population);
			

		};
		free(base_population);
		free(next_population);
		/*sort(base_population,0 ,population-1);
		double best = -base_population[population - 1].fitness;
		struct chromosom* best_chromosom = base_population[population - 1].genotyp;
		*/
	
	return 0;
}