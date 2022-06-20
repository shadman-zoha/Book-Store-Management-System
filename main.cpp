
//Name: MD SHADMAN ZOHA
//Matric No: B031910480
//BITS,S1G1
#include<iostream>

#include<conio.h>
#include<fstream>
#include<string>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<windows.h>
#include<mysql.h>
#include<iomanip>


using namespace std;
void signUp();
bool loginFile();
void admin();
void user();
void adminViewProduct();
void AddItem();
void UpdateItem();
void DeleteItem();
void Promotion();
void exit();
void CustomerInfo();
void makePurchase();
void searchProduct();
void addCart();
void deleteCart();
void adminlogin();
void userViewProduct();
void userlogin();
void mainpage();


int qstate;
MYSQL* conn;
MYSQL_ROW row;
MYSQL_RES* res;
string customerid;
int pRomotion;
int qUantity;
string PurchaseId;

MYSQL* connectdatabase()
{
    MYSQL* conn;
    conn = mysql_init(0);

    conn = mysql_real_connect(conn, "localhost", "root", "", "bdbsms", 3306, NULL, 0);

    if (conn)
    {
        cout << "Databse Connected Successfully" << conn << endl;
        return conn;
    }
    else
    {
        cout << "Failed To Connet With Databse" << mysql_errno(conn) << endl;
        return conn;
    }
}


int main()
{
    system("Color E4");
        string a= "WELCOME TO OUR BOOKSTORE";
        int x = 0;
        while (a[x] != '\0')
        {
            cout << endl;
            cout << std::setw(310) << a[x];
            Sleep(250);
            x++;
        };
        mainpage();
    
   
}

void mainpage()
{
    system("CLS");
    MYSQL* conn = connectdatabase();
    
    system("Color E4");
    cout << setw(155) << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "|                                   Book Store Management System                                             |" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;

    cout << setw(155) << "__________________________________________Welcome To The Shop_________________________________________________" << endl;


    cout << setw(83) << "==> Please Choose any option to Login:" << endl;
    cout << setw(155) << "--------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. Admin                                                                                                   |" << endl;
    cout << setw(155) << "| 2. Customer                                                                                                |" << endl;
    cout << setw(155) << "| 0. Exit                                                                                                    |" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------\n\n" << endl;

    string choice;
    cout << setw(60) << "==> Your Choice:";

    cin >> choice;

    if (choice == "2") {
        user();
    }
    else if (choice == "1") {
        admin();
    }
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(115) << "Worng Keyword !! Please Try again" << endl;
        _getch();
        mainpage();
    }

}


void signUp() {
    {
        MYSQL* conn = connectdatabase();


        int qstate = 0;
        stringstream ss;
        string username, password, name, email, phone;
        system("CLS");

        cout << setw(170) << endl << endl << "__________________________________________Please Fill Up This Form For Registration _________________________________________________" << endl << endl << endl;
        getline(cin, name);

        cout << setw(80) << "Please Enter Your Full Name :";
        getline(cin, name);
        cout << setw(80) << "Please Enter Your Email Address :";
        getline(cin, email);
        cout << setw(80) << "Please Enter Your Current Phone Number :";
        getline(cin, phone);
        cout << setw(80) << "Please Create a Username :";
        getline(cin, username);
        cout << setw(80) << "Please Make a Password :" ;
        getline(cin, password);

        ss << "INSERT INTO customer(CustomerName,CustomerEmail,PhoneNumber,UserName,UserPassword)VALUES('" + name + "','" + email + "','" + phone + "','" + username + "','" + password + "')";
        string query = ss.str();
        const char* q = query.c_str();
        qstate = mysql_query(conn, q);
        if (qstate == 0)
        {
            cout << endl << endl << setw(115) << "Record Inserted To DataBase" << endl << endl;
            cout << setw(120) << "Press Enter To Go To The User Login Page. ";
            _getch();
            user();
        }
        else {
            cout << setw(80) << "Failed to Insert The Information Into Database" << endl << endl;
            cout << setw(120) << "Press Enter To Go To The User Login Page.";
            _getch();
            user();
        }


    }
}



bool loginFile()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    stringstream ss;
    string username, password;
    system("CLS");
    system("CLS"); 
    cout << setw(155) << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "|                                   Book Store Management System                                             |" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;

    cout << setw(155) << "_____________________________________Welcome To Customer Login Page___________________________________________" << endl << endl;
    getline(cin, username);
    cout << setw(75) << "Please Enter Your Username :";
    getline(cin, username);
    
    cout << setw(75) << "Please Enter Your Password :";
    getline(cin, password);

    ss << "select * from customer where UserName = '" + username + "' and UserPassword = '" + password + "'";
    string query = ss.str();
    const char* qn = query.c_str();
    qstate = mysql_query(conn, qn);


    if (qstate==0)
    {
        res = mysql_store_result(conn);
        if ((row = mysql_fetch_row(res)))
        {
            customerid = row[0];
            userlogin();
        }
        else
        {
            cout << setw(115) << endl << "Wrong Username Or Password. Please Try Again" << endl;
            _getch();
            system("CLS");
            loginFile();

        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        _getch();
        system("CLS");
        loginFile();

    }



}

