#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define population 5
#define len 5
#define mutation_propability 0.001

void create(struct chromosom** phead);
void crossover(struct chromosom* p1, struct chromosom*p2, int k);
void set_base_population(struct osobnik base[]);
void judge_population(struct osobnik pop[]);
double fitness_function(struct chromosom* chrom);
double function_(double x);
void choose_population(struct osobnik parents[], struct osobnik offspring[]);
void sort(struct osobnik p[],int size);
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
	/*struct chromosom* test = NULL;
	for (int i = 0; i < len; i++) {
		create(&test);
	}
	struct chromosom* test2 = NULL;
	for (int i = 0; i < len; i++) {
		create(&test2);
	}
	crossover(test,test2,1);
	*/
	struct osobnik base_population[population]=NULL;
	struct osobnik next_population[population];
	set_base_population(next_population);
	int generation = 10;
	for(int m=0; m<generation;m++)
	{
		{

		}
		judge_population(next_population);
		for (int i = 0; i < population - 1; i += 2)
		{
			k = rand() % len;
			crossover(next_population[i].genotyp, next_population[i + 1].genotyp, k);
		}
	};

	return 0;
}

void create(struct chromosom** phead)
{
	enum bool x;
	scanf("%d", &x);
	struct chromosom* nowy = malloc(sizeof(struct chromosom));
	nowy->gen = x;
	nowy->next = *phead;
	*phead = nowy;	
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
	sort(parents,population);
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
			partial_sum += parents[i].fitness;
		}
		current_point += p;
		offspring[j] = parents[i];
		j++;

	}
}

void sort(struct osobnik p[],int size){

}


void mutation(struct osobnik m[]) {
	enum bool mutate;
	struct chromosom* current;
		for (int j = 0; j < population j++)
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