#include <rtv1.h>

t_env				*set_env(t_env *env)
{
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		error(INIT, __LINE__ - 1, __FILE__);
	env->bpp = 0;
	env->size_line = 0;
	env->endian = 0;
	env->t = 1000;
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIDTH, HEIGHT,
	"hello");
	env->img = mlx_new_image(env->mlx, WIDTH, HEIGHT);
	env->img_addr = (int *)mlx_get_data_addr(env->img,
	&env->bpp, &env->size_line, &env->endian);
	return (env);
}
