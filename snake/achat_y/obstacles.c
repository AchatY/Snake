/*
** obstacles.c for obstacle.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:20:10 2017 Achat Youmer
** Last update Thu May  4 23:36:32 2017 Achat Youmer
*/
#include "snake.h"

int		display_murs(SDL_Surface *ecran, SDL_Rect position,
			     int continuer, position_t ecran_size)
{
  SDL_Surface	*mur;
  SDL_Rect	position_mur;
  position_t	cord_mur[100];
  int		i;
  
  i = 0;
  position_mur.y = 0;
  mur = IMG_Load("snake_image/mur.jpg");
  while(position_mur.y < ecran_size.y)
    {
      position_mur.x = 0;
      while(position_mur.x < ecran_size.x)
	{
	  if ((position_mur.y == 0 && position_mur.x > 300)||
	      (position_mur.x == 0 && position_mur.y < 300)||
	      (position_mur.x == (ecran_size.x - 20) && position_mur.y < 200)||
	      (position_mur.y == (ecran_size.y - 20) && position_mur.x > 150))
	    {
	      cord_mur[i].x = position_mur.x;
	      cord_mur[i].y = position_mur.y;
	      SDL_BlitSurface(mur, NULL, ecran, &position_mur);
	      i++;
	    }
	  position_mur.x = position_mur.x + 20;
	}
      position_mur.y = position_mur.y + 20;
    }
  SDL_FreeSurface(mur);
  return game_over_mur(position, cord_mur, continuer);
}

int	game_over_mur(SDL_Rect position, position_t cord_mur[42],int continuer)
{
  int	i;
  
  i = 0;
  while (i <= 42)
    {
      if (cord_mur[i].x == position.x && cord_mur[i].y == position.y)
	continuer = 0;
      i++;
    }
  return continuer;
}

