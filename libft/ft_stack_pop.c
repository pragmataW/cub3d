/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:48:33 by yciftci           #+#    #+#             */
/*   Updated: 2024/03/07 19:27:34 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack	*ft_stack_pop(t_stack **root)
{
	t_stack	*tmp;
	t_stack	*rvalue;

	if (*root == NULL)
	{
		ft_printf("stack is empty!\n");
		return (NULL);
	}
	tmp = *root;
	rvalue = ft_stack_new(tmp->x, tmp->y);
	*root = (*root)->next;
	free(tmp);
	return (rvalue);
}
