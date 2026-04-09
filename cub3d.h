/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 22:07:47 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/12 22:07:47 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define S_SIZE_X		1280
# define S_SIZE_Y		720
# define M_SIZ_X		500
# define M_SIZE_Y		500

# define MAP_MAX_SIZE	50000
# define TILE_SIZE		16
# define MINIMAP		1

# define LINE_COLOR		0x2300ff
# define TILE_COLOR		0x781028
# define PLAYER_COLOR	0xffffff
# define PLAYER_SPEED	0.1
# define PLAYER_SENS	5
# define PLAYER_SIZE	0.3f

# define FPT			1

# define RAY_LENGTH		20
//reduction du nb de rayon
# define ACCURACY		1.0f
# define RAY_COLOR		0x00ff17
# define POV			60.0f
# define FISH_EYE		0

# ifndef M_PI
#  define M_PI	3.14159265358979323846
# endif

// EPSILON
# ifndef EPS
#  define EPS	1e-6
# endif

# define E_CLOSE_WINDOW     17
# define MASK_CLOSE_WINDOW  0L
# define EVENT_KEY_PRESS    2
# define MASK_KEY_PRESS     1L
# define EVENT_KEY_UP    	3
# define MASK_KEY_UP		2L

# define SOUTH				1
# define NORTH				2
# define EAST				3
# define WEST				0

# define GUN_ANIM "Assets/gun_anim.xpm"

//errors
# define ERR_ARGS "Too few args or invalid path "
# define ERR_MALLOC "Failed to allocate place for "
# define ERR_MAP_SIZE "Map to big"
# define ERR_MAP_CLOSE "Map not closed"
# define ERR_MLX "Couldn't init mlx"
# define ERR_WINDOW "Couldn't create a new window "
# define ERR_IMG "Couldn't create a new image "
# define ERR_OPEN "Could't open file "
# define ERR_READ "Couldn't read "
# define ERR_ONE_PLAYER "Map should contain one player (NSEO)"
# define ERR_MAP_CHAR "Unknown map character "
# define ERR_PARAM "Wrong param syntax or not enough param"
# define ERR_RENDER "Failed to render "
# define ERR_UKN "Unkown param "

//structures
typedef struct s_vect2D
{
	float	x;
	float	y;
}	t_v2D;

typedef struct s_line_sup_params
{
	int		index;
	float	angle;
}	t_line_param;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		ppl;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_dir
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	rt_r;
	int	rt_l;
}	t_dir;

typedef struct s_player
{
	float		x;
	float		y;
	int			color;
	t_v2D		frwd;
	t_dir		p_dir;
}	t_player;

typedef struct s_tile
{
	int			x;
	int			y;
	int			color;
}	t_tile;

typedef struct s_list
{
	void			*val;
	struct s_list	*next;
}	t_list;

// game master
typedef struct s_world_info
{
	int		floor;
	int		roof;
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea;

}	t_wi;

typedef struct uv_info
{
	int		tex_type;
	float	uv_x;
	float	dist;
}	t_uv;

typedef struct s_anim
{
	t_img	img;
	int		frame;
	int		maxframe;
	t_v2D	fdim;
	int		play;
}	t_anim;

typedef struct s_tb
{
	int		m_x;
	int		m_y;
	char	**tb;
}	t_tb;

typedef struct s_list_map
{
	int		m_x;
	int		m_y;
	t_list	*lines;
}	t_list_map;

//temp
typedef struct ray
{
	t_v2D	hit;
	int		side;
	t_v2D	origin;
}	t_ray;

typedef struct s_game_master
{
	void		*mlx;
	void		*window;
	t_img		main_img;
	t_img		render;
	t_img		bg;
	t_player	*p1;
	t_wi		wi;
	void		*to_free;
	t_anim		m_anim;
	t_tb		*tb_c;
}	t_gm;

//structs for put line
typedef struct s_line
{
	t_uv	uv;
	float	ray_angle;
	int		index;
}	t_line;

