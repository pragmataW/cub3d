/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusuf <yusuf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 14:01:44 by yciftci           #+#    #+#             */
/*   Updated: 2024/03/07 19:27:17 by yusuf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_stack_push(t_stack **root, t_stack *new)
{
	if (!new)
		return ;
	if (*root != NULL)
		new->next = *root;
	*root = new;
}
