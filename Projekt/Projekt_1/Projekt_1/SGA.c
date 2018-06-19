#include"Header.h"

void cross(struct osobnik p[],int population) {

	int k;
	shuffle(p, population);
	for (int i = 0; i < population - 1; i+=2)
	{
	
		k = rand() % size_64;
		crossover(&p[i].chromosom, &p[i+1].chromosom, k);
	}

}





void set_base_population(struct osobnik base[],int population)
{
	for (int i = 0; i < population; i++)
	{
		base[i].chromosom = rand()<<49;
		base[i].chromosom |=rand()<<32;
		base[i].chromosom |=rand()<<16;
	}
}

void judge_population(struct osobnik pop[],int population)
{
	for (int i = 0; i <population ; i++)
	{
		pop[i].fitness = -fitness_function(pop[i].chromosom);
	}

}

double fitness_function(int64_t chrom)
{
	double x =pow(2, -31)*chrom;
		return function_2(x);
	
}

double function_1(double x)
{
	return (x*x*x*x + x*x+ 3* x - 1+20*sin(2*x));
}

double function_2(double x)
{
	return (20*sin(6*x) + 2*x*x*x*x + 16*x*x*x + x*x);
}


void choose_population(struct osobnik parents[], struct osobnik offspring[], int population)
{
	sort(parents, 0, population - 1);
	double partial_sum = 0;
	for (int i = 0; i < population; i++)
		parents[i].rank = i + 1;
	double pop = population;
	double sum = ((pop + 1) / 2)*pop;
	double p = (pop + 1) / 2;
	double starting_point = (double)rand() / RAND_MAX * p;	//losowanie liczby calkowitej z przedzialu (0,p)
	double current_point = starting_point;
	int i = 0;
	int j = 0;
	while (current_point < sum) {


		while (partial_sum < current_point)
		{
			partial_sum += parents[i].rank;
			i++;
		}
		current_point += p;
		offspring[j] = parents[i - 1];
		j++;

	}
}

void sort(struct osobnik p[], int left, int right) {
	int i, j;
	i = (left + right) / 2;
	struct osobnik piwot, temp;
	piwot = p[i];
	p[i] = p[right];
	for (i = j = left; i < right; i++)
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

	if (left < j - 1)  sort(p, left, j - 1);
	if (j + 1 < right) sort(p, j + 1, right);

}


void mutate(struct osobnik m[],double probability) {
	
	for (int j = 0; j <2; j++)
	{
		int64_t k;
		double mutate;
		for (int i = 0; i < size_64; i++)
		{
			k = 1;
			mutate = (double)rand() / RAND_MAX;
			if (mutate < probability)
			{
				k=k << i;
				m[j].chromosom ^= k;
			};
		}
	}
}

void copy(struct osobnik parents[], struct osobnik offspring[], int population) {
	for (int i = 0; i < population; i++)
	{
		parents[i] = offspring[i];
	}
}




void crossover(int64_t* p1, int64_t* p2, int k)
{
	int64_t temp1, temp2, x;
	temp1 = *p1;
	temp2 = *p2;
	x = 0;
	x = ~x;
	x = (uint64_t)x >> 1;
	x = x << k;
	*p1 &= x;
	*p2 &= x;
	x = ~x;
	temp1 &= x;
	temp2 &= x;
	*p1 += temp2;
	*p2 += temp1;

}

void shuffle(struct osobnik p[], int population) {

	struct osobnik temp; 
	int p1, p2;
	int loop = 3*population;
	for (int i = 0; i < loop; i++)
	{
		p1 = rand() % size_64;
		p2 = rand() % size_64;
		temp = p[p1];
		p[p1] = p[p2];
		p[p2] = temp;
	}
}