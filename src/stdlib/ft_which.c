/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 16:11:48 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/08 09:59:57 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static char	*ft_find_exec_in_path(const char *exec, char *path);

char	*ft_which(const char *argv, char *path)
{
	char	*exec_name;
	char	*cmd;

	if (argv == NULL)
		return (NULL);
	if (ft_strchr(argv, ' ') == NULL)
		exec_name = (char *) argv;
	else
		exec_name = ft_strndup(argv, ft_strchr(argv, ' ') - argv);
	cmd = ft_find_exec_in_path(exec_name, path);
	if (ft_strchr(argv, ' ') != NULL)
		free(exec_name);
	if (cmd == NULL)
		return (NULL);
	return (cmd);
}

static char	*ft_find_exec_in_path(const char *exec, char *path)
{
	size_t	dir_len;
	char	*dir;
	char	*filename;
	char	*temp;

	while (path != NULL)
	{
		if (ft_strchr(path, ':') == NULL)
			dir_len = ft_strlen(path);
		else
			dir_len = ft_strchr(path, ':') - path;
		dir = ft_strndup(path, dir_len);
		temp = ft_strjoin(dir, "/");
		filename = ft_strjoin(temp, exec);
		free(temp);
		free(dir);
		if (access(filename, X_OK) == 0 && open(filename, O_DIRECTORY) == -1)
			return (filename);
		free(filename);
		path = ft_strchr(path, ':');
		if (path != NULL)
			++path;
	}
	return (NULL);
}
