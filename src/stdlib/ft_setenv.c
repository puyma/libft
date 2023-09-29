/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:14:01 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/08/11 19:16:55 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static char	**ft_add(const char *name, const char *value, char **envp);
static int	ft_overwrite(const char *name, const char *value, char **envp);

int	ft_setenv(const char *name, const char *value, int owr, char ***envp)
{
	char	*env_name;

	env_name = NULL;
	if (name == NULL)
		return (EXIT_FAILURE);
	else if (name != NULL && owr == 0)
		return (EXIT_SUCCESS);
	env_name = ft_getenv(name, (const char **) *envp);
	if (env_name == NULL)
		*envp = ft_add(name, value, *envp);
	else if (owr != 0)
		ft_overwrite(name, value, *envp);
	return (EXIT_SUCCESS);
}

static char	**ft_add(const char *name, const char *value, char **envp)
{
	char	*var_name;
	char	*env_name;
	char	**new_envp;
	char	**temp;
	int		len;

	len = 0;
	temp = envp;
	while (temp[len] != NULL)
		++len;
	var_name = ft_strjoin(name, "=");
	env_name = ft_strjoin(var_name, value);
	free(var_name);
	if (env_name == NULL)
		return (NULL);
	new_envp = (char **) ft_realloc(temp, sizeof(char *) * len,
			sizeof(char *) * (len + 2));
	new_envp[len] = ft_strdup(env_name);
	new_envp[len + 1] = NULL;
	free(env_name);
	return (new_envp);
}

static int	ft_overwrite(const char *name, const char *value, char **envp)
{
	int		i;
	char	*var_name;

	i = 0;
	var_name = ft_strjoin(name, "=");
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], var_name, ft_strlen(var_name)) == 0)
			break ;
		++i;
	}
	free(envp[i]);
	envp[i] = ft_strjoin(var_name, value);
	free(var_name);
	if (envp[i] == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
