/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_home.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:49:39 by sahafid           #+#    #+#             */
/*   Updated: 2022/07/02 22:51:00 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	get_home(char	**home, t_env *lst)
{
	while (lst)
	{
		if (!ft_strcmp(lst->key, "HOME"))
		{
			if (chdir(lst->value))
			{
				printf("no such file or directory\n");
				g_status.exit_status = 1;
				return (1);
			}
			*home = ft_strdup(lst->value);
			break ;
		}
		lst = lst->next;
	}
	if (!*home)
	{
		printf("home not found\n");
		g_status.exit_status = 1;
		return (1);
	}
	return (0);
}

void	create_new_pwd(char	*home, t_env *env)
{
	t_env	*lst;

	lst = NULL;
	lst = ft_envnew("PWD", home);
	ft_envadd_back(&env, lst);
}

void	cd_home(t_env *env, char *oldpwd)
{
	t_env	*lst;
	char	*home;

	lst = env;
	home = NULL;
	if (get_home(&home, lst))
		return ;
	while (lst)
	{
		if (!ft_strcmp(lst->key, "PWD"))
		{
			if (lst->value != NULL)
			{
				oldpwd = ft_strdup(lst->value);
				free(lst->value);
			}
			lst->value = home;
			break ;
		}
		lst = lst->next;
	}
	if (!pwd(env, 0))
		create_new_pwd(home, env);
	check_oldpwd(env, oldpwd);
}
