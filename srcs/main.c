/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/08 11:01:45 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void		test_func_str(char *str)
{
	int ret;
	int ret2;
	char *temp;

	temp = ft_strdup("Hi this is a test");
	printf("flags : %s", str);
	ft_printf("my output	: ");
	ret = ft_printf(str, temp);
	printf("real output	: ");
	ret2 = printf(str, temp);
	ft_printf("my ret		: %d\n", ret);
	printf("real ret	: %d\n", ret2);
	printf("---	**  **	---\n");
}

void		test_func_c(char *str)
{
	int ret;
	int ret2;
	char c;

	c = 'z';
	printf("flags : %s", str);
	ft_printf("my output	: ");
	ret = ft_printf(str, c);
	printf("real output	: ");
	ret2 = printf(str, c);
	ft_printf("my ret		: %d\n", ret);
	printf("real ret	: %d\n", ret2);
	printf("---	**  **	---\n");
}

void		test_c(void)
{
	printf("--- START TESTING C ---\n");
	test_func_c("%c\n");
	test_func_c("%.0c-|\n");
	test_func_c("%.10c-|\n");
	test_func_c("%5c-|\n");
	test_func_c("%0c-|\n");
	test_func_c("%-5c-|\n");
	test_func_c("%05c\n");
	test_func_c("%-05c\n");
	printf("--- FINISHED TESTING C ---\n");
}

void		test_str(void)
{
	printf("--- START TESTING STR ---\n");
	test_func_str("%s\n");
	test_func_str("%.5s-|\n");
	test_func_str("%.25s-|\n");
	test_func_str("%0s-|\n");
	test_func_str("%25s-|\n");
	test_func_str("%-25s-|\n");
	test_func_str("%025s\n");
	test_func_str("%-025s\n");
	printf("--- FINISHED TESTING STR ---\n");
}

int main(void)
{
	printf("\n|----		ft_print	----|\n\n");
	////////////	test section	////////////

	test_str();

	////////////	test section	////////////
	printf("\n\n|----		end		----|\n\n");
	//system("leaks a.out");
	return (0);
}

//printf("width : %d\njustify : %d\nfill : %d\nspecifier : %d\n", param->width, param->justify, param->fill, param->specifier);
