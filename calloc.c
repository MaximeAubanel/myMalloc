/*
** calloc.c for calloc in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:15:28 2017 Aubanel Maxime
** Last update Sun Feb 12 21:15:34 2017 aubanel_m
*/

#include "malloc.h"

void	*calloc(size_t nmemb, size_t size)
{
  size_t	*tab;
  unsigned int	i;
  size_t	alignSize;

  i = -1;
  alignSize = align_size(size * nmemb);
  if ((tab = malloc(sizeof(size_t) * nmemb * size)) == NULL)
    return (NULL);
  if (nmemb == 0 || size == 0)
    return (NULL);
  while ((++i * 4) < alignSize)
    tab[i] = 0;
  return (tab);
}
