/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:26:03 by madufour          #+#    #+#             */
/*   Updated: 2018/11/30 18:09:14 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
int	main(int argc, char ** argv)
{
	int		fd;
	int		fd2;
	char	*line;
	//pid_t	child;
	char	n = '\n';

	if (argc < 2)
	{
		printf("Usage %s <filename>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	fd2 = open("me.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd == -1 || fd2 == -1)
	{
		perror("open");
		close(fd);
		close(fd2);
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		write(fd2, line, ft_strlen(line));
		write(fd2, &n, 1);					// attention si le fichier test n a pas de \n et que ca affiche une erreur c'est normal
		free(line);							// vous inquietez pas
	}
	close(fd);
	close(fd2);
	child = fork();
	if (child == 0)
	{
		char	*arg[] = {"/usr/bin/diff", NULL, "me.txt", NULL};

		arg[1] = argv[1];
		execve(arg[0], arg, NULL);
		exit(0);
	}
	else
		wait(NULL); // bad code I know ... but it's not the project
	(void)argc;
	(void)argv;
	while(1)
		;
	return (0);
}*/

#include <fcntl.h>

int main(int ac, char **av)
{
	int fd = open(av[1],O_RDONLY);
	char *line =NULL;
	int ret;

	(void)ac;
	while((ret = get_next_line(fd,&line)) > 0)
	{
		printf("[%d]%s\n",ret,line);
		free(line);
	}
	printf("final return = %d",ret);
	close (fd);
	return (0);
}
