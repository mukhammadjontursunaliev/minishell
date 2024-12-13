/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtursuna <mtursuna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 19:08:53 by mtursuna          #+#    #+#             */
/*   Updated: 2024/03/12 15:25:10 by mtursuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (c);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// void compareResults(int expected, int actual, const char *testCase)
// {
//     if (expected == actual)
//     {
//         printf("Test Case %s: Passed\n", testCase);
//     }
//     else
//     {
//         printf("Test Case %s: Failed\n", testCase);
//         printf("Expected: %d, Actual: %d\n", expected, actual);
//     }
// }

// int main()
// {
//     // Test Case 1: Lowercase letter 'a'
//     int expected1 = isalpha('a');
//     int result1 = ft_isalpha('a');
//     compareResults(expected1, result1, "1");

//     // Test Case 2: Uppercase letter 'Z'
//     int expected2 = isalpha('Z');
//     int result2 = ft_isalpha('Z');
//     compareResults(expected2, result2, "2");

//     // Test Case 3: Digit '5'
//     int expected3 = isalpha('5');
//     int result3 = ft_isalpha('5');
//     compareResults(expected3, result3, "3");

//     // Test Case 4: Special character '#'
//     int expected4 = isalpha('#');
//     int result4 = ft_isalpha('#');
//     compareResults(expected4, result4, "4");

//     // Test Case 5: Lowercase letter 'z'
//     int expected5 = isalpha('z');
//     int result5 = ft_isalpha('z');
//     compareResults(expected5, result5, "5");

//     // Test Case 6: Uppercase letter 'A'
//     int expected6 = isalpha('A');
//     int result6 = ft_isalpha('A');
//     compareResults(expected6, result6, "6");

//     // Test Case 7: Null character '\0'
//     int expected7 = isalpha('\0');
//     int result7 = ft_isalpha('\0');
//     compareResults(expected7, result7, "7");

//     // Edge Test Case 8: Lower bound (character 0)
//     int expected8 = isalpha(0);
//     int result8 = ft_isalpha(0);
//     compareResults(expected8, result8, "8");

//     // Edge Test Case 9: Upper bound (character 255)
//     int expected9 = isalpha(255);
//     int result9 = ft_isalpha(255);
//     compareResults(expected9, result9, "9");

//     // Edge Test Case 10: Negative number (-1)
//     int expected10 = isalpha(-1);
//     int result10 = ft_isalpha(-1);
//     compareResults(expected10, result10, "10");

//     // Edge Test Case 11: Large positive number (1000)
//     int expected11 = isalpha(1000);
//     int result11 = ft_isalpha(1000);
//     compareResults(expected11, result11, "11");

//     return 0;
// }