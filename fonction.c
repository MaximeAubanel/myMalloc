/*
** fonction.c for fonction in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:15:46 2017 Aubanel Maxime
** Last update Sun Feb 12 22:31:03 2017 Aubanel Maxime
*/

#include "malloc.h"

size_t	align_size(size_t size)
{
  size_t	new_size;

  new_size = (((((size) % 4 != 0) ? ((((size) / 4) + 1) * 4) : (size))));
  return (new_size);
}

size_t	mini_block(size_t full_size)
{
  size_t	new_size;

  new_size = ((full_size / getpagesize()) + 1) * getpagesize();
  return (new_size);
}

int	is_mergeable_next(t_list *list)
{
  if (list)
    {
      if (list->next != NULL)
        {
          if (list->next->free == true)
            return (true);
        }
    }
  return (false);
}

int	is_mergeable(t_list *list)
{
  if (list)
    {
      if (list->prev != NULL)
        {
          if (list->prev->free == true)
            return (true);
        }
    }
  return (false);
}
