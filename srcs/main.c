/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thgermai <thgermai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:34:43 by thgermai          #+#    #+#             */
/*   Updated: 2019/12/14 17:01:15 by thgermai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

#include "../libft/libft.h"
#include "../includes/ft_printf.h"

void		test_func_add(char *str)
{
	int ret;
	int ret2;
	char *temp;

	temp = ft_strdup("Bonsoir a toute et a tous");
	printf("flags : %s", str);
	ft_printf("my output	: ");
	ret = ft_printf(str, (unsigned int)temp);
	printf("real output	: ");
	ret2 = printf(str, (unsigned int)temp);
	printf("my ret		: %d\n", ret);
	printf("real ret	: %d\n", ret2);
	printf("---	**  **	---\n");
	free(temp);
}

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
	printf("my ret		: %d\n", ret);
	printf("real ret	: %d\n", ret2);
	printf("---	**  **	---\n");
	free(temp);
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
	printf("my ret		: %d\n", ret);
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
	test_func_str("%s-|\n");
	test_func_str("%.5s-|\n");
	test_func_str("%.s-|\n");
	test_func_str("%.0s-|\n");
	test_func_str("%.1s-|\n");
	test_func_str("%10.0s-|\n");
	test_func_str("%10.5s-|\n");
	test_func_str("%-10.5s-|\n");
	test_func_str("%.28s-|\n");
	test_func_str("%0s-|\n");
	test_func_str("%25s-|\n");
	test_func_str("%-25s-|\n");
	test_func_str("%025s-|\n");
	test_func_str("%-025s-|\n");
	printf("--- FINISHED TESTING STR ---\n");
}

void		test_add(void)
{
	printf("--- START TESTING ADD ---\n");
	test_func_add("%p-|\n");
	test_func_add("%20p-|\n");
	test_func_add("%020p-|\n");
	test_func_add("%-20p-|\n");
	test_func_add("%-020p-|\n");
	test_func_add("%.25p-|\n");
	test_func_add("%10.25p-|\n");
	test_func_add("%10.8p-|\n");
	printf("--- FINISHED TESTING ADD ---\n");
}


int main(void)
{
	//printf("\n|----		ft_print	----|\n\n");
	////////////	test section	////////////

	int ret = ft_printf("%.6i", -3);
	printf("\n%d\n", ret);


	////////////	test section	////////////
	//printf("\n\n|----		end		----|\n\n");
	system("leaks a.out");
	return (0);
}

/* cheking
** > 0
** < 0
** = 0
** min value
** max value
*/

//printf("precision : %d\nwidth : %d\njustify : %d\nfill : %d\nspecifier : %d\n",param->precision, param->width, param->justify, param->fill, param->specifier);

/* to check :
** c
** s
** p
** d
** i
** u
** x
** X
** %
*/
