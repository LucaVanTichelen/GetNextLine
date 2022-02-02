/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:56:14 by lvan-tic          #+#    #+#             */
/*   Updated: 2021/07/17 16:22:40 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_string(char *str)
{
	free(str);
	return (NULL);
}

char	*concat_temp(char *buff, char *temp)
{
	char	*str;
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (temp[i])
		i++;
	while (buff[n])
		n++;
	str = malloc(sizeof(char) * (i + n + 1));
	if (!str)
		return (free_string(temp));
	i = -1;
	n = 0;
	while (temp[++i])
		str[i] = temp[i];
	while (buff[n])
		str[i++] = buff[n++];
	str[i] = buff[n];
	free(temp);
	return (str);
}

char	*concat(char *buff, char *temp)
{
	char	*str;
	int		i;

	i = 0;
	if (temp == NULL)
	{
		while (buff[i])
			i++;
		str = malloc(sizeof(char) * (i + 1));
		if (!str)
			return (free_string(buff));
		i = -1;
		while (buff[++i])
			str[i] = buff[i];
		str[i] = buff[i];
	}
	else
		str = concat_temp(buff, temp);
	if (str == NULL)
		free(buff);
	return (str);
}

char	*return_line(char **line, char **temp)
{
	int	i;

	i = 0;
	*line = return_string(*temp);
	while ((*temp)[i] != '\n' && (*temp)[i] != '\0')
		i++;
	if (!(*line) && *temp != NULL && (i != 0 || (*temp)[i] != '\0'))
		return (free_string(*temp));
	i = find_newline(*temp);
	*temp = move_front(*temp);
	if (!(*temp) && i)
		return (free_string(*line));
	if (*line)
		return (*line);
	else
		return (NULL);
}
