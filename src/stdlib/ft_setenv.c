/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:14:01 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/13 12:14:33 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	add(const char *name, const char *value, char ***envp);
static int	overwrite(const char *name, const char *value, const char **envp);

int	ft_setenv(const char *name, const char *value, int owr, const char **envp)
{
	char	*env_name;

	env_name = NULL;
	if (name == NULL)
		return (EXIT_FAILURE);
	else if (name != NULL && owr == 0)
		return (EXIT_SUCCESS);
	env_name = ft_getenv(name, envp);
	if (env_name == NULL)
		add(name, value, (char ***) &envp);
	else if (owr != 0)
		overwrite(name, value, envp);
	return (EXIT_SUCCESS);
}

static int	add(const char *name, const char *value, char ***envp)
{
	char	*var_name;
	char	*env_name;
	char	**new_envp;
	int		len;

	len = 0;
	while (envp[0][len] != NULL)
		++len;
	--len;
	var_name = ft_strjoin(name, "=");
	env_name = ft_strjoin(var_name, value);
	free(var_name);
	if (env_name == NULL)
		return (EXIT_FAILURE);
	new_envp = (char **) realloc(*envp, sizeof(char **) * (len + 1));
	new_envp[len] = env_name;
	new_envp[len + 1] = NULL;
	envp = &new_envp;
	return (EXIT_SUCCESS);
}

static int	overwrite(const char *name, const char *value, const char **envp)
{
	char	*var_name;
	char	*env_name;

	var_name = ft_strjoin(name, "=");
	env_name = ft_getenv(name, envp) - ft_strlen(var_name);
	if (env_name == NULL)
	{
		free(var_name);
		return (EXIT_FAILURE);
	}
	free(env_name);
	env_name = ft_strjoin(var_name, value);
	free(var_name);
	if (env_name == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
