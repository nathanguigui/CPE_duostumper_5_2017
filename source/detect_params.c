/*
** EPITECH PROJECT, 2017
** detect_params.c
** File description:
** 
*/

int get_params(stumper_t *result, char *arg)
{
	if (my_strcmp("-r", arg)){
		result->group = 1;
		return (0);
	}
	if (my_strcmp("-t", arg)){
		result->tri = 1;
		return (0);
	}
	return (-1);
}

int get_chars(stumper_t *result, char *chars)
{
	static int i = 0;

	if (i == 0) {
		result->str = my_strcat(chars, "");
		i = i + 1;
	} else if (i == 1) {
		result->to_find = my_strcat(chars, "");
		i = i + 1;
	} else {
		return (-1);
	}
	return (0);
}

stumper_t *detect_params(int ac, char **av)
{
	stumper_t *result = malloc(sizeof(stumper_t));
	int status = 0;

	result->group = 0;
	result->tri = 0;
	result->chars = NULL;
	result->nb = NULL;
	result->to_find = NULL;
	if (ac == 1)
		return (NULL);
	for (int i = 1; av[i]; i = i + 1) {
		if (av[i][0] == '-')
			(get_params(result, av[i]) == -1) ? status = -1 : 1;
		else
			(get_chars(result, av[i]) == -1) ? status = -1 : 1;
	}
	if (status == -1)
		return (NULL);
	return (result);
}
