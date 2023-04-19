/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <bsafi@student.42nice.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:10:28 by bsafi             #+#    #+#             */
/*   Updated: 2023/04/19 19:38:10 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	i++;
	return (i);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char )c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	if (!s1 || !s2)
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

/*void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}*/
char	*readline(int fd, char *tmp)
{
	char	*buf;
	size_t	j;

	j = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	while (!(ft_strchr(tmp, '\n')) && j != 0)
	{
		j = read (fd, buf, BUFFER_SIZE);
		if (j == -1)
		{
			free(buf);
			return (0);
		}
		tmp = ft_strjoin(tmp, buf);
	}
	free (buf);
	return (tmp);
} 
char	*bef(char *tmp)
{
	int		i;
	char	*final;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	final = malloc(sizeof(char) * (i + 2));
	if (!final)
		return (0);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		final[i] = tmp[i];
		i++;
	}
	if (tmp == '\n')
	{
		final[i] = tmp[i];
		i++;
	}
	final = '\0';
	return (final);
}
char	*fin(char *tmp)
{
	int		i;
	int		j;
	char	*poub;

	i = 0;
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	poub = malloc(sizeof(char) * (i + 2));
	if (!poub)
		return (0);
	i++;
	while (tmp[i])
	{
		poub[j] = tmp[i];
		i++;
		j++;
	}
	poub = '\0';
	return (poub);
}

char	*get_next_line(int fd)
{
	char	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	tmp = readline(fd, tmp);
}

	/*while (j > 0)
	{
		if (fd < 0)
			return (NULL);
		while (tmp[i] != '\n')
		{
			read(fd, buf, n);
		}
		if (buf[i] == '\n')
		{
			ft_putstr(tmp);
			write(1, "\n", 1);
			break;
		}
	}
	return (0);*	
		
	read (fd, buf, n);
		while (buf[i] != '\n')
		{
			tmp[i] = buf[i];
			i++;
		}
		if (buf[i] == '\n')
		{
			ft_putstr(tmp);
			write(1, "\n", 1);
			i++;
		}
	}
		if (i == 0)
		{
			read (fd, buf, n);
			i++;
		}
		tmp[j] = buf[j];
		j++;
		i++;
		if (buf[j] == '\n')
		{
			ft_putstr(tmp);
			write (1, "\n", 1);
			i = 0;
		}
	}
}*/
int	main()
{
	int		fd;
	char	*buf;

	fd = open ("rev.c", O_RDONLY);
	read (fd, buf, 10);
	printf("%s\n", buf);
	close(fd);
	fd = open ("rev.c", O_RDONLY);
	printf("%s", get_next_line(fd));
	return (0);
}
