/* =====================================================
 * File        : main.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : //
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../one_line_format.h"

int	main(int argc, char **argv)
{
	int	i;
	int	fd;

	i = 1;
	fd = 0;
	if (argc < 2)
	{
		ft_dprintf(1, "Error: no file.\n");
		return (1);
	}
	while (argv[i])
	{
		fd = open(argv[i], O_RDWR);
		if (fd == -1)
		{
			ft_dprintf(1, "Error: invalid file.\n");
			return(1);
		}
		ft_dprintf(fd, "Test for view if dprintf overwrite other text.");
		i++;
	}
}
