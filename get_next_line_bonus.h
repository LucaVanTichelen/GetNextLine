/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvan-tic <lvan-tic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 09:56:17 by lvan-tic          #+#    #+#             */
/*   Updated: 2021/07/19 12:58:14 by lvan-tic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

char	*check_input(int fd);
int		find_newline(char *temp);
char	*return_string(char *temp);
char	*move_front(char *temp);
char	*get_next_line(int fd);
char	*free_string(char *str);
char	*concat_temp(char *buff, char *temp);
char	*concat(char *buff, char *temp);
char	*return_line(char **line, char **temp);

#endif