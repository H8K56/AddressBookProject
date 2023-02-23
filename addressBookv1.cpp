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
        string streetName,cityName,district;
        int postCode;
        
        public:
        Address(string street,string city,string district,int post_code)
        {
            this->streetName = street;
            this->cityName = city;
            this->district = district;
            this->postCode = post_code;
        }
        string getAddress(string,string,string,int);
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