void userlogin()
{
    system("CLS");
    cout << setw(110) << endl << endl << "Logged in sucessfully!" << endl << endl;
    cout << setw(157) << "___________________________________________________Welcome To Customer____________________________________________" << endl << endl << endl;


    cout << setw(157) << "===================================================================================================================" << endl;
    cout << setw(157) << "|                                                    Main Menu                                                    |" << endl;
    cout << setw(157) << "===================================================================================================================" << endl;

    cout << setw(71) << "==> Please Choose any option:" << endl;
    cout << setw(157) << "-------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(157) << "| 1. View Product                                                                                                 |" << endl;
    cout << setw(157) << "| 2. Make Purchase                                                                                                |" << endl;
    cout << setw(157) << "| 3. Search Product                                                                                               |" << endl;
    cout << setw(157) << "| 4. Add to cart                                                                                                  |" << endl;
    cout << setw(157) << "| 5. Delete from cart                                                                                             |" << endl;
    cout << setw(157) << "| 0. Exit                                                                                                         |" << endl;
    cout << setw(157) << "-------------------------------------------------------------------------------------------------------------------" << endl;

    string choice;
    cout << setw(58) << "==> Your Choice:";

    cin >> choice;
    if (choice == "1") {
        userViewProduct();
    }
    else if (choice == "2") {
        makePurchase();
    }
    else if (choice == "3") {
        searchProduct();
    }
    else if (choice == "4") {
        addCart();
    }
    else if (choice == "5") {
        deleteCart();
    }
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(115) << "Worng Keyword !! Please Try again" << endl;
        _getch();
        userlogin();
    }

    

}


void admin()
{
    system("CLS");
    cout << setw(155) << endl << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "|                                   Book Store Management System                                             |" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;

    cout << setw(155) << "_____________________________________Welcome To Admin Login Page______________________________________________" << endl << endl;

    string Dname = "zoha";
    string name;
    string Dpass = "123";
    string pass;
    cout << setw(83) << "Please Enter Username and Password:" << endl;
     getline(cin, name);
    cout << setw(83) << "Username :";
    getline(cin, name);
    cout << setw(83) << "Passeord :";
    getline(cin, pass);

    if (name == Dname && pass == Dpass) {

        adminlogin();
        
    }
    else {
        cout << setw(120) << endl << endl << "Wrong Username or Password!! Please try again." << endl;

        _getch();
        admin();

    }

}

void adminlogin()
{
    system("CLS");
    cout << setw(108) << endl << endl << "Successfully Lgoin" << endl;

    cout << setw(155) << endl << endl << "___________________________________________________Welcome To ADMIN_________________________________________________" << endl;


    cout << setw(155) << "====================================================================================================================" << endl;
    cout << setw(155) << "|                                                       Main Menu                                                  |" << endl;
    cout << setw(155) << "====================================================================================================================" << endl;

    cout << setw(70) << "==> Please Choose any option:" << endl;
    cout << setw(155) << "--------------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. View Product                                                                                                  |" << endl;
    cout << setw(155) << "| 2. Add Item                                                                                                      |" << endl;
    cout << setw(155) << "| 3. Update Item                                                                                                   |" << endl;
    cout << setw(155) << "| 4. Delete Item                                                                                                   |" << endl;
    cout << setw(155) << "| 5. Promotion                                                                                                     |" << endl;
    cout << setw(155) << "| 6. Customer Information                                                                                          |" << endl;
    cout << setw(155) << "| 0. Exit                                                                                                          |" << endl;
    cout << setw(155) << "--------------------------------------------------------------------------------------------------------------------" << endl << endl << endl;

    string choice;
    cout << setw(55) << "==> Your Choice:";

    cin >> choice;

    if (choice == "1") {
        adminViewProduct();
    }
    else if (choice == "2") {
        AddItem();
    }
    else if (choice == "3") {
        UpdateItem();
    }
    else if (choice == "4") {
        DeleteItem();
    }
    else if (choice == "5") {
        Promotion();
    }
    else if (choice == "6") {
        CustomerInfo();
    }
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(120) << "Worng Keyword !! Please Try again" << endl;
        _getch();
        adminlogin();
    }


}

