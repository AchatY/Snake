/*
** liste_chainer.c for liste_chainer.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:18:57 2017 Achat Youmer
** Last update Thu May  4 23:33:04 2017 Achat Youmer
*/
#include "snake.h"

liste_t		*init_liste(SDL_Surface *ecran)
{
  bout_t	*bout;
  liste_t	*liste;

  liste = NULL;
  liste = malloc(sizeof(liste_t));
  bout = malloc(sizeof(bout_t));
  bout->bout = IMG_Load("snake_image/snake_droite.png");
  bout->position_actuelle.x = ecran->w / 2 - bout->bout->w / 2;
  bout->position_actuelle.y = ecran->h / 2 - bout->bout->h / 2;
  bout->position_precedente.x = bout->position_actuelle.x / 2;
  bout->position_precedente.x = bout->position_actuelle.y;
  bout->next = NULL;
  liste->first = bout;
  liste->last = bout;
  liste->first->next = liste->last;
  liste->nbr = 1;
  return liste;
}

liste_t		*ajouter_liste(liste_t *liste)
{
  bout_t	*bout_new;

  bout_new = create_bout();
  liste->last->next = bout_new;
  liste->last = bout_new;
  liste->nbr++;
  return liste;
}

liste_t		*display_liste(SDL_Surface *ecran, liste_t *liste, SDL_Rect position_snake, int ind)
{
  bout_t	*bout_actuel;
  int		i;

  bout_actuel = malloc(sizeof(bout_t));
  if (ind)
    liste = ajouter_liste(liste);
  liste->first->position_precedente =
    cp_position(liste->first->bout,liste->first->position_actuelle);
  liste->first->position_actuelle =
    cp_position(liste->first->bout,position_snake);
  bout_actuel = liste->first;
  i = 0;
  while (bout_actuel->next != NULL)
    {
      SDL_BlitSurface(bout_actuel->bout , NULL, ecran, &bout_actuel->position_actuelle);
      bout_actuel->next->position_precedente =
	cp_position(bout_actuel->bout, bout_actuel->next->position_actuelle);
      bout_actuel->next->position_actuelle =
	cp_position(bout_actuel->bout, bout_actuel->position_precedente);
      bout_actuel = bout_actuel->next;
      i++;
    }
  return liste;
}

bout_t		*create_bout()
{
  bout_t	*bout_new;

  bout_new = NULL;
  bout_new = malloc(sizeof(bout_t));
  bout_new->bout = IMG_Load("snake_image/bout_snake.png");
  bout_new->position_actuelle.x = 0;
  bout_new->position_actuelle.y = 0;
  bout_new->position_precedente.x = 0;
  bout_new->position_precedente.x = 0;
  bout_new->next = NULL;
  return bout_new;
}
