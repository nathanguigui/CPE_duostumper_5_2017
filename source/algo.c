/*
** EPITECH PROJECT, 2018
** stumper
** File description:
** algo
*/

void update_var(stumper_t *stumper, char c)
{
	int pos;

	for (pos = 0; stumper->chars[pos] != c && stumper->chars[pos] != '\0';
	pos = pos + 1);
	if (stumper->chars[pos] != c)
		return;
	stumper->nb[pos] += 1;
}

void add_void(stumper_t *stumper, char c)
{
	char *temp = stumper->chars;
	int *temp2 = stumper->nb;
	char *tmp = malloc(sizeof(char) * 2);
	int i = 0;
	int len;

	tmp[0] = c;
	tmp[1] = '\0';
	stumper->chars = my_strcat(temp, tmp);
	free(temp);
	free(tmp);
	len = my_strlen(stumper->chars);
	stumper->nb = malloc(sizeof(int) * len);
	for (i = 0; i < len - 1; i = i + 1)
		stumper->nb[i] = temp2[i];
	stumper->nb[i] = 0;
	free(temp2);
}

void add_var(stumper_t *stumper, char c)
{
	char *temp = stumper->chars;
	int *temp2 = stumper->nb;
	char *tmp = malloc(sizeof(char) * 2);
	int i = 0;
	int len;

	tmp[0] = c;
	tmp[1] = '\0';
	stumper->chars = my_strcat(temp, tmp);
	free(temp);
	free(tmp);
	len = my_strlen(stumper->chars);
	stumper->nb = malloc(sizeof(int) * len);
	for (i = 0; i < len - 1; i = i + 1)
		stumper->nb[i] = temp2[i];
	stumper->nb[i] = 1;
	free(temp2);
}

void algo1(stumper_t *stumper)
{
	for (int i = 0; stumper->str[i] != '\0'; i = i + 1) {
		if (str_find(stumper->chars, stumper->str[i]))
			update_var(stumper, stumper->str[i]);
		else
			add_var(stumper, stumper->str[i]);
	}
}

void algo2(stumper_t *stumper)
{
	for (int i = 0; stumper->str[i] != '\0'; i = i + 1) {
		if (str_find(stumper->chars, stumper->str[i]) &&
			str_find(stumper->to_find, stumper->str[i]))
			update_var(stumper, stumper->str[i]);
		else if (str_find(stumper->to_find, stumper->str[i]))
			add_var(stumper, stumper->str[i]);
	}
	for (int i = 0; stumper->to_find[i]; i = i + 1) {
		if (!str_find(stumper->chars, stumper->to_find[i])) {
			add_void(stumper, stumper->to_find[i]);
		}
	}
}
