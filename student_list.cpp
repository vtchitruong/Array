#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

using namespace std;

struct Student
{
    int number; // ordinal number in class
    string fullName;
    int birthYear;
    bool gender; // true: male; false: female

    double math;
    double cs; // computer science
    double english;

    double avg; // average
};

// global variables
Student st[1000];
int size; // number of elements

//-------------------------------------------------------
void init()
{
    size = 5;

    st[0] = {1, "William Henry Gates III (Bill Gates)", 2021, true};
    st[1] = {2, "Elon Reeve Musk FRS", 2022, true};
    st[2] = {3, "Mark Elliot Zuckerberg", 2023, true};
    st[3] = {4, "Thai Van Linh", 2024, false};
    st[4] = {5, "Park Hang Seo", 2018, true};

    for (int i = 0; i < size; i++)
    {
        st[i].math = 0;
        st[i].cs = 0;
        st[i].english = 0;
        st[i].avg = 0;
    }
}

//-------------------------------------------------------
void showInfo()
{
    cout << "STUDENT LIST" << endl;
    
    cout << ' ' << string(69, '-') << endl;
    cout << "| Num | Name" << string(40 - 4, ' ') << "|";
    cout << " Birth Year | Gender |" << endl;
    cout << ' ' << string(69, '-') << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "| ";
        
        // number
        cout << st[i].number;
        string tmp_number;
        tmp_number = to_string(st[i].number); // convert number to string
        cout << string(4 - tmp_number.length(), ' ') << "| ";
        
        // name
        cout << st[i].fullName << string(40 - st[i].fullName.length(), ' ') << "| ";
        
        // birth year
        cout << st[i].birthYear << string(11 - 4, ' ') << "| ";

        // gender
        string tmp_gender = st[i].gender ? "Male" : "Female";        
        cout << tmp_gender << string(7 - tmp_gender.length(), ' ') << "| ";
        cout << endl;
    }

    cout << ' ' << string(69, '-') << endl;    
}

//-------------------------------------------------------
void showScore()
{
    cout << "SCORE LIST" << endl;
    
    cout << ' ' << string(82, '-') << endl;
    cout << "| Num | Name" << string(40 - 4, ' ') << "| ";
    cout << "Maths | CS   | English | Average |" << endl;
    cout << ' ' << string(82, '-') << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "| ";
        
        // number
        cout << st[i].number;
        string tmp_number;
        tmp_number = to_string(st[i].number); // convert number to string
        cout << string(4 - tmp_number.length(), ' ') << "| ";
        
        // name
        cout << st[i].fullName << string(40 - st[i].fullName.length(), ' ') << "| ";

        // score
        cout << fixed << setprecision(1);
        cout << setw(5) << st[i].math << " | ";
        cout << setw(4) <<st[i].cs << " | ";
        cout << setw(7) <<st[i].english << " | ";
        cout << setw(7) <<st[i].avg << " |";

        cout << endl;
    }
    cout << ' ' << string(82, '-') << endl;
}

//-------------------------------------------------------
void inputScore(char subject)
{
    for (int i = 0; i < size; i++)
    {
        cout << st[i].fullName << ": ";

        switch (subject)
        {
        case 'm':     
            cin >> st[i].math;
            break;
        case 'c':            
            cin >> st[i].cs;
            break;
        case 'e':            
            cin >> st[i].english;
            break;
        default:
            cout << "Subject invalid. Please try again." << endl;
            break;
        }
    }
}

//-------------------------------------------------------
void average()
{
    for (int i = 0; i < size; i++)
    {
        st[i].avg = (st[i].math + st[i].cs + st[i].english) / 3;
    }
}

//-------------------------------------------------------
void addNewStudents(int quantity)
{
    cout << "You are inputting data of " << quantity << " students." << endl;
   
    for (int i = size; i < size + quantity; i++)
    {
        cout << "Student " << i + 1 << ":" << endl;
        st[i].number = i + 1;       

        cout << "Name: ";
        getline(cin, st[i].fullName);       
        fflush(stdin);

        cout << "Birth year: ";
        cin >> st[i].birthYear;
        cin.ignore();

        cout << "Gender: (1 for male, 0 for female) ";
        int g; // gender
        cin >> g;
        st[i].gender = g == 1 ? true : false;
        cin.ignore();

        st[i].math = 0.0;
        st[i].cs = 0.0;
        st[i].english = 0.0;
        st[i].avg = 0.0;
    }

    size += quantity;
}

//-------------------------------------------------------
void removeStudent(int number)
{
    cout << "Are you sure to remove student number " << number << "? (Y/N) ";
    char answer;
    cin >> answer; 

    if (answer == 'Y' || answer == 'y')
    {
        number = number - 1; // real number of the array, not the number displayed for user

        for (int i = number; i < size - 1; i++)
        {
            st[i].fullName = st[i + 1].fullName;
            st[i].birthYear = st[i + 1].birthYear;
            st[i].gender = st[i + 1].gender;
            st[i].math = st[i + 1].math;
            st[i].cs = st[i + 1].cs;
            st[i].english = st[i + 1].english;
            st[i].avg = st[i + 1].avg;
        }

        size--;
    }
    else
    {
        cout << "Remove command aborted." << endl;
    }
}

//-------------------------------------------------------
int main()
{
    init();
    showInfo();

    // inputScore('c'); // enter scores for Computer science

    // average();
    // showScore();

    addNewStudents(2); // add 2 new students
    showInfo();

    removeStudent(5); // remove student number 5
    showInfo();

    return 0;
}