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
        string getName(string,string);
    };
    class Address
    {
        private:
        string streetName,cityName,district,postCode;
        
        public:
        string getAddress(string,string,string,string);
    };
    class emailAddress
    {
        private:
        string email;

        public:
        string getEmailAddress(string);
    };
    class Telephone
    {
        private:
        string phoneNumber;

        public:
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

//function to display menu
void displayMenu()
{
    cout << "1) Add Contact.\n";
    cout << "2) Update existing contact.\n";
    cout << "3) remove contact\n";
    cout << "4) Display full contact list\n";
    cout << "5) Quit\n";
}


int main()
{
    // //open file for writing
    // ofstream open("contact_list.txt");
    // open << "******Address Book******" << '\n';
    string first,last,telephone,street,city,district,postcode,e_mail;
    string updateContact,findContact;
    string removeContact;
    int option;
    
    //empty map container
    multimap<string,string> contact;

    //person object
    AddressBook::Person Person;
    //Telephone object
    AddressBook::Telephone Telephone;
    //Address object
    AddressBook::Address Address;
    //E-mail object
    AddressBook::emailAddress emailAddress;
    
    do
    {
        displayMenu();
        cin >> option;
        
        if(option == 1)
        {
            cout << "First name: "; cin >> first;
            cout << "Last name: "; cin >> last;
            cout << "telephone: "; cin >> telephone;
            cout << "Street name: "; cin >> street;
            cout << "City: "; cin >> city;
            cout << "District: "; cin >> district;
            cout << "Postcode: "; cin >> postcode;
            cout << "E-mail address: "; cin >> e_mail;
            
            //Map that stores format of inputs
            contact.insert(pair<string,string> ("Name",Person.getName(first,last)));
            contact.insert(pair<string,string> ("Telephone",Telephone.getTelePhone(telephone)));
            contact.insert(pair<string,string> ("Address",Address.getAddress(street,city,district,postcode)));
            contact.insert(pair<string,string> ("Email",emailAddress.getEmailAddress(e_mail)));
        }else if(option == 2)
        {
            cout << "Enter the last name of the contact you want to update: ";
            cin >> findContact;
            
            multimap<string,string>::iterator itr;

            auto it = contact.equal_range(findContact);

            if(it.first == it.second)
            {
                cout << "Contact name not found " << '\n';
            }else
            {
                cout << "Enter you would like to add: ";
                cin >> updateContact;
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
        }else if(option == 3)
        {
            cout << "Enter the last name of contact you want to remove: ";
                   
            cin >> removeContact;

            multimap<string,string>::iterator itr1;

            auto it = contact.equal_range(removeContact);

            if(it.first == it.second)
            {
                cout << "Contact name not found" << '\n';
            }else
            {
                contact.erase(it.first,it.second);

                for(const auto& [key,value] : contact)
                {
                    cout << key << ": " << value << '\n';
                }
            }
        }else if(option == 4)
        {
            for(const auto& [key,value] : contact)
            {
                    cout << key << ": " << value << '\n';
            }
        }
    }while(option != 5);
    return 0;
}