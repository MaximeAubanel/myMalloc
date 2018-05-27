/*
** malloc.h for malloc in /home/aubanel_m/tek2/PSU_2016_malloc/
**
** Made by Aubanel Maxime
** Login   <aubane_m@epitech.eu>
**
** Started on  Sun Feb 12 21:16:05 2017 Aubanel Maxime
** Last update Sun Feb 12 22:19:09 2017 aubanel_m
*/

#ifndef _MALLOC_H_
# define _MALLOC_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef struct	s_list
{
  struct s_list	*prev;
  struct s_list	*next;
  size_t	size;
  int		free;
  char		data[1];
}		t_list;

#define SIZE_HEADER ((sizeof(t_list *) *2) + sizeof(size_t) + sizeof(int))
#define true 1
#define false 0

extern void	*start;

// chain_list.c
t_list	*chain_list(t_list *, size_t);
t_list	*find_free_space(t_list **, size_t);
t_list	*split_memory(t_list *, size_t);

//  fonction.c
void	show_alloc_mem();
int	is_first(void *);
size_t	align_size(size_t);
size_t	mini_block(size_t);
int	is_mergeable(t_list *);
int	is_mergeable_next(t_list *);

// my_malloc.c
void	*malloc(size_t);
void	free(void *);

// free.c
int	detect_ptr_pos(void *);
t_list	*free_merge(t_list *);
t_list	*extract_block(void *);

// calloc.c
void	*calloc(size_t, size_t);

// realloc.c
void	*realloc(void *, size_t);
void	*realloc_extend(t_list *, void *, size_t);
void	my_memcpy(t_list *, t_list *);

#endif /* _MALLOC_H_ */
