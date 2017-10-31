/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edhommee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/03 18:29:32 by edhommee          #+#    #+#             */
/*   Updated: 2017/10/31 15:35:31 by edhommee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static int			cmp_content(void *data1, void *data2)
{
	return (ft_strcmp(((t_content*)data1)->name, ((t_content*)data2)->name));
}

t_content			*get_pos(t_list *list, int y, int x, t_term *var)
{
	t_list		*tmp;

	tmp = NULL;
	if (x >= 0 && x < var->line && y >= 0 && y < var->col)
		tmp = ft_list_at(list, 1 + x + y * var->line);
	if (tmp)
		return ((t_content*)tmp->data);
	return (NULL);
}

t_list				*get_list(char **args)
{
	t_list		*begin;
	t_content	*tmp;
	int			i;

	i = 0;
	begin = NULL;
	while (args[i])
	{
		tmp = new_content(args[i]);
		ft_lstinsert(&begin, tmp, &cmp_content);
		i++;
	}
	return (begin);
}

void				return_selec(t_list *begin_list)
{
	t_list		*tmp;

	tmp = begin_list;
	while (tmp)
	{
		if (((t_content*)tmp->data)->is_selected == 1)
			ft_printf("%w%s ", 1, ((t_content*)tmp->data)->name);
		tmp = tmp->next;
	}
}
