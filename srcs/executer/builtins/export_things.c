/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_things.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahafid <sahafid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 16:05:59 by sahafid           #+#    #+#             */
/*   Updated: 2022/07/02 23:45:58 by sahafid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../minishell.h"

int	check_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	key_already_exist(char	*tmp, t_env *lst, char	*find)
{
	tmp = lst->value;
	if (!lst->value)
		lst->value = "";
	lst->value = ft_strjoin(lst->value, ft_strchr(find, '=') + 1);
	if (tmp != NULL)
		free(tmp);
}

int	key_exist(t_env *lst, char	*find, int *j)
{
	char	*tmp;

	tmp = NULL;
	while (lst)
	{
		if (!ft_strncmp(lst->key, find, ft_strlen(lst->key)))
		{
			if (*j == 1)
				key_already_exist(tmp, lst, find);
			else
			{
				tmp = lst->value;
				lst->value = ft_strdup(ft_strchr(find, '=') + 1);
				ft_free(tmp);
			}
			if (!lst->value)
				lst->value = NULL;
			g_status.exit_status = 0;
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void	key_not_exist(t_env **lst, char	*find, int j, int i)
{
	char	*value;
	char	*key;
	t_env	*lst1;

	value = ft_strdup(ft_strchr(find, '=') + 1);
	key = ft_strdup(get_keys(find, '='));
	if (j == 1)
		key = get_keys(key, '+');
	i = -1;
	while (key[++i])
	{
		if (key[i] == '+' || key[i] == '-')
		{
			ft_putstr_fd("error\n", 2);
			g_status.exit_status = 1;
			free(key);
			free(value);
			return ;
		}
	}
	if (!*lst)
		*lst = NULL;
	lst1 = ft_envnew(key, value);
	ft_envadd_back(lst, lst1);
	g_status.exit_status = 0;
}

void	export_things(t_env **env, char	*find)
{
	int		i;
	int		j;
	t_env	*lst;

	i = 0;
	j = 0;
	lst = *env;
	if (check_keys(env, find, &j, i))
		return ;
	if (key_exist(lst, find, &j))
		return ;
	i = 0;
	key_not_exist(env, find, j, i);
}
