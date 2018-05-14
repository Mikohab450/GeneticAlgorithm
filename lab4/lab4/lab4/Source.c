#include<stdio.h>
#include<conio.h>

typedef void(*change_action)();
//typedef void(*take_action)()
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
  printf("rozpoczeto odtwarzanie");
};

void print_stop()
{
  printf("zakonczono odtwarzanie");
};
void exit_()
{
  exit(0);
}
//void ()

int main()
{
  enum state przejscia[3][3] = { {genre,play,end},{ genre,play,end } ,{0,0,0} };
  change_action act[3][3] = { {idle,print_play,idle},{ print_stop, idle,idle },{ idle ,idle,idle } };
  char znak="1";
  enum state current = genre;
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
    act[current][next_state];
    current = next_state;
  }
  return 0;
}