#include "ft_push_swap.h"
#include "libft.h"

int	ft_checkpile_s(f_arg *list)
{
	if ((list->begin)->next == NULL)
		return (0);
	if (list->end == list->begin)
		return (0);
	return (1);
}

int	ft_checkpile_p(f_arg *list)
{
	if (!(list->begin)->next)
		return (0);
	return (1);
}

void	ft_adjustpile(f_arg **list)
{
	d_arg	*tmp;

	if ((*list)->begin == ((*list)->end))
		free((*list)->begin);
	else if (((*list)->begin)->next == (*list)->end)
	{
	printf("%p\n", (*list)->begin);
	printf("end:%p\n", (*list)->end);
	printf("%p\n", ((*list)->begin)->next);
		tmp = ((*list)->begin)->next;
		printf("tmp:%d\n", tmp->nbr);
		free((*list)->begin);
//		tmp = (*list)->begin;
//		(*list)->begin = ((*list)->begin)->next;
//		free(tmp);
		printf("tmp:%d\n", tmp->nbr);
		(*list)->begin = tmp;
		printf("list:%d\n", ((*list)->begin)->nbr);
		((*list)->begin)->next = (*list)->begin;
		((*list)->begin)->prev = (*list)->begin;
	}
	else
	{
		tmp = ((*list)->begin)->next;
		free((*list)->begin);
		printf("list:%d\n", ((*list)->end)->nbr);
		printf("tmp:%d\n", tmp->nbr);
		(*list)->begin = tmp;
		((*list)->end)->next = (*list)->begin;
		((*list)->begin)->prev = (*list)->end;
	}
}
