/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unadoroz <unadoroz@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:20:42 by unadoroz          #+#    #+#             */
/*   Updated: 2025/05/22 13:05:06 by unadoroz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	char *line;
	int fd = open("test.txt", O_RDONLY);
	int i = 1;

	if (fd == -1)
		return (perror("open"), 1);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line [%d]: %s", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}
