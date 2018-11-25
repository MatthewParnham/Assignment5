#include <iostream>
#include "GenBST.h"
#include "GenStack.h"
#include "Faculty.h"
#include "Menu.h"
#include "Person.h"
#include "Student.h"
#include "GenTreeNode.h"
#include "GenDoublyLL.h"
#include <fstream>
#include <string>
#include <unordered_set>
#include <limits>

using namespace std;

int main(int argc, char const *argv[]) {

  // Declare Tables
  GenBST<Student> masterStudent;
  GenBST<Faculty> masterFaculty;
  unordered_set<int> studentMap;
  unordered_set<int> facultyMap;

  // Check if save file exists

  ifstream in;
  in.open("masterStudent"); //student loading
  if(in) {
    string line;
    while(getline(in, line)) { //each line of save file is a student. substring is used to
      int ID = stoi(line.substr(4,(line.find("Name")-5)));
      string name = line.substr(line.find("Name")+6,line.find("Level")-1-(line.find("Name")+6));
      string level = line.substr(line.find("Level")+7,line.find("Major")-1-(line.find("Level")+7));
      string major = line.substr(line.find("Major")+7,line.find("GPA")-1-(line.find("Major")+7));
      double gpa = stod(line.substr(line.find("GPA")+5,line.find("Advisor")-1-(line.find("GPA")+5)));
      int advisor = stoi(line.substr(line.find("Advisor")+9,string::npos));
      masterStudent.insert(*(new Student(ID,name,level,major,gpa,advisor)));
      studentMap.insert(ID);
    }
  }
  in.close();

  in.open("masterFaculty"); //faculty loading
  if(in) {
    string line;
    while(getline(in, line)) { //this functions the same as for students except the advisee list
      int ID = stoi(line.substr(4,(line.find("Name")-5)));
      string name = line.substr(line.find("Name")+6,line.find("Level")-1-(line.find("Name")+6));
      string level = line.substr(line.find("Level")+7,line.find("Department")-1-(line.find("Level")+7));
      string department = line.substr(line.find("Department")+12,line.find("Advisees")-1-(line.find("Department")+12));
      masterFaculty.insert(*(new Faculty(ID,name,level,department)));
      facultyMap.insert(ID);
      string advisees = line.substr(line.find("Advisees")+10,string::npos);

      for (int i = 0; i < advisees.length(); i++) { //advisee list is loaded in
        if(advisees[i] == ' ') {
          masterFaculty.search(ID).adviseeList->insertFront(new int(stoi(advisees.substr(0,i))));
          advisees = advisees.substr(i+1,string::npos);
          i = -1;
        }
      }
    }
  }
  in.close();

//Main Loop of program
  Menu menu(&masterStudent,&masterFaculty, &studentMap, &facultyMap);
  int ans = 0;
  while(ans != 14) {
    menu.printMenu(); //menu is printed
    cout << "\nYour Selection: "; //user input is taken
    while (!(cin >> ans))
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cerr << "INVALID INPUT please enter an Integer" << endl;
    }

    if(ans > 0 && ans < 15)
    {
      cout << endl;
      menu.prompt(ans); //input is parsed and appropriate function is called
    }

    else{
      cout << "INVALID INPUT" << endl;
    }
  }


  // Save
  ofstream out;
  out.open("masterStudent", std::ofstream::out | std::ofstream::trunc); //student table saved
  masterStudent.saveTree(out, masterStudent.getRoot());
  out.close();

  out.open("masterFaculty", std::ofstream::out | std::ofstream::trunc); //faculty table saved
  masterFaculty.saveTree(out, masterFaculty.getRoot());
  out.close();

  return 0;
}
