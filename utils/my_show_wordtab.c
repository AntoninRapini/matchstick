/*
** my_showa_wordtab.c for my_show_wordtab in /home/antonin.rapini/CPool_Day08/task03
** 
** Made by Antonin Rapini
** Login   <antonin.rapini@epitech.net>
** 
** Started on  Wed Oct 12 21:18:48 2016 Antonin Rapini
** Last update Wed Feb 15 01:41:18 2017 Antonin Rapini
*/

#include "utils.h"

void	my_show_wordtab(char **tab)
{
  int	index;

  index = 0;
  while (tab[index] != 0)
    {
      my_putstr(tab[index]);
      my_putchar('\n');
      index = index + 1;
    }
}
