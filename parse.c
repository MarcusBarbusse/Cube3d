/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 14:15:48 by hbuisser          #+#    #+#             */
/*   Updated: 2020/02/08 18:52:50 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_data_and_map(int fd, t_index *idx)
{
	char 	*line;

	idx->parse->map_string = "";
	idx->parse->data = "";
	while (get_next_line(fd, &line))
	{
		if (line[0] == '\0')
			get_next_line(fd, &line);
		if (!ft_isdigit(line[0]))
		{
			idx->parse->data = ft_strjoin(idx->parse->data, line);
			idx->parse->data = ft_strjoin(idx->parse->data, "\n");
			free(line);
			line = NULL;
		}
		else
		{
			if (line[0] == '1')
			{
				idx->parse->map_string = ft_strjoin(idx->parse->map_string, line);
				idx->parse->map_string = ft_strjoin(idx->parse->map_string, "\n");
				free(line);
				line = NULL;
			}
			else
			{
				write(1, "map not surrounded by 1", 23);
				return (-1);
			}
		}
	}
	idx->parse->map_string = ft_strjoin(idx->parse->map_string, line);
	idx->parse->map_string = ft_strjoin(idx->parse->map_string, "\0");
	idx->parse->data = ft_strjoin(idx->parse->data, "\0");
	free(line);
	line = NULL;
	return (0);
}

int count_no_spaces(t_index *idx)
{
	int i;
	int count;

	i = -1;
	count = 0;
	while (idx->parse->map_string[++i] != '\0')
		if (idx->parse->map_string[i] != ' ')
			count++;
	return (count);
}

char *create_map(t_index *idx, int count)
{
	int i;
	int j;
	char *map_string_clean;

	i = 0;
	j = 0;
	if (!(map_string_clean = malloc(sizeof(char) * count + 1)))
		return (NULL);
	while (idx->parse->map_string[i] != '\0')
	{
		if (idx->parse->map_string[i] != ' ')
		{
			map_string_clean[j] = idx->parse->map_string[i];
			j++;
		}
		i++;
	}
	map_string_clean[j] = '\0';
	if (!(idx->parse->map = ft_split(map_string_clean, '\n')))
		return (NULL);
	i = 0;
	j = 0;
	while (idx->parse->map[i] != NULL)
	{
		j = 0;
		while (idx->parse->map[i][j] != '\0')
		{
			if ((ft_isalpha(idx->parse->map[i][j])))
			{
				idx->parse->posX = j;
				idx->parse->posY = i;
				idx->parse->dir = idx->parse->map[i][j];
				idx->parse->map[i][j] = '0';
			}
			j++;
		}
		i++;
	}
	idx->parse->line_nbr = i;
	idx->parse->column_nbr = j;
	return (map_string_clean);
}

int parse_cub(t_index *idx, char *filename)
{
	int		fd;
	int 	count;
	char 	*map_string_clean;
	
	fd = open(filename, O_RDONLY);
	if (parse_data_and_map(fd, idx) < 0)
		return (-1);
	close(fd);
	count = count_no_spaces(idx);
	map_string_clean = create_map(idx, count);
	if (create_elements(idx) < 0)
		return (-1);
	if (check_elements_errors(idx) < 0)
		return (-1);
	if (check_map_errors(idx, map_string_clean) < 0)
		return (-1);
	return (1);
}
