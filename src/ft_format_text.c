/* =====================================================
 * File        : ft_format_text.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : //
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../one_line_format.h"

static bool	ft_update_depth(char c, int *depth)
{
	if (c == '{')
		(*depth)++;
	else if (c == '}')
		(*depth)--;
	return (*depth > 0);
}

static void	ft_replace_whitespaces(char *str)
{
	int	depth;
	int	i;

	depth = 0;
	i = 0;
	while (str[i])
	{
		if ((str[i] == '\n' || str[i] == '\t') && depth > 0)
			str[i] = ' ';
		ft_update_depth(str[i], &depth);
		i++;
	}
}

static void	ft_remove_extra_spaces(char *str)
{
	int		i;
	int		j;
	int		depth;
	bool	space;

	i = 0;
	j = 0;
	depth = 0;
	space = false;
	while (str[i])
	{
		ft_update_depth(str[i], &depth);
		if (depth > 0 && str[i] == ' ' && space)
			i++;
		else
		{
			space = (str[i] == ' ');
			str[j++] = str[i++];
		}
	}
	str[j] = '\0';
}

char	*ft_format_text(char *str)
{
	if (!str)
		return (NULL);
	ft_replace_whitespaces(str);
	ft_remove_extra_spaces(str);
	return (str);
}
