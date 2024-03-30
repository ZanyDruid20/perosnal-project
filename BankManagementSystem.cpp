// BankManagementSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>
using namespace std;
//const char all = 999;
char all[999];
void menu();

class ManageMenu {
protected:
    string userName;
public:
    ManageMenu() {
        cout << "\\n\n\n\n\n\n\n\n\t Enter your name to continue as Admin: ";
        cin >> userName;
        system("CLS");
        menu();
    }
    ~ManageMenu() {
        
    }
};
class Customers {
public:
    void SetName(string Name) {
        m_name = Name;
    }
    void SetAge(int Age) {
        m_Age = Age;
    }
    void SetAddress(string Address) {
        m_Address = Address;
    }
    void SetMobileNum(int MobileNum) {
        m_mobileNum = MobileNum;
    }
    void  SetCustomerID(int customerID) {
        m_customerID = customerID;
    }
    string GetName() {
        return m_name;
    }
    int GetAge() {
        return m_Age;
    }
    string GetAddress() {
        return  m_Address;
    }
    int GetMobileNum() {
        return m_mobileNum;
    }
    int GetCustomerID() {
        return m_customerID;
    }
    void Details() {
        ofstream outputFile("old-customers.txt", ios::app);
        {
            cout << "Enter cutomer ID: ";
            cin >> m_customerID;
            cout << "Enter Name: ";
            cin >> m_name;
            cout << "Enter Age: ";
            cin >> m_Age;
            cout << "Address: ";
            cin >> m_Address;
            cout << "Mobile Number: ";
            cin >> m_mobileNum;

        }
        outputFile << "Customer ID: " << m_customerID << endl;
        outputFile << "Name: " << m_name << endl;
        outputFile << "Age: " << m_Age << endl;
        outputFile << "Address: " << m_Address << endl;
        outputFile << "Mobile Number: " << m_mobileNum << endl;
        outputFile << "_________________________________________" << endl;
        outputFile << "We have saved your details, now creating your account" << endl;
        outputFile.close();
       
        
    }
    void ShowDetails() {
        ifstream inputStream("old-customers.txt");
        if (!inputStream.is_open()) {
            cerr << "File not Open" << endl;
            return;
        }
        while (!inputStream.eof()) {
            inputStream.getline(all, 999);
            cout << all << endl;
        }
        inputStream.close();
    }

private:
    string m_name;
    int m_Age;
    string m_Address;
    int m_mobileNum;
    static int m_customerID;

};
int Customers::m_customerID = 0;

class Cars {
public:
    int CabChoice;
    float Kilometres;
    float Cost;
    static float LastCost;
    void cabDetails() {
        cout << "We collborate with the fastest cars to satisfy your needs" << endl;
        cout << "-------------------ABC----------------\n" << endl;
        cout << "1. Rent a standard car - $10 for 1KM" << endl;
        cout << "2. Rent a luxury car - $50 for 1KM" << endl;

        cout << "\n To calculate the cost of your journey" << endl;
        cout << "Enter which cab you need: ";
        cin >> CabChoice;
        cout << "Enter Kilometres you have to travel: ";
        cin >> Kilometres;
        int hireACar;
        if (CabChoice == 1) {
            Cost = Kilometres * 10,0;
            cout << "Your tour cost " << Cost << " dollars for a standard car" << endl;
            cout << "Press 1 to hire this Car or";
            cout << " Press 2 to select another car" << endl;
            cin >> hireACar;
            system("CLS");
            if (hireACar == 1) {
                LastCost = Cost;
                cout << "Wow you've hired a Car" << endl;
                cout << "Return to the menu to take your receipt" << endl;
            }
            else if (hireACar == 2) {
                cabDetails();
            }
            else {
                cout << "Invalid Input, Redirecting to menu" << endl;
                cout << "Please Wait" << endl;
                Sleep(999);
                system("CLS");
                cabDetails();
            }
        }
        else if (CabChoice == 2) {
            Cost = Kilometres * 50.00;
            cout << "Your tour cost " << Cost << " dollars for a standard car" << endl;
            cout << "Press 1 to hire this Car or";
            cout << " Press 2 to select another car" << endl;
            cin >> hireACar;
            system("CLS");
            if (hireACar == 1) {
                LastCost = Cost;
                cout << "Wow you've hired a Car" << endl;
                cout << "Return to the menu to take your receipt" << endl;
            }
            else if (hireACar == 2) {
                cabDetails();
            }
            else {
                cout << "Invalid Input, Redirecting to menu" << endl;
                cout << "Please Wait" << endl;
                Sleep(1100);
                system("CLS");
                cabDetails();
            }

        }
        else {
            cout << "Pls return to main menu" << endl;
            Sleep(1100);
            system("CLS");
            cabDetails();
        }
        cout << "Press 1 to go back to main menu" << endl;
        cin >> hireACar;
        system("CLS");
        if (hireACar == 1) {
            menu();
        }
        else {
            menu();
        }
    }
};
float Cars::LastCost;

