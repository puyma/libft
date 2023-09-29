/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:48:39 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/07/25 13:51:46 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include <limits.h>/* PATH_MAX */
#include <errno.h>/* errno */

// temp
#include <stdlib.h>

static char		*ft_setcld(const char *file_name, char *resolve_path);
static char		*ft_realpath_loop(char *cld, char **file_name_components);
static char		*ft_resolve_path(char *cld, char *file_name_component);

/*
int	main(void)
{
	char	*path;
	char	*realp;

	path = ft_strdup("/./././.././././/../Users/mpuig-ma/.././.././..");
	realp = realpath(path, NULL);
	printf("og: %d: %s\n", errno, realp);
	free(realp);
	realp = ft_realpath(path, NULL);
	printf("ft: %d: %s\n", errno, realp);
	free(realp);
	free(path);
	if (errno)
		perror(ft_itoa(errno));
	return (0);
}
*/

/*
 * It won't follow symbolic links!
 *
 * ft_realpath (const char *file_name, char *resolve_path) 
 * 		cld -> current lookup directory
 *
 */

char	*ft_realpath(const char *file_name, char *resolve_path)
{
	char	**file_name_components;
	char	*cld;

	if (file_name == NULL)
		return (NULL);
	cld = ft_setcld(file_name, resolve_path);
	if (cld == NULL)
		return (NULL);
	file_name_components = ft_split(file_name, '/');
	cld = ft_realpath_loop(cld, file_name_components);
	ft_free_arr(file_name_components);
	return (cld);
}

static char	*ft_setcld(const char *file_name, char *resolve_path)
{
	char	*cld;

	if (resolve_path != NULL)
		cld = resolve_path;
	else
	{
		cld = (char *) malloc(sizeof(char *) * PATH_MAX);
		if (cld == NULL)
			return (errno = ENOMEM, NULL);
		ft_memset(cld, '\0', PATH_MAX);
	}
	if (*file_name != '/')
		getcwd(cld, PATH_MAX);
	else
		*cld = '/';
	return (cld);
}

// if no search permission on the current lookup directory -> EACCES
// if component is not found -> ENOENT
// if component is not a directory nor a symbolic link -> ENOTDIR
//
// if component is found and is a directory,
// we set the currentlookupdirectory to that directory,
// and go to the next component.

char	*ft_realpath_loop(char *cld, char **file_name_components)
{
	int	i;

	i = 0;
	while (file_name_components[i] != NULL)
	{
		cld = ft_resolve_path(cld, file_name_components[i]);
		if (access(cld, X_OK) == -1)
			return (free(cld), NULL);
		++i;
	}
	return (cld);
}

static char	*ft_resolve_path(char *cld, char *file_name_component)
{
	char	*last;
	char	*compost;

	if (ft_strcmp("..", file_name_component) == 0)
	{
		last = ft_strrchr(cld, '/');
		if (last != NULL && ft_strlen(cld) > 1)
			ft_memset(last, '\0', ft_strlen(last));
		*cld = '/';
	}
	else if (ft_strcmp(".", file_name_component) != 0)
	{
		if (ft_strlen(cld) == 1 && *cld == '/')
			*cld = '\0';
		compost = ft_strjoin("/", file_name_component);
		last = ft_strjoin(cld, compost);
		free(compost);
		free(cld);
		cld = last;
	}
	return (cld);
}
