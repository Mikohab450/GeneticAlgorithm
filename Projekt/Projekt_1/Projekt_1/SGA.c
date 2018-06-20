#include"Header.h"


void set_base_population(struct osobnik* base, int population)
{

	
	for (int i = 0; i < population; i++)
	{
		
		base[i].chromosom = 0;
		for (int j = 0; j < 5; ++j) 
			base[i].chromosom = (base[i].chromosom << 15) | (rand() & 0x7FFF); //losowanie liczby 64 bitowej
		
		/*	
			rand() & 0x7FFF zwroci 15 losowych bitow
			ktore sa dodawane do chromosomu, ktory jest za kazdym razem przesuwany o 15 bitow w lewo(aby zrobic miejsce na nowa porcje bitow)
		*/
	}
}


void judge_population(struct osobnik* pop, int population)
{
	for (int i = 0; i <population; i++)
	{
		pop[i].fitness = -fitness_function(pop[i].chromosom);
	}

}
void choose_and_cross(struct osobnik* p,int population) {

	int crossing_point;	
	shuffle(p, population);		//mieszanie tablicy osobnikow
	for (int i = 0; i < population - 1; i+=2)		
	{
	
		crossing_point = rand() % size_64;			//wybor punktu przeciecia
		crossover(&p[i].chromosom, &p[i+1].chromosom, crossing_point);		//krzyzowanie dwoch kolejnych osobnikow
	}

}




double fitness_function(int64_t chrom)
{
	double x =pow(2, -31)*chrom;	//geny sa reprezentowa jako liczby staloprzecinkowe o okreslonej precyzji
		return function_1(x);
	
}


double function_1(double x)
{
	return (sin(16 * x) + 2 * pow(x,4) + 6 * pow(x,3) + pow(x , 3)+4*pow(x,2));
}

void choose_population(struct osobnik* parents, struct osobnik* offspring, int population)
{
	sort(parents, 0, population - 1);		//sortowanie populacji rodzicielskiej
	double partial_sum = 0;		//suma czesciowa, sluzaca do sprawdzania na ktorego osobnika wskazuje punkt
	for (int i = 0; i < population; i++)
		parents[i].rank = i + 1;				//przypisanie odpowiednich rang
	double sum = ((population + 1) / 2)*population;  //laczna suma wszystkich rang
	double p = (population + 1) / 2;				//dlugosc jenego przedzialu
	double starting_point = (double)rand() / RAND_MAX * p;	//losowanie liczby calkowitej z przedzialu (0,p)
	double current_point = starting_point;		//poczatkowe ustawienie punktu 
	int i = 0;			//iteratory w petli
	int j = 0;
	while (current_point < sum) {			//dopoki nie przekroczymy calego zakresu


		while (partial_sum < current_point)		//sprawdzenie, na ktorego osobnika wskazuje punkt
		{
			partial_sum += parents[i].rank;	
			i++;
		}
		current_point += p;			//przesuniecie punktu
		offspring[j] = parents[i - 1];	//wybor osobnika
		j++;

	}
}

void sort(struct osobnik* p, int left, int right) {
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


void mutate(struct osobnik* m,double probability, int population) {
	
	for (int j = 0; j <population; j++)		//dla kazdego sosbnika z populacji
	{
		int64_t mask;		//maska do operacji bitowych
		double mutate;
		for (int i = 0; i < size_64; i++)		//dla kazdego jego genu
		{
			mask = 1;					
			mutate = (double)rand() / RAND_MAX;	//losowanie liczby rzeczywistej z przedzialu (0,1)
			if (mutate < probability)			//jezeli zaszlo prawdopodobienstwo mutacji
			{
				mask=mask << i;			//przesuwamy maske na bit, na ktorym ma zajsc mutacja
				m[j].chromosom ^= mask;		//negujemy bit, na ktorym maska jest 1
			};
		}
	}
}

void copy(struct osobnik* parents, struct osobnik* offspring, int population) {
	for (int i = 0; i < population; i++)
	{
		parents[i] = offspring[i];
	}
}




void crossover(int64_t* p1, int64_t* p2, int cross_point)
{
	int64_t temp1, temp2;	//zmienne pomocnicze, przechowujace wartosci liczb do krzyzowania
	int64_t mask;		//maska do operacji bitowych
	temp1 = *p1;
	temp2 = *p2;
	mask = 0;	
	mask = ~mask;		//maska ustawiona na ciag samych jedynek
	mask = mask << cross_point;		
	*p1 &= mask;	//wyzerowanie odpowiedniej liczby mniej znaczacych bitow
	*p2 &= mask;
	mask = ~mask;	
	temp1 &= mask;	//wyzerowanie odpowiedniej liczby bardziej znaczacych bitow
	temp2 &= mask;
	*p1 |= temp2;		//dodanie bitowe odpowiednich ciagow bitow
	*p2 |= temp1;

}

void shuffle(struct osobnik* p, int population) {

	struct osobnik temp; //zmienna tymczasowa, uzywana do zamiany elementow
	int p1, p2;		//dwa indeksy tablicy, ktore zostana ze soba zamienione
	int loop = 3*population;
	for (int i = 0; i < loop; i++)
	{
		p1 = rand() % population;	//losowanie indeksow								
		p2 = rand() % population;				
		temp = p[p1];		//zamiana elementow tablicy
		p[p1] = p[p2];
		p[p2] = temp;
	}
}

