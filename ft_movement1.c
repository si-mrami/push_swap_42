/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:47:31 by mrami             #+#    #+#             */
/*   Updated: 2023/03/04 21:07:13 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushSwap.h"

/* rotate the first element of stack B in the last of the stack. */

void	ft_rotet_b(t_stack *stack_b)
{
	int	size_b;

	size_b = stack_b->counter;
	if (size_b > 2)
	{
		ft_rotate(stack_b, size_b);
		write(1, "rb\n", 3);
	}
}

/* rotete the last elment of an array in the first */

void	ft_rotet_rev(t_stack *stack_rv, int len)
{
	int	i;
	int	temp;

	temp = stack_rv->stack[len - 1];
	i = len - 1;
	while (i > 0)
	{
		stack_rv->stack[i] = stack_rv->stack[i - 1];
		i--;
	}
	stack_rv->stack[0] = temp;
}

/* rotate rev to stack A */

void	ft_rotet_rev_a(t_stack *stack_a)
{
	int	len;

	len = stack_a->counter;
	if (len > 1)
	{
		ft_rotet_rev(stack_a, len);
		write(1, "rra\n", 4);
	}
}

/* rotate rev to stack B */

void	ft_rotet_rev_b(t_stack *stack_b)
{
	int	len;

	len = stack_b->counter;
	if (len > 1)
	{
		ft_rotet_rev(stack_b, len);
		write(1, "rrb\n", 4);
	}
}

/* push the top of stack A to the top of stack B */

void	ft_push_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;
	int	temp;

	len_a = stack_a->counter;
	len_b = stack_b->counter;
	if (len_a == 0)
		ft_print_error("stack A no found!");
	temp = stack_a->stack[0];
	len_b++;
	len_a--;
	stack_b->stack = malloc((len_b + 1) * sizeof(int));
	if (!stack_b->stack)
		ft_print_error("No stack B A'Location.");
}
