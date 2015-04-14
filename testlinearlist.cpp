#include <iostream>
#include "linearlist.h"
#include <cstring>
class Student
{
public:
  char roll[50];
  int marks;
Student();
};
Student::Student()
{
roll[0]='\0';
marks=0;
}
bool comp(Student s1,Student s2)
{
  if(strcmp(s1.roll,s2.roll)==0)
    return true;
  return false;
}

 int main()
  {
    Student s1;
    Student s2;
    Student s3;
    // LinearList<Student> list1;
    LinearList<Student> list;
    list.assign_size(4);
    //list1=list;
    strcpy(s1.roll,"B13312");
    s1.marks=92;
    strcpy(s2.roll,"B13311");
    s2.marks=82;
    strcpy(s3.roll,"B13319");
    s3.marks=34;
    list.insert(1,s1);
    list.insert(2,s2);
    list.insert(4,s3);
    list.deleteElement(2,s2);
    std::cout<< list.search(s2,comp)<<"\n";
    std::cout<< s2.roll<<"\n";
    //list.find(2,s2);
    //std::cout<< s2.roll<<"\n";
    
    /*while(list.traverse(s3))
      {
	std::cout<<s3.roll<<"\n";
	}*/
    return 0;
  }

