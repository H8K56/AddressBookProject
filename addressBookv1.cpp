/**
 * @file addressBookv1.cpp
 * @author Hussein Khadra
 * @brief A simple address book program holding five contacts
 * @version 0.1
 * @date 2023-03-03
 * @copyright MIT LISENcE 2023
 * 
 */

#include <iostream>
#include <string>

using namespace std;

/**
 * @brief A struct holding five contact variables
 * 
 */
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
    string Combined_Contact1,Combined_Contact2,Combined_Contact3,Combined_Contact4,Combined_Contact5;
    
    int updateContact,findContact,removeContact,option,userInput,count = 0;
    /**
     * "Name: "+ first + "," + last + ",Tele: " + telephone + ",Address: " + street + "," + city + "," + district + "," + postcode + ",email: " + e_mail;
     * 
     */
    //array to store all contacts
    string contact_arr[5];
    
    do
    {
        displayMenu();
        cin >> option;
        
        switch(option)
        {
            case 1:
            {
                cout << "First name: "; cin >> first;
                cout << "Last name: "; cin >> last;
                cout << "telephone: "; cin >> telephone;
                cout << "Street name: "; cin >> street;
                cout << "City: \n"; cin >> city;
                cout << "District: \n"; cin >> district;
                cout << "Postcode: "; cin >> postcode;
                cout << "E-mail address: "; cin >> e_mail;
                count++;
                
                if(count == 1)
                {Combined_Contact1 = "Name: "+ first + "," + last + ",Tele: " + telephone + ",Address: " + street + "," + city + "," + district + "," + postcode + ",email: " + e_mail;Contact1.contact = Combined_Contact1;contact_arr[0] = Contact1.contact;}
                else if(count == 2)
                {Combined_Contact2 = "Name: "+ first + "," + last + ",Tele: " + telephone + ",Address: " + street + "," + city + "," + district + "," + postcode + ",email: " + e_mail;Contact2.contact = Combined_Contact2;contact_arr[1] = Contact2.contact;}
                else if(count == 3)
                {Combined_Contact3 = "Name: "+ first + "," + last + ",Tele: " + telephone + ",Address: " + street + "," + city + "," + district + "," + postcode + ",email: " + e_mail;Contact3.contact = Combined_Contact3;contact_arr[2] = Contact3.contact;}
                else if(count == 4)
                {Combined_Contact4 = "Name: "+ first + "," + last + ",Tele: " + telephone + ",Address: " + street + "," + city + "," + district + "," + postcode + ",email: " + e_mail;Contact4.contact = Combined_Contact4;contact_arr[3] = Contact4.contact;}
                else if(count == 5)
                {Combined_Contact5 = "Name: "+ first + "," + last + ",Tele: " + telephone + ",Address: " + street + "," + city + "," + district + "," + postcode + ",email: " + e_mail;Contact5.contact = Combined_Contact5;contact_arr[4] = Contact5.contact;}
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

                    Contact1.contact = Combined_Contact1; 
                    contact_arr[0] = Contact1.contact;
                    cout << contact_arr[0] << '\n';
                }else if(updateContact == 2)
                {
                    cout <<"Contact 2: "<< Contact2.contact << '\n';
                    
                    cout << "First name: "; cin >> first;
                    cout << "Last name: "; cin >> last;
                    cout << "telephone: "; cin >> telephone;
                    cout << "Street name: "; cin >> street;
                    cout << "City: "; cin >> city;
                    cout << "\nDistrict: "; cin >> district;
                    cout << "Postcode: "; cin >> postcode;
                    cout << "E-mail address: "; cin >> e_mail;

                    Contact2.contact = Combined_Contact2; 
                    contact_arr[1] = Contact2.contact;

                    cout << contact_arr[1] << '\n';
                }else if(updateContact == 3)
                {
                    cout <<"Contact 3: "<< Contact3.contact << '\n';
                    
                    cout << "First name: "; cin >> first;
                    cout << "Last name: "; cin >> last;
                    cout << "telephone: "; cin >> telephone;
                    cout << "Street name: "; cin >> street;
                    cout << "City: "; cin >> city;
                    cout << "\nDistrict: "; cin >> district;
                    cout << "Postcode: "; cin >> postcode;
                    cout << "E-mail address: "; cin >> e_mail;

                    Contact3.contact = Combined_Contact3; 
                    contact_arr[2] = Contact3.contact;

                    cout << contact_arr[2] << '\n';
                }else if(updateContact == 4)
                {
                    cout <<"Contact 4: "<< Contact4.contact << '\n';
                    
                    cout << "First name: "; cin >> first;
                    cout << "Last name: "; cin >> last;
                    cout << "telephone: "; cin >> telephone;
                    cout << "Street name: "; cin >> street;
                    cout << "City: "; cin >> city;
                    cout << "\nDistrict: "; cin >> district;
                    cout << "Postcode: "; cin >> postcode;
                    cout << "E-mail address: "; cin >> e_mail;

                    Contact4.contact = Combined_Contact4; 
                    contact_arr[3] = Contact4.contact;

                    cout << contact_arr[3] << '\n';
                }else if(updateContact == 5)
                {
                    cout <<"Contact 5: "<< Contact5.contact << '\n';
                    
                    cout << "First name: "; cin >> first;
                    cout << "Last name: "; cin >> last;
                    cout << "telephone: "; cin >> telephone;
                    cout << "Street name: "; cin >> street;
                    cout << "City: "; cin >> city;
                    cout << "\nDistrict: "; cin >> district;
                    cout << "Postcode: "; cin >> postcode;
                    cout << "E-mail address: "; cin >> e_mail;

                    Contact5.contact = Combined_Contact5; 
                    contact_arr[4] = Contact5.contact;

                    cout << contact_arr[4] << '\n';
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
                int chosenContact;
                cout << "(1) to display all contacts or (2) chose a contact to display.\n";
                cin >> chosenContact;

                if(chosenContact == 1)
                {
                    for(int i = 0;i < count;i++)
                    {
                        cout << contact_arr[i] << '\n';
                    }
                }else if(chosenContact == 2)
                {
                    cout << "Enter contact number: "<<'\n';
                    int contactChoice;
                    cin >> contactChoice;
                    cout << contact_arr[contactChoice - 1] << '\n';
                }
                break;
            }
        }
    }while(option != 5);

    cout << "You are blessed";
    return 0;
}