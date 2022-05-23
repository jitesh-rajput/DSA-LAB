/*
Company maintains employee information as employee ID, name,
designation and salary. Allow user to add, delete information of
employee. Display information of particular employee. If employee
does not exist an appropriate message is displayed. If it is, then the
C217.4 61
system displays the employee details. Use index sequential file to
maintain the data
*/
#include <iostream>
#include "bits/stdc++.h"
using namespace std;

class Employee
{
public:
    string eid, name, salary, address;
    void accept()
    {
        cout << "\n Enter Employee Id :- ";
        cin >> eid;
        cout << "\n Enter  Name :- ";
        cin >> name;
        cout << "\n Enter  Salary :-";
        cin >> salary;
        cout << "\n Enter  Address :- ";
        cin >> address;
    }
    string display()
    {
        string str = "\n Name :- " + name + "\t ID :- " + eid + "\t Salary :- " + salary + "\t Address :- " + address + "\t";
        return str;
    }
};

int main()
{
    Employee t1;
    int ch;
    string line;
    fstream f;
    ifstream r;
    int flag = 0;
    string id;
    do
    {
        cout << "\n1. Insert \n";
        cout << "2. Display \n";
        cout << "3. Search \n";
        cout << "4. Exit \n";
        cout << " Enter your Choice :- ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            f.open("EmployeeRecord", ios::app | ios::binary);
            t1.accept();
            f.seekp(0, ios::end);
            f.write((char *)&t1, sizeof(t1));
            f.close();
            break;
        case 2:
            f.open("EmployeeRecord", ios::in | ios::binary);
            f.seekg(0, ios::beg);
            while (f.read((char *)&t1, sizeof(t1)))
            {
                cout << t1.display();
            }
            f.close();
            break;
        case 3:
            cout << "\nEnter id to be search :- ";
            cin >> id;
            f.open("EmployeeRecord", ios::in | ios::binary);
            f.seekg(0, ios::beg);
            while (f.read((char *)&t1, sizeof(t1)))
            {
                if (t1.eid == id)
                {
                    cout << "Record Found ...";
                    cout << t1.display();
                    flag = 1;
                }
            }
            if (!flag)
                cout << "Record not found ...";
            f.close();
            break;
        default:
            break;
        }
    } while (ch != 6);
    return 0;
}