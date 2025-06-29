int	ft_strcmp(char *s1,char *s2)
{
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	sort_env(t_env *env)
{
	int		i;
	int		sorted;
	char	*tmp;

	if (!env)
		return ;

	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = 0;
		while (env->env_cpy[i] && env->env_cpy[i + 1])
		{
			if (ft_strcmp(env->env_cpy[i], env->env_cpy[i + 1]) > 0)
			{
				tmp = env->env_cpy[i];
				env->env_cpy[i] = env->env_cpy[i + 1];
				env->env_cpy[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
	}
}