void user()
{
  
    system("CLS");
    cout << setw(155) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "|                                   Book Store Management System                                             |" << endl;
    cout << setw(155) << "|                                                                                                            |" << endl;
    cout << setw(155) << "``````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
    cout << setw(155) << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;
    cout << setw(155) << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;

    

    cout << setw(155) << "_______________________________________Welcome To User Login Page______________________________________________" << endl << endl << endl;

    cout << setw(72) << "==> Please Choose any option:" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. Registration                                                                                              |" << endl;
    cout << setw(155) << "| 2. Login                                                                                                     |" << endl;
    cout << setw(155) << "| 0. Exit                                                                                                      |" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;

    string choice;
    cout << setw(60) << "==> Your Choice:";

    cin >> choice;

    if (choice == "1") {
        signUp();
    }
    else if (choice == "2") {
        loginFile();
    }
    
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(120) << "Worng Keyword !! Please Try again" << endl;
        _getch();
        user();
    }


}

void exit()
{
    MYSQL* conn = connectdatabase();
    string choice;
    int qstate = 0;
    system("CLS");
   

        cout << endl << endl << endl << setw(135) << "Are You Sure You Want To Exit From This System or GO TO The Main Login Page?" << endl << endl << endl << setw(100) << "[1]Yes" << endl << setw(99) << "[2]No" << endl << endl << endl << setw(100) << "Your choice : ";
        cin >> choice;

        if (choice == "1") {
            stringstream ss;
            ss << "DELETE FROM cart";

            string query = ss.str();
            const char* qia = query.c_str();
            qstate = mysql_query(conn, qia);

            cout << endl << endl << setw(135) << "Thank You For Using Our Book Store System. Please Come Again!!!!!" << endl << endl << endl;
            _getch();
            exit(0);
           
        }
        else if (choice == "2") {
            mainpage();
        }
        else {
            cout << setw(120) << "Wrong Input!! Please Try Again." << endl;
            
            exit();
        }
  
    
   
}

void adminViewProduct()
{
    
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    system("cls");
    cout << endl << endl << setw(120) << "The Available Book Information In The Bookstore" << endl << endl;
    qstate = mysql_query(conn, "select * from bookinfo");
    if (qstate==0)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
            cout << setw(100) << "ISBN: " << row[0] << endl << setw(100) << "AUTHORNAME: " << row[1] << endl << setw(100) << "BOOKTITLE: " << row[2] << endl << setw(100) << "YEAR: " << row[3] << endl << setw(100) << "PRICE: " << row[4] << endl << setw(100) << "BOOKQUANTITY: " << row[5] << endl << endl;
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl << endl << endl;
            
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        system("cls");
        adminlogin();
    }
    cout << setw(72) << "==> Please Choose any option:" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. Admin Login Page                                                                                          |" << endl;
    cout << setw(155) << "| 0. Exit                                                                                                      |" << endl;

    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
    string choice;
    cout << setw(60) << "==> Your Choice:";

    cin >> choice;

    if (choice == "1") {
        adminlogin();
    }
    
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(120) << "Worng Keyword !! Please Try again" << endl;
        _getch();
        adminViewProduct();
    }
    
}

void userViewProduct()
{

    MYSQL* conn = connectdatabase();
    int qstate = 0;
    system("cls");
    cout << endl << endl << setw(120) << "The Available Book Information In The Bookstore" << endl << endl;
    qstate = mysql_query(conn, "select * from bookinfo");
    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
            cout << setw(100) << "ISBN: " << row[0] << endl << setw(100) << "AUTHORNAME: " << row[1] << endl << setw(100) << "BOOKTITLE: " << row[2] << endl << setw(100) << "YEAR: " << row[3] << endl << setw(100) << "PRICE: " << row[4] << endl << setw(100) << "BOOKQUANTITY: " << row[5] << endl << endl;
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl << endl << endl;

        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
        system("cls");
        userlogin();
    }
    cout << setw(72) << "==> Please Choose any option:" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. User Login Page                                                                                           |" << endl;
    cout << setw(155) << "| 0. Exit                                                                                                      |" << endl;

    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
    string choice;
    cout << setw(60) << "==> Your Choice:";

    cin >> choice;

    if (choice == "1") {
        userlogin();
    }
    
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(120) << "Worng Keyword !! Please Try again" << endl;
        _getch();
        userViewProduct();
    }

}

void CustomerInfo()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    system("CLS");
    cout << endl << endl << setw(120) << "All The Information About Recorded Customer:" << endl << endl;
    qstate = mysql_query(conn, "select * from customer");
    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {

            
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
            cout << setw(100) << "CUSTOMER ID   : " << row[0] << endl << setw(100) << "CUSTOMER NAME : " << row[1] << endl << setw(100) << "CUSTOMER EMAIL: " << row[2] << endl << setw(100) << "PHONE NUMBER  : " << row[3] << endl << setw(100) << "USER NAME     : " << row[4] << endl << setw(100) << "USER PASSWORD : " << row[5] <<  endl << endl;
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
           
        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }


    cout << setw(72) << "==> Please Choose any option:" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. Admin Login Page                                                                                          |" << endl;
    cout << setw(155) << "| 0. Exit                                                                                                      |" << endl;

    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
    string choice;
    cout << setw(60) << "==> Your Choice:";

    cin >> choice;

    if (choice == "1") {
        adminlogin();
    }
    
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(120) << "Worng Keyword !! Please Try again" << endl;
        _getch();
        CustomerInfo();
    }

}


