
#include"Header.h"


int main(int argc, char** argv[])
{	
	//srand(time(NULL));		//linijka zakomentowana na czas testownia programu dla roznych parametrow wejsciowych
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
	if (gen_check && pop_check && mut_check)		//jezeli wszystki parametry zostaly odczytane
	{
		FILE* fp;
		fp = fopen("FUN_test.txt", "w");
		struct osobnik* base_population = (struct osobnik*)malloc(population * sizeof(struct osobnik));
		struct osobnik* next_population = (struct osobnik*)malloc(population * sizeof(struct osobnik));;
		set_base_population(base_population, population);		//ustawienie populacji poczatkowej

		for (int m = 0; m < generation; m++)		//przez okreslona liczbe iteracji
		{

			judge_population(base_population, population);		//ocena populazji bazowej
			choose_population(base_population, next_population, population);	//wybor osobnikow do kolejnej populacji
			fprintf(fp, "%d\t %f\n", m, base_population[population - 1].fitness);	//zapis najlepszego osobnika do pliku
			choose_and_cross(next_population, population);		//krzyzowanie nowej populacji
			mutate(next_population, mutation_probability, population);		//mutacja nowej populacji
			copy(base_population, next_population, population);	//nowa populacja staje sie populacja bazowa


		};
		free(base_population);	//zwolnienie pamieci
		free(next_population);
		base_population = NULL;
		next_population = NULL;

	}
	else
		printf("Nieprawidlowe parametry!");
	return 0;
}