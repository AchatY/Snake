/*
** readline.c for readline.c in /home/achat/Documents/DEVC/achat_y
** 
** Made by Achat Youmer
** Login   <achat_y_e@etna-alternance.net>
** 
** Started on  Thu May  4 22:18:46 2017 Achat Youmer
** Last update Thu May  4 22:18:46 2017 Achat Youmer
*/
#include "snake.h"

char		*readline()
{
  ssize_t	ret;
  char		*buff;

  if ((buff = malloc(sizeof(*buff) * (50 + 1))) == NULL)
    return (NULL);
  if ((ret = read(0, buff, 50)) > 1)
    {
      buff[ret - 1] = '\0';
      return (buff);
    }
  buff[0] = '\0';
  return (buff);
}

char	*my_strlowcase(char str[])
{
  int	i;
  
  i = 0;
  while (str[i] != '\0')
    {
      if (65 <= str[i] && str[i] <= 90)
	{
	  str[i] = str[i] + 32;
	}
      i = i + 1;
    }
  return (str);
}

void quit()
{
  return ;
}
