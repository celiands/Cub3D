/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngauthre <ngauthre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 02:33:21 by ngauthre          #+#    #+#             */
/*   Updated: 2025/07/13 02:33:21 by ngauthre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
//debug tools

// debug / test tool
void	printlist(t_list *lst)
{
	printf("list output :");
	if (!lst)
		return ;
	printf("f\n");
	while (lst != NULL)
	{
		printf("//%d, %d)", ((t_tile *)lst->val)->x, ((t_tile *)lst->val)->y);
		lst = lst->next;
	}
}

void print_mem_usage(void) {
    FILE *f = fopen("/proc/self/status", "r");
    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, "VmSize:", 7) == 0 || strncmp(line, "VmRSS:", 6) == 0)
            printf("%s", line);
    }
    fclose(f);
}

//print value of all char of a string
void	printline(char *str)
{
	int	i;

	printf("[{%ld}", ft_strlen(str));
	i = 0;
	while (str[i])
		printf("%d",str[i++]);
	printf("]\n");
}

bool	ret_true_x_time(int x)
{
	static int t = 0;
	t++;
	if (t < x)
		return (true);
	return (false);
}

#include <stdio.h>
#include <time.h>

void print_fps(void)
{
    static clock_t last_time = 0;
    static float fps = 0.0f;

    clock_t now = clock();
    if (last_time != 0)
    {
        double delta = (double)(now - last_time) / CLOCKS_PER_SEC;
        if (delta > 0.0)
            fps = 1.0 / delta;

        printf("%.2f\n", fps);
    }
    last_time = now;
}

void	print_tb(t_tb *tb)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (i < tb->m_y)
	{
		j = 0;
		while (j < tb->m_x)
		{
			printf("%d",(tb->tb)[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("%d)",i - 1 + (j - 1 * tb->m_x));
}*/