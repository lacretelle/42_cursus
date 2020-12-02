/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:05:51 by madufour          #+#    #+#             */
/*   Updated: 2020/09/14 16:05:53 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_H
# define PHONEBOOK_CLASS_H
# include <iostream>
# include <iomanip>
# include "Contact.class.hpp"

class Phonebook
{
private:
    Contact _contacts[8];
    int     _numberOfContact;

public:
    Phonebook(void);
    ~Phonebook(void);
    void     fillBook(void);
    void    displayBook(void);
    void    displayAll(void) const;
    void    displayOne(Contact contact) const;
    Contact getContact(int n) const;
    int     getNumberOfContact(void) const;
    void    setNumberOfContact(int n);
};
#endif
