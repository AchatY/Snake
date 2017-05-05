/*
** put_nbr.c for my_put_nbr.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:26:07 2017 Achat Youmer
** Last update Thu May  4 22:54:37 2017 Achat Youmer
*/

#include "snake.h"

void my_putchar(char c);

int my_nb_len(int n)
{
  int dev;
  int nb_len;

  nb_len = 1;
  dev = n;
  while (dev > 9 || dev < (-9))
    {
      nb_len = nb_len + 1;
      dev = dev / 10;
    }
  return (nb_len);
}

int find_dev(int n)
{
  int i;
  int dev;

  dev = 1;
  i = 1;
  while (i < n)
    {
      dev = dev * 10;
      i = i + 1;
    }
  return (dev);
}

char *my_put_nbr(int n)
{
  int i;
  int rs;
  int dev;
  int nb;
  char *str;

  str = malloc(sizeof(char) * 100);
  i = 0;
  rs = n;
  dev = find_dev(my_nb_len(n));
  while (i < my_nb_len(n))
    {
      nb = rs / dev;
      if (nb < 0)
	nb = nb * (-1);
      str[i] = nb + 48;
      rs = rs % dev;
      dev = dev / 10;
      i = i + 1;
    }
  str[i] = '\0';
  return str;
}
