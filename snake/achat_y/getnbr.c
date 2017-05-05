/*
** getnbr.c for my_getnbr.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:18:15 2017 Achat Youmer
** Last update Thu May  4 23:39:21 2017 Achat Youmer
*/
#include "snake.h"

void	declar(int *i, int *nbchif, int *nbmoins, int *res)
{
  *i = 0;
  *nbchif = 0;
  *nbmoins = 0;
  *res = 0;
}

void	test_neg(int *res, int *nbmoins)
{
  if (*nbmoins % 2 == 1)
    {
      *res = (*res) * (-1);
    }
}

void	compt_moins(char *str, int *nbchif, int *nbmoins, int *ind)
{
  if ((*str == '-' || *str == '+') && *nbchif == 0)
    {
      if (*str == '-')
	{
	  *nbmoins = (*nbmoins) + 1;
	}
    }
  else
    {
      *ind = 2;
    }
}

void	compt_nomb(char *str, int *nbchif, int *res)
{
  *nbchif = (*nbchif) + 1;
  *res = ((*res) * 10) + (*str - 48);
}

int	my_getnbr(char *str)
{
  int	i;
  int	ind;
  int	nbmoins;
  int	nbchif;
  int	res;

  declar(&i, &nbmoins, &nbchif, &res);
  ind = 1;
  while (str[i] != '\0')
    {
      if (str[i] == '-' || str[i] == '+')
	compt_moins(&str[i], &nbchif, &nbmoins, &ind);
      else if (str[i] >= 48 && str[i] <= 57 && ind == 1)
	compt_nomb(&str[i], &nbchif, &res);
      else
	ind = 3;
      i = i + 1;
    }
  test_neg(&res, &nbmoins);
  return res;
}
