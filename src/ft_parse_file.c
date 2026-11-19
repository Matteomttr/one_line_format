/* =====================================================
 * File        : ft_parse_file.c
 * Author      : Matteomttr
 * Date        : 2026
 * Description : //
 *
 * Copyright (c) 2026 Matteomttr. All rights reserved.
 * ===================================================== */

#include "../one_line_format.h"

char	*ft_parse_file(int fd)
{
	char	*line;
	char	*tmp;
	char	*str;

	str = NULL;
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(str, line);
		free(str);
		str = tmp;
		free(line);
		line = get_next_line(fd);
	}
	return (str);
}
