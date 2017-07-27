#include "ft_push_swap.h"
#include "libft.h"

int	ft_checkpile_s(f_arg *list)
{
	if (!list)
		return (0);
	if (list->end == list->begin)
		return (0);
	return (1);
}

int	ft_checkpile_p(f_arg *list)
{
	if (!list)
		return (0);
}
