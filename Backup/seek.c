/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   seek.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:32:13 by zmahomed          #+#    #+#             */
/*   Updated: 2019/04/17 02:05:53 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/norm.h"

//Global variables
int line_cur = 0;
int err_tot = 0;

//File seek, sifts through the contents character by character
void	file_seek(char *file)
{
	int i = 0;				//Basic counter which goes through the file char by char
	int char_count = 1;		//Number of chars in line
	int char_blank = 0;		//Keeps track of if the line is blank or not
	int char_brace = 0;		//Something to do with { }, can't remember 
	int func_line = 0;		//Number of lines in functions
	int func_count = 0;		//Number of functions in file
	int pre_proc = 0;		//State of pre_processor detection
	err_tot = 0;			//Total number of errors
	line_cur = 0;			//Current line
	//Loops through all the contents of the file
	while (file[i] != '\0')
	{
		if (file[i] == '\n')
		{
//			printf("\t\t%i\t%i\n",line_cur,char_count); //Simple debug for line by line tracing
			line_cur++;
			if (line_cur < 12 && char_count != 81 && err_tot < 1)
				print_error("Incorrect 42header");
			if (line_cur == 11 && file[i + 1] != '\n')
				print_error("Empty line required after 42header");
			if (file[i + 1] == '\n' && file[i + 2] == '\0')
				print_error("Empty line at the end of the file");
			if (file[i + 1] == '\n' && file[i + 2] == '\n')
				print_error("Empty line");
			if (char_count > 81)
				print_error("Too many characters in line, max 80 characters");
			if (file[i - 1] == '\t' || file[i - 1] == ' ')
				print_error("Space at the end of the line");
			if (file[i + 1] == '{')
				func_line = 0;
			if (file[i + 1] == '}')
			{
				func_count++;
				if (func_line > 26)
					print_error("Too many lines in function, max 25 lines");
				if (func_count > 5)
					print_error("Too many functions in file, max 5 functions");
				if (file[i + 3] != '\n' && file[i + 3] != '\0')
					print_error("Empty line required after function");
			}
			if (char_brace == 1 && char_blank == 1)
				print_error("Curly braces need to be on their own line");
			if (line_cur > 11 && pre_proc == 0 && file[i + 1] != '#')
				pre_proc = 1; //Went into and exited pre_proc
			if (line_cur > 12 && file[i + 1] == '#' && pre_proc > 0)
				print_error("Pre-processor/s need to be at the top of the file");
			if (pre_proc == 1 && file[i + 1] != '#' && file[i + 1] == '\n')
				pre_proc = 2;
			else if (pre_proc == 1 && file[i + 1] != '#' && file[i + 1] != '\n')
			{
				pre_proc = 2;
				print_error("Empty line required after pre-processor/s");
			}
			func_line++;
			char_brace = 0;
			char_blank = 0; 
			char_count = 0;
		} //End loop for "\n"
		else if (file[i] != '\t' && file[i] != ' ' && file[i] != '{' && file[i] != '}')
			char_blank = 1;
		if (file[i] == '\t')
			char_count+=4;
		else 
			char_count++;
		if (file[i] == '{' || file[i] == '}')
			char_brace = 1;
		i++;
	} //End loop for entire script
	print_stats(err_tot, line_cur);
}

//Printing final stats
void	print_stats(int errors, int lines)
{
	printf("\033[33;1mLines: %i",lines);
	printf("\n\033[31;1mErrors: %i",errors);
	printf("\033[0m\n");
}

//Printing error messages
void	print_error(char *msg)
{
	printf("\033[96;1m%i",line_cur);
	printf("\033[0m %s\n", msg);
	printf("\033[0m");
	err_tot++;
}
