/*
** func_calc.c for func_calc.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:19:51 2017 Achat Youmer
** Last update Thu May  4 23:07:08 2017 Achat Youmer
*/
#include "snake.h"

SDL_Rect init_position()
{
  SDL_Rect position;

  position.x = 0;
  position.y = 0;
  return position;
}

SDL_Rect changer_position(position_t ecran_size)
{
  SDL_Rect position;
  position.x = myRand(2, ecran_size.x / 20 - 2) * 20;
  position.y = myRand(2, ecran_size.y / 20 - 2) * 20;
  return position;
}

int cmp_position(SDL_Rect position_bonus, SDL_Rect position_snake)
{
  if (((position_snake.x) <= position_bonus.x
       && position_bonus.x <= (position_snake.x))
      && ((position_snake.y) <= position_bonus.y
	  && position_bonus.y <= (position_snake.y)))
    return 1;
  else
    return 0;
}

int     myRand(int low, int high)
{
  srand(time(NULL));
  return rand() % (high - low + 1) + low;
}

SDL_Rect cp_position(SDL_Surface *snake,SDL_Rect position1)
{
  SDL_Rect position2;

  position2.x = position1.x - snake->w + snake->w ;
  position2.y = position1.y;
  return position2;
}
