	int	i;
	int	elemsort;

	i = 0;
	ft_visual(*pile_a, *pile_b, *list);
	ft_pivot(list);
	while (i < (*list)->size_pivot)
	{
		ft_r_or_rr(list, pile_a, pile_b, 0);
		ft_pb(pile_a, pile_b, list);
		i++;
	}
	ft_size(list);
	ft_pivotb(list);
	while ((*list)->size_b > 5)
	{
		i = 0;
		ft_pivotb(list);
		while (i < 5)
		{
			if (((*list)->begin_b)->nbr >= (*list)->pivotb)
			{
				ft_pa(pile_a, pile_b, list);
				i++;
			}
			else
				ft_r(pile_a, pile_b, list, 7);
		}
	ft_size(list);
	}
	elemsort = (*list)->size_b;
	if ((*list)->size_b >= 3 && (*list)->size_b <= 5)
	{
		ft_fifthelem(list, pile_a, pile_b);
		(*list)->size_pivot = (*list)->size_pivot - elemsort;
	}
	if ((*list)->size_b > 0 && (*list)->size_b < 3)
	{
		ft_algotwo(list, pile_a, pile_b);
		(*list)->size_pivot = (*list)->size_pivot - elemsort;
	}
	while ((*list)->size_pivot != 0)
	{
		i = 0;
		while (i < 5)
		{
			ft_pb(pile_a, pile_b, list);
			i++;
		}
		ft_size(list);
		ft_fifthelem(list, pile_a, pile_b);
		(*list)->size_pivot = (*list)->size_pivot - 5;
	}
	ft_size(list);
	if ((*list)->size_a % 2 == 1)
		(*list)->size_pivot = (*list)->size_a / 2 + 1;
	else
		(*list)->size_pivot = (*list)->size_a / 2;
	while (((*list)->begin_a)->nbr >= (*list)->pivot)
		ft_pb(pile_a, pile_b, list);
	ft_size(list);
	ft_pivotb(list);
	while ((*list)->size_b > 5)
	{
		i = 0;
		ft_pivotb(list);
		while (i < 5)
		{
			if (((*list)->begin_b)->nbr >= (*list)->pivotb)
			{
				ft_pa(pile_a, pile_b, list);
				i++;
			}
			else
				ft_r(pile_a, pile_b, list, 7);
		}
	ft_size(list);
	}
	elemsort = (*list)->size_b;
	if ((*list)->size_b >= 3 && (*list)->size_b <= 5)
	{
		ft_fifthelem(list, pile_a, pile_b);
		(*list)->size_pivot = (*list)->size_pivot - elemsort;
	}
	if ((*list)->size_b > 0 && (*list)->size_b < 3)
	{
		ft_algotwo(list, pile_a, pile_b);
		(*list)->size_pivot = (*list)->size_pivot - elemsort;
	}
	while ((*list)->size_pivot != 0)
	{
		i = 0;
		while (i < 5)
		{
			ft_pb(pile_a, pile_b, list);
			i++;
		}
		ft_size(list);
		ft_fifthelem(list, pile_a, pile_b);
		(*list)->size_pivot = (*list)->size_pivot - 5;
	}

