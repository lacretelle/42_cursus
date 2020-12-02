/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 12:23:32 by madufour          #+#    #+#             */
/*   Updated: 2020/09/14 12:23:36 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <iostream>
#include <cctype>
#include <string>

int count_size(char *s[])
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (s[i])
    {
        count += strlen(s[i]);
        i++;
    }
    return count;
}

int main(int argc, char *argv[])
{
    int i;
    int k;
    int len;

    if (argc > 1)
    {
        len = count_size(argv);
        char str[len];
        i = 1;
        k = 0;
        while (i < argc)
        {
            int j;
            j = 0;
            while (argv[i][j])
            {
                str[k] = toupper(argv[i][j]);
                j++;
                k++;
            }
            i++;
        }
        std::cout << str << std::endl;
    }
    else
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    }
    return 0;
}