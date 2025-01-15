#include <iostream>
#include <string>
#include <fstream>
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

bool isRollNumberUnique(const string &rollnumber)
{
    for (int i = 0; i < student_count; i++)
    {
        if (students[i].roll_number == rollnumber)
            return false;
    }
    return true;
}

bool isEmailUnique(const string &email)
{
    for (int i = 0; i < student_count; i++)
    {
        if (students[i].email == email)
            return false;
    }
    return true;
}

void saveToFile()
{
    ofstream file("students.txt");
    if (file.is_open())
    {
        file << student_count << endl;
        for (int i = 0; i < student_count; i++)
        {
            file << students[i].id << endl
                 << students[i].name << endl
                 << students[i].age << endl
                 << students[i].date_of_birth << endl
                 << students[i].address << endl
                 << students[i].phone_number << endl
                 << students[i].email << endl
                 << students[i].cnic << endl
                 << students[i].roll_number << endl
                 << students[i].blood_group << endl
                 << students[i].gpa << endl
                 << students[i].degree << endl
                 << students[i].joining_session << endl;

            for (int j = 0; j < 5; j++)
            {
                file << students[i].courses[j] << endl;
            }

            file << students[i].scholarship << endl
                 << students[i].academic_standing << endl
                 << students[i].medical_conditions << endl
                 << students[i].is_fee_paid << endl
                 << students[i].financial_status << endl
                 << students[i].emergency_contact << endl;
        }
        file.close();
    }
    else
    {
        cout << "Error saving data!" << endl;
    }
}

void loadFromFile()
{
    ifstream file("students.txt");
    if (file.is_open())
    {
        file >> student_count;
        file.ignore();
        for (int i = 0; i < student_count; i++)
        {
            file >> students[i].id;
            file.ignore();
            getline(file, students[i].name);
            file >> students[i].age;
            file.ignore();
            getline(file, students[i].date_of_birth);
            getline(file, students[i].address);
            getline(file, students[i].phone_number);
            getline(file, students[i].email);
            getline(file, students[i].cnic);
            getline(file, students[i].roll_number);
            getline(file, students[i].blood_group);
            file >> students[i].gpa;
            file.ignore();
            getline(file, students[i].degree);
            getline(file, students[i].joining_session);

            for (int j = 0; j < 5; j++)
            {
                getline(file, students[i].courses[j]);
            }

            getline(file, students[i].scholarship);
            getline(file, students[i].academic_standing);
            getline(file, students[i].medical_conditions);
            file >> students[i].is_fee_paid;
            file.ignore();
            getline(file, students[i].financial_status);
            getline(file, students[i].emergency_contact);
        }
        file.close();
    }
    else
    {
        cout << "No data found. Starting fresh!" << endl;
    }
}

