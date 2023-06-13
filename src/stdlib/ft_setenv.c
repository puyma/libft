/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpuig-ma <mpuig-ma@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 12:14:01 by mpuig-ma          #+#    #+#             */
/*   Updated: 2023/06/13 15:39:26 by mpuig-ma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"

static int	add(const char *name, const char *value, char ***envp);
static int	overwrite(const char *name, const char *value, char **envp);

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
		overwrite(name, value, (char **) envp);
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
	new_envp = (char **) ft_realloc(*envp, sizeof(char **) * (len + 2));
	new_envp[len + 1] = env_name;
	new_envp[len + 2] = NULL;
	envp = &new_envp;
	return (EXIT_SUCCESS);
}

static int	overwrite(const char *name, const char *value, char **envp)
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
	free((char *) envp[i]);
	envp[i] = ft_strjoin(var_name, value);
	free(var_name);
	if (envp[i] == NULL)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
