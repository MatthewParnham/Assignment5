#include "Menu.h"
#include <iostream>
#include <string>
#include "Student.h"
#include "Faculty.h"
#include <stdlib.h>
#include "GenBST.h"
#include <unordered_set>
#include <time.h>
#include <limits>

using namespace std;

//constructor/destructor=========================================================
Menu::Menu(GenBST<Student>* ms, GenBST<Faculty>* mf, unordered_set<int>* sSet, unordered_set<int>* fSet)
{
  masterStudent = ms;
  masterFaculty = mf;
  studentMap = sSet;
  facultyMap = fSet;
}

Menu::~Menu()
{

}

int Menu::randInt(int max) {
  srand(time(NULL));
  return (rand() % max) + 1;
}


void Menu::printMenu()
{
  cout << "\nMENU OPTIONS:\n"
  "1. Print all students and their information (1)\n"
  "2. Print all faculty and their information (2)\n"
  "\n"
  "3. Search for student and display information (3)\n"
  "4. Search for faculty and display information (4)\n"
  "\n"
  "5. Using student ID, print corresponding name and info of faculty advisor (5)\n"
  "6. Using faculty ID, print list of all names and info of their advisees (6)\n"
  "\n"
  "7. Add a new student (7)\n"
  "8. Delete a student (8)\n"
  "\n"
  "9. Add a new faculty member (9)\n"
  "10. Delete a faculty member (10)\n"
  "\n"
  "11. Change a student's advisor (11)\n"
  "12. Remove an advisee from a faculty member (12)\n"
  "13. Rollback, undo (13)\n"
  "14. EXIT (14)\n";
}

void Menu::prompt(int ans)
{
  int id, a;
  string n, l, m, d;
  double g;
  switch(ans) {
    case 1:
      printStudents();
      break;

    case 2:
      printFaculty();
      break;

    case 3:
      cout << "What is the student's ID?: ";
      cin >> id;
      findStudent(id);
      break;

    case 4:
      cout << "What is the faculty member's ID?: ";
      cin >> id;
      findFaculty(id);
      break;

    case 5:
      cout << "What is the Student's ID?: ";
      cin >> id;
      printAdvisor(id);
      break;

    case 6:
      cout << "What is the faculty member's ID?: ";
      cin >> id;
      printAdvisees(id);
      break;

    case 7:
      cin.ignore();
      cout << "Name: " << endl;
      getline(cin, n);
      cout << "Level: " << endl;
      getline(cin, l);
      cout << "Major: " << endl;
      getline(cin, m);
      cout << "GPA: " << endl;
      cin >> g;
      cout << "Advisor: " << endl;
      cin >> a;

      addStudent(n, l, m, g, a);
      break;

    case 8:
      cout << "Student's ID: ";
      cin >> id;
      deleteStudent(id);
      break;

    case 9:
      cin.ignore();
      cout << "Name: " << endl;
      getline(cin, n);
      cout << "Level: " << endl;
      getline(cin, l);
      cout << "Department: " << endl;
      getline(cin, d);
      addFaculty(n, l, d);
      break;

    case 10:
      cout << "Faculty's ID: ";
      cin >> id;
      deleteFaculty(id);
      break;

    case 11:
      cout << "Student's ID: ";
      cin >> id;
      cout << "New Advisor ID: ";
      cin >> a;
      changeAdvisor(id, a);
      break;

    case 12:
      cout << "Student's ID: ";
      cin >> id;
      cout << "Faculty's ID: ";
      cin >> a;
      removeAdvisee(id, a);
      break;

    case 13:
      break;

    case 14:
      cout << "Exiting" << endl;
      break;

    default:
      cout << "INVALID INPUT" << endl;
      cout << "DID NOT EXECUTE" << endl;
      //exit(EXIT_FAILURE);
      break;
  }
}

//1
void Menu::printStudents()
{
  cout << "PRINTING STUDENTS" << endl;
  masterStudent->printTree();
}

//2
void Menu::printFaculty()
{
  cout << "PRINTING FACULTY" << endl;
  masterFaculty->printTree();
}

//3
void Menu::findStudent(int id)
{
  if(studentMap->count(id) > 0) {
    cout << masterStudent->search(id)->key << endl;
  }
  else {
    cout << "No student found with that ID." << endl;
  }
}