void AddItem()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    stringstream ss;
    string ISBN, booktitle, authorname;
    string year;
   string bookquantity;
    string price;
    system("CLS");
    cout << endl << endl << setw(125) << "Please Insert All The Infromation About Book :" << endl << endl;
    getline(cin, ISBN);
    


    cout << setw(80) << "Enter ISBN For The Book: ";
    getline(cin, ISBN);

    cout << setw(80) << "Enter BookTitle : ";
    getline(cin,booktitle);

    cout << setw(80) << "Enter Author Name : ";
    getline(cin, authorname);

    cout << setw(80) << "Enter Publication Year : ";
    getline(cin, year);

    cout << setw(80) << "Enter Book Price: ";
    getline(cin, price);

    cout << setw(80) << "Enter Book Quantity: ";
    getline(cin,bookquantity);
  
   

        ss << "INSERT INTO bookinfo(ISBN,AuthorName,BookTitle,Year,Price,BookQuantity)VALUES('" + ISBN + "','" + authorname + "','" + booktitle + "','" + year + "','" + price + "','" + bookquantity + "')";
        string query = ss.str();
        const char* qm = query.c_str();
        qstate = mysql_query(conn, qm);
        if (qstate == 0)
        {
            cout << endl << endl << setw(122) << "Record Inserted Sucessfully In Database "<<endl;
            
            
        }
        else {
            cout << endl << endl << setw(122) << "Failed To Insert Into Databse" << endl;
            cout << setw(124) << "Worng Keyword!! Please Try Again "<<endl;
            
            
        }

    
    cout << setw(72) << "==> Please Choose any option:" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. Admin Login Page                                                                                          |" << endl;
    cout << setw(155) << "| 2. Add Again                                                                                                 |" << endl;
    cout << setw(155) << "| 0. Exit                                                                                                      |" << endl;

    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
    string choice;
    cout << setw(60) << "==> Your Choice:";

    cin >> choice;

    if (choice == "1") {
        adminlogin();
    }

    else if (choice == "2") {
        AddItem();
    }
    else if (choice == "0") {
        exit();
    }
    else {
        cout << endl << endl << setw(120) << "Worng Keyword !! Please Try again" << endl;
        cout << endl << endl << setw(120) << "Press any key to go to admin main menu." << endl;
        _getch();
        adminlogin();
    }

}
    

void UpdateItem()
{
    MYSQL* conn = connectdatabase();
    

    string updateISBN, choice;


    string ISBN, author, title, year, price, quantity;
    bool HaveException = false;
    bool NotInDatabase = false;
    int indexForISBN = 0;

    string bookISBN = "";
    string bookauthorname = "";
    string booktitle = "";
    
    string bookyear = "";

    string bookprice = "";
    string bookquantity = "";
    system("CLS");
    cout << endl << setw(155) << " ********************************************************************************************************************** " << endl;
    cout << setw(155) << " *********************************************** *** UPDATE PRODUCT *** *********************************************** " << endl;
    cout << setw(155) << " ********************************************************************************************************************** " << endl << endl;


    while (1) {
       

        try
        {
            cout << endl;
            cout << setw(80) << "Enter ISBN: ";
            cin >> ISBN;
            cout << endl;
        }
        catch (exception e)
        {
            cout << setw(120) << "Please Enter a valid ISBN." << endl;
            HaveException = true;
            system("CLS");
        }

        if (HaveException == false)
        {
            stringstream streamid;
            string strid;
            streamid << ISBN;
            streamid >> strid;


            if (NotInDatabase == false)
            {
                string findbyid_query = "select * from bookinfo where ISBN = '" + ISBN + "'";
                const char* qi = findbyid_query.c_str();
                qstate = mysql_query(conn, qi);

                if (!qstate)
                {
                    int found = 0;
                    res = mysql_store_result(conn);
                    cout << endl;
                    while ((row = mysql_fetch_row(res)))
                    {
                        system("CLS");
                        cout <<endl<< setw(120) << "You can change your book information below:" << endl;
                        found = 1;
                        cout << endl << setw(100) << "ISBN: " << row[0] << endl << setw(100) << "AUTHOR: " << row[1] << endl << setw(100) << "Title: " << row[2] << endl << setw(100) << "Year: " << row[3] << endl << setw(100) << "Price: " << row[4] << endl << setw(100) << "Quantity: "<< row[5]  << endl << endl;

                        bookauthorname = row[1];
                        booktitle = row[2];
                        bookyear = row[3];

                        bookprice = row[4];
                        bookquantity = row[5];

                    }
                    if (found == 0) {
                        cout << setw(120) << "The Book Is Not Found In Database. Please use a valid ISBN ." << endl;
                        _getch();
                        continue;
                    }
                }
                else
                {
                    cout << setw(120) << "Query Execution Problem!" << mysql_errno(conn) << endl;
                }

                cin.ignore(1, '\n');

                cout << setw(100) << "Enter Author (N to not change): ";
                getline(cin, author);
                if (author == "N" )
                {
                    author = bookauthorname;
                }

                cout << setw(100) << "Enter Title (N to not change): ";
                getline(cin, title);
                if (title == "N" )
                {
                    title = booktitle;
                }
                
               
                cout << setw(100) << "Enter Year (N to not change): ";
                getline(cin, year);
                if (year == "N" )
                {
                    year = bookyear;
                }
                cout << setw(100) << "Enter Price (N to not change): ";
                getline(cin, price);
                if (price == "N" )
                {
                    price = bookprice;
                }
                cout << setw(100) << "Enter Quantity (N to not change): ";
                getline(cin, quantity);
                if (quantity == "N")
                {
                    quantity = bookquantity;
                }

                
                string update_query = "update bookinfo set AuthorName='" + author + "', BookTitle='" + title + "', Year ='" + year + "', Price ='" + price + "', BookQuantity ='" + quantity + "' where ISBN='" + ISBN + "'";
                const char* qu = update_query.c_str();
                qstate = mysql_query(conn, qu);


                if (!qstate)
                {
                    cout << endl << setw(120) << "The New Information Of Book Successfully Saved In Database!" << endl;
                }
                else
                {
                    cout << setw(120) << "Failed To Update Into Databse ! Please Try Again." << mysql_errno(conn) << endl;
                }


             

                    cout << endl << setw(120) << "Do you want to update again?" << endl << setw(100) << "[1]Yes" << endl << setw(99) << "[2]No" << endl << setw(100) << "Your choice : ";
                    cin >> choice;

                    if (choice == "1") {
                        UpdateItem();
                    }
                    else if (choice == "2") {
                        adminlogin();
                    }
                    else  {
                        cout << setw(120) << "Wrong Input!! Please Try Again." << endl;
                        UpdateItem();
                        
                    }
               

            }





        }

    }





}



