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

using namespace std;

int main(int argc, char const *argv[]) {

  // Declare Tables
  GenBST<Student> masterStudent;
  GenBST<Faculty> masterFaculty;

  // Check if save file exists

  ifstream in;
  in.open("masterStudent"); //student loading
  if(in) {
    string line;
    while(getline(in, line)) {
      int ID = stoi(line.substr(4,(line.find("Name")-5)));
      string name = line.substr(line.find("Name")+6,line.find("Level")-1-(line.find("Name")+6));
      string level = line.substr(line.find("Level")+7,line.find("Major")-1-(line.find("Level")+7));
      string major = line.substr(line.find("Major")+7,line.find("Advisor")-1-(line.find("Major")+7));
      int advisor = stoi(line.substr(line.find("Advisor")+9,string::npos));
      masterStudent.insert(*(new Student(ID,name,level,major,advisor)));
    }
  }
  in.close();

  in.open("masterFaculty"); //faculty loading
  if(in) {
    string line;
    while(getline(in, line)) {
      int ID = stoi(line.substr(4,(line.find("Name")-5)));
      string name = line.substr(line.find("Name")+6,line.find("Level")-1-(line.find("Name")+6));
      string level = line.substr(line.find("Level")+7,line.find("Department")-1-(line.find("Level")+7));
      string department = line.substr(line.find("Department")+12,line.find("Advisees")-1-(line.find("Department")+12));
      masterFaculty.insert(*(new Faculty(ID,name,level,department)));
      string advisees = line.substr(line.find("Advisees")+10,string::npos);

      for (int i = 0; i < advisees.length(); i++) {
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
  Menu menu(&masterStudent,&masterFaculty);
  int ans;
  while(ans != 14) {
    menu.printMenu();
    cin >> ans;
    menu.prompt(ans);
  }


  // Save
  ofstream out;
  out.open("masterStudent", std::ofstream::out | std::ofstream::trunc);
  masterStudent.saveTree(out, masterStudent.getRoot());
  out.close();

  out.open("masterFaculty", std::ofstream::out | std::ofstream::trunc);
  masterFaculty.saveTree(out, masterFaculty.getRoot());
  out.close();

  return 0;
}
