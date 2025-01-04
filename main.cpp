#include <iostream>
#include <string>
using namespace std;

struct StudentData
{
    int id;
    string name;
    int age;
    string date_of_birth;
    string address;
    string phone_number;
    string email;
    string cnic;
    string roll_number;
    string blood_group;

    double gpa;
    string degree;
    string joining_session;
    string courses[5];
    string grade;
    string scholarship;
    string academic_standing;

    string medical_conditions;

    bool is_fee_paid;
    string financial_status;

    string emergency_contact;
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

        cout << "\nPersonal Information\n";

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
        cout << "Enter Age: ";
        cin >> students[i].age;
        if (students[i].age <= 0)
        {
            cout << "Negative or 0 is not allowed!\n";
            cout << "Enter Again!\n";
            i--;
            continue;
        }
        cout << "Enter Date of Birth: ";
        cin >> students[i].date_of_birth;
        cin.ignore();
        cout << "Enter Address: ";
        getline(cin, students[i].address);
        cout << "Enter Phone Number: ";
        cin >> students[i].phone_number;
        cout << "Enter Email: ";
        cin >> students[i].email;
        cout << "Enter Cnic: ";
        cin >> students[i].cnic;
        cout << "Enter Roll-Number: ";
        cin >> students[i].roll_number;
        cout << "Enter Blood Group: ";
        cin >> students[i].blood_group;

        cout << "\nAcademic Information\n";
        cout << "Enter GPA (0.0 to 4.0): ";
        cin >> students[i].gpa;
        if (students[i].gpa < 0.0 || students[i].gpa > 4.0)
        {
            cout << "Only 0.0 to 4.0 is allowed!\n";
            cout << "Enter Again!\n";
            i--;
            continue;
        }
        cin.ignore();
        cout << "Enter Degree: ";
        cin >> students[i].degree;
        cout << "Enter Joining Session: ";
        cin >> students[i].joining_session;

        cout << "Enter 5 courses (code):\n";
        for (int j = 0; j < 5; j++)
        {
            cout << "Course " << j + 1 << ": ";
            cin >> students[i].courses[j];
        }

        cout << "Enter Grade: ";
        cin >> students[i].grade;
        cout << "Enter Academic Standing: ";
        cin >> students[i].academic_standing;

        cout << "\nMedical Information\n";
        cout << "Enter any medical conditions (if any): ";
        cin.ignore();
        getline(cin, students[i].medical_conditions);

        cout << "\nFinancial Information\n";
        cout << "Enter Financial Status(Good or Bad): ";
        cin >> students[i].financial_status;
        cout << "Has the fee been paid (1 for Yes, 0 for No): ";
        cin >> students[i].is_fee_paid;

        cout << "\nEmergency Contact\n";
        cout << "Enter Emergency Contact Number: ";
        cin >> students[i].emergency_contact;

        student_count++;
    }
}
void displayStudents()
{
    cout << "\nDisplaying Student Information:\n";
    cout << "-------------------------------------------------------------\n";

    for (int i = 0; i < student_count; i++)
    {
        cout << "ID: " << students[i].id << "\n"
             << "Name: " << students[i].name << "\n"
             << "Age: " << students[i].age << "\n"
             << "Date of Birth: " << students[i].date_of_birth << "\n"
             << "Adress: " << students[i].address << "\n"
             << "Phone: " << students[i].phone_number << "\n"
             << "Email: " << students[i].email << "\n"
             << "Cnic: " << students[i].cnic << "\n"
             << "Roll-No: " << students[i].roll_number << "\n"
             << "Blood Group: " << students[i].blood_group << "\n"
             << "GPA: " << students[i].gpa << "\n"
             << "Degree: " << students[i].degree << "\n"
             << "Joining Session: " << students[i].joining_session << "\n";

        cout << "Courses: ";
        for (int j = 0; j < 5; j++)
        {
            cout << students[i].courses[j] << " ";
        }
        cout << "\n";

        cout << "Grade: " << students[i].grade << "\n";
        cout << "Scholarship: " << students[i].scholarship << "\n";
        cout << "Academic Standing: " << students[i].academic_standing << "\n";
        cout << "Medical Conditions: " << students[i].medical_conditions << "\n";
        cout << "Fee Paid: " << (students[i].is_fee_paid ? "Yes" : "No") << "\n";
        cout << "Financial Status: " << students[i].financial_status << "\n";
        cout << "Emergency Contact: " << students[i].emergency_contact << "\n";
        cout << "-------------------------------------------------------------\n";
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

void searchById()
{
    int id;
    cout << "Enter the ID of the student: ";
    cin >> id;

    for (int i = 0; i < student_count; i++)
    {
        if (students[i].id == id)
        {
            cout << "Student Found!" << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "GPA: " << students[i].gpa << endl;
        }
    }
}

void sortById()
{
    for (int i = 0; i < student_count - 1; i++)
    {

        for (int j = 0; j < student_count - i - 1; j++)
        {
            if (students[j].id > students[j + 1].id)
            {
                StudentData temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << "Sorted By ID!";
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
                searchById();
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
                sortById();
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