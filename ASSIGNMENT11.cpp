/*
Department maintains a student information. The file contains rollnumber, name, division and address. Allow user to add, delete
information of student. Display information of particular employee. If record of student does not exist an appropriate message is
displayed. If it is, then the system displays the student details. Use sequential file to main the data
*/
#include "bits/stdc++.h"
using namespace std;

class Student
{
public:
    string rollno, name, div, address;
    void accept()
    {
        cout << "\n Enter Roll Number :- ";
        cin >> rollno;
        cout << "\n Enter Student Name :- ";
        cin >> name;
        cout << "\n Enter Student Division :-";
        cin >> div;
        cout << "\n Enter Student Address :- ";
        cin >> address;
    }
    string display()
    {
        string str = "\n Name :- " + name + "\t Roll Number :- " + rollno + "\t Division :- " + div + "\t Address :- " + address + "\t";
        return str;
    }
};

int main()
{
    Student t1;
    int ch;
    string line;
    fstream f;
    ifstream r;
    int flag = 0;
    string roll;
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
            f.open("StudentRecord", ios::binary | ios::app);
            t1.accept();
            f.write((char *)&t1, sizeof(t1));
            f.close();
            break;
        case 2:
            r.open("StudentRecord", ios::binary);
            while (r.read((char *)&t1, sizeof(t1)))
            {
                cout << t1.display();
            }
            r.close();
            break;
        case 3:
            cout << "\nEnter roll number to be search :- ";
            cin >> roll;
            r.open("StudentRecord", ios::binary);
            while (r.read((char *)&t1, sizeof(t1)))
            {
                if (t1.rollno == roll)
                {
                    cout << "Record Found ...";
                    cout << t1.display();
                    flag = 1;
                }
            }
            if (!flag)
                cout << "Record not found ...";
            r.close();
            break;
        default:
            break;
        }
    } while (ch != 6);
    return 0;
}