void DeleteItem()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    stringstream ss;
    system("CLS");
    cout << endl << endl << setw(155) << " ********************************************************************************************************************** " << endl;
    cout << setw(155) << " *********************************************** *** DELETE PRODUCT *** *********************************************** " << endl;
    cout << setw(155) << " ********************************************************************************************************************** " << endl;

    string isbn;
    

    cout << endl << setw(80) << "Enter ISBN:";
    cin >> isbn;
    ss << "select * from bookinfo where ISBN = '" + isbn + "' ";
    string query = ss.str();
    const char* qn = query.c_str();
    qstate = mysql_query(conn, qn);


    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        if ((row = mysql_fetch_row(res)))
        {
            
            
            
                 int qstate = 0;
                stringstream ss;
                ss << "delete from bookinfo where ISBN = '" + isbn + "'";

                string query = ss.str();
                const char* qz = query.c_str();
                qstate = mysql_query(conn, qz);


                if (qstate == 0)

                {
                    cout << endl << endl << setw(120) << "The Book Infromation Is Successfully Deleted From Databse." << endl;
                }
                else
                {
                    cout << endl << setw(120) << "Failed to delete from Database." << endl;
                    DeleteItem();
                }
            
        }
        else
        {
            cout << endl << endl << setw(120) << "There is no information in database for this ISBN." << endl;
        }
    }
    else
    {
        cout << setw(120) << "There is some problem, Please Try Again!!" << endl;
    }
    int flag = 0;
    while (1) {
        string choice;
        cout << endl << endl << setw(100) << "Do you want to delete again?" << endl << setw(80) << "[1]Yes" << endl << setw(79) << "[2]No" << endl << endl << setw(80) << "Your choice : ";
        cin >> choice;

        if (choice == "2") {
            flag = 1;
            break;
        }
        else if (choice != "1") {
            cout << setw(120) << "Wrong Input!! Please Try Again." << endl;
        }
        else if (choice == "1") {
            DeleteItem();
        }
    }
    if (flag == 1) {
        adminlogin();

    }
}


