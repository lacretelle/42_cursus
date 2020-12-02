/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madufour <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:05:51 by madufour          #+#    #+#             */
/*   Updated: 2020/09/14 16:05:53 by madufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_H
# define CONTACT_CLASS_H
# include <iostream>
# include <string>
# include <iomanip>

class Contact
{
private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _login;
    std::string _postal;
    std::string _address;
    std::string _email;
    std::string _phone;
    std::string _birthday;
    std::string _date;
    std::string _favoriteMeal;
    std::string _underwearColor;
    std::string _darkestSecret;

public:
    Contact(void);
    ~Contact(void);

    // // GET AND SET
    std::string getFirstName(void);
    std::string getLastName(void);
    std::string getNickname(void);
    std::string getLogin(void);
    std::string getPostal(void);
    std::string getAddress(void);
    std::string getEmail(void);
    std::string getPhone(void);
    std::string getBirthday(void);
    std::string getDate(void);
    std::string getFavoriteMeal(void);
    std::string getUnderwearColor(void);
    std::string getDarkestSecret(void);

    void setFirstName(std::string firstname);
    void setLastName(std::string lastname);
    void setNickname(std::string nickname);
    void setLogin(std::string login);
    void setPostal(std::string postal);
    void setAddress(std::string address);
    void setEmail(std::string email);
    void setPhone(std::string phone);
    void setBirthday(std::string birthday);
    void setDate(std::string date);
    void setFavoriteMeal(std::string favoritemeal);
    void setUnderwearColor(std::string underwearcolor);
    void setDarkestSecret(std::string darkestsecret);
};
#endif
