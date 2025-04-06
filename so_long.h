/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbenmoha <hbenmoha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 16:09:16 by hbenmoha          #+#    #+#             */
/*   Updated: 2025/04/07 00:23:40 by hbenmoha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//? get_next_line buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//? scrine size
# define WIDTH 5120
# define HEIGHT 2880

//? Define key codes for Mac
# define KEY_W   13  // 'W' key
# define KEY_A   0   // 'A' key
# define KEY_S   1   // 'S' key
# define KEY_D   2   // 'D' key

# define KEY_UP     126  // Up arrow
# define KEY_DOWN   125  // Down arrow
# define KEY_RIGHT  124  // Right arrow
# define KEY_LEFT   123  // Left arrow

# define KEY_ESC	53  // Escape key

# define ON_DESTROY 17

//? size of pixels
# define SIZE		64

//? title of window:
# define TITLE "so_long"

//? Macros for ft_safe_malloc keys:
# define ALLOCATE 1
# define FREE_ALL 0
# define FREE_ONE 2

//? ft_safe_malloc struct:
typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

//? so_long struct:
typedef struct s_game
{
	void	*player_pic;
	void	*wall_pic;
	void	*floor_pic;
	void	*collect_pic;
	void	*exit_pic;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		coins;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		width;
	int		height;
	int		moves;
}	t_game;

//? parsing fun:
void	parse_map(int ac, char *av[], t_game *game);
void	*ft_safe_malloc(size_t size, int key, int exit_status, void *to_delete);
int		close_window(t_game *game);
size_t	ft_strlen_map_check(const char *s);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *dst, const char *src);
char	**copy_map(t_game *game);
void	game_init(t_game *game);
void	find_player(t_game *game);
void	flood_fill(char **map, int x, int y, t_game *game);
void	update_map_info(t_game *map_inf);
void	is_valid(t_game *game, char **map_cp);
void	check_map_fits_screen(t_game *size, int fd);
void	check_elements(t_game *game, int invalid_char);
void	make_area(int fd, t_game *game);
void	check_map_extension(char *map_name);
void	check_map_closed(t_game *game);
void	check_map_exists(char *map_file, t_game *game);

//? game fun:
int		key_handler(int keycode, t_game *game);
void	load_images(t_game *game);
void	draw_map(t_game *game);
void	player_up(t_game *game);
void	player_down(t_game *game);
void	player_left(t_game *game);
void	player_right(t_game *game);
void	ft_putnbr(int nb);
void	ft_putchar(char c);
void	find_exit(t_game *game);

//? get_next_line fun:
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
