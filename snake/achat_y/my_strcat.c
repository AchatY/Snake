/*
** my_strcat.c for my_strcat.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:34:46 2017 Achat Youmer
** Last update Thu May  4 22:42:33 2017 Achat Youmer
*/

#include "snake.h"

char *my_strcat(char *dest, char *src)
{
  int i;
  int j;

  i = 0;
  j = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  while (src[j] != '\0')
    {
      dest[i + j] = src[j];
      j++;
    }
  dest[i + j] = '\0';
  return dest;
}
