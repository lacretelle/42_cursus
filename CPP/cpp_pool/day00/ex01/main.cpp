/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 15:29:24 by madufour          #+#    #+#             */
/*   Updated: 2020/09/14 15:29:27 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Phonebook.class.hpp"

int main(void)
{
    Phonebook   phonebook;
    std::string str;

    char first[] = "What do you want to do ADD, SEARCH or EXIT?";
    char errorMaxBook[] = "I am sorry, you can't register a new contact.";
    char errorInput[] = "Enter a valid input: ADD, SEARCH or EXIT.";

    phonebook.setNumberOfContact(0);

    while (str.compare("EXIT") != 0)
    {
        std::cout << first << std::endl;
        std::cin >> str;
        if (str.compare("ADD") == 0)
        {
            if (phonebook.getNumberOfContact() < 8)
                phonebook.fillBook();
            else
                std::cout << errorMaxBook << std::endl;
        }
        else if (str.compare("SEARCH") == 0)
            phonebook.displayBook();
        else if (str.compare("EXIT") == 0)
            std::cout << "Good Bye !" << std::endl;
        else
            std::cout << errorInput << std::endl;
    }
    return 0;
}
