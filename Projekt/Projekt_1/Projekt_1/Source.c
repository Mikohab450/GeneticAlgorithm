
#include"Header.h"
#define popu 200

int main(int argc, char** argv[])
{	
	//srand(time(NULL));
	int population;
	char* temp;
	double mutation_probability ;
	int generation;
	for (int i = 1; i < argc-1; i++)
	{
		temp = argv[i];
		if (!strcmp(temp,"-p"))
		{
			population=atoi(argv[i+1]);
		}
			else if (!strcmp(temp, "-m"))
			{
				mutation_probability=atof(argv[i+1]);
			}
					else if (!strcmp(temp, "-g"))
				{
						generation = atoi(argv[i+1]);
				}
		}
			
	FILE* fp;
	fp = fopen("danexx.txt", "w");
	struct osobnik base_population[popu];
	struct osobnik next_population[popu];
	set_base_population(base_population,population);
	
	for(int m=0; m<generation;m++)
	{

	judge_population(base_population,population);
	choose_population(base_population, next_population,population);
	fprintf(fp, "%d\t %f\n", m,base_population[population-1].fitness);
	cross(next_population,population);
	mutate(next_population,mutation_probability);
	copy(base_population, next_population,population);
	
	};
	/*sort(base_population,0 ,population-1);
	double best = -base_population[population - 1].fitness;
	struct chromosom* best_chromosom = base_population[population - 1].genotyp;
	*/

	return 0;
}