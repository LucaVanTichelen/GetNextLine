/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:45:12 by lvan-tic          #+#    #+#             */
/*   Updated: 2021/07/17 16:51:36 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*check_input(int fd)
{
	char	*str;

	if (fd < 0 || BUFFER_SIZE < 1 || fd >= FOPEN_MAX)
		return (NULL);
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (NULL);
	return (str);
}

int	find_newline(char *temp)
{
	int	i;

	i = 0;
	if (temp == NULL)
		return (0);
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*return_string(char *temp)
{
	char	*str;
	int		i;

	i = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if ((i == 0 && temp[i] == '\0') || temp == NULL)
		return (NULL);
	else if (temp[i] == '\n')
		str = malloc(sizeof(char) * (i + 2));
	else
		str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (temp[++i] != '\n' && temp[i] != '\0')
		str[i] = temp[i];
	if (temp[i] == '\n')
	{
		str[i] = temp[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*move_front(char *temp)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (temp[i] != '\n' && temp[i] != '\0')
		i++;
	if (temp[i] == '\0')
		return (free_string(temp));
	n = ++i;
	while (temp[i])
		i++;
	str = malloc(sizeof(char) * (i - n + 1));
	if (!str)
		return (free_string(temp));
	i = 0;
	while (temp[n])
		str[i++] = temp[n++];
	str[i] = temp[n];
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*buff;
	char		*line;
	static char	*temp;
	int			i;

	buff = check_input(fd);
	if (!buff)
		return (NULL);
	i = 1;
	while (find_newline(temp) == 0 && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0 || (i == 0 && temp == NULL))
			return (free_string(buff));
		buff[i] = '\0';
		temp = concat(buff, temp);
		if (!temp)
			return (NULL);
	}
	free (buff);
	return (return_line(&line, &temp));
}
