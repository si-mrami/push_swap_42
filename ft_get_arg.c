/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrami <mrami@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:22:29 by mrami             #+#    #+#             */
/*   Updated: 2023/04/11 00:26:39 by mrami            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"pushSwap.h"

/* get lenght of args */

int	ft_lenght_args(int argc, char const *argv[])
{
	int	i;
	int	total_len;

	total_len = 0;
	i = 1;
	while (i < argc)
	{
		total_len += ft_strlen(argv[i]);
		i++;
	}
	total_len += argc - 2;
	return (total_len);
}

/* get all args and jion to space */

char	*ft_get_all_args(int argc, char const *argv[])
{
	int		total_len;
	int		i;
	char	*total_args;
	int		j;
	size_t	arg_len;

	total_len = ft_lenght_args(argc, argv);
	if (total_len <= 0)
		ft_print_error("Error");
	total_args = malloc(total_len + 1);
	if (total_args == NULL)
		return (NULL);
	j = 0;
	i = 1;
	while (i < argc)
	{
		arg_len = ft_strlen(argv[i]);
		ft_memcpy(total_args + j, argv[i], arg_len);
		j += arg_len;
		total_args[j++] = ' ';
		i++;
	}
	total_args[total_len] = '\0';
	return (total_args);
}

/* slplit by space and convert  to int */

void	ft_split_to_atio(int argc, char const *argv[], t_stack *stack_a)
{
	char	*arg;
	char	**spliter;
	int		i;
	int		num_ints;
	int		*results;

	arg = ft_get_all_args(argc, argv);
	if (ft_check_alpha(arg))
		ft_print_error("Error:");
	spliter = ft_split(arg, ' ');
	free(arg);
	num_ints = ft_length_of_spliter(spliter);
	results = (int *)malloc(sizeof(int) * num_ints);
	i = 0;
	while (spliter[i] != NULL)
	{
		results[i] = ft_atoi(spliter[i]);
		free(spliter[i]);
		i++;
	}
	free(spliter);
	if (ft_check_dup(results, num_ints))
		ft_print_error("Error:");
	stack_a->stack = results;
	stack_a->counter = num_ints;
}
