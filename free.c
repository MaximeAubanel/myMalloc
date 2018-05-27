/*
** free.c for free in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:15:53 2017 Aubanel Maxime
** Last update Mon Mar  6 15:03:25 2017 Maxime AUBANEL
*/

#include "malloc.h"

void    free(void *ptr)
{
  t_list        *list;

  if (detect_ptr_pos(ptr) == true)
    {
      list = extract_block(ptr);
      list->free = true;
      if (is_mergeable(list) == true)
	list = free_merge(list->prev);
      free_merge(list);
      if (list->next == NULL)
	{
	  if (list->prev)
	    list->prev->next = NULL;
	  else
	    start = NULL;
          brk(list);
	}
    }
}

int	detect_ptr_pos(void *ptr)
{
  if (start)
    {
      if (start < ptr && ptr < sbrk(0))
	     return (true);
    }
  return (false);
}

t_list	*free_merge(t_list *list)
{
  if (list->next != NULL && list->next->free == true)
    {
      list->size = list->next->size + SIZE_HEADER + list->size;
      list->next = list->next->next;
      if (list->next != NULL)
	     list->next->prev = list;
    }
  return (list);
}

t_list	*extract_block(void *ptr)
{
  char	*address;

  address = ptr;
  address = address - SIZE_HEADER;
  ptr = address;
  return (ptr);
}
