/**
 * @file addressBookv1.cpp
 * @author Hussein Khadra
 * @brief A simple address book program holding five contacts
 * @version 0.1
 * @date 2023-03-03
 * @copyright MIT LISENCE 2023
 */

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/**
 * @brief A struct holding five contact variables
 * 
 */
struct addressBookv1
{
    string first,last,telephone,street,city,district,postcode,e_mail;
}Contact_Arr[100];


void displayMenu()
{
    cout << "\n1) Add Contact.\n";
    cout << "2) Update existing contact.\n";
    cout << "3) remove contact\n";
    cout << "4) Display full contact list\n";
    cout << "5) Quit\n";
}


int main()
{   
    int updateContact,findContact,removeContact,option,userInput,count = 0;

    do
    {
        displayMenu();
        cin >> option;
        
        switch(option)
        {
            case 1:
            {   
                cout << "First name: "; cin >> Contact_Arr[count].first;
                cout << "Last name: "; cin >> Contact_Arr[count].last;
                cout << "telephone: "; cin >> Contact_Arr[count].telephone;
                cout << "Street name: "; cin >> Contact_Arr[count].street;
                cout << "City: "; cin >> Contact_Arr[count].city;
                cout << "District: "; cin >> Contact_Arr[count].district;
                cout << "Postcode: "; cin >> Contact_Arr[count].postcode;
                cout << "E-mail address: "; cin >> Contact_Arr[count].e_mail;
                count++;
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

                for(int i = 0;i < count;i++)
                {
                    if(i == updateContact)
                        cout << "First name: "; cin >> Contact_Arr[i].first;
                        cout << "Last name: "; cin >> Contact_Arr[i].last;
                        cout << "telephone: "; cin >> Contact_Arr[i].telephone;
                        cout << "Street name: "; cin >> Contact_Arr[i].street;
                        cout << "City: "; cin >> Contact_Arr[i].city;
                        cout << "District: "; cin >> Contact_Arr[i].district;
                        cout << "Postcode: "; cin >> Contact_Arr[i].postcode;
                        cout << "E-mail address: "; cin >> Contact_Arr[i].e_mail;
                }
                break;
            }
            case 3:
            {
                cout << "Enter the contact number to remove contact: ";
                cin >> removeContact;

                for(int i = removeContact - 1;i < count;i++)
                {
                    Contact_Arr[i] = Contact_Arr[i + 1];
                }

                for(int i = 0;i < count;i++)
                {
                    cout << "First name: "; cout << Contact_Arr[i].first;
                    cout << "Last name: "; cout << Contact_Arr[i].last;
                    cout << "telephone: "; cout << Contact_Arr[i].telephone;
                    cout << "Street name: "; cout << Contact_Arr[i].street;
                    cout << "City: "; cout << Contact_Arr[i].city;
                    cout << "District: ";cout << Contact_Arr[i].district;
                    cout << "Postcode: "; cout << Contact_Arr[i].postcode;
                    cout << "E-mail address: "; cout << Contact_Arr[i].e_mail;
                    cout << '\n';
                }
                break;
            }
            case 4:
            {
                int chosenContact;
                cout << "(1) to display all contacts or (2) chose a contact to display.\n";
                cin >> chosenContact;

                if(chosenContact == 1)
                {
                    for(int i = 0;i < count;i++)
                    {
                        cout << "First name: "; cout << Contact_Arr[i].first;
                        cout << "Last name: "; cout << Contact_Arr[i].last;
                        cout << "telephone: "; cout << Contact_Arr[i].telephone;
                        cout << "Street name: "; cout << Contact_Arr[i].street;
                        cout << "City: "; cout << Contact_Arr[i].city;
                        cout << "District: ";cout << Contact_Arr[i].district;
                        cout << "Postcode: "; cout << Contact_Arr[i].postcode;
                        cout << "E-mail address: "; cout << Contact_Arr[i].e_mail;
                        cout << '\n';
                    }
                }else if(chosenContact == 2)
                {
                    cout << "Enter contact number: "<<'\n';
                    int contactChoice;
                    cin >> contactChoice;
                    
                    for(int i = 0;i < count && i != contactChoice;i++)
                    {
                        if(i == contactChoice)
                            cout << "First name: "; cout << Contact_Arr[i].first;
                            cout << "Last name: "; cout << Contact_Arr[i].last;
                            cout << "telephone: "; cout << Contact_Arr[i].telephone;
                            cout << "Street name: "; cout << Contact_Arr[i].street;
                            cout << "City: "; cout << Contact_Arr[i].city;
                            cout << "District: ";cout << Contact_Arr[i].district;
                            cout << "Postcode: "; cout << Contact_Arr[i].postcode;
                            cout << "E-mail address: "; cout << Contact_Arr[i].e_mail;
                            cout << '\n';
                    }
                }
                break;
            }
        }
    }while(option != 5);

    ofstream file;
    file.open("Contact.txt");

    if(!file.is_open())
    {
        cout << "File failed to open";
    }

    int j = 0;
    file << "********Contact List********" << '\n';
    while(j < count)
    {
        file << "First name: "; file << Contact_Arr[j].first;
        file << '\n';
        file << "Last name: "; file << Contact_Arr[j].last;
        file << '\n';
        file << "telephone: "; file << Contact_Arr[j].telephone;
        file << '\n';
        file << "Street name: "; file << Contact_Arr[j].street;
        file << '\n';
        file << "City: "; file << Contact_Arr[j].city;
        file << '\n';
        file << "District: ";file << Contact_Arr[j].district;
        file << '\n';
        file << "Postcode: "; file << Contact_Arr[j].postcode;
        file << '\n';
        file << "E-mail address: "; file << Contact_Arr[j].e_mail;
        file << '\n';
        j++;
    }

    file.close();

    cout << "You are blessed";
    return 0;
}