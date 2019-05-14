/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmahomed <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 03:33:50 by zmahomed          #+#    #+#             */
/*   Updated: 2019/04/17 17:12:32 by zmahomed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef norm_h
#define norm_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

void    print_stats(int errors, int lines, double time_tot);
void    print_error(char *msg);
void	file_seek(char *file);
int		file_main(char *fileName);
int		main(int ac, char **av);

#endif
