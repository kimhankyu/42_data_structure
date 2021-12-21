/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hankkim <hankkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 15:19:14 by hankkim           #+#    #+#             */
/*   Updated: 2021/11/25 17:32:43 by hankkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doublylist.h"
#include <assert.h>
#include <stdio.h>

int		main(void)
{
	DoublyList *dl = createDoublyList();

	assert(dl == NULL);
	
	return (0);
}
