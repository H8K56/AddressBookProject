/**
 * @file addressBookv1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <iostream>
#include <string>

using namespace std;

struct addressBookv1
{
    string contact;
}Contact1,Contact2,Contact3,Contact4,Contact5;

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
    string first,last,telephone,street,city,district,postcode,e_mail;
    string Combined_Contact = "Name: "+ first + "," + last + ",Tele: " + telephone + ",Address: " + street + "," + city + "," + district + "," + postcode + ",email: " + e_mail;
    int updateContact,findContact,removeContact;
    int option,userInput,count = 0;
    string contact_arr[5];
    do
    {
        displayMenu();
        cin >> option;
        
        switch(option)
        {
            case 1:
            {
                do
                {
                    cout << "First name: "; cin >> first;
                    cout << "Last name: "; cin >> last;
                    cout << "telephone: "; cin >> telephone;
                    cout << "Street name: "; cin >> street;
                    cout << "City: "; cin >> city;
                    cout << "\nDistrict: "; cin >> district;
                    cout << "Postcode: "; cin >> postcode;
                    cout << "E-mail address: "; cin >> e_mail;
                    count++;
                    
                    if(count == 1)
                    {Contact1.contact = Combined_Contact; contact_arr[0] = Contact1.contact;}
                    else if(count == 2)
                    {Contact2.contact = Combined_Contact;contact_arr[1] = Contact2.contact;}
                    else if(count == 3)
                    {Contact3.contact = Combined_Contact;contact_arr[2] = Contact3.contact;}
                    else if(count == 4)
                    {Contact4.contact = Combined_Contact;contact_arr[3] = Contact4.contact;}
                    else if(count == 5)
                    {Contact5.contact = Combined_Contact;contact_arr[4] = Contact5.contact;}
                    
                    cout << "Continue(1), quit(0)";
                    cin >> userInput;
                } while (userInput != 0);
                
                break;
            }
            case 2:
            {
                cout << "Enter the contact number you want to update: ";
                cin >> updateContact;
                
                if(updateContact <= 0 || updateContact > 5)
                {
                    cout << "Contact not found!";
                    cout << "Enter the contact number you want to update: ";
                    cin >> updateContact;
                }
                int size_of_arr = sizeof(contact_arr)/sizeof(contact_arr[0]);

                if(updateContact == 1)
                {
                    cout <<"Contact 1: "<< Contact1.contact << '\n';
                    
                    cout << "First name: "; cin >> first;
                    cout << "Last name: "; cin >> last;
                    cout << "telephone: "; cin >> telephone;
                    cout << "Street name: "; cin >> street;
                    cout << "City: "; cin >> city;
                    cout << "\nDistrict: "; cin >> district;
                    cout << "Postcode: "; cin >> postcode;
                    cout << "E-mail address: "; cin >> e_mail;

                    Contact1.contact = Combined_Contact; 
                    contact_arr[0] = Contact1.contact;
                }
                break;
            }
            case 3:
            {
                cout << "Enter the contact number to remove contact: ";
                cin >> removeContact;

                int size_of_arr = sizeof(contact_arr)/sizeof(contact_arr[0]);

                for(int i = removeContact - 1;i < size_of_arr - 1;i++)
                {
                    contact_arr[i] = contact_arr[i + 1];
                }
                size_of_arr--;

                for(int i = 0;i < size_of_arr;i++)
                {
                    cout << contact_arr[i] << '\n';
                }
                break;
            }
            case 4:
            {
                for(int i = 0;i < count;i++)
                {
                    cout << contact_arr[i] << '\n';
                }
                break;
            }
        }
    }while(option != 5);

    cout << "You are blessed";
    return 0;
}