/*
** affichage.c for affichage.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:17:44 2017 Achat Youmer
** Last update Fri May  5 08:59:53 2017 Achat Youmer
*/

#include "snake.h"

void			aff_surface(position_t ecran_size, SDL_Surface *ecran, liste_t *my_liste
		 			, SDL_Rect position, SDL_Surface *snake_dir[4])
{
  bonus_position	bonus_position;
  SDL_Event		event;
  SDL_Rect		position_tmp;
  con_dir		continuer_direction;
  int			continuer, tempsPrecedent, tempsActuel;
  char			direction;

  direction = 'd';
  bonus_position.position = init_position();
  tempsPrecedent = tempsActuel = 0;
  continuer = 1;
  while (continuer)
    {
      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
      SDL_PollEvent(&event);
      continuer_direction = evennement(event, continuer, direction, snake_dir);
      continuer = continuer_direction.continuer;
      direction = continuer_direction.direction;
      if (continuer_direction.snake_actuelle != NULL)
	my_liste->first->bout = continuer_direction.snake_actuelle;
      tempsActuel = SDL_GetTicks();
      if (tempsActuel - tempsPrecedent > 150)
	{
	  position_tmp = deplacement_infini(direction, position, ecran_size);
	  position.x = position_tmp.x;
	  position.y = position_tmp.y;
	  my_liste = display_liste(ecran, my_liste, position, bonus_position.ind);
	  bonus_position = bonus(ecran, bonus_position.position, position, ecran_size);
	  continuer = display_murs(ecran, position, continuer, ecran_size);
	  continuer = colision_snake(my_liste, continuer);
	  score(ecran, my_liste->nbr);
	  tempsPrecedent = tempsActuel; 
	}
      else
	SDL_Delay(150 - (tempsActuel - tempsPrecedent));
      SDL_Flip(ecran);
    }
  SDL_FreeSurface(bonus_position.bonus);
  if (test_rejouer(ecran, my_liste->nbr))
    game_princ(ecran, ecran_size);
}

con_dir		evennement(SDL_Event event, int continuer, char direction,
			   SDL_Surface *snake_dir[4])
{
  con_dir	con_dir;
  SDL_Surface	*snake_actuelle = NULL;
  
  con_dir.continuer = continuer;
  con_dir.direction = direction;
  if (event.type == SDL_QUIT)
	con_dir.continuer = 0;
  else if(event.type == SDL_KEYDOWN)
    {
      if (event.key.keysym.sym == SDLK_UP)
	if(con_dir.direction != 'b' && (con_dir.direction ='h'))
	  snake_actuelle = snake_dir[HAUT];
      if (event.key.keysym.sym == SDLK_DOWN)
	if (con_dir.direction != 'h' && (con_dir.direction = 'b'))
	  snake_actuelle = snake_dir[BAS];
      if (event.key.keysym.sym == SDLK_RIGHT)
	if (con_dir.direction != 'g' && (con_dir.direction = 'd'))
	  snake_actuelle = snake_dir[DROITE];
      if(event.key.keysym.sym == SDLK_LEFT)
	if (con_dir.direction != 'd' && (con_dir.direction = 'g'))
	  snake_actuelle = snake_dir[GAUCHE];
    }
  con_dir.snake_actuelle = snake_actuelle;
  return con_dir;
}