void addStudents()
{
    StudentData student;

    cout << "\nEnter Student Data!\n";
    cout << "\nPersonal Information\n";
    cout << "Enter ID(only numbers allowed!): ";
    cin >> student.id;
    if (isIDUnique(student.id) == false)
    {
        cout << "ID already Exists";
        return;
    }
    cout << "Enter Student Name: ";
    cin.ignore();
    getline(cin, student.name);
    cout << "Enter Age: ";
    cin >> student.age;
    if (student.age <= 0)
    {
        cout << "Negative or 0 is not allowed!\n";
        cout << "Enter Again!\n";
        return;
    }
    cout << "Enter Date of Birth: ";
    cin >> student.date_of_birth;
    cout << "Enter Address: ";
    cin.ignore();
    getline(cin, student.address);
    cout << "Enter Phone Number: ";
    cin >> student.phone_number;
    cout << "Enter Email: ";
    cin >> student.email;
    if (isEmailUnique(student.email) == false)
    {
        cout << "Email already Exists";
        return;
    }
    cout << "Enter Cnic: ";
    cin >> student.cnic;

    cout << "Enter Roll-Number: ";
    cin >> student.roll_number;
    if (isRollNumberUnique(student.roll_number) == false)
    {
        cout << "Roll-Number already Exists";
        return;
    }

    cout << "Enter Blood Group: ";
    cin >> student.blood_group;

    cout << "\nAcademic Information\n";
    cout << "Enter GPA (0.0 to 4.0): ";
    cin >> student.gpa;
    if (student.gpa < 0.0 || student.gpa > 4.0)
    {
        cout << "Only 0.0 to 4.0 is allowed!\n";
        cout << "Enter Again!\n";
        return;
    }
    cin.ignore();
    cout << "Enter Degree: ";
    cin >> student.degree;
    cout << "Enter Joining Session: ";
    cin >> student.joining_session;

    cout << "Enter 5 courses (code):\n";
    for (int j = 0; j < 5; j++)
    {
        cout << "Course " << j + 1 << ": ";
        cin >> student.courses[j];
    }

    cout << "Enter Academic Standing: ";
    cin >> student.academic_standing;

    cout << "\nMedical Information\n";
    cout << "Enter any medical conditions (if any): ";
    cin.ignore();
    getline(cin, student.medical_conditions);

    cout << "\nFinancial Information\n";
    cout << "Enter Financial Status(Good or Bad): ";
    cin >> student.financial_status;
    cout << "Has the fee been paid (1 for Yes, 0 for No): ";
    cin >> student.is_fee_paid;

    cout << "\nEmergency Contact\n";
    cout << "Enter Emergency Contact Number: ";
    cin >> student.emergency_contact;

    students[student_count] = student;
    student_count++;
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
    int choice;
    do
    {
        cout << "\nWhat do you want to update?\n";
        cout << "1. Name\n";
        cout << "2. GPA\n";
        cout << "3. Age\n";
        cout << "4. Date of Birth\n";
        cout << "5. Address\n";
        cout << "6. Phone Number\n";
        cout << "7. Email\n";
        cout << "8. CNIC\n";
        cout << "9. Roll Number\n";
        cout << "10. Blood Group\n";
        cout << "11. Degree\n";
        cout << "12. Joining Session\n";
        cout << "13. Courses\n";
        cout << "14. Scholarship\n";
        cout << "15. Academic Standing\n";
        cout << "16. Medical Conditions\n";
        cout << "17. Fee Paid Status\n";
        cout << "18. Financial Status\n";
        cout << "19. Emergency Contact\n";
        cout << "20. Go Back\n";
        cout << "Enter your choice: ";
        cin >> choice;

        for (int i = 0; i < student_count; i++)
        {
            if (students[i].id == id)
            {
                switch (choice)
                {
                case 1:
                {
                    string new_name;
                    cout << "Enter new name of the student: ";
                    cin.ignore();
                    getline(cin, new_name);
                    students[i].name = new_name;
                    cout << "Name Updated!\n";
                }
                break;
                case 2:
                {
                    double new_gpa;
                    cout << "Enter new GPA of the student: ";
                    cin >> new_gpa;
                    students[i].gpa = new_gpa;
                    cout << "GPA Updated!\n";
                }
                break;
                case 3:
                {
                    int new_age;
                    cout << "Enter new age of the student: ";
                    cin >> new_age;
                    students[i].age = new_age;
                    cout << "Age Updated!\n";
                }
                break;
                case 4:
                {
                    string new_dob;
                    cout << "Enter new date of birth of the student: ";
                    cin.ignore();
                    getline(cin, new_dob);
                    students[i].date_of_birth = new_dob;
                    cout << "Date of Birth Updated!\n";
                }
                break;
                case 5:
                {
                    string new_address;
                    cout << "Enter new address of the student: ";
                    cin.ignore();
                    getline(cin, new_address);
                    students[i].address = new_address;
                    cout << "Address Updated!\n";
                }
                break;
                case 6:
                {
                    string new_phone;
                    cout << "Enter new phone number of the student: ";
                    cin.ignore();
                    getline(cin, new_phone);
                    students[i].phone_number = new_phone;
                    cout << "Phone Number Updated!\n";
                }
                break;
                case 7:
                {
                    string new_email;
                    cout << "Enter new email of the student: ";
                    cin.ignore();
                    getline(cin, new_email);
                    students[i].email = new_email;
                    cout << "Email Updated!\n";
                }
                break;
                case 8:
                {
                    string new_cnic;
                    cout << "Enter new CNIC of the student: ";
                    cin.ignore();
                    getline(cin, new_cnic);
                    students[i].cnic = new_cnic;
                    cout << "CNIC Updated!\n";
                }
                break;
                case 9:
                {
                    string new_roll_number;
                    cout << "Enter new roll number of the student: ";
                    cin.ignore();
                    getline(cin, new_roll_number);
                    students[i].roll_number = new_roll_number;
                    cout << "Roll Number Updated!\n";
                }
                break;
                case 10:
                {
                    string new_blood_group;
                    cout << "Enter new blood group of the student: ";
                    cin.ignore();
                    getline(cin, new_blood_group);
                    students[i].blood_group = new_blood_group;
                    cout << "Blood Group Updated!\n";
                }
                break;
                case 11:
                {
                    string new_degree;
                    cout << "Enter new degree of the student: ";
                    cin.ignore();
                    getline(cin, new_degree);
                    students[i].degree = new_degree;
                    cout << "Degree Updated!\n";
                }
                break;
                case 12:
                {
                    string new_joining_session;
                    cout << "Enter new joining session of the student: ";
                    cin.ignore();
                    getline(cin, new_joining_session);
                    students[i].joining_session = new_joining_session;
                    cout << "Joining Session Updated!\n";
                }
                break;
                case 13:
                {
                    cout << "Enter new courses for the student (up to 5):\n";
                    for (int j = 0; j < 5; j++)
                    {
                        cout << "Course " << j + 1 << ": ";
                        getline(cin, students[i].courses[j]);
                    }
                    cout << "Courses Updated!\n";
                }
                break;
                case 14:
                {
                    string new_scholarship;
                    cout << "Enter new scholarship status of the student: ";
                    cin.ignore();
                    getline(cin, new_scholarship);
                    students[i].scholarship = new_scholarship;
                    cout << "Scholarship Updated!\n";
                }
                break;
                case 15:
                {
                    string new_academic_standing;
                    cout << "Enter new academic standing of the student: ";
                    cin.ignore();
                    getline(cin, new_academic_standing);
                    students[i].academic_standing = new_academic_standing;
                    cout << "Academic Standing Updated!\n";
                }
                break;
                case 16:
                {
                    string new_medical_conditions;
                    cout << "Enter new medical conditions of the student: ";
                    cin.ignore();
                    getline(cin, new_medical_conditions);
                    students[i].medical_conditions = new_medical_conditions;
                    cout << "Medical Conditions Updated!\n";
                }
                break;
                case 17:
                {
                    bool new_fee_paid_status;
                    cout << "Enter new fee paid status of the student (0 for Unpaid, 1 for Paid): ";
                    cin >> new_fee_paid_status;
                    students[i].is_fee_paid = new_fee_paid_status;
                    cout << "Fee Paid Status Updated!\n";
                }
                break;
                case 18:
                {
                    string new_financial_status;
                    cout << "Enter new financial status of the student: ";
                    cin.ignore();
                    getline(cin, new_financial_status);
                    students[i].financial_status = new_financial_status;
                    cout << "Financial Status Updated!\n";
                }
                break;
                case 19:
                {
                    string new_emergency_contact;
                    cout << "Enter new emergency contact of the student: ";
                    cin.ignore();
                    getline(cin, new_emergency_contact);
                    students[i].emergency_contact = new_emergency_contact;
                    cout << "Emergency Contact Updated!\n";
                }
                break;
                case 20:
                    cout << "Going Back...\n";
                    break;
                default:
                    cout << "Enter a valid number!\n";
                }
                break;
            }
        }
    } while (choice != 20);
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
            cout << "-----------------------------------------------------" << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "Age: " << students[i].age << endl;
            cout << "Date of Birth: " << students[i].date_of_birth << endl;
            cout << "Address: " << students[i].address << endl;
            cout << "Phone Number: " << students[i].phone_number << endl;
            cout << "Email: " << students[i].email << endl;
            cout << "CNIC: " << students[i].cnic << endl;
            cout << "Roll Number: " << students[i].roll_number << endl;
            cout << "Blood Group: " << students[i].blood_group << endl;
            cout << "GPA: " << students[i].gpa << endl;
            cout << "Degree: " << students[i].degree << endl;
            cout << "Joining Session: " << students[i].joining_session << endl;

            cout << "Courses: ";
            for (int j = 0; j < 5; j++)
            {
                cout << students[i].courses[j] << " ";
            }
            cout << "\n";

            cout << "Scholarship: " << students[i].scholarship << endl;
            cout << "Academic Standing: " << students[i].academic_standing << endl;
            cout << "Medical Conditions: " << students[i].medical_conditions << endl;
            cout << "Fee Paid: " << (students[i].is_fee_paid ? "Yes" : "No") << endl;
            cout << "Financial Status: " << students[i].financial_status << endl;
            cout << "Emergency Contact: " << students[i].emergency_contact << endl;
            cout << "-----------------------------------------------------" << endl;
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
    cout << endl;
}

