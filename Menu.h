#ifndef MENU_H
#define MENU_H

#include "Student.h"
#include "Faculty.h"
#include <string>
#include "GenBST.h"
#include <unordered_set>

class Menu
{
public:
  Menu(GenBST<Student>* ms, GenBST<Faculty>* mf, unordered_set<int>* sSet, unordered_set<int>* fSet);
  ~Menu();

  int randInt(int max); //generates a random int between 1 and max

  void printMenu();
  void prompt(int ans);

//1. Print all Students
  void printStudents();

//2. Print all Faculty
  void printFaculty();

//3. Find student with given ID
  void findStudent(int id);

//4. Find faculty with given ID
  void findFaculty(int id);

//5. print faculty advisor of student with given ID
  void printAdvisor(int id);

//6. Print all advisees of given faculty ID
  void printAdvisees(int id);

//7. Add Student
  void addStudent(string n, string l, string m, double g, int a);

//8. delete student with ID
  void deleteStudent(int id);

//9. add Faculty
  void addFaculty(string n, string l, string d);

//10. delete faculty with ID
  void deleteFaculty(int id);

//11. change advisor (student ID, Faculty ID)
  void changeAdvisor(int sid, int fid);

//12. Remove an advisee from a faculty member
  void removeAdvisee(int sid, int fid);

//13. Rollback
  void rollBack(); //???????

//14. Exit
  void quit();

//inst vars
GenBST<Student>* masterStudent;
GenBST<Faculty>* masterFaculty;
unordered_set<int>* studentMap;
unordered_set<int>* facultyMap;

private:
};

#endif
