/*
** chain_list.c for chain_list in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:15:37 2017 Aubanel Maxime
** Last update Sun Feb 12 22:23:27 2017 Aubanel Maxime
*/

#include "malloc.h"

t_list	*chain_list(t_list *list, size_t size)
{
  t_list	*tmp;
  size_t	miniblock;

  miniblock = mini_block(SIZE_HEADER + size);
  tmp = sbrk(0);
  if (sbrk(miniblock) == (void *) -1)
    return (NULL);
  tmp->size = miniblock - SIZE_HEADER;
  tmp->free = false;
  tmp->next = NULL;
  tmp->prev = list;
  if (list)
    list->next = tmp;
  return (tmp);
}

t_list	*split_memory(t_list *list, size_t size)
{
  t_list	*new_space;

  new_space = (t_list *)(list->data + size);
  new_space->size = list->size - SIZE_HEADER - size;
  new_space->free = true;
  new_space->next = list->next;
  list->size = size;
  list->next = new_space;
  new_space->prev = list;
  if (new_space->next)
    new_space->next->prev = new_space;
  return (new_space);
}

t_list	*find_free_space(t_list **prev_malloc, size_t size)
{
  t_list	*tmp;

  tmp = start;
  while (tmp != NULL)
    {
      *prev_malloc = tmp;
      if (tmp->free == true && tmp->size >= size)
	     return (tmp);
      tmp = tmp->next;
    }
  return (tmp);
}
