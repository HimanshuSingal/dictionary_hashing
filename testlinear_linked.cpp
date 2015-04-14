#include <iostream>
#include "linearlist.h"
#include "linkedlist.h"
#include <cstring>
#include <stdlib.h>
class Student
{
public:
  char roll[50];
  int marks;
};

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
    LinearList<Chain<Student> > list(4);
    //std::cout<<&(list.getElement(1));
    
    //std::cout<< list.getElement(1).length();
    
    /*Chain<Student> * t;
     t=(Chain<Student> *)malloc(sizeof(Chain<Student>)*4);
     // LinearList<Chain<Student> > list(4);*/
    strcpy(s1.roll,"B13312");
    s1.marks=92;
    strcpy(s2.roll,"B13311");
    s2.marks=82;
    strcpy(s3.roll,"B13319");
    s3.marks=34;
    list.getElement(1).append(s1);
    list.getElement(1).append(s2);
    list.getElement(1).append(s3);


    /*list.insert(1,s1);
    list.insert(2,s2);
    list.insert(4,s3);
    list.deleteElement(2,s2);
    std::cout<< list.search(s2,comp)<<"\n";
    std::cout<< s2.roll<<"\n";
    //list.find(2,s2);
    //std::cout<< s2.roll<<"\n";
    */
  
    while(list.getElement(1).traverse(s3))
      {
	std::cout<<s3.roll<<"\n";
	}
    std::cout<<"2nd \n";
    while(list.getElement(2).traverse(s3))
      {
	std::cout<<s3.roll<<"\n";
	}

    return 0;
  }