void Promotion()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    stringstream ss;
    int promotion;
    int changepromotion;
    system("CLS");
    cout << endl << endl << setw(110) << "Promotion :" << endl << endl;
    

    
    
    cout << endl << endl << setw(120) << "Current Promotion On Your Bookstore Is:" << endl << endl;
    qstate = mysql_query(conn, "select * from promotion");
    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
            cout << setw(100) << "Percentage: " << row[1] << endl  << endl << endl;
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl << endl << endl;
            

            int x = atoi(row[1]);
            promotion = x;
            pRomotion = x;
           
          
            
            cout << endl << setw(80) << "Please Enter The Promotion Percentage:  ";
            cin >> changepromotion;
            

            if (changepromotion >= 0 && changepromotion <= 100)
            {
                promotion = changepromotion;





                stringstream update_query;
                update_query << "update promotion set Percentage ='" << promotion << "' where PromotionID =1";

                const char* qu = update_query.str().c_str();
                qstate = mysql_query(conn, qu);


                if (!qstate)
                {
                    cout << endl << endl << setw(120) << "Successfully Saved In Database!" << endl;
                }
                else
                {
                    cout << endl << setw(120) << "Failed To Update!" << endl;
                    cout << endl << setw(120) << "You insert worng value for promotiom. Please try again and change the promotion with integer value between (0 to 100)" << endl;
                }
            }
             else
             {
                 
                 cout << endl << setw(120) << "You insert worng value for promotiom. Please try again and change the promotion with integer value between (0 to 100)" << endl;
                 _getch();
                 Promotion();
             }
        }
    }
    else
    {
        cout << endl << setw(120) << "Query Execution Problem!" <<  endl;
        system("cls");
        Promotion();
    }
    
   
        string choice;
        cout << endl << endl << setw(100) << "Want to Change again or exit??" << endl << setw(80) << "[1]Yes" << endl << setw(79) << "[2]No" << endl << endl << setw(80) << "Your choice : ";
        cin >> choice;

        if (choice == "1") {
            Promotion();
        }
        else if (choice == "2") {
            adminlogin();
            
        }
        else  {
            cout << setw(120) << "Wrong Input!! Please Try Again." << endl;
            _getch();
            Promotion();
        }
   
}

void makePurchase()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    system("CLS");
    double total;
    double PROMOTION;

    cout << endl << endl << setw(100) << "Cart Info" << endl << endl;
    qstate = mysql_query(conn, "select * from cart");
    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {


            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
            cout << setw(100) << "ISBN  : " << row[0] << endl << setw(100) << "Price : " << row[1] << endl << setw(100) << "Book Title: " << row[2] << endl << setw(100) << "Cart ID : " << row[3] << endl << endl << endl;
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;



        }
    }
    else
    {
        cout << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }

    cout << setw(90) << "==>You are sure you want to buy this product?" << endl;
    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
    cout << setw(155) << "| 1. Yes                                                                                                        |" << endl;
    cout << setw(155) << "| 2. No                                                                                                         |" << endl;

    cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
    string ch;
    cout << setw(60) << "==> Your Choice:";

    cin >> ch;
    if (ch == "1") {
        qstate = mysql_query(conn, "select * from promotion");
        if (qstate == 0)
        {
            res = mysql_store_result(conn);
            if (row = mysql_fetch_row(res))
            {
                pRomotion = atoi(row[1]);
            }
        }
        stringstream ss;
        //ss << "INSERT INTO purchase(TotalPrice,promotionprice)";
        ss << " SELECT SUM(Price) as Total FROM cart ";




        string query = ss.str();
        const char* qm = query.c_str();
        qstate = mysql_query(conn, qm);
        if (qstate == 0)
        {
            res = mysql_store_result(conn);
            row = mysql_fetch_row(res);


            stringstream geek(row[0]);
            geek >> total;
            stringstream so;
            PROMOTION = total - (total * pRomotion / 100);
            so << "INSERT INTO purchase(TotalPrice,promotionprice,Customerid) VALUES ('" << row[0] << "','" << PROMOTION << "','" + customerid + "')";
            query = so.str();
            const char* qw = query.c_str();
            qstate = mysql_query(conn, qw);
            if (qstate == 0) {

                stringstream ss;
                ss << "UPDATE bookinfo INNER JOIN cart ON bookinfo.ISBN=cart.ISBN SET bookinfo.BookQuantity=(bookinfo.BookQuantity-cart.Quantity)";
                string query = ss.str();
                const char* qz = query.c_str();
                qstate = mysql_query(conn, qz);
                if (qstate == 0) {

                    stringstream ss;
                    ss << "DELETE FROM cart";

                    string query = ss.str();
                    const char* qi = query.c_str();
                    qstate = mysql_query(conn, qi);

                   


                }
            }

        }
        else {
            cout << endl << endl << setw(122) << "Failed To Insert Into Databse" << endl;
            cout << setw(124) << "Worng Keyword!! Please Try Again ";
            _getch();
            addCart();
        }




        cout << endl << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << endl << endl << setw(140) << "Total Price  :" << total << endl;
        cout << endl << endl << setw(100) << "Our Shop gives you " << pRomotion << "% promotion. After promotion the price is:";
        cout << endl << endl << setw(140) << "Promotion Price  :" << PROMOTION << endl;
        cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;


        cout << setw(72) << "==> Please Choose any option:" << endl;
        cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(155) << "| 1. User Login Page                                                                                          |" << endl;
        cout << setw(155) << "| 0. Exit                                                                                                     |" << endl;

        cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
        string choice;
        cout << setw(60) << "==> Your Choice:";

        cin >> choice;

        if (choice == "1") {
            userlogin();

        }

        else if (choice == "0") {
            exit();
        }
        else {
            cout << endl << endl << setw(120) << "Worng Keyword !! Press any Key for go to User login page." << endl;
            _getch();
            userlogin();
        }
    }
    else if (ch == "2") {
    userlogin();
    }
    else {
    cout << endl << endl << setw(120) << "Worng Keyword !! Press any Key for go to User login page." << endl;
    _getch();
    makePurchase();
    }
}
    
    


