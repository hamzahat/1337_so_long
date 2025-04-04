/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:47:15 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/04 12:11:48 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! so_long parsing
#include "so_long.h"

//? check that the map is .ber extension
static void	Check_map_extension(char *map_name)
{
	size_t	len;

	len = ft_strlen(map_name);
	if (len < 4 || ft_strcmp(map_name + len - 4, ".ber") != 0)
	{
		ft_putstr_fd("Error: Map file must have a .ber extension\n", 2);
		exit(1);
	}
}

//? check if the map file exist & open the fd
static void	check_map_exists(char *map_file, int *fd)
{
	close(*fd);
	*fd = open(map_file, O_RDONLY);
	if (*fd == -1)
	{
		ft_putstr_fd("Error: Map file not found or inaccessible.\n", 2);
		exit(1);
	}
}

//? check if the map is rectangular
static void	check_map_rectangular(int fd)
{
	char	*tmp;
	size_t	width;
	size_t	len;

	tmp = get_next_line(fd);
	if (!tmp)
	{
		ft_putstr_fd("Error: Empty map file.\n", 2);
		close(fd);
		exit(1);
	}
	width = ft_strlen_map_check(tmp);
	free(tmp);
	while ((tmp = get_next_line(fd)))
	{
		len = ft_strlen_map_check(tmp);
		if (len != width)
		{
			ft_putstr_fd("Error: Map is not rectangular.\n", 2);
			free(tmp);
			close(fd);
			exit(1);
		}
		free(tmp);
	}
}

//? calculate x and y of the map ( the size )
static void	calculate_size(t_map *size, int fd)
{
	int i = 1;
	char	*tmp = get_next_line(fd);
	if (!tmp)
	{
		close(fd);
		exit(1);
	}
	size->width = ft_strlen_map_check(tmp);
	free(tmp);
	while ((tmp = get_next_line(fd)))
	{
		i++;
		free(tmp);
	}
	size->height = i;
}

//? copy the map from file (.ber) to 2D array
static char	**make_area(int fd, t_map *size)
{
    char    **map;
    char    *line;
    int     i = 0;

    map = ft_safe_malloc(sizeof(char *) * (size->height + 1), ALLOCATE, 1, NULL);
    while ((line = get_next_line(fd)))
    {
        map[i] = ft_safe_malloc(sizeof(char) * (ft_strlen_map_check(line) + 1), ALLOCATE, 1,NULL);
        ft_strcpy(map[i], line);
        free(line);
        i++;
    }
    map[i] = NULL;
    return (map);
}

//? check if the map is closed by walls ( 1 )
static void check_map_closed(char **map, t_map *size)
{
	int i = 0;
	while (i < size->width)
	{
		if ((map[0][i] != '1') || (map[size->height - 1][i] != '1'))
		{
			ft_putstr_fd("Error: Map is not enclosed in walls.\n", 2);
			ft_safe_malloc(0, 0, ALLOCATE, NULL);
		}
		i++;
	}
	i = 0;
	while (i < size->height)
	{
		if ((map[i][0] != '1') || (map[i][size->width - 1] != '1'))
		{
			ft_putstr_fd("Error: Map is not enclosed in walls.\n", 2);
			ft_safe_malloc(0, 0, ALLOCATE, NULL);
		}
		i++;
	}
}

//? check if there is just (E) (P) (C) (O) (1) chars
static void	check_valid_chars(char **map, t_game *count)
{
	int i = 0;
	int j = 0;
	int invalid_char = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				count->exit++;
			else if (map[i][j] == 'P')
				count->player++;
			else if (map[i][j] == 'C')
				count->coins++;
			else if (map[i][j] == '0' || map[i][j] == '1')
				;
			else
				invalid_char = 1; //* check if there is somthing else 
			j++;
		}
		i++;
	}
	if ((count->exit != 1) || (count->player != 1) || (count->coins < 1) || (invalid_char == 1))
	{
		ft_putstr_fd("Error: Map must have exactly 1 exit, 1 player, at least 1 coins\n", 2);
		ft_safe_malloc(0, 0, ALLOCATE, NULL);
	}
}

//? check if the player can reach all collectibles and the exit
void	validate_path(char **map, t_map size, t_game *count)
{
	char	**map_cp;
	int		i;
	int		j;
	int		px;
	int		py;

	map_cp = copy_map(map, size);
	find_player(map_cp, size, count);
	printf("\n");
	px = count->player_x;
	py = count->player_y;
	flood_fill(map_cp, px, py, size);
	i = 0;
	while (i < size.height)
	{
		j = 0;
		while (j < size.width)
		{
			if (map_cp[i][j] == 'C' || map_cp[i][j] == 'E')
			{
				ft_putstr_fd("Error: Not all collectibles or the exit are reachable.\n", 2);
				ft_safe_malloc(0, FREE_ALL, 1, NULL);
			}
			j++;
		}
		i++;
	}
	while (i < size.height)
		ft_safe_malloc(0, FREE_ONE, 1, map_cp[i++]);
	ft_safe_malloc(0, FREE_ONE, 1, map_cp);
}

//? Parse the map
void	parse_map(int ac, char *av[])
{
	int		fd;
	char	**map;
	t_map	size;
	t_game	count;

	if (ac != 2)
		exit(1);
	count.coins = 0;
	count.exit = 0;
	count.player = 0;
	Check_map_extension(av[1]);
	check_map_exists(av[1], &fd);
	check_map_rectangular(fd);
	check_map_exists(av[1], &fd);
	calculate_size(&size, fd);
	check_map_exists(av[1], &fd);
	map = make_area(fd, &size);
	close(fd);
	check_map_closed(map, &size);
	check_valid_chars(map, &count);
	validate_path(map, size, &count);
}

//? parsing algo:
/*
*
* check that the map is surrounded by walls ( 1 ) 									(done)
* check that the map contain 1 player (P), 1 exit (E), at least 1 collectibel (C) 	(done)
* check the size of map before open flood fill 										(todo)
* handle player moves . ( you should print the moves if realy the player move )		(todo)
* 
*/

