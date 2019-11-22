/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 14:22:38 by kroselin          #+#    #+#             */
/*   Updated: 2019/11/22 14:42:27 by mdirect          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**"work with tetri" - func, which makes a char to int.
**"move tetro" moves tetra in top left corner,
**"check_tetramino" has a list of right tetras and check new number on it.
*/

t_uint128_t	work_with_tetri(char *content)
{
	t_uint128_t	tmp;
	int			j;

	j = 15;
	tmp = 0;
	while (*content && j >= 0)
	{
		if (*content == '\n')
			content++;
		if (*content == '#')
			tmp = (tmp | 1 << j);
		j--;
		content++;
	}
	tmp = move_tetro(tmp, 4);
	if (!(check_tetramino(tmp)))
		return (0);
	return (tmp);
}

int			correct_chars(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf && buf[i] != '\n' && buf[i] != '.' && buf[i] != '#')
			return (0);
		if (buf[i] == '\n' && !(((i + 1) % 5) == 0))
			return (0);
		if (buf[i] == '#')
			count++;
		i++;
	}
	return (count);
}

int			river_check(char *buf)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < 19)
	{
		if (buf[i] == '#')
		{
			if (i + 1 <= 18 && buf[i + 1] == '#')
				count++;
			if (i - 1 >= 0 && buf[i - 1] == '#')
				count++;
			if (i + 5 <= 18 && buf[i + 5] == '#')
				count++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				count++;
		}
		i++;
	}
	return (count);
}

/*
** is valid checks, that we have right sq and tetramins,
** then it put them in mas of tetras (*t)
*/

int			is_valid(char *buf, int size, t_uint128_t *t)
{
	int		i;

	i = 0;
	while (i <= size)
	{
		if (correct_chars(buf + i) != 4)
			return (0);
		if (river_check(buf + i) != 6 && river_check(buf + i) != 8)
			return (0);
		*t = work_with_tetri(buf + i);
		t++;
		i += 21;
	}
	return (1);
}

/*
** 26 tetas * 21 symbs = 546, but we begin from 0, so 545
*/

int			parser(char *filename, t_uint128_t *t)
{
	char	buff[545];
	int		ret;
	int		fd;

	if ((fd = open(filename, O_RDONLY)) < 0)
		return (write(1, "No file with such name.\n", 24));
	ret = read(fd, buff, 545);
	if (close(fd) == -1)
		return (write(1, "error: close fd\n", 16));
	if (ret > 544 || ret < 19)
		return (0);
	buff[ret] = '\0';
	if (!(is_valid(buff, ret, t)))
		return (0);
	else
		return (1);
}