void searchProduct()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    stringstream ss;
    system("CLS");
    cout << endl << endl << setw(155) << " ********************************************************************************************************************** " << endl;
    cout << setw(155) << " ********************************************** *** SEARCH PRODUCT *** ************************************************ " << endl;
    cout << setw(155) << " ********************************************************************************************************************** " << endl;

    string ISBN;
    int choice;
    bool print = false;
    while (1) {
        system("CLS");
        int found = 0;

        cout << endl << setw(80) << "Search Product" << endl << endl;

        cout << endl << setw(80) << "ENTER ISBN : ";
        cin >> ISBN;

        string findbyid_query = "select * from bookinfo where ISBN = '" + ISBN + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                found = 1;
                cout << endl << setw(100) << "ISBN: " << row[0] << endl << setw(100) << "AUTHOR: " << row[1] << endl << setw(100) << "Title: " << row[2] << endl << setw(100) << "Year: " << row[3] << endl << setw(100) << "Price: " << row[4] << endl << setw(100) << "Quantity: " << row[5] << endl << endl;

            }
            if (found == 0) {
                cout << setw(100) << "Not Found" << endl;

                cout << endl << endl << setw(100) << "Do you want to continue searching?" << endl << setw(80) << "[1]Yes" << endl << setw(81) << "[2]No" << endl << endl << setw(80) << "Your choice : ";
                cin >> choice;

                if (choice == 2) {
                    userlogin();
                }
                else
                    continue;
            }
        }
        else
        {
            cout << setw(100) << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
        
        cout << setw(72) << "==> Please Choose any option:" << endl;
        cout << setw(155) << "--------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(155) << "| 1. User Login Page                                                                                          |" << endl;
        cout << setw(155) << "| 2. Search Again                                                                                             |" << endl;
        cout << setw(155) << "| 0. Exit                                                                                                     |" << endl;

        cout << setw(155) << "---------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
        string choice;
        cout << setw(60) << "==> Your Choice:";

        cin >> choice;

        if (choice == "1") {
            userlogin();
        }
        else if (choice == "2") {
            searchProduct();
        }
        
        else if (choice == "0") {
            exit();
        }
        else {
            cout << endl << endl << setw(120) << "Worng Keyword !! Press any key for go to user login page." << endl;
            _getch();
            userlogin();
        }
    }

}
void addCart()
{
    MYSQL* conn = connectdatabase();
    int qstate = 0;
    system("cls");
    cout << endl << endl << setw(120) << "The Available Book Information In The Bookstore" << endl << endl;
    string Isbn,  booktitle;
    int quantity, price;
   
    
    qstate = mysql_query(conn, "select * from bookinfo");
    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
            cout << setw(100) << "ISBN: " << row[0] << endl << setw(100) << "AUTHORNAME: " << row[1] << endl << setw(100) << "BOOKTITLE: " << row[2] << endl << setw(100) << "YEAR: " << row[3] << endl << setw(100) << "PRICE: " << row[4] << endl << setw(100) << "BOOKQUANTITY: " << row[5] << endl << endl;
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl << endl << endl;
            

        }
    }
    else
    {
        cout << endl << setw(60) << "Query Execution Problem!" << mysql_errno(conn) << endl;
        system("cls");
        userlogin();
    }

    string isbn;
    int choice;
    bool print = false;
    while (1) {

        int found = 0;

        cout << endl << setw(60) << "ADD TO CART" << endl << endl;
        
        cout << endl << setw(80) << "ENTER ISBN : ";
        cin >> isbn;
        cout << endl << setw(80) << "Quantity";
        cin >> quantity;

        string findbyid_query = "select * from bookinfo where ISBN = '" + isbn + "'";
        const char* qi = findbyid_query.c_str();
        qstate = mysql_query(conn, qi);
        

        if (!qstate)
        {
            res = mysql_store_result(conn);
            while ((row = mysql_fetch_row(res)))
            {
                qUantity = atoi(row[5]);
                
                if (qUantity > 0 && quantity < qUantity) {
                    stringstream ss;
                    found = 1;
                    cout << endl << setw(100) << "ISBN: " << row[0] << endl << setw(100) << "AUTHOR: " << row[1] << endl << setw(100) << "Title: " << row[2] << endl << setw(100) << "Year: " << row[3] << endl << setw(100) << "Price: " << row[4] << endl << setw(100) << "Quantity: " << row[5] << endl << endl;
                    Isbn = row[0];
                    price = atoi(row[4]);
                    booktitle = row[2];
                    customerid;
                    int PRice;
                    PRice = price * quantity;
                    ss << "INSERT INTO cart(ISBN,Price,BookTitle,CustomerID,Quantity)VALUES('" + Isbn + "','" << PRice << "','" + booktitle + "','" + customerid + "','" << quantity << "')";


                    string query = ss.str();
                    const char* qm = query.c_str();
                    qstate = mysql_query(conn, qm);
                    if (qstate == 0)
                    {
                        cout << endl << endl << setw(122) << "Record Inserted Sucessfully In Database " << endl << endl;

                    }
                    else {
                        cout << endl << endl << setw(122) << "Failed To Insert Into Databse" << endl;
                        cout << setw(124) << "Worng Keyword!! Please Try Again ";
                        _getch();
                        addCart();
                    }
                }
                else {
                    cout << endl << endl << setw(100) << "Out of Stock!!" << endl;
                }
                
            }
            if (found == 0) {
                cout << setw(100) << "Try Again. Not Found!!" << endl;

                
            }
        }
        else
        {
            cout << setw(100) << "Query Execution Problem!" << mysql_errno(conn) << endl;
        }
        cout << setw(72) << "==> Please Choose any option:" << endl;
        cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl;
        cout << setw(155) << "| 1. User Login Page                                                                                           |" << endl;
        cout << setw(155) << "| 2. Add Again                                                                                                 |" << endl;
        cout << setw(155) << "| 0. Exit                                                                                                      |" << endl;
        cout << setw(155) << "----------------------------------------------------------------------------------------------------------------" << endl << endl << endl;
        string choice;
        cout << setw(60) << "==> Your Choice:";

        cin >> choice;

        if (choice == "1") {
            userlogin();
        }
        else if (choice == "2") {
            addCart();
        }
       
        else if (choice == "0") {
            exit();
        }
        else {
            cout << endl << endl << setw(120) << "Worng Keyword !!Press any key for go to user login page." << endl;
            _getch();
            userlogin();
        }

    }
}

