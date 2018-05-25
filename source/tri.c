/*
** EPITECH PROJECT, 2018
** stumper
** File description:
** tri
*/

void swap(stumper_t *stumper, int i)
{
	int temp = stumper->nb[i];
	char temp2 = stumper->chars[i];

	stumper->nb[i] = stumper->nb[i + 1];
	stumper->nb[i + 1] = temp;
	stumper->chars[i] = stumper->chars[i + 1];
	stumper->chars[i + 1] = temp2;
}

void tri(stumper_t *stumper)
{
	int len = my_strlen(stumper->chars);

	for (int i = 0; i + 1 < len; i = i + 1) {
		if (stumper->nb[i] < stumper->nb[i + 1])
			swap(stumper, i);
	}
}

void free_stumper(stumper_t *stumper)
{
	free(stumper->chars);
	free(stumper->nb);
	free(stumper->to_find);
	free(stumper->str);
	free(stumper);
}
