#include<stdio.h>
#include<conio.h>

typedef void(*change_action)();
typedef void(*take_action)(char** gatunek);

enum state {
  genre,
  play,
  end
};
enum action {
  start,
  stop,
  escape
};
void idle()
{
};
void print_play()
{
  printf("rozpoczeto odtwarzanie\n");
};

void print_stop()
{
  printf("zakonczono odtwarzanie\n");
};
void exit_()
{
  exit(0);
}
void genre_choice(char** gatunek)
{
	int choice;
	printf("wybierz gatunek\n1-R&B\n2-Rock\n3-Jazz\n4-Blues\n");
	scanf("%i", &choice);
	switch (choice) {
	case 1:
		*gatunek = "R&B";
			break;
	case 2:
		*gatunek = "Rock";
			break;
	case 3:
		*gatunek = "Jazz";
			break;
	case 4:
		*gatunek = "Blues";
			break;
	}

	

	
}

void print_genre(char** gatunek)
{
	printf(*gatunek);
	printf("\n");
}

void end_(char**gatunek)
{
	exit(0);
}



int main()
{
  enum state przejscia[3][3] = { {play,genre,end},{play,genre,end } ,{0,0,0} };
  change_action act_change[3][3] = { {idle,print_play,idle},{ print_stop, idle,idle },{ idle ,idle,idle } };
  take_action act[3] = {genre_choice,print_genre,end_};
  char znak="1";
  enum state current = genre;
  char* current_genre;
  genre_choice(&current_genre);
  while (znak!=27)
  {
    while (!kbhit()){}
    znak = getch();
    enum action a;
	
    if (znak == '1')
      a = start;
    else if (znak == '0')
      a = stop;
    else if (znak == 27)
      a = escape;
    else {
      break;
    }
    enum state next_state= przejscia[current][a];
    act_change[current][next_state]();
    current = next_state;
	act[current](&current_genre);

  }
  return 0;
}