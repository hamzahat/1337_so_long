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
//! this are wrong ! chang them for Mac
# define KEY_ESC        65307
# define KEY_W          119
# define KEY_A          97
# define KEY_S          115
# define KEY_D          100

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

//?
typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		coins;
	int		exit;
	int		player;
} t_game;

//?
// typedef struct s_vars
// {
// 	int	x;
// 	int	y;
// }	t_vars;

//?
typedef struct s_map
{
	int	width;
	int	height;
}	t_map;

//? game fun:
void	parse_map(int ac, char *av[]);
void	open_window(void *mlx, void *win);
void	*ft_safe_malloc(size_t size, int key, int exit_status, void *to_delete);
int		close_window(void *mlx, void *win);
size_t	ft_strlen_map_check(const char *s);
size_t	ft_strlen(const char *s);
int		ft_strcmp(char *s1, char *s2);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strcpy(char *dst, const char *src);


//? get_next_line fun:
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);


#endif
