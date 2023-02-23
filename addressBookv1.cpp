#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;
//Main class
class AddressBook
{
    private:
    class Person
    {
        private:
            string firstName;
            string lastName;
        
        public:
        Person(string first,string last)
        {
            this->firstName = first;
            this->lastName = last;
        }
        string getName(string,string);
    };
    class Address
    {
        private:
        string streetName,cityName,district,postCode;
        
        public:
        Address(string street,string city,string district,string post_code)
        {
            this->streetName = street;
            this->cityName = city;
            this->district = district;
            this->postCode = post_code;
        }
        string getAddress(string,string,string,string);
    };
    class emailAddress
    {
        private:
        string email;

        public:
        emailAddress(string e_mail)
        {
            this->email = e_mail;
        }
        string getEmailAddress(string);
    };
    class Telephone
    {
        private:
        string phoneNumber;

        public:
        Telephone(string phone_number)
        {
            this->phoneNumber = phone_number;
        }
        string getTelePhone(string);
    };
};
//Functions that set the format for the address book
string AddressBook::Person::getName(string first,string last)
{
    string fullName = first + " " + last;
    return fullName;
}
string AddressBook::Address::getAddress(string street,string city,string district,string postCode)
{
    string addressOfPerson = street + "," + city + "," + district + "," + postCode;
    return addressOfPerson;
}
string AddressBook::emailAddress::getEmailAddress(string e_mail)
{
    return e_mail; 
}
string AddressBook::Telephone::getTelePhone(string phone)
{
    return phone;
}