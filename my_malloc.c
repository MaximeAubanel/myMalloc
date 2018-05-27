/*
** my_malloc.c for malloc in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:15:09 2017 Aubanel Maxime
** Last update Sun Feb 12 22:38:53 2017 Aubanel Maxime
*/

#include <limits.h>
#include "malloc.h"

void	*start = NULL;

void	*malloc(size_t size)
{
  t_list	*list;
  t_list	*prev_malloc;

  if (size >= LONG_MAX || size == 0 || (int)size < 1)
    return (NULL);
  size = align_size(size);
  if (start == NULL)
    {
      list = NULL;
      list = chain_list(list, size);
      start = list;
    }
  else
    {
      prev_malloc = start;
      if ((list = find_free_space(&prev_malloc, size)) == NULL)
	     list = chain_list(prev_malloc, size);
      else
        list->free = false;
    }
  if ((list->size - size) >= sizeof(t_list))
    split_memory(list, size);
  return (list->data);
}
