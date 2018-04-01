/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lfunctions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 12:09:18 by allauren          #+#    #+#             */
/*   Updated: 2018/04/01 13:25:07 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_link(t_data *data)
{
	char *lnk;

	if (!(lnk = ft_memalloc(data->buf.st_size + 16)))
		ft_alexis();
	if (readlink(data->path, lnk, data->buf.st_size + 8) == -1)
		ft_wrong_folder(data->path);
	else
	{
		ft_printf("%s ", data->name);
		ft_printf(" -> %s\n", lnk);
	}
	ft_strdel(&lnk);
}


void		print_size(t_data *data, char c)
{
	if (c == 'b' || c == 'c')
	{
		if (minor(data->buf.st_rdev) >= 256)
			ft_printf("%10d, %#010x ", major(data->buf.st_rdev), minor(data->buf.st_rdev));
		else
			ft_printf("%10d, %10d ", major(data->buf.st_rdev), minor(data->buf.st_rdev));
	}
	else
		ft_printf("%23lld ", data->buf.st_size);
}