/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 07:28:15 by zmahomed          #+#    #+#             */
/*   Updated: 2019/04/16 19:21:07 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/norm.h"

//Main function, handles file input and basic error checks
int		main(int ac, char **av)
{
	(void)**av;
	if (ac < 2)
		printf("File name missing.\n");
	if (ac > 2)
		printf("Too many arguments.\n");
	if (ac == 2)
		file_main(av[1]);
	return (0);
}

//Main file function, handles memory and storage of the files contents
int		file_main(char *fileName)
{
	FILE *file = fopen(fileName, "r");
	long f_size;
	char *contents;
	int c;
	int i = 0;

	//Checks if the file exists
	if (file == NULL)
	{
		printf("\033[31;1mError opening %s\n\033[0m",fileName);
		return (1);
	}
	printf("\033[33;1mFile: %s\n\033[0m",fileName);
	//Gets size of file for malloc, then goes back to the start
	fseek(file, 0, SEEK_END);
	f_size = ftell(file);
	contents = malloc(sizeof(char) * f_size * 1.1);
	fseek(file, 0, SEEK_SET);
	//Reads the file into contents
	while ((c = fgetc(file)) != EOF)
		contents[i++] = (char)c;
	contents[i] = '\0';
	fclose(file);
	file_seek(contents);
	//Frees the memory
	free(contents);
	return (0);
}
