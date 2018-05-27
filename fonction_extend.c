/*
** fonction_extend.c for extend in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:30:54 2017 Aubanel Maxime
** Last update Sun Feb 12 22:33:18 2017 Aubanel Maxime
*/

#include "malloc.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_putnbr_b(int nb, char *base)
{
  int   _div;
  int   rez;
  int   length;

  if (nb == -2147483648)
    my_putstr("-2147483648");
  else
    {
      length = my_strlen(base);
      _div = 1;
      if (nb < 0)
        {
          my_putchar('-');
          nb = nb - 1;
        }
      while ((nb / _div) >= length)
        _div = _div * length;
      while (_div > 0)
        {
          rez = (nb / _div) % length;
          _div = _div / length;
          my_putchar(base[rez]);
        }
    }
  return (0);
}

void	show_alloc_mem()
{
  t_list				*tmp;
  size_t        _block;

  tmp = start;
  my_putstr("break : 0x");
  my_putnbr_b((size_t)sbrk(0), "0123456789ABCDEF");
  my_putchar('\n');
  while (tmp != NULL)
    {
      _block = (size_t)tmp;
      my_putstr("0x");
      my_putnbr_b(_block, "0123456789ABCDEF");
      my_putstr(" - 0x");
      my_putnbr_b(_block + tmp->size, "0123456789ABCDEF");
      my_putstr(" : ");
      my_putnbr_b(tmp->size, "0123456789");
      my_putstr(" bytes");
      my_putchar('\n');
      tmp = tmp->next;
    }
}
