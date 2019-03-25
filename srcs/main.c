/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 07:28:15 by zmahomed          #+#    #+#             */
/*   Updated: 2019/03/26 00:55:19 by zmahomed         ###   ########.fr       */
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
	int		func_line = 0;
	int		func_count = 0;
	int		char_count  = 0;
	int		errors = 0;
	int		pre_proc = 0;
	int		tot_func = -1;
	int		tot_func_b = 0;
	char	buf[BUF_SIZE + 1];

	if (fd == 3)
	{
		ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
		while (buf[i])
		{
			if (char_count > 80)
			{
					printf("\033[96;1m%i\033[0m : \033[31m%i\033[0m characters in line\n",line_num, char_count);
					errors++;
			}
			if (buf[i] == '\n')
			{
				line_num++;
				char_count = 0;
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
					else if (pre_proc == 2)
					{
						printf("\033[96;1m%i\033[0m : All pre-processors should be at the top\n",line_num);
						errors++;
						pre_proc++;
					}	
				}
				else if (pre_proc == 1 || pre_proc == 3)
					pre_proc++;
				else if (buf[i + 1] == '\n' && buf[i + 2] == '\n')
				{
					printf("\033[96;1m%i\033[0m : Empty line\n",line_num);
					errors++;
				}
				if (pre_proc == 2 && buf[i + 1] != '\n')
				{
					printf("\033[96;1m%i\033[0m : Empty line after pre-processors required\n",line_num);
					errors++;
					pre_proc++;
				}
				else if (pre_proc == 2)
					pre_proc++;
				if (buf[i + 1] == '{' && func_count == 0)
				{
					func_count = 1;
					func_line = 0;
				}
				if (func_count == 1)
				{
					if (buf[i + 1] == '}')
					{
						tot_func++;
						func_count = 0;
					}
					if (buf[i + 1] == '}' && func_line - 1 > 25)
					{
						printf("\033[96;1m%i\033[0m : \033[31m%i\033[0m lines in function\n",line_num ,func_line - 1);
						tot_func++;
						errors++;
					}
					else
						func_line++;
				}
				if (buf[i + 1] == '\n' && buf[i + 2] == '\0')
				{
					printf("\033[96;1m%i\033[0m : Empty line at the end of the file\n",line_num);
					errors++;
				}
				if (buf[i - 1] == ' ' || buf[i - 1] == '\t')
				{
					printf("\033[96;1m%i\033[0m : Trailing spaces at end of line\n",line_num);
					errors++;
				}
				if (tot_func > 5 && tot_func_b == 0)
				{
					printf("\033[96;1m%i\033[0m : \033[31m%i\033[0m functions\n",line_num, tot_func);
					errors++;
					tot_func_b++;
				}
			}
			else if (buf[i] == '\t')
				char_count+=4;
			else
				char_count++;
			i++;
		}
		close(fd);
		printf("\n\033[33;1mLines: %i",line_num);
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
		printf("File name missing.\n");
	if (ac > 2)
		printf("Too many arguments.\n");
	if (ac == 2)
	{
		printf("\033[33;1mFile: %s\n\n\033[0m",av[1]);
		disp_file(av[1]);
	}
	return (0);
}
