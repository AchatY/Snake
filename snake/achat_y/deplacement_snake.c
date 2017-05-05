/*
** deplacement_snake.c for deplacement_snake.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:18:00 2017 Achat Youmer
** Last update Thu May  4 23:41:56 2017 Achat Youmer
*/
#include "snake.h"

int		colision_snake(liste_t *my_liste, int continuer)
{
  bout_t	*bout_actuel;
  SDL_Rect	position_snake;
  
  bout_actuel = my_liste->first;
  position_snake = bout_actuel->position_actuelle;
  bout_actuel = bout_actuel->next;
  while(bout_actuel->next != NULL)
    {
      if (cmp_position(position_snake,
	      bout_actuel->position_actuelle))
	continuer = 0;
      bout_actuel = bout_actuel->next;
    }
  return continuer;
}

SDL_Rect	deplacement_infini(char direction, SDL_Rect position_init, position_t ecran_size)
{
  SDL_Rect	position;

  position.x = position_init.x;
  position.y = position_init.y;
  if (direction == 'g')
    {
      if (position.x == 0)
	position.x = ecran_size.x + 20;
      position.x = position.x - 20;
    }
  else if (direction == 'd')
    {
      if (position.x == ecran_size.x)
	position.x = -20;
      position.x = position.x + 20;
    }
  else if (direction == 'h')
    {
      if (position.y == 0)
	position.y = ecran_size.y + 20;
      position.y = position.y - 20;
    }
  else if (direction == 'b')
    {
      if (position.y == ecran_size.y)
	position.y = - 20;
      position.y = position.y + 20;
    }
  return position;
}

void		game_princ(SDL_Surface *ecran, position_t ecran_size)
{
  SDL_Surface	*snake_dir[4] = {NULL};
  liste_t	*my_liste;
  SDL_Rect	position;

  snake_dir[DROITE] = IMG_Load("snake_image/snake_droite.png");
  snake_dir[GAUCHE] = IMG_Load("snake_image/snake_gauche.png");
  snake_dir[HAUT] = IMG_Load("snake_image/snake_haut.png");
  snake_dir[BAS] = IMG_Load("snake_image/snake_bas.png");
  my_liste = init_liste(ecran);
  aff_surface(ecran_size,ecran, my_liste, position, snake_dir);
}

void		snake(char **argv)
{
  SDL_Surface	*ecran = NULL;
  position_t	ecran_size;

  ecran_size.x = my_getnbr(argv[1]) * TAILLE_BLOCK;
  ecran_size.y = my_getnbr(argv[2]) * TAILLE_BLOCK;
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(ecran_size.x, ecran_size.y, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Snake", NULL);
  game_princ(ecran, ecran_size);
  SDL_FreeSurface(ecran);
  SDL_Quit();
}