//4
void Menu::findFaculty(int id)
{
  if(facultyMap->count(id) > 0) {
    cout << masterFaculty->search(id)->key << endl;
  }
  else {
    cout << "No faculty member found with that ID." << endl;
  }
}

//5
void Menu::printAdvisor(int id)
{
  if(studentMap->count(id) > 0) {
    cout << masterFaculty->search(masterStudent->search(id)->key.getAdvisor())->key << endl;
  }
  else {
    cout << "No student found with that ID." << endl;
  }
}

//6
void Menu::printAdvisees(int id)
{
  if(facultyMap->count(id) > 0) {
    ListNode<int> *curr = masterFaculty->search(id)->key.adviseeList->getFront();

    while(curr != NULL)
    {
      cout << masterStudent->search(*curr->data)->key << endl;
      curr = curr->next;
    }
  }
  else {
    cout << "No faculty member found with that ID." << endl;
  }
}

//7
void Menu::addStudent(string n, string l, string m, double g, int a)
{
  while(true) {
    int id = randInt(500);
    if(studentMap->count(id) == 0) {
      if(facultyMap->count(a) == 0) {
        cout << "No advisor exists with ID " << a << ". Student not added." << endl;
        return;
      }
      masterStudent->insert(*(new Student(id,n,l,m,g,a)));
      studentMap->insert(id);
      masterFaculty->search(a)->key.adviseeList->insertFront(new int(id));
      cout << "Student added with ID " << id << "." << endl;
      return;
    }
  }
}

//8
void Menu::deleteStudent(int id) {
  if(studentMap->count(id) > 0) {
    masterFaculty->search(masterStudent->search(id)->key.getAdvisor())->key.adviseeList->remove(id);
    masterStudent->deleteRec(masterStudent->search(id)->key);
    studentMap->erase(id);
    cout << "Student deleted." << endl;
  }
  else {
    cout << "Student not found." << endl;
  }
}

//9
void Menu::addFaculty(string n, string l, string d) {
  while(true) {
    int id = randInt(500);
    if(facultyMap->count(id) == 0) {
      masterFaculty->insert(*(new Faculty(id,n,l,d)));
      facultyMap->insert(id);
      cout << "Faculty member added with ID " << id << "." << endl;
      return;
    }
  }
}


//10
void Menu::deleteFaculty(int id) {
  if(facultyMap->count(id) > 0) {
    if(masterFaculty->search(id)->key.adviseeList->getSize() > 0) {
      cout << "Please reassign this faculty member's advisees before deleting." << endl;
    }
    else {
      masterFaculty->deleteRec(masterFaculty->search(id)->key);
      facultyMap->erase(id);
      cout << "Faculty member deleted." << endl;
    }
  }
  else {
    cout << "Faculty member not found." << endl;
  }
}

//11
void Menu::changeAdvisor(int sid, int fid) {
  if(studentMap->count(sid) > 0) {
    if(facultyMap->count(fid) == 0) {
      cout << "No advisor exists with ID " << fid << ". Student not added." << endl;
      return;
    }
    masterFaculty->search(masterStudent->search(sid)->key.getAdvisor())->key.adviseeList->remove(sid); //remove student from original advisor
    masterFaculty->search(fid)->key.adviseeList->insertFront(new int(sid)); //add student to new advisor
    masterStudent->search(sid)->key.setAdvisor(fid); //set new advisor to student
    cout << "Student removed from original advisor to Faculty Member " << fid << "." << endl;
  }
  else {
    cout << "Student not found." << endl;
  }

}

//12
void Menu::removeAdvisee(int sid, int fid) {
  cout << "Would you like to then delete the student (1) or change their advisor (2)?: ";
  int ans = 0;
  while(ans != 1 || ans != 2)
  {
    while (!(cin >> ans))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cerr << "INVALID INPUT please enter an Integer" << endl;
    }

    if(ans == 1 || ans == 2)
    {
      break;
    }

    else{
      cout << "INVALID INPUT" << endl;
    }
  }

  if(ans == 1)
  {
    deleteStudent(sid);
  }

  else if(ans == 2)
  {
    cout << "What is the ID of the new Advisor?: ";
    cin >> fid;
    changeAdvisor(sid, fid);
  }
}

//13
void rollBack() {

}
