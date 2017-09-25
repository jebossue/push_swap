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
	if ((list->begin)->next == NULL)
		return (0);
	return (1);
}

void	ft_adjustpile(f_arg **list)
{
	d_arg	*tmp;

	if ((*list)->begin == ((*list)->end))
		free((*list)->begin);
	else
	{
		tmp = (*list)->begin;
		if (((*list)->begin)->next == (*list)->end)
		{
			((*list)->end)->next = (*list)->end;
			((*list)->end)->prev = (*list)->end;
			(*list)->begin = ((*list)->begin)->next;
			(*list)->end = (*list)->begin;
			printf(" list : %d\n", ((*list)->begin)->nbr);
		}
		else
		{
			(*list)->begin = ((*list)->begin)->next;
			(*list)->end->next = (*list)->begin;
		}
			printf(" tmp : %d\n", tmp->nbr);
		free(tmp);
			printf(" list2 : %d\n", ((*list)->begin)->nbr);
	}
}
