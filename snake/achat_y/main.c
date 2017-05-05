/*
** main.c for main.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:20:02 2017 Achat Youmer
** Last update Thu May  4 22:20:03 2017 Achat Youmer
*/
#include "snake.h"

int main(int argc, char **argv)
{
  if (argc == 3)
    snake(argv);
  else
    my_putstr("Usage :\n./snake [width] [height]\n");
  return 0;
}
