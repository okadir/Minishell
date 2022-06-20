#include "../lexer.h"

char	*expender(char *line, int *i, t_env *env)
{
	char	*buffer;
	char	*res;
	int 	len;
	int 	start;

	len = 0;
	*i += 1;
	start = *i;
	buffer = NULL;
	while (line[*i])
	{
		if (ft_strchr("\"\' $", line[*i]))
			break ;
		len++;
		*i += 1;
	}
	buffer = ft_substr(line, start, len);
	res = ft_getenv(env, buffer);
	ft_free(buffer);
	return (res);
}

/*----------------------------------------------------------------------------*/

static	char	*get_chunk(char *line, int *i)
{
	int len;
	int start;

	len = 0;
	start = *i;
	while (line[*i])
	{
		if (ft_strchr("$\"", line[*i]))
			break ;
		len++;
		*i += 1;
	}
	return (ft_substr(line, start, len));
}

/*----------------------------------------------------------------------------*/

char	*word_within_dqoutes(char *line, int *i, t_env *env)
{
	char	*string;
	char	*substring;
	char	*tmp;

	*i += 1;
	string = NULL;
	substring = NULL;
	while (line[*i])
	{
		if (line[*i] == '$')
			substring = expender(line, i, env);
		else
			substring = get_chunk(line, i);

		if (!string)
			string = ft_strdup(substring);
		else if (substring)
			string = ft_realloc(string, substring);
		ft_free(substring);
		if (line[*i] == '\"')
		{
			*i += 1;
			break;
		}
	}
	return (string);
}

/*----------------------------------------------------------------------------*/

char	*word_within_sqoutes(char *line, int *i)
{
	int len;
	int start;

	len = 0;
	*i += 1;
	start = *i;
	while (line[*i])
	{
		if (line[*i] == '\'')
		{
			*i += 1;
			break ;
		}
		len++;
		*i += 1;
	}
	return (ft_substr(line, start, len));
}

/*----------------------------------------------------------------------------*/

char	*word(char *line, int *i)
{
	int len;
	int start;

	len = 0;
	start = *i;
	while (line[*i])
	{
		if (ft_strchr("<>| \'\"", line[*i]))
			break ;
		len++;
		*i += 1;
	}
	return (ft_substr(line, start, len));
}

/*----------------------------------------------------------------------------*/

char get_word(t_token **token, char *line, int *i, t_env *env)
{
	char	*content;

	content = NULL;
	if (line[*i] == '\"')
		content = word_within_dqoutes(line, i, env);
	else if (line[*i] == '\'')
		content = word_within_sqoutes(line, i);
	else if (line[*i] == '$' && ft_isalnum(line[(*i) + 1]))
		content = expender(line, i, env);
	else
		content = word(line, i);
	if (!content)
		return (1);
	tokenadd_back(token, tokennew(content, WORD));
	return (0);
}