typedef struct col
{
	t_line	ifl;
	short	x;
	short	y;
	short	line_siz;
	short	pix_lim;
}	t_col;

typedef struct s_dda
{
	double	posx;
	double	posy;
	double	dirx;
	double	diry;
	double	deltadistx;
	double	deltadisty;
	double	sidedistx;
	double	sidedisty;
	t_ray	ray;
}	t_dda;

//raycasting render
t_uv	dda(t_v2D o, t_v2D dir, t_img *dst, t_gm *g);
t_uv	get_uvx_sq(t_ray ray, float dist);
int		get_pix(t_v2D uv, t_gm *gm, int tex);
void	draw_raycasting(t_v2D v, t_v2D dir, t_img *dst, t_gm *gm);
t_line	new_line(int index, t_uv uv, float ray_angle);
t_col	new_column(short line_siz, short x, t_line ifl, short lim);

int		new_image(t_img *img, int x, int y, t_gm *gm);
void	copy_t_image(t_img *dst_img, t_tile *src, int color);
void	copy_image(t_img *dst_img, t_img *src, int sx, int sy);
void	put_pixel(t_img *dst_img, int x, int y, int color);
void	fill_img(char *addr, size_t dim, unsigned int color);
void	cleanup(t_gm *gm);
//void	render_tiles(t_list *list, t_img *img);
void	render_tiles_celian(t_tb *list, t_img *img);
void	render_player(t_img *dst, t_gm *gm);
int		param_game(t_gm *gm, int fd);

bool	put_error(char *err, char *var);
void	free_split(char **split);

//op
float	min(float x1, float x2);
float	max(float x1, float x2);
int		max_int(int a, int b);
int		is_empty(const char *str);

//opti
int		make_tb_c(t_gm *gm);
void	set_tb_c(t_gm *gm);
void	freetb(t_tb *tb_c);
t_tb	*tb_cpy(t_tb *tb);

//anim
t_anim	load_anim(char *path, int mf, t_v2D dim, t_gm *gm);
void	play_animation(t_img *dst, t_v2D coords, t_gm *gm);

int		mouse_input(int button, int x, int y, t_gm *gm);

//vect
t_v2D	new2d_vect(float x, float y);
t_v2D	rotate(t_v2D v, float deg);
t_v2D	get_sq(t_v2D coords);

//player
int		new_player(int x, int y, char dir, t_gm *gm);
void	move_p(t_v2D v, t_gm *gm);
t_dir	newdir(void);

// col
int		test_colision(t_v2D nv, t_gm *gm);

//hooks
int		close_window(t_gm *gm);
int		key_input(int keycode, t_gm *gm);
int		key_output(int keycode, t_gm *gm);
int		hook_loop(t_gm *gm);
void	render_loop(t_gm *gm);
int		mouse_move_handler(int x, int y, t_gm *gm);

//inits
int		init_game_master(t_gm *gm);
int		init_map(char *path, t_gm *gm);
int		init_mlx_hooks(t_gm *gm);
void	make_bg(t_gm *gm);
bool	ret_true_x_time(int x);

//map
int		check_map(int fd);
int		is_paramed(t_gm *gm);
int		conv_rgb(const char *line);
int		create_map_celian(t_gm *gm, int fd);
int		flood_check(t_v2D trg, t_tb *tb_c);

//list
void	freelst(t_list **lst);
t_list	*lstindex(t_list *lst, int i);
int		lstsize(t_list *lst);
t_list	*get_last(t_list *lst);
void	append(t_list **lst, t_list *new);
t_list	*new_list(void *value);

//gnl
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t n);
int		in(char *str, char c);
void	ft_close(int fd);

//test
void	printlist(t_list *lst);
void	print_mem_usage(void);
void	print_heap_usage(void);
void	printline(char *str);

void	print_fps(void);
void	print_tb(t_tb *tb);

void	put_circle(t_img *dst, int r);
#endif