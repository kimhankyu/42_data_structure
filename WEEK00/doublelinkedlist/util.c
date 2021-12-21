/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:28:00 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/25 15:40:09 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"

t_flag rotation_direction(DoublyList pList, const int position)
{
	if (position <= pList.currentElementCount / 2)
		return (CW);
	else
		return (CCW);
}