/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_one_group2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:34:36 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 15:35:07 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_arr1(int arr[], int box[], int type)
{
	int	i;

	if (type == 0)
	{
		arr[0] = 0;
		arr[1] = 1;
		arr[2] = 2;
	}
	else if (type == 1)
	{
		arr[0] = 0;
		arr[1] = 2;
		arr[2] = 1;
	}
	else
	{
		arr[0] = 1;
		arr[1] = 0;
		arr[2] = 2;
	}
	i = -1;
	while (++i < 3)
		if (box[arr[i]] == 0)
			arr[i] = -1;
}

void	set_arr2(int arr[], int box[], int type)
{
	int	i;

	if (type == 3)
	{
		arr[0] = 1;
		arr[1] = 2;
		arr[2] = 0;
	}
	else if (type == 4)
	{
		arr[0] = 2;
		arr[1] = 0;
		arr[2] = 1;
	}
	else
	{
		arr[0] = 2;
		arr[1] = 1;
		arr[2] = 0;
	}
	i = -1;
	while (++i < 3)
		if (box[arr[i]] == 0)
			arr[i] = -1;
}

int	pick_one(int arr[], int tri_type)
{
	int	i;

	i = 0;
	if (tri_type == 0)
	{
		i = 2;
		while (i >= 0)
		{
			if (arr[i] != -1)
				break ;
			i--;
		}
	}
	else
	{
		while (i <= 2)
		{
			if (arr[i] != -1)
				break ;
			i++;
		}
	}
	return (arr[i]);
}
