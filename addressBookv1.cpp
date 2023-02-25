#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <fstream>

using namespace std;
//Main class
class AddressBook
{
    public:
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
//Functions that set the format of the address book
string AddressBook::Person::getName(string first = "",string last = "")
{
    string fullName = first + " " + last;
    return fullName;
}
string AddressBook::Address::getAddress(string street = "",string city = "",string district = "",string postCode = "")
{
    string addressOfPerson = street + "," + city + "," + district + "," + postCode;
    return addressOfPerson;
}
string AddressBook::emailAddress::getEmailAddress(string e_mail = "")
{
    return e_mail; 
}
string AddressBook::Telephone::getTelePhone(string phone = "")
{
    return phone;
}

void displayMenu()
{
    cout << "1) Add Contact.\n";
    cout << "2) Update existing contact.\n";
    cout << "3) remove contact\n";
    cout << "4) Display full contact list\n";
    cout << "5) Search Contact name.";
}


int main()
{
    string first,last,telephone,street,city,district,postcode,e_mail;
    int option;
    
    //empty map container
    multimap<string,string> contact;
    displayMenu();
    cin >> option;

    switch(option)
    {
        case 1:
            cout << "First name: "; cin >> first;
            cout << "Last name: "; cin >> last;
            cout << "telephone: "; cin >> telephone;
            cout << "Street name: "; cin >> street;
            cout << "City: "; cin >> city;
            cout << "District: "; cin >> district;
            cout << "Postcode: "; cin >> postcode;
            cout << "E-mail address: "; cin >> e_mail;
            
            //person object
            AddressBook::Person Person(first,last);
            //Telephone object
            AddressBook::Telephone Telephone(telephone);
            //Address object
            AddressBook::Address Address(street,city,district,postcode);
            //E-mail object
            AddressBook::emailAddress emailAddress(e_mail);
            
            //Map that stores format of inputs
            contact.insert(pair<string,string> (last,Person.getName(first,last)));
            contact.insert(pair<string,string> ("Telephone",Telephone.getTelePhone(telephone)));
            contact.insert(pair<string,string> ("Address",Address.getAddress(street,city,district,postcode)));
            contact.insert(pair<string,string> ("Email",emailAddress.getEmailAddress(e_mail)));
        break;
        case 2:
          cout << "Enter the last name of the contact you want to update: ";
          string updateContact;
          cin >> updateContact;
          multimap<string,string>::iterator itr;

          auto it = contact.equal_range(updateContact);

        if(it.first == it.second)
        {
            cout << "Contact name not found " << '\n';
        }else
        {
           for(auto itr = it.first;itr != it.second;itr++)
          {
            itr->second = updateContact;
          }
           
           //Prints updated list
           for(const auto& [key,value] : contact)
           {
                cout << key << ": " << value << '\n';
           }
        }
        break;  
    }
}