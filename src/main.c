/* =====================================================
 * File        : main.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : //
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../one_line_format.h"

/* Modif function */
void	modif_file(char *str, char *argv)
{
	int	fd;

	fd = open(argv, O_WRONLY | O_TRUNC);
	if (fd == -1)
	{
		free(str);
		return ;
	}
	ft_dprintf(fd, "%s", str);
	close(fd);
}

/* Read function */
char	*read_file(char *argv)
{
	int		fd;
	char	*str;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error: invalid file %s\n", argv);
		return (NULL);
	}
	str = ft_parse_file(fd);
	close(fd);
	return (str);
}

/* Main function */
int	main(int argc, char **argv)
{
	int		i;
	char	*str;

	if (argc < 2)
	{
		ft_dprintf(2, "Error: no file.\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		str = read_file(argv[i]);
		if (!str)
			return (1);
		str = ft_format_text(str);
		modif_file(str, argv[i]);
		free(str);
		i++;
	}
	return (0);
}
