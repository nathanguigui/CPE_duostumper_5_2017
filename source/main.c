/*
** EPITECH PROJECT, 2018
** stumper
** File description:
** main
*/

void print(stumper_t *stumper)
{
	if (stumper->chars == NULL || stumper->nb == NULL)
		return;
	for (int i = 0; stumper->chars[i] != '\0'; i = i + 1) {
		my_putchar(stumper->chars[i]);
		my_putchar(':');
		my_putnbr(stumper->nb[i]);
		my_putchar('\n');
	}
}

void realloc_str(char **str, char c)
{
	char *temp = NULL;
	char *tmp = malloc(sizeof(char) * 2);

	tmp[1] = '\0';
	tmp[0] = c;
	temp = my_strcat(*str, tmp);
	free(*str);
	*str = temp;
	free(tmp);
}

void print_group(int current, int i, stumper_t *stumper, char **str)
{
	int k = i;

	if (str_find(*str, stumper->chars[i]))
		return;
	my_putchar(stumper->chars[i]);
	realloc_str(str, stumper->chars[i]);
	k = k + 1;
	while (stumper->chars[k] != '\0') {
		if (stumper->nb[k] == current) {
			my_putchar(',');
			my_putchar(stumper->chars[k]);
			realloc_str(str, stumper->chars[k]);
		}
		k = k + 1;
	}
	my_putchar(':');
	my_putnbr(stumper->nb[i]);
	my_putchar('\n');
}

void group(stumper_t *stumper)
{
	char *str = NULL;
	int current = 0;

	for (int i = 0; stumper->chars[i] != '\0'; i = i + 1) {
		current = stumper->nb[i];
		print_group(current, i, stumper, &str);
	}
	free(str);
}

int main(int ac, char **av)
{
	stumper_t *stumper = detect_params(ac, av);

	if (stumper == NULL || stumper->str == NULL)
		return (84);
	if (stumper->to_find == NULL)
		algo1(stumper);
	else
		algo2(stumper);
	if (stumper->tri)
		tri(stumper);
	if (stumper->group == 0)
		print(stumper);
	else
		group(stumper);
	free_stumper(stumper);
	return (0);
}
