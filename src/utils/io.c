#include "cub3d.h"

static char	*extract_line(char *line)
{
	size_t	count;
	char	*s_line;

	count = 0;
	while (line[count] != '\n' && line[count] != '\0')
		count++;
	if (line[count] == '\0')
		return (NULL);
	s_line = ft_substr(line, count + 1, ft_strlen(line) - count);
	if (*s_line == '\0')
	{
		free(s_line);
		s_line = NULL;
	}
	line[count + 1] = '\0';
	return (s_line);
}

static char	*ft_get_line(int fd, char *s_line, char *buf)
{
	ssize_t	ret;

	ret = 1;
	while (ret != 0)
	{
		ret = read(fd, buf, 100);
		if (ret < 0)
		{
			free (s_line);
			return (NULL);
		}
		buf[ret] = '\0';
		if (ret == 0)
			break ;
		if (!s_line)
			s_line = ft_strdup("");
		s_line = ft_strjoin(s_line, buf);
		if (ft_strchr(s_line, '\n'))
			break ;
	}
	return (s_line);
}

char	*get_next_line(int fd)
{
	static char	*s_line;
	char		*buf;
	char		*line;

	if (fd < 0)
	{
		free (s_line);
		s_line = NULL;
		return (NULL);
	}
	buf = malloc((size_t)100 + 1);
	if (!buf)
		return (NULL);
	line = ft_get_line(fd, s_line, buf);
	free(buf);
	buf = NULL;
	if (!line)
		return (NULL);
	s_line = extract_line(line);
	return (line);
}
