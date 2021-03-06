/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_operators_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitkadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:21:15 by haitkadi          #+#    #+#             */
/*   Updated: 2022/07/02 23:21:18 by haitkadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*----------------------------------------------------------------------------*/

char	get_here_doc(t_token **token, int *i)
{
	if (tokenadd_back(token, tokennew(NULL, HERE_DOC)))
		return (1);
	*i += 2;
	return (0);
}

/*----------------------------------------------------------------------------*/

char	get_red_in(t_token **token, int *i)
{
	if (tokenadd_back(token, tokennew(NULL, RED_IN)))
		return (1);
	*i += 1;
	return (0);
}

char	get_red_append(t_token **token, int *i)
{
	if (tokenadd_back(token, tokennew(NULL, RED_APPEND)))
		return (1);
	*i += 2;
	return (0);
}

/*----------------------------------------------------------------------------*/

char	get_red_out(t_token **token, int *i)
{
	if (tokenadd_back(token, tokennew(NULL, RED_OUT)))
		return (1);
	*i += 1;
	return (0);
}

/*----------------------------------------------------------------------------*/

char	get_pipe(t_token **token, int *i)
{
	if (tokenadd_back(token, tokennew(ft_strdup("|"), PIPE)))
		return (1);
	*i += 1;
	return (0);
}
