/*
** score.c for score.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:19:15 2017 Achat Youmer
** Last update Thu May  4 23:40:30 2017 Achat Youmer
*/
#include "snake.h"

char	*Score_str()
{
  char	*Score;

  Score = malloc(sizeof(char) * 100);
  Score[0] = 'S';
  Score[1] = 'c';
  Score[2] = 'o';
  Score[3] = 'r';
  Score[4] = 'e';
  Score[5] = ' ';
  Score[6] = ' ';
  Score[7] = '\0';
  return Score;
}

void	score(SDL_Surface *ecran, int ind)
{
  SDL_Rect	position;
  SDL_Surface	*texte = NULL;
  TTF_Font	*police = NULL;
  SDL_Color	couleurNoire = {255, 255, 255, 255};
  char *str;
  
  TTF_Init();
  str = my_strcat(Score_str(), my_put_nbr(ind - 2));
  position.x = 30;
  position.y = 20;
  police = TTF_OpenFont("angelina.TTF", 30);
  texte = TTF_RenderText_Blended(police, str, couleurNoire);
  SDL_BlitSurface(texte, NULL, ecran, &position);
  TTF_CloseFont(police);
  TTF_Quit();
  SDL_FreeSurface(texte);
}
