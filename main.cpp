#include <iostream>
#include <string>
using namespace std;

struct StudentData
{
    int id;
    string name;
    int age;
    double weight;
    string grade;
    string address;
    string phone_number;
    string email;
    string degree;
    string joining_session;
    double gpa;
    string courses[5];
    string roll_number;
    string cnic;
    string date_of_birth;
    string blood_group;
    string medical_conditions;
    string emergency_contact;
    bool is_fee_paid;
    string scholarship;
    string financial_status;
    string academic_standing;
};

void menu()
{
    int choice;
    do
    {
        switch (choice)
        {
        case 1:
            cout << "Add students";
            break;
        case 2:
            cout << "Delete students";
            break;
        case 3:
            cout << "Update students";
            break;
        case 4:
            cout << "Display All students";
            break;
        case 5:
            cout << "Display number of students";
            break;
        case 6:
            cout << "Search By Age";
            break;
        case 7:
            cout << "Search By ID";
            break;
        case 8:
            cout << "Search By Degree";
            break;
        case 9:
            cout << "Search By Joining Session";
            break;
        case 10:
            cout << "Search By Roll Number";
            break;
        case 11:
            cout << "Search By Blood Group";
            break;
        case 12:
            cout << "Search By Age";
            break;
        case 13:
            cout << "Search By ID";
            break;
        case 14:
            cout << "Search By Degree";
            break;
        case 15:
            cout << "Search By Joining Session";
            break;
        case 16:
            cout << "Search By Roll Number";
            break;
        case 17:
            cout << "Search By Blood Group";
            break;
        default:
            break;
        }

    } while (choice != 8);
}

int main()
{

    return 0;
}