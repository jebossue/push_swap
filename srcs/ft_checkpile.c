#include "ft_push_swap.h"
#include "libft.h"

int	ft_checkpile_s(d_arg *list)
{
	if (list->next == NULL || list->next == list)
		return (0);
	return (1);
}
/*
int	ft_checkpile_p(f_arg *list)
{
	if (!(list->begin)->next)
		return (0);
	return (1);
}

void	ft_adjustpile(f_arg **list)
{
	if ((*list)->begin == ((*list)->end))
	{
		(*list)->begin = NULL;
		(*list)->end = NULL;
	}
	else if (((*list)->begin)->next == (*list)->end)
	{
		(*list)->begin = ((*list)->begin)->next;
		((*list)->begin)->next = (*list)->begin;
		((*list)->begin)->prev = (*list)->begin;
	}
	else
	{
		(*list)->begin = ((*list)->begin)->next;
		((*list)->end)->next = (*list)->begin;
		((*list)->begin)->prev = (*list)->end;
	}
}*/
