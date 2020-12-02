#include "Phonebook.class.hpp"

Phonebook::Phonebook(void) {}
Phonebook::~Phonebook(void) {}

void     Phonebook::fillBook(void)
{
    Contact         new_contact;
    std::string     str;
    int    count = this->getNumberOfContact();

    std::cout << "Answer to few questions please, are you ready ?" << std::endl;
    std::getline(std::cin, str);
    std::cout << "What's your first name ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setFirstName(str);
    std::cout << "What's your last name ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setLastName(str);
    std::cout << "What's your nick name ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setNickname(str);
    std::cout << "What's your login ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setLogin(str);
    std::cout << "What's your postal ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setPostal(str);
    std::cout << "What's your address ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setAddress(str);
    std::cout << "What's your email ?" << std::endl;
    if (str.size() > 0)
        std::getline(std::cin, str);
    new_contact.setEmail(str);
    std::cout << "What's your phone ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setPhone(str);
    std::cout << "What's your birthday ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setBirthday(str);
    std::cout << "What's is date of today ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setDate(str);
    std::cout << "What's your favorite meal ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setFavoriteMeal(str);
    std::cout << "What's your underwear color ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setUnderwearColor(str);
    std::cout << "What's your darkest secret ?" << std::endl;
    std::getline(std::cin, str);
    if (str.size() > 0)
        new_contact.setDarkestSecret(str);
    this->_contacts[count] = new_contact;
    this->setNumberOfContact(count + 1);
}
void    Phonebook::displayBook(void)
{
    std::string str;
    int index = 1;

    if (this->getNumberOfContact() > 0)
    {
        this->displayAll();
        std::cout << "Which contact do you want to watch, enter index (1 - max) ?" << std::endl;
        std::cin >> index;
        while (index < 1 && index > (this->getNumberOfContact() + 1))
        {
            std::cout << "This input doesn't exist ! Enter a number between 1 to " << this->getNumberOfContact() << std::endl;
            std::cin >> index;
        }
        Contact contact = this->getContact(index - 1);
        this->displayOne(contact);
    }
    else
        std::cout << "This phonebook is empty, add a contact first !" << std::endl;
}

std::string update_too_long(std::string str)
{
    std::string res;
    if (str.size() > 10)
    {
        str.resize(9);
        str += ".";
        return str;
    }
    return str;
}
void        Phonebook::displayAll() const
{
    int i = 1;
    std::string firstname;
    std::string lastname;
    std::string nickname;
    std::cout << std::setw(11);
    std::cout << "index|";
    std::cout << std::setw(11);
    std::cout << "Firstname|";
    std::cout << std::setw(11);
    std::cout << "Lastname|";
    std::cout << std::setw(11);
    std::cout << "Nickname" << std::endl;

    while (i < (this->getNumberOfContact() +1))
    {
        std::cout << std::setw(10);
        std::cout << std::to_string(i) << "|";
        firstname = update_too_long(this->getContact(i - 1).getFirstName());
        lastname = update_too_long(this->getContact(i - 1).getLastName());
        nickname = update_too_long(this->getContact(i - 1).getNickname());
        std::cout << std::setw(10);
        std::cout << firstname << "|";
        std::cout << std::setw(10);
        std::cout << lastname << "|";
        std::cout << std::setw(10);
        std::cout << nickname << std::endl;
        i++;
    }
}
void        Phonebook::displayOne(Contact contact) const
{
    std::cout << contact.getPhone() << std::endl;
    std::cout << contact.getAddress() << std::endl;
    std::cout << contact.getPostal() << std::endl;
    std::cout << contact.getEmail() << std::endl;
}


Contact Phonebook::getContact(int n) const
{
    return this->_contacts[n];
}
int     Phonebook::getNumberOfContact(void) const
{
    return this->_numberOfContact;
}
void    Phonebook::setNumberOfContact(int n)
{
    this->_numberOfContact = n;
}
