/*
** realloc.c for realloc in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:16:18 2017 Aubanel Maxime
** Last update Sun Feb 12 22:41:35 2017 Aubanel Maxime
*/

#include "malloc.h"

void            *realloc(void *ptr, size_t size)
{
  t_list	*new;
  size_t	alignSize;

  if (!ptr)
    return (malloc(size));
  if (detect_ptr_pos(ptr) == true)
    {
      alignSize = align_size(size);
      new = extract_block(ptr);
      if (new->size < alignSize)
	     return (realloc_extend(new, ptr, alignSize));
      else
        {
          if ((new->size - alignSize) > sizeof(t_list))
	         split_memory(new, alignSize);
        }
    }
  return (ptr);
}

void            my_memcpy(t_list *dest, t_list *src)
{
  int           *s;
  size_t        i;
  int           *d;

  i = 0;
  d = (int*)dest->data;
  s = (int*)src->data;
  while (i < (dest->size / 4) && i < (src->size / 4))
    {
      d[i] = s[i];
      i++;
    }
}

void            *realloc_extend(t_list *list, void *ptr, size_t size)
{
  t_list      *tmp;
  void          *new_ptr;

  if ((is_mergeable_next(list) == true) &&
  (list->size + SIZE_HEADER + list->next->size) >= size)
    {
      free_merge(list);
      if ((list->size - size) > sizeof(t_list))
	     split_memory(list, size);
    }
  else
    {
      if ((new_ptr = malloc(size)) == NULL)
	     return (NULL);
      tmp = extract_block(new_ptr);
      my_memcpy(tmp, list);
      free(ptr);
      return (new_ptr);
    }
  return (ptr);
}
