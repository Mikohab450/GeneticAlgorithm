#include"Header.h"

void cross(struct osobnik p[]) {
	int t = population;
	struct osobnik temp;
	int p1, k;
	for (int i = 0; i < population - 1; i++)
	{
		p1 = rand() % (population - i);
		temp = p[p1];
		p[p1] = p[population - i - 1];
		p[population - i - 1] = temp;
		i++;
		p1 = rand() % (population - i);
		temp = p[p1];
		p[p1] = p[population - i - 1];
		p[population - i - 1] = temp;
		k = rand() % len;
		crossover(p[population - i].genotyp, p[population - i - 1].genotyp, k);
	}

}




void crossover(struct chromosom* p1, struct chromosom* p2, int k)
{

	struct chromosom* temp1;
	struct chromosom*temp2;
	temp1 = p1;
	temp2 = p2;
	for (int i = 0; i < k - 1; i++) {
		temp1 = temp1->next;
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
	struct chromosom* temp = chrom->next;
	double L = temp->gen;
	for (int i = 1; i < len - 1; i++)
	{
		temp = temp->next;
		L = L * 2 + temp->gen;
	}
	t = pow(2, -4);
	if (chrom->gen)
		return function_((-L*t));
	else
		return function_((L*t));
}

double function_(double x)
{
	return (x*x*x*x + 3 * x*x*x - 1);
}

void choose_population(struct osobnik parents[], struct osobnik offspring[])
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


void mutate(struct osobnik m[]) {
	struct chromosom* current;
	for (int j = 0; j < population; j++)
	{
		current = m[j].genotyp;
		for (int i = 0; i<len; i++)
			if ((double)rand() / RAND_MAX < mutation_propability)
			{
				current->gen = !current->gen;
			};
		current = current->next;

	}
}

void copy(struct osobnik parents[], struct osobnik offspring[]) {
	for (int i = 0; i < population; i++)
	{
		parents[i] = offspring[i];
	}
}



void delete_list(struct osobnik populacja[])
{
	struct chromosom* temp;
	struct chromosom* temp2;
	for (int i =0; i<population; i++)
	{
		temp = populacja[i].genotyp;
		for (int j = 0; j < len ; j++)
		{
			temp2 = temp;
			temp = temp2->next;
			free(temp2);
		}
	}

}