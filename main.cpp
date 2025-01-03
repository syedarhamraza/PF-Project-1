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

const int MAX_STUDENTS_SIZE = 2;
StudentData students[MAX_STUDENTS_SIZE];
int student_count = 0;

bool isIDUnique(int id)
{
    for (int i = 0; i < student_count; i++)
    {
        if (students[i].id == id)
            return false;
    }
    return true;
}

void addStudents()
{
    cout << "\nEnter Student Data!\n";
    for (int i = student_count; i < MAX_STUDENTS_SIZE; i++)
    {
        cout << "Enter ID(only numbers allowed!): ";
        cin >> students[i].id;
        if (isIDUnique(students[i].id) == false)
        {
            cout << "ID already Exists";
            return;
        }
        cin.ignore();
        cout << "Enter Student Name: ";
        getline(cin, students[i].name);
        cout << "Enter GPA: ";
        cin >> students[i].gpa;
        cin.ignore();
        student_count++;
    }
}

void displayStudents()
{
    cout << "ID\tName\tGPA\n";
    for (int i = 0; i < student_count; i++)
    {
        cout << students[i].id << "\t" << students[i].name << "\t" << students[i].gpa << "\n";
    }
}

void deleteStudents()
{
    int id;
    cout << "Enter the ID of student: ";
    cin >> id;
    for (int i = 0; i < student_count; i++)
    {
        if (students[i].id == id)
        {
            for (int j = i; j < student_count - 1; j++)
            {
                students[j] = students[j + 1];
            }
            student_count--;
            cout << "Student deleted!" << endl;
            return;
        }
    }
    cout << "Student not found!";
}

void updateStudents()
{
    int id;
    cout << "Enter the ID of the student: ";
    cin >> id;
    int choice = 0;
    do
    {
        cout << "What do you want to Update\n";
        cout << "1. Name\n";
        cout << "2. GPA\n";
        cout << "3. Go Back\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            for (int i = 0; i < student_count; i++)
            {
                if (students[i].id == id)
                {
                    string new_name;
                    cout << "Enter new name of the student " << students[i].name << ": ";
                    cin.ignore();
                    getline(cin, new_name);
                    students[i].name = new_name;
                }
            }
            break;
        case 2:
            for (int i = 0; i < student_count; i++)
            {
                if (students[i].id == id)
                {
                    double new_gpa;
                    cout << "Enter new GPA of the student " << students[i].gpa << ": ";
                    cin >> new_gpa;
                    students[i].gpa = new_gpa;
                }
            }
            break;
        case 3:
            cout << "Going Back!\n";
            break;

        default:
            cout << "Enter only valid number\n";
            break;
        }
    } while (choice != 3);
}

void displayNumberOfStudents()
{
    cout << "The Number of Student are: " << student_count << endl;
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
            deleteStudents();
            break;
        case 3:
            updateStudents();
            break;
        case 4:
            displayStudents();
            break;
        case 5:
            displayNumberOfStudents();
            break;
        case 6:
            int choice_search;
            cout << "1. Search By Age\n";
            cout << "2. Search By ID\n";
            cout << "3. Search By Degree\n";
            cout << "4. Search By Joining Session\n";
            cout << "5. Search By Roll Number\n";
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