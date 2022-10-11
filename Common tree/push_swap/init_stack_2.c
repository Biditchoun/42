/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swijnber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:12:29 by swijnber          #+#    #+#             */
/*   Updated: 2022/10/11 07:48:38 by swijnber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_in_stack(int *buf, int argc)
{
	int	i;
	int	j;
	int	content;

	i = -1;
	content = INT_MAX;
	while (++i < argc)
	{
		if (buf[i] < content)
		{
			j = i;
			content = buf[i];
		}
	}
	if (content == INT_MAX)
		return (INT_MAX);
	return (j);
}

static int	*case_int_max(int *a, int *a_, int argc)
{
	int	i;
	int	*buf;

	i = -1;
	while (++i < argc)
		if (a[i] == INT_MAX)
			break ;
	a_[i] = argc;
	a_[argc] = 0;
	if (a[i] == INT_MAX)
		a_[argc] = -1;
	buf = malloc(sizeof(int) * argc);
	if (!buf)
		return (NULL);
	i = -1;
	while (++i < argc)
		buf[i] = a[i];
	return (buf);
}

int	*init_a_(int *a, int argc)
{
	int	*a_;
	int	*buf;
	int	i;
	int	count;

	a_ = malloc(sizeof(int) * argc);
	if (!a_)
		return (NULL);
	buf = case_int_max(a, a_, --argc);
	if (!buf)
		return (ft_free((void *)a_, NULL));
	count = 1;
	while (count - 1 < argc)
	{
		i = min_in_stack(buf, argc);
		if (i == INT_MAX)
			break ;
		a_[i] = count++;
		buf[i] = INT_MAX;
	}
	free(buf);
	return (a_);
}

int	*init_b_(int *a_, int argc)
{
	int	i;
	int	*b_;

	b_ = malloc(sizeof(int) * argc);
	if (!b_)
		return (NULL);
	i = 0;
	while (i < argc)
		b_[i++] = a_[argc - 1];
	return (b_);
}
