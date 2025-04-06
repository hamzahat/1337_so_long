/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:47:15 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 19:43:04 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! so_long parsing
#include "so_long.h"

//? calculate width + height of map
static void	calculate_size(t_game *size, int fd)
{
	int i = 1;

	char	*tmp = get_next_line(fd);
	if (!tmp)
	{
		ft_putstr_fd("Error\nEmpty map file.\n", 2);
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
	if (((size->width * SIZE) > (WIDTH / 2)) || ((size->height * SIZE) > (HEIGHT / 2)))
	{
		ft_putstr_fd("Error\nMap too large to fit the window. Try a smaller map.\n", 2);
		close(fd);
		exit(1);
	}
}
//? check that the map is .ber extension
static void	Check_map_extension(char *map_name)
{
	size_t	len;

	len = ft_strlen(map_name);
	if (len < 4 || ft_strcmp(map_name + len - 4, ".ber") != 0)
	{
		ft_putstr_fd("Error\nMap file must have a .ber extension\n", 2);
		exit(1);
	}
}

//? copy the map from file (.ber) to 2D array & check if the map is rectangular
static void	make_area(int fd, t_game *game)
{
    char    **map;
    char    *line;
    int     i = 0;

    map = ft_safe_malloc(sizeof(char *) * (game->height + 1), ALLOCATE, 1, NULL);
    while ((line = get_next_line(fd)))
    {
        map[i] = ft_safe_malloc(sizeof(char) * (ft_strlen_map_check(line) + 1), ALLOCATE, 1,NULL);
        ft_strcpy(map[i], line);
		if (ft_strlen(map[i]) != (size_t)game->width)
		{
			printf("Error\nMap is not rectangular.\n");
			close(fd);
			ft_safe_malloc(0, FREE_ALL, 1, NULL);
		}
        free(line);
        i++;
    }
    map[i] = NULL;
    game->map = map;
}

//? check if the map file exist & open the fd & calculate width + height & copy mape frome fd to 2D array
static void	check_map_exists(char *map_file, t_game *game)
{
	int	fd;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nMap file not found or inaccessible.\n", 2);
		exit(1);
	}
	calculate_size(game, fd);
	close(fd);
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd("Error\nMap file not found or inaccessible.\n", 2);
		exit(1);
	}
	make_area(fd, game);
	close(fd);
}


//? check if the map is closed by walls ( 1 )
static void check_map_closed(t_game *game)
{
	int i = 0;
	while (i < game->width)
	{
		if ((game->map[0][i] != '1') || (game->map[game->height - 1][i] != '1'))
		{
			ft_putstr_fd("Error\nMap is not enclosed in walls.\n", 2);
			ft_safe_malloc(0, 0, ALLOCATE, NULL);
		}
		i++;
	}
	i = 0;
	while (i < game->height)
	{
		if ((game->map[i][0] != '1') || (game->map[i][game->width - 1] != '1'))
		{
			ft_putstr_fd("Error\nMap is not enclosed in walls.\n", 2);
			ft_safe_malloc(0, 0, ALLOCATE, NULL);
		}
		i++;
	}
}

//? check if there is just (E) (P) (C) (O) (1) chars
static void	check_valid_chars(t_game *game)
{
	int invalid_char;
	int	i;
	int	j;

	invalid_char = 0;
	i = 0;
	j = 0;
	update_map_info(game);
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E' \
				&& game->map[i][j] != 'P' && game->map[i][j] != '0' && game->map[i][j] != '1')
				invalid_char = 1; // check if there is somthing else 
			j++;
		}
		i++;
	}
	if ((game->exit != 1) || (game->player != 1) || (game->coins < 1) || (invalid_char == 1))
	{
		ft_putstr_fd("Error\nMap must have exactly 1 exit, 1 player, at least 1 coins\n", 2);
		ft_safe_malloc(0, 0, ALLOCATE, NULL);
	}
}

//? check if the player can reach all collectibles and the exit
void	validate_path(t_game *game)
{
	char	**map_cp;
	int		i;
	int		px;
	int		py;

	i = 0;
	map_cp = copy_map(game);
	find_player(game);
	px = game->player_x;
	py = game->player_y;
	flood_fill(map_cp, px, py, game);
	is_valid(game, map_cp);
	while (i < game->height)
		ft_safe_malloc(0, FREE_ONE, 1, map_cp[i++]);
	ft_safe_malloc(0, FREE_ONE, 1, map_cp);
}

//? Parse the map
void	parse_map(int ac, char *av[], t_game *game)
{
	if (ac != 2)
		exit(1);
	game_init(game);
	Check_map_extension(av[1]);
	check_map_exists(av[1], game);
	check_map_closed(game);
	check_valid_chars(game);
	validate_path(game);
}
