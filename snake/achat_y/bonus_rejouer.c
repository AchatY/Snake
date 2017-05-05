/*
** bonus_rejouer.c for bonus_rejouer.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:19:30 2017 Achat Youmer
** Last update Fri May  5 09:02:13 2017 Achat Youmer
*/
#include "snake.h"

bonus_position		bonus(SDL_Surface *ecran, SDL_Rect position_bonus,
			      SDL_Rect position_snake, position_t ecran_size)
{
  bonus_position	bonus_position;

  bonus_position.ind = 0;
  bonus_position.bonus = IMG_Load("snake_image/bonus.png");
  bonus_position.position.x = position_bonus.x;
  bonus_position.position.y = position_bonus.y;
  if (position_bonus.x == 0 && position_bonus.y == 0)
    bonus_position.position = changer_position(ecran_size);
  else if(cmp_position(position_bonus, position_snake))
    {
      bonus_position.position = changer_position(ecran_size);
      bonus_position.ind = 1;
    }
  SDL_BlitSurface(bonus_position.bonus, NULL, ecran, &bonus_position.position);
  return bonus_position;
}

int		test_rejouer(SDL_Surface *ecran, int nbr)
{
  int		quiter;
  SDL_Surface	*game_over;

  quiter = 1;
  game_over = IMG_Load("snake_image/game_over.jpg");
  while (quiter)
    {
      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
      quiter = rejouer(ecran, game_over, nbr);
      if (quiter == 2)
	return 1;
      SDL_Flip(ecran);
    }
  return 0;
}

int		rejouer(SDL_Surface *ecran, SDL_Surface *game_over, int nbr)
{
  SDL_Event	event;
  int		continuer;
  SDL_Rect	position_GO;

  continuer = 1;
  position_GO.x = ecran->w / 2 - game_over->w / 2;
  position_GO.y = ecran->h / 2 - game_over->h / 2;
  SDL_PollEvent(&event);
  if (event.type == SDL_QUIT)
      continuer = 0;
  if (event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_ESCAPE)
	continuer = 0;
      if (event.key.keysym.sym == SDLK_r)
	continuer = 2;
    }
  SDL_BlitSurface(game_over, NULL, ecran, &position_GO);
  score(ecran,nbr);
  
  return continuer;
}

