#include <bits/stdc++.h>
using namespace std;

class Customer
{
public:
    int accountNumber;
    string name;
    float balance;
    Customer(int acNo, string Name, float bl)
    {
        accountNumber = acNo;
        name = Name;
        balance = bl;
    }
};

class Bank
{
public:
    vector<Customer> customers;

    float credit(Customer c, float amount)
    {

        c.balance += amount;
        cout << "Amount "  <<(amount) << " creadited to Account - " <<(c.accountNumber) << endl;
        return c.balance;
    }

    float debit(Customer c, float amount)
    {

        c.balance -= amount;

        cout << "Amount " <<(amount) << " debited from Account - " <<(c.accountNumber) << endl;
        cout<<"Current Balance : "<<c.balance<<endl<<endl;
        return c.balance;
    }
};

int main()
{

    Bank b;
    int counter = 1001;
    Customer c1(counter, "Sayak", 1500);
    counter++;

    Customer c2(counter, "Shouvik", 1000);
    counter++;

    b.customers.push_back(c1);
    b.customers.push_back(c2);

    int flag = 1;
    while (true)
    {
        cout << "Choose options from below" << endl;
        cout << "1. View all customers" << endl;
        cout << "2. Credit" << endl;
        cout << "3. Debit" << endl;
        cout << "4. Transfer" << endl;
        cout << "5. Add Customer" << endl;
        cout << "6. Exit" << endl;
        int operation;
        cin >> operation;
        Customer c(0, "", 0);
        Customer c1(0, "", 0);
        Customer c2(0, "", 0);
        int customerAccount;
        float amnt;
        int customerAccount1;
        int customerAccount2;
        float newBalance = 0;
        float newBalance1 = 0;
        float newBalance2 = 0;
        string name;
        int f;
        switch (operation)
        {
        case 1:
            cout << "\tAll Customer Details " << endl;
            for (int i = 0; i < b.customers.size(); i++)
            {
                cout << "Customer " << (i + 1) << " ";
                cout << b.customers[i].name << " ";
                cout << b.customers[i].accountNumber << " ";
                cout << b.customers[i].balance << " " << endl;
            }
            break;
        case 2:
            cout << "Enter Account number : ";
            cin >> customerAccount;
            cout << "Enter Ammount to be credited : ";
            cin >> amnt;
            for (int i = 0; i < b.customers.size(); i++)
            {
                if (b.customers[i].accountNumber == customerAccount)
                {
                    c.accountNumber = b.customers[i].accountNumber;
                    c.balance = b.customers[i].balance;
                    c.name = b.customers[i].name;
                    //c = b.customers[i];
                }
            }
            newBalance = b.credit(c, amnt);
            for (int i = 0; i < b.customers.size(); i++)
            {
                if (b.customers[i].accountNumber == customerAccount)
                {
                    b.customers[i].balance = newBalance;
                    cout<<"Current Balance : "<<b.customers[i].balance<<endl<<endl;
                }
            }
            break;

        case 3:
            f = 1;
            cout << "Enter Account number : ";
            cin >> customerAccount;
            cout << "Enter Ammount to be debited : ";
            cin >> amnt;
            for (int i = 0; i < b.customers.size(); i++)
            {
                if (b.customers[i].accountNumber == customerAccount)
                {
                    if (b.customers[i].balance >= amnt)
                    {
                        c.accountNumber = b.customers[i].accountNumber;
                        c.balance = b.customers[i].balance;
                        c.name = b.customers[i].name;
                    }
                    else
                    {
                        f = 0;
                    }
                }
            }
            if (f == 0)
            {
                cout << "Do Not Have Sufficient Balance" << endl;
            }
            else
            {
                newBalance = b.debit(c, amnt);
                for (int i = 0; i < b.customers.size(); i++)
                {
                    if (b.customers[i].accountNumber == customerAccount)
                    {
                        b.customers[i].balance = newBalance;
                        cout<<"Current Balance : "<<b.customers[i].balance<<endl<<endl;
                    }
                }
            }
            break;
        case 4:
            f = 1;
            cout << "Enter Account number(Sender) : ";
            cin >> customerAccount1;
            cout << "Enter Account number(Reciever) : ";
            cin >> customerAccount2;
            cout << "Enter Ammount to be transfered : ";
            cin >> amnt;
            for (int i = 0; i < b.customers.size(); i++)
            {
                if (b.customers[i].accountNumber == customerAccount1)
                {
                    if (b.customers[i].balance >= amnt)
                    {
                        c1.accountNumber = b.customers[i].accountNumber;
                        c1.balance = b.customers[i].balance;
                        c1.name = b.customers[i].name;
                    }
                    else
                    {
                        f = 0;
                    }
                }
                if (b.customers[i].accountNumber == customerAccount2)
                {
                    c2.accountNumber = b.customers[i].accountNumber;
                    c2.balance = b.customers[i].balance;
                    c2.name = b.customers[i].name;
                }
            }
            if (f == 0)
            {
                cout << "Sender Do Not Have Sufficient Balance" << endl;
            }

            else
            {
                newBalance1 = b.debit(c1, amnt);
                newBalance2 = b.credit(c2, amnt);

                for (int i = 0; i < b.customers.size(); i++)
                {
                    if (b.customers[i].accountNumber == customerAccount1)
                    {
                        b.customers[i].balance = newBalance1;
                        cout<<"Current Balance of sender : "<<b.customers[i].balance<<endl<<endl;
                    }
                    if (b.customers[i].accountNumber == customerAccount2)
                    {
                        b.customers[i].balance = newBalance2;
                        cout<<"Current Balance of reciever : "<<b.customers[i].balance<<endl<<endl;
                    }
                }
            }
            break;
        case 5:
            cout << "Enter Details \n";
            cout << "Enter A/C Holder Name : ";
            cin >> name;
            c.accountNumber = counter;
            c.balance = 0;
            c.name = name;
            b.customers.push_back(c);
            cout << "Account Added successfully with A/C no " <<counter<< endl;
            counter++;
            break;
        case 6:
            flag = 0;
            break;

        default:
            cout << "Choose a valid option." << endl;
            break;
        }
        if (flag == 0)
        {
            cout << "Thank You" << endl;
            break;
        }
    }

    return 0;
}
