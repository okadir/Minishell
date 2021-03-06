/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokennew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 00:09:42 by haitkadi          #+#    #+#             */
/*   Updated: 2022/07/03 00:09:43 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_token	*tokennew(char *content, int token)
{
	t_token	*temp;

	temp = (t_token *)malloc(sizeof(t_token));
	if (!temp)
		return (NULL);
	temp->prev = NULL;
	temp->token = token;
	temp->content = content;
	temp->next = NULL;
	return (temp);
}
