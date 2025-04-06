/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_fun_parsing_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 21:19:58 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/06 22:29:49 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//? Checks if the map dimensions fit within half the screen resolution.
void	check_map_fits_screen(t_game *size, int fd)
{
    //* Check if the scaled map width/height exceeds half the screen dimensions
	if ((size->width * SIZE > WIDTH / 2) || (size->height * SIZE > HEIGHT / 2))
	{
		ft_putstr_fd("Error\nMap too large.\n", 2); //* Print error to stderr
        close(fd); //* Close the file descriptor to avoid leaks
		exit(1);
	}
}

//? copy the map from file (.ber) to 2D array & check if the map is rectangular
void	make_area(int fd, t_game *game)
{
	char	**map;  //* 2D array to store the map
	char	*line;  //* Buffer for each line read from the file
	int		i;   	//* Row index

    //* Allocate memory for rows (height + 1 for NULL)
	i = 0;
	map = ft_safe_malloc(sizeof(char *) * (game->height + 1), ALLOCATE, 1, NULL);
	//* Read the file line by line
	line = get_next_line(fd);
	while (line)
	{
		//* Allocate memory for the current line (+1 for null terminator)
		map[i] = ft_safe_malloc(sizeof(char) * (ft_strlen_map_check(line) + 1), ALLOCATE, 1, NULL);
		//* Copy the line into the map
		ft_strcpy(map[i], line);
		//* Check if the line length matches the expected width (rectangular map)
		if (ft_strlen(map[i]) != (size_t)game->width)
		{
			ft_putstr_fd("Error\nMap is not rectangular.\n", 2);
			close(fd); //* Close the file
			ft_safe_malloc(0, FREE_ALL, 1, NULL); //* Free all allocated memory
		}
		free(line); //* Free the line buffer after copying
		i++;
		line = get_next_line(fd); //* Read the next line
	}
	map[i] = NULL; //* Null-terminate the 2D array
	game->map = map; //* Store the map in the game struct
}

//? Checks if the map has exactly 1 exit, 1 player, and at least 1 collectible (coin).
void	check_elements(t_game *game, int invalid_char)
{
    //* Validate counts:
    //*   - Exactly 1 exit (`game->exit == 1`)
    //*   - Exactly 1 player (`game->player == 1`)
    //*   - At least 1 coin (`game->coins >= 1`)
    //*   - No invalid characters (`invalid_char == 0`)
	if (game->exit != 1 || game->player != 1 || game->coins < 1 || invalid_char)
	{
		ft_putstr_fd("Error\nMap must have exactly 1 exit, 1 player, at least 1 coin\n", 2);
		ft_safe_malloc(0, 0, ALLOCATE, NULL);
	}
}
