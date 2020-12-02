#include "Contact.class.hpp"

Contact::Contact(void) {}
Contact::~Contact(void) {}

std::string Contact::getFirstName(void) { return this->_firstName;}
std::string Contact::getLastName(void) { return this->_lastName;}
std::string Contact::getNickname(void) { return this->_nickname;}
std::string Contact::getLogin(void) { return this->_login;}
std::string Contact::getPostal(void) { return this->_postal;}
std::string Contact::getAddress(void) { return this->_address;}
std::string Contact::getEmail(void) { return this->_email;}
std::string Contact::getPhone(void) { return this->_phone;}
std::string Contact::getBirthday(void) { return this->_birthday;}
std::string Contact::getDate(void) { return this->_date;}
std::string Contact::getFavoriteMeal(void) { return this->_favoriteMeal;}
std::string Contact::getUnderwearColor(void) { return this->_underwearColor;}
std::string Contact::getDarkestSecret(void) { return this->_darkestSecret;}

void Contact::setFirstName(std::string firstname) {  this->_firstName = firstname;}
void Contact::setLastName(std::string lastname) {  this->_lastName = lastname;}
void Contact::setNickname(std::string nickname) {  this->_nickname = nickname;}
void Contact::setLogin(std::string login) {  this->_login = login;}
void Contact::setPostal(std::string postal) {  this->_postal = postal;}
void Contact::setAddress(std::string address) {  this->_address = address;}
void Contact::setEmail(std::string email) {  this->_email = email;}
void Contact::setPhone(std::string phone) {  this->_phone = phone;}
void Contact::setBirthday(std::string birthday) {  this->_birthday= birthday;}
void Contact::setDate(std::string date) {  this->_date = date;}
void Contact::setFavoriteMeal(std::string favoritemeal) {  this->_favoriteMeal = favoritemeal;}
void Contact::setUnderwearColor(std::string underwearcolor) {  this->_underwearColor = underwearcolor;}
void Contact::setDarkestSecret(std::string darkestsecret) {  this->_darkestSecret = darkestsecret;}