#ifndef FDF_H
# define FDF_H

# define V_WIDTH 1200
# define V_HEIGHT 860
# define MLX_ERROR 1
# define PI 3.141592653589

# define RED "\e[0;31m"
# define GRN "\e[0;32m"
# define YEL "\e[0;33m"
# define BLU "\e[0;34m"
# define MAG "\e[0;35m"
# define CYN "\e[0;36m"
# define WHT "\e[0;37m"
# define RESET "\033[0m"

#define RED_PIXEL 0xFF0055
#define GRN_PIXEL 0x00FF55
#define BLU_PIXEL 0x0055FF

# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "lib/libft/libft.h"
# include "lib/minilibx-linux/mlx.h"

typedef struct s_coords
{
	int x_pers;
	int y_pers;
	double z;
} t_coords;

typedef struct s_map
{
	int	n_cols;
	int	n_rows;
	double	a_x;
	double	a_z;
	int color;
	t_coords **coords;
}	t_map;

typedef struct s_rect
{
    int	x;
    int	y;
    int width;
    int height;
    int color;
}	t_rect;

typedef struct s_img
{
    void	*mlx_img;
    char	*addr;
    int		bpp; /* bits per pixel */
    int		line_len;
    int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
	t_img	img;
}	t_data;

int	handle_no_event(void *data);
int	handle_input(int keysym, t_data *data);
int	handle_keypress(int keysym, t_data *data);
int	handle_keyrelease(int keysym, void *data);

void	*mlx_new_image(void *mlx_ptr,int width,int height);
void	img_pix_put(t_img *img, int x, int y, int color);
char	*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);

//int render_rect(t_img *img, t_rect rect);
int render(t_data *data);

void free_arr2D(char **arr2D);
void import_map(char *str, t_data *data);
char	*get_next_line(int fd);


#endif