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

StudentData students[5];
int student_count = 0;

void addStudents()
{
    cout << "Enter Student Data!";
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter ID(only numbers allowed!): ";
        cin >> students[i].id;
        cout << "Enter Student Name: ";
        cin >> students[i].name;
        cout << "Enter GPA: ";
        cin >> students[i].gpa;
        student_count++;
    }
}

void displayStudents()
{
    for (int i = 0; i < student_count; i++)
    {
        cout << students[i].id << "\t" << students[i].name << "\t" << students[i].gpa;
    }
    cout << "\n"
         << student_count;
}

void menu()
{
    int choice = 0;
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add students\n";
        cout << "2. Delete students\n";
        cout << "3. Update students\n";
        cout << "4. Display All students\n";
        cout << "5. Display number of students\n";
        cout << "6. Search Methods\n";
        cout << "7. Sort Methods\n";
        cout << "8. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            addStudents();
            break;
        case 2:
            cout << "Delete students\n";
            break;
        case 3:
            cout << "Update students\n";
            break;
        case 4:
            displayStudents();
            break;
        case 5:
            cout << "Display number of students\n";
            break;
        case 6:
            int choice_search;
            cout << "1. Search By Age\n";
            cout << "2. Search By ID\n";
            cout << "3. Search By Degree\n";
            cout << "4. Search By Joining Session\n";
            cout << "5. Search By Roll Number\n";
            cout << "6. Search By Blood Group\n";
            cin >> choice_search;

            switch (choice_search)
            {
            case 1:
                cout << "Search By Age\n";
                break;
            case 2:
                cout << "Search By ID\n";
                break;
            case 3:
                cout << "Search By Degree\n";
                break;
            case 4:
                cout << "Search By Joining Session\n";
                break;
            case 5:
                cout << "Search By Roll Number\n";
                break;
            case 6:
                cout << "Search By Blood Group\n";
                break;
            default:
                cout << "Enter only valid choice\n";
                break;
            }
            break;
        case 7:
            int choice_sort;
            cout << "1. Sort By Age\n";
            cout << "2. Sort By ID\n";
            cout << "3. Sort By Degree\n";
            cout << "4. Sort By Joining Session\n";
            cout << "5. Sort By Roll Number\n";
            cout << "6. Sort By Blood Group\n";
            cin >> choice_sort;

            switch (choice_sort)
            {
            case 1:
                cout << "Sort By Age\n";
                break;
            case 2:
                cout << "Sort By ID\n";
                break;
            case 3:
                cout << "Sort By Degree\n";
                break;
            case 4:
                cout << "Sort By Joining Session\n";
                break;
            case 5:
                cout << "Sort By Roll Number\n";
                break;
            case 6:
                cout << "Sort By Blood Group\n";
                break;
            default:
                cout << "Enter only valid choice\n";
                break;
            }
            break;
        case 8:
            cout << "Exit Program! Bye\n";
            break;
        default:
            cout << "Enter only valid choice\n";
            break;
        }

    } while (choice != 8);
}

int main()
{
    menu();
    return 0;
}