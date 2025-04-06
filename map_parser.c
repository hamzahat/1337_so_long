/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:47:15 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/07 00:10:35 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! so_long parsing
#include "so_long.h"

//? Calculate map dimensions (width/height) from file
static void	calculate_size(t_game *size, int fd)
{
	int		i;          //* Line counter for height
	char	*tmp;       //* Buffer for each line read

	i = 1;
	tmp = get_next_line(fd);
	if (!tmp)           //* Handle empty file
	{
		ft_putstr_fd("Error\nEmpty map file.\n", 2);
		close(fd);
		exit(1);
	}
	size->width = ft_strlen_map_check(tmp);  //* Set width from first line
	free(tmp);
    //* Count remaining lines for height
	tmp = get_next_line(fd);
	while (tmp)
	{
		i++;
		free(tmp);
		tmp = get_next_line(fd);
	}
	size->height = i;
	check_map_fits_screen(size, fd);  //* Verify map fits game window
}

//? check if the map file exist & open the fd & calculate width 
//? + height & copy mape frome fd to 2D array
void	check_map_exists(char *map_file, t_game *game)
{
	int	fd;  //* File descriptor

    //* First open: read dimensions
	fd = open(map_file, O_RDONLY);
	if (fd == -1)       //* Verify file access
	{
		ft_putstr_fd("Error\nMap file not found or inaccessible.\n", 2);
		exit(1);
	}
	calculate_size(game, fd);
	close(fd);

    // Second open: copy map data
	fd = open(map_file, O_RDONLY);
	if (fd == -1)       // Re-check accessibility
	{
		ft_putstr_fd("Error\nMap file not found or inaccessible.\n", 2);
		exit(1);
	}
	make_area(fd, game);  // Create 2D map array
	close(fd);			// close the fd
}

//? check if there is just (E) (P) (C) (O) (1) chars
static void	check_valid_chars(t_game *game)
{
	int	invalid_char;  //* Flag for illegal chars
	int	i;         //* Map coordinates
	int	j;

	invalid_char = 0;
	i = 0;
	update_map_info(game);	//* Update player/exit/coin counts ( count how many C and E and P in the map to check theme later in check_elements fun )
    //* Scan entire map
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
            //* Check for invalid characters
			if (game->map[i][j] != 'C' && game->map[i][j] != 'E' && game->map[i][j] != 'P' && game->map[i][j] != '0' && game->map[i][j] != '1')
				invalid_char = 1;
			j++;
		}
		i++;
	}
	check_elements(game, invalid_char);  // Validate element counts
}

//? check if the player can reach all collectibles and the exit
void	validate_path(t_game *game)
{
	char	**map_cp;  // Map copy for flood-fill
	int		i;		// indix
	int		px;     // Player coordinates
	int		py;

	i = 0;
	map_cp = copy_map(game);      // Create editable map copy
	find_player(game);            // Locate player start position
	px = game->player_x;
	py = game->player_y;
	flood_fill(map_cp, px, py, game);  // Mark accessible areas
    
	// Free map copy
	is_valid(game, map_cp);       // Check remaining unreachable elements
	while (i < game->height)
		ft_safe_malloc(0, FREE_ONE, 1, map_cp[i++]);
	ft_safe_malloc(0, FREE_ONE, 1, map_cp);
}

//? Map parsing function
void	parse_map(int ac, char *av[], t_game *game)
{
	if (ac != 2)        // Verify argument count
		exit(1);
	game_init(game);    // Initialize game struct


    // Execute validation pipeline
	check_map_extension(av[1]);    // .ber extension
	check_map_exists(av[1], game); // File processing
	check_map_closed(game);        // Wall enclosure
	check_valid_chars(game);       // Character validation
	validate_path(game);           // Path accessibility
}
