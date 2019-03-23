/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 07:28:15 by zmahomed          #+#    #+#             */
/*   Updated: 2019/03/23 03:04:52 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#define BUF_SIZE 4096

int		disp_file(char *str)
{
	int		fd = open(str, O_RDONLY);
	int		ret;
	int		i = 0;
	int		line_num = 0;
	int		errors = 0;
	int		pre_proc = 0;
	char	buf[BUF_SIZE + 1];

	if (fd == 3)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		while (buf[i])
		{
			if (buf[i] == '\n')
			{
				line_num++;
				if (line_num < 11 && buf[i + 1] != '/' && errors == 0)
				{
					printf("\033[96;1m%i\033[0m : Incorrect 42Header\n",line_num);
					errors++;
				}
				else if (line_num == 11 && buf[i] == '\n' && buf[i + 1] != '\n' && errors == 0)
				{
					printf("\033[96;1m%i\033[0m : Line after 42Header not empty\n",line_num);
					errors++;
				}
				else if (line_num > 11 && buf[i + 1] == '#')
				{
					if (pre_proc == 0)
					{
						pre_proc++;
					}
					else if (pre_proc == 1)
					{
						printf("\033[96;1m%i\033[0m : All pre-processors should be at the top\n",line_num);
						pre_proc++;
					}	
				}
				else if (buf[i + 2] == '\n')
				{
					printf("\033[96;1m%i\033[0m : Empty line\n",line_num);
				}
			}
			i++;
		}
		close(fd);
		printf("\n\033[33;1mLines: %i",line_num);
		printf("\n\033[33;1mChars: %i",i);
		printf("\n\033[31;1mErrors: %i",errors);
		printf("\033[0m\n");
		return (1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	(void)**av;
	if (ac < 2)
		printf("File name missing.");
	if (ac > 2)
		printf("Too many arguments.");
	if (ac == 2)
	{
		printf("\033[33;1mNorminette : %s\n\n\033[0m",av[1]);
		disp_file(av[1]);
	}
	return (0);
}