class Booking {
public:
    int choiceHotel;
    int packChoice;
    static float HotelCost;
    void hotels() {
        string HotelNo[] = { "Marriot","Sheraton","Holiday Inn" };
        for (int i = 0; i < 3; i++) {
            cout << i + 1 << ". Hotel " << HotelNo[i] << endl;
        }
        cout << "Currently we collaborate with these Hotels" << endl;
        cout << "Press any key to go back \n or Enter the number of hotel you want to book: ";
        cin >> choiceHotel;
        system("CLS");
        if (choiceHotel == 1) {
            cout << "-----------WELCOME TO MARRIOT HOTELS-----------\n" << endl;
            cout << "The garden, the sun ,food and beverage, stay chilled while in the sun" << endl;
            cout << "Packages offered by Marriot Includes " << endl;
            cout << "1. Standard Package" << endl;
            cout << "All the basic facilities for : $1000" << endl;
            cout << "2. Premium Package" << endl;
            cout << "Enjoy Premium: $1800" << endl;
            cout << "3. Luxury Package" << endl;
            cout << "Enjoy the Luxury: $2500" << endl;

            cout << "Press another key to go back or \n Enter Package Number" << endl;
            cin >> packChoice;

            if (packChoice == 1) {
                HotelCost = 1000;
                cout << "You have successfully purchased the standard ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else if (packChoice == 2) {
                HotelCost = 1800;
                cout << "You have successfully purchased the premium ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else if (packChoice == 3) {
                HotelCost = 2500;
                cout << "You have successfully purchased the luxury ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else {
                cout << "Invalid input, Redirecting to menu" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotoHotels;
            cout << "Press 1 to go back" << endl;
            cin >> gotoHotels;
            if (gotoHotels == 1) {
                menu();
               // hotels();
            }
            else {
                menu();
                //hotels();
            }
        }
        else if (choiceHotel == 2) {
            cout << "-----------WELCOME TO SHERATON HOTELS-----------\n" << endl;
            cout << "The garden, the sun ,food and beverage, stay chilled while in the sun" << endl;
            cout << "Packages offered by Marriot Includes " << endl;
            cout << "1. Standard Package" << endl;
            cout << "All the basic facilities for : $1200" << endl;
            cout << "2. Premium Package" << endl;
            cout << "Enjoy Premium: $1800" << endl;
            cout << "3. Luxury Package" << endl;
            cout << "Enjoy the Luxury: $2500" << endl;

            cout << "Press another key to go back or \n Enter Package Number" << endl;
            cin >> packChoice;

            if (packChoice == 1) {
                HotelCost = 1200;
                cout << "You have successfully purchased the standard ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else if (packChoice == 2) {
                HotelCost = 1800;
                cout << "You have successfully purchased the premium ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else if (packChoice == 3) {
                HotelCost = 2500;
                cout << "You have successfully purchased the luxury ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else {
                cout << "Invalid input, Redirecting to menu" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotoHotels;
            cout << "Press 1 to go back" << endl;
            cin >> gotoHotels;
            if (gotoHotels == 1) {
                //hotels();
                menu();
            }
            else {
                //hotels();
                menu();
            }
        }
        else if (choiceHotel == 3) {
            cout << "-----------WELCOME TO HOLIDAY INN----------\n" << endl;
            cout << "The garden, the sun ,food and beverage, stay chilled while in the sun" << endl;
            cout << "Packages offered by Marriot Includes " << endl;
            cout << "1. Standard Package" << endl;
            cout << "All the basic facilities for : $1500" << endl;
            cout << "2. Premium Package" << endl;
            cout << "Enjoy Premium: $1800" << endl;
            cout << "3. Luxury Package" << endl;
            cout << "Enjoy the Luxury: $2500" << endl;

            cout << "Press another key to go back or \n Enter Package Number" << endl;
            cin >> packChoice;

            if (packChoice == 1) {
                HotelCost = 1500;
                cout << "You have successfully purchased the standard ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else if (packChoice == 2) {
                HotelCost = 2200;
                cout << "You have successfully purchased the premium ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else if (packChoice == 3) {
                HotelCost = 3000;
                cout << "You have successfully purchased the luxury ticket" << endl;
                cout << "Please take your receipt" << endl;
            }
            else {
                cout << "Invalid input, Redirecting to menu" << endl;
                Sleep(1100);
                system("CLS");
                hotels();
            }
            int gotoHotels;
            cout << "Press 1 to go back" << endl;
            cin >> gotoHotels;
            if (gotoHotels == 1) {
                menu();
                //hotels();
            }
            else {
                //hotels();
                menu();
            }
        }
    }
};

float Booking::HotelCost;

class Charges : public Customers, Cars, Booking {
public:
    void printBill() {
        ofstream out("receipt.txt");
        {
            cout << "---------ENIGMA ESCAPES--------" << endl;
            cout << "----------RECEIPT--------------" << endl;
            cout << "_______________________________" << endl;
            cout << "Customer ID: " << Customers::GetCustomerID() << endl << endl;
            cout << "Description, Total " << endl;
            cout << "Hotel Cost: " << fixed << setprecision(2) << Booking::HotelCost << endl;
            cout << "Travel (car) cost" << fixed << setprecision(2) << Cars::LastCost << endl;

            cout << "__________________________________________" << endl;
            cout << "Total Charge: " << fixed << setprecision(2) << Booking::HotelCost + Cars::LastCost << endl;
            cout << "__________________________________________" << endl;
            cout << "________________THANK YOU_________________" << endl;
        }
        out.close();
    }
    void showBill() {
        ifstream inputstream("receipt.txt");
        if (!inputstream.is_open()) {
            cout << "File not opened" << endl;

        }
        while (!(inputstream.eof())) {
            inputstream.getline(all, 999);
            cout << all << endl;
        }
        inputstream.close();
        
    }
};
void menu() {
    int mainChoice;
    int inChoice;
    int gotoMenu;

    cout << "---------ENIGMA ESCAPES--------" << endl;
    cout << "---------Main Menu-------------" << endl;
    cout << "\t_____________________________" << endl;
    cout << "|Customer Management -> 1|" << endl;
    cout << "|Cars Management -> 2|" << endl;
    cout << "Bookings Management -> 3" << endl;
    cout << "|Charges bill -> 4|" << endl;
    cout << "|Exit  -> 5|" << endl;
    cout << "\t|\t\t\t\t|" << endl;
    cout << "\t|______________________|" << endl;
    cout << "Enter your choice: ";
    cin >> mainChoice;
    system("CLS");
    Customers A1;
    Cars A2;
    Booking A3;
    Charges A4;
    if (mainChoice == 1) {
        cout << "--------Customers------" << endl;
        cout << "Enter New Customers" << endl;
        cout << "See Old Customers" << endl;
        cout << "Enter Choice: ";
        cin >> inChoice;
        system("CLS");
        if (inChoice == 1) {
            A1.Details();
        }
        else if (inChoice == 2) {
            A1.ShowDetails();
        }
        else {
            cout << "Invalid input, Redirecting to menu" << endl;
            Sleep(1100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to go back " << endl;
        cin >> gotoMenu;
        if (gotoMenu == 1) {
            menu();
        }
        else {
            menu();
        }


    }
    else if (mainChoice == 2) {
        A2.cabDetails();
    }
    else if (mainChoice == 3) {
        cout << "Booka Hotel Using the System" << endl;
        A3.hotels();
    }
    else if (mainChoice == 4) {
        cout << "Get Your Receipt" << endl;
        A4.printBill();
        cout << "Your receipt has been printed you can get it now" << endl;
        cout << "To display your screen, press 1: or Enter another key to go back to main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1) {
            system("CLS");
            A4.showBill();
            cout << "Press 1 to go to main menu" << endl;
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1) {
                menu();
            }
            else {
                menu();
            }
        }
        else {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 5) {
        cout << "THANK YOU, GOOD BYE" << endl;
        Sleep(999);
        system("CLS");
       // menu();
        
    }
}
int main()
{
    cout << "Hello World!" << endl;
    ManageMenu startObj;
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
