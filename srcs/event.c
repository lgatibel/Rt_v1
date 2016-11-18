#include <rtv1.h>

void				event(t_env *env)
{
	mlx_hook(env->win, 2, (1L<<0), ft_exit, &env);
	mlx_hook(env->win, 17, (1L<<17), ft_exit, &env);
}
