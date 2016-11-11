#include <rtv1.h>

static void set_vec(t_point *vec, double x, double y,
double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

t_env				*set_env(t_env *env)
{
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		error(INIT, __LINE__ - 1, __FILE__);
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	env->t = 1000;
	env->viewplane.width = 0.35;
	env->viewplane.height = 0.5;
	env->viewplane.dist = 1;
	set_vec(&env->cam, 0, 0, -1);
	set_vec(&env->viewplane.vecdir, 0, 0, 1);
	set_vec(&env->viewplane.upvec, 0, 1, 0);
	set_vec(&env->viewplane.rightvec, 1, 0, 0);
	//right here
	env->cam.y = 0;
	env->cam.y = 0;
	env->cam.z = 3;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT,
	"hello");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_addr = (int *)mlx_get_data_addr(env->img,
	&env->bpp, &env->size_line, &env->endian);
	return (env);
}