void deleteCart()
{

    MYSQL* conn = connectdatabase();
    int qstate = 0;
    stringstream ss;
    system("CLS");
    cout << endl << endl << setw(120) << "All Product IN CART:" << endl << endl;
    qstate = mysql_query(conn, "select * from cart");
    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        while ((row = mysql_fetch_row(res)))
        {


            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;
            cout << setw(100) << "ISBN   : " << row[0] << endl << setw(100) << "Price : " << row[1] << endl << setw(100) << "Book Title:" << row[2] << endl << setw(100) << "Cart iD : " << row[3] << endl << endl;
            cout << setw(155) << "````````````````````````````````````````````````````````````````````````````````````````````````````````````````" << endl;

        }
    }
    else
    {
        cout << endl << setw(60) << "Query Execution Problem!" << mysql_errno(conn) << endl;
    }
    cout << endl << endl << setw(155) << " ********************************************************************************************************************** " << endl;
    cout << setw(155) << " *********************************************** *** DELETE PRODUCT FROM CART*** ************************************** " << endl;
    cout << setw(155) << " ********************************************************************************************************************** " << endl;

    string id;


    cout << endl << setw(80) << "Enter Cart ID:";
    cin >> id;
    ss << "select * from cart where CartID = '" + id + "' ";
    string query = ss.str();
    const char* qn = query.c_str();
    qstate = mysql_query(conn, qn);


    if (qstate == 0)
    {
        res = mysql_store_result(conn);
        if ((row = mysql_fetch_row(res)))
        {



            int qstate = 0;
            stringstream ss;
            ss << "delete from cart where CartID = '" + id + "'";

            string query = ss.str();
            const char* qz = query.c_str();
            qstate = mysql_query(conn, qz);


            if (qstate == 0)

            {
                cout << endl << endl << setw(120) << "The Product Is Successfully Deleted From Cart." << endl;
            }
            else
            {
                cout << endl << setw(120) << "Failed to delete from Cart." << endl;
                deleteCart();
            }

        }
        else
        {
            cout << endl << endl << setw(120) << "There is no information in Cart for this ID." << endl;
        }
    }
    else
    {
        cout << setw(120) << "There is some problem, Please Try Again!!" << endl;
    }
    int flag = 0;
    while (1) {
        string choice;
        cout << endl << endl << setw(100) << "Do you want to delete again?" << endl << setw(80) << "[1]Yes" << endl << setw(79) << "[2]No" << endl << endl << setw(80) << "Your choice : ";
        cin >> choice;

        if (choice == "2") {
            flag = 1;
            break;
        }
        else if (choice != "1") {
            cout << setw(120) << "Wrong Input!! Please Try Again." << endl;
        }
        else if (choice == "1") {
            deleteCart();
        }
    }
    if (flag == 1) {
        userlogin();
    }
}
