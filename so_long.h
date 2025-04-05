#ifndef SO_LONG_H
# define SO_LONG_H

#include <mlx.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

//! remove this : 
# include <stdio.h>

//? get_next_line buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//? scrine size
# define WIDTH 800
# define HEIGHT 600


//? Define key codes for Linux
# define KEY_W   13  // 'W' key
# define KEY_A   0   // 'A' key
# define KEY_S   1   // 'S' key
# define KEY_D   2   // 'D' key

# define KEY_up     126  // Up arrow
# define KEY_down   125  // Down arrow
# define KEY_right  124  // Right arrow
# define KEY_left   123  // Left arrow

# define KEY_ESC	53  // Escape key

#define ON_DESTROY 17

//? size of pixels
# define SIZE		64

//? title of window:
#define TITLE "so_long"

//? Macros for ft_safe_malloc keys:
#define ALLOCATE 1
#define FREE_ALL 0
#define FREE_ONE 2

//? ft_safe_malloc struct:
typedef struct s_mem_node
{
	void				*address;
	struct s_mem_node	*next;
}	t_mem_node;

//? so_long struct:
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	int		coins;
	int		exit;
	int		player;
	int		player_x;
	int		player_y;
	int		width;
	int		height;
} t_game;

//? game fun:
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
void	flood_fill(char **map, int x, int y , t_game *game);
void	update_map_info(t_game *map_inf);
void	is_valid(t_game *game, char **map_cp);

//? get_next_line fun:
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);

//! remove this : 
void	print_tab(t_game *game);
void	print_struct(t_game *game);
#endif
