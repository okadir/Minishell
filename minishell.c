#include "minishell.h"


int main(int ac, char **av, char **env)
{
	char *line;

	line = NULL;
	while (1)
	{
		line = readline("\033[1;32mMinishell:\033[0m ");
		if (!line)
			break ;
		else if (line[0] == '\n')
			continue ;
		add_history (line);
		if (lexer(line))
			ft_putstr_fd("\033[1;31mSyntax error\033[0m\n", 2);
	}
	return (0);
}