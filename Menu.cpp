#include "Menu.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"

using namespace std;

//constructor/destructor=========================================================
Menu::Menu()
{

}

Menu::~Menu()
{

}


void Menu::printMenu()
{
  cout << "MENU OPTIONS:\n"
  "Print all students and their information (1)\n"
  "Print all faculty and their information (2)\n"
  "\n"
  "Search for student and display information (3)\n"
  "Search for faculty and display information (4)\n"
  "\n"
  "Using student ID, print corresponding name and info of faculty advisor (5)\n"
  "Using faculty ID, print list of all names and info of their advisees (6)\n"
  "\n"
  "Add a new student (7)\n"
  "Delete a student (8)\n"
  "\n"
  "Add a new faculty member (9)\n"
  "Delete a faculty member (10)\n"
  "\n"
  "Change a student's advisor (11)\n"
  "Remove an advisee from a faculty member (12)\n"
  "Rollback, undo (13)\n"
  "EXIT (14)\n";
}

void Menu::prompt(int ans)
{
  int id, a;
  string n, l, m;

  switch(ans) {
    case 1:
      printStudents();
      break;

    case 2:
      printFaculty();
      break;

    case 3:
      cout << "What is the student's ID?: ";
      findStudent(id);
      break;

    case 4:
      cout << "What is the faculty member's ID?: ";
      cin >> id;
      findFaculty(id);
      break;

    case 5:
      cout << "What is the Student's ID?: ";
      printAdvisor(id);
      break;

    case 6:
      cout << "What is the faculty member's ID?: ";
      printAdvisees(id);
      break;

    case 7:
      cout << "ID: " << endl;
      cin >> id;
      cout << "Name: " << endl;
      cin >> n;
      cout << "Level: " << endl;
      cin >> l;
      cout << "Major: " << endl;
      cin >> m;
      cout << "Advisor: " << endl;
      cin >> a;

      addStudent(id, n, l, m, a);
      break;

    case 8:
      cout << "Student's ID:"

    default:
      cout << "INVALID INPUT" << endl;
      cout << "DID NOT EXECUTE" << endl;
  }
}

//1
void Menu::printStudents()
{
  cout << "PRINTING STUDENTS" << endl;
}

//2
void Menu::printFaculty()
{
  cout << "PRINTING FACULTY" << endl;
}

//3
Student Menu::findStudent(int id)
{
  cout << "FINDING STUDENT" << endl;

}

//4
Faculty Menu::findFaculty(int id)
{
  cout << "FINDING FACULTY" << endl;
}

//5
void Menu::printAdvisor(int id)
{
  cout << "PRINTING ADVISOR" << endl;
}

//6
void Menu::printAdvisees(int id)
{
  cout << "PRINTING ADVISEES" << endl;
}

//7
void Menu::addStudent(int id, string n, string l, string m, int a)
{
  cout << "ADDING STUDENT" << endl;
}

//8


//9



//10


//11


//12
