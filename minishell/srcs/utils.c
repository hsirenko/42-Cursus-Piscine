/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 10:40:22 by dferreir          #+#    #+#             */
/*   Updated: 2023/03/22 11:47:45 by dferreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minishell.h"

int	print_err(char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

char	**get_path(char **envp)
{
	int		i;
	char	*env;
	char	**res;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH=", 5)) //chercher "PATH=" dans la cmd env
		{
			env = ft_substr(envp[i], 6, ft_strlen(envp[i])); //mettre reste dans var
			if (!env)
				return (0);
			res = ft_split(env, ':'); //separer par ':'
			free (env);
			if (!res)
				return (0);
			return (res);
		}
		i++;
	}
	return (0);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	if (access(cmd, 0) == 0) //si arg en lui meme est deja path entiere
		return(ft_strdup(cmd));
	while (*paths) //sinon, joindre path a arg et tester si correct
	{
		tmp = ft_strjoin(*paths, "/"); //rajouter '/' a fin de path
		command = ft_strjoin(tmp, cmd); //rajouter arg a fin de path
		free(tmp);
		if (access(command, 0) == 0) //controler si cmd exite (0 = true)
			return (command);
		free(command);
		paths++; //recommencer avec nouvelle path
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while ((*s1 && *s2) && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	**ft_split2(char const *s, char c)
{
	char	**new_strs;
	int		x;
	size_t	i;
	size_t	j;
	int		start;

	x = 0;
	i = 0;
	j = 0;
	start = -42;
	new_strs = malloc((word_counter(s, c) + 1) * sizeof(char *));
	if (!s || !new_strs)
		return (0);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && start < 0)
			start = i;
		else if ((s[i] == c || !s[i]) && start >= 0 && (!x || !s[i]))
		{
			x++;
			new_strs[j++] = str_maker(s, start, i);
			start = -42;
		}
		i++;
	}
	new_strs[j] = 0;
	return (new_strs);
}