void sortByAge()
{
    for (int i = 0; i < student_count - 1; i++)
    {
        for (int j = 0; j < student_count - i - 1; j++)
        {
            if (students[j].age > students[j + 1].age)
            {
                StudentData temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << "Sorted By Age!";
    cout << endl;
}

void sortByDegree()
{
    for (int i = 0; i < student_count - 1; i++)
    {
        for (int j = 0; j < student_count - i - 1; j++)
        {
            if (students[j].degree > students[j + 1].degree)
            {
                StudentData temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << "Sorted By Degree!";
    cout << endl;
}

void sortByJoiningSession()
{
    for (int i = 0; i < student_count - 1; i++)
    {
        for (int j = 0; j < student_count - i - 1; j++)
        {
            if (students[j].joining_session > students[j + 1].joining_session)
            {
                StudentData temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << "Sorted By Joining Session!";
    cout << endl;
}

void sortByRollNumber()
{
    for (int i = 0; i < student_count - 1; i++)
    {
        for (int j = 0; j < student_count - i - 1; j++)
        {
            if (students[j].roll_number > students[j + 1].roll_number)
            {
                StudentData temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    cout << "Sorted By Roll Number!";
    cout << endl;
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
        cout << "4. Display all students\n";
        cout << "5. Display number of students\n";
        cout << "6. Search By ID\n";
        cout << "7. Sort Methods(ascending order)\n";
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
            searchById();
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
                sortByAge();
                break;
            case 2:
                sortById();
                break;
            case 3:
                sortByDegree();
                break;
            case 4:
                sortByJoiningSession();
                break;
            case 5:
                sortByRollNumber();
                break;
            default:
                cout << "Enter a valid choice\n";
                break;
            }
            break;
        case 8:
            cout << "Exit Program! Bye\n";
            break;
        default:
            cout << "Enter a valid choice\n";
            break;
        }

    } while (choice != 8);
}

int main()
{
    loadFromFile();
    menu();
    saveToFile();
    return 0;
}