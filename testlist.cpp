#include <iostream>
#include "linkedlist.h"
#include <cstring>
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
    Chain<Student> list;
    strcpy(s1.roll,"B13312");
    s1.marks=92;
    strcpy(s2.roll,"B13311");
    s2.marks=82;
    strcpy(s3.roll,"B13319");
    s3.marks=34;
    list.append(s1);
    list.insert(1,s2);
    list.insert(1,s3);
    list.delete_elem(2,s1);
    std::cout<< list.search(s3,comp)<<"\n";
  
    while(list.traverse(s3))
      {
	std::cout<<s3.roll<<"\n";
      }
  

    //	std::cin>>x;
    //	list.append(x);
    /* for(int i=1;i<=n;i++)
      {
	std::cin>>x;
	//	std::cout<<"Lenth - "<<list.length()<<"\n";
	list.append(x);
	}*/
    /*
    std::cin>>x;
    list.insert(2,x);
    std::cout<<"Lenth - "<<list.length()<<"\n";
    std::cout<<"Ele at 4 - "<<list.find(4,x)<<"\n";
    std::cout<<"Ele at 4 - "<<x<<"\n";

    std::cout<<list.delete_elem(4,x);
    std::cout<<"Lenth - "<<list.length()<<"\n";
    std::cout<<"Search For"<<"\n";
    std::cin>>x;
    std::cout<<"Search For - "<<list.search(x)<<"\n";
    */
    // list.traverse();
    /*
    std::cin >> n;
    for(int i=1;i<=n;i++)
      {
	int x;
	std::cin>>x;
	list2.append(x);
      }
    list.join(&list2);
    list.traverse();
    */
  }
