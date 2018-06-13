#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define population 5
#define len 5
#define mutation_propability 0.001

void crossover(struct chromosom* p1, struct chromosom*p2, int k);
void set_base_population(struct osobnik base[]);
void judge_population(struct osobnik pop[]);
double fitness_function(struct chromosom* chrom);
double function_(double x);
void choose_population(struct osobnik parents[], struct osobnik offspring[]);
void sort(struct osobnik p[],int left,int right);
void mutation(struct osobnik m[]);

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

int main()
{
	srand(time(NULL));
	int k;

	struct osobnik base_population[population] = { NULL };
	struct osobnik next_population[population] = { NULL };
	set_base_population(base_population);
	int generation = 1;
	for(int m=0; m<generation;m++)
	{

		judge_population(base_population);
		choose_population(base_population, next_population);
		for (int i = 0; i < population - 1; i += 2)
		{
			k = rand() % len;
			crossover(next_population[i].genotyp, next_population[i + 1].genotyp, k);
		}
	};

	return 0;
}

void crossover(struct chromosom* p1, struct chromosom* p2, int k)
{

	struct chromosom* temp1;
	struct chromosom*temp2;
	temp1 = p1;
	temp2 =  p2;
	for (int i = 0; i < k-1; i++) {
		temp1 =  temp1->next;
		temp2 = temp2->next;
	}
	struct chromosom* temp3;
	temp3 = temp1->next;
	temp1->next = temp2->next;
	temp2->next = temp3;
}



void set_base_population(struct osobnik base[])
{
	for (int i = 0; i < population; i++)
	{
		for (int j = 0; j < len; j++)
		{
		
			struct chromosom* nowy = malloc(sizeof(struct chromosom));
			nowy->gen = rand() & 1;
			nowy->next = base[i].genotyp;
			base[i].genotyp = nowy;
		}
	}
}

void judge_population(struct osobnik pop[])
{
	for (int i = 0; i < population; i++)
	{
		pop[i].fitness = -fitness_function(pop[i].genotyp);
	}

}

double fitness_function(struct chromosom* chrom)
{
	double t;
	double L=chrom->gen;
	struct chromosom* temp = chrom;
	for (int i = 0; i < len-1; i++)
	{
		temp = temp->next;
		L = L * 2 + temp->gen;
	}
	t = pow(2, -2);
	return function_(L*t);
}

double function_(double x)
{
	return x*x;
}

void choose_population(struct osobnik parents[], struct osobnik offspring[])
{
	sort(parents,0,population-1);
	double partial_sum = 0;
	for(int i = 0; i < population; i++)
		parents[i].rank = i + 1;
	double sum = ((population + 1) / 2)*population;
	double p = (population + 1) / 2;
	double starting_point = (double)rand() / RAND_MAX * p;	//losowanie liczby calkowitej z przedzialu (0,p)
	double current_point = starting_point;
	int i , j = 0;
	while (current_point < sum) {


		for (i = 0; partial_sum < current_point; i++)
		{
			partial_sum += parents[i].rank;
		}
		current_point += p;
		offspring[j] = parents[i];
		j++;

	}
}

void sort(struct osobnik p[], int left, int right) {
	int i, j;
	i = (left + right) / 2;
	struct osobnik piwot, temp;
	piwot = p[i];
	p[i] = p[right];
	for (i = j = 0; i < right; i++)
	{
		if (p[i].fitness < piwot.fitness)
		{
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
			j++;
		}
	}
		p[right] = p[j];
		p[j] = piwot; 
	
	if (left < j - 1)  sort(p,left, j - 1);
	if (j + 1 < right) sort(p,j + 1,right);

}


void mutation(struct osobnik m[]) {
	struct chromosom* current;
		for (int j = 0; j < population ;j++)
		{
			current = m[j].genotyp;
			for(int i=0;i<len;i++)
			if ((double)rand() / RAND_MAX < mutation_propability)
			{
				current->gen = !current->gen;
			};
			current = current->next;
				
		}
}