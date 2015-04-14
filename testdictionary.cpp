#include "dictionary_hash.h"
#include <fstream>
#include <iostream>
#include <assert.h>

int main()
{
  std::cout<<"Enter Collision Method:\nEnter:\n1 for Chaining\n2 for Linear Probing\n3 for double hashing\n ";
  int flag;
  std::cin>>flag;
  Dictionary data(flag);
  //assign_data(data,flag,m,m_re);
  int ch=0;
  record a;
  char key[10];
  while(ch!=5)
    {
      std::cout<<"Menu::\n1 for insertion\n2 for search\n3 for delete\n4 for print\n5 for exit\n";
      std::cin>>ch;
      switch(ch){
      case 1:
	std::cout<<"Input record:\nItem_Num Item_Name Remaining_Num Price Manufacturing_Company Manufacturing_addres\n";
	a.input();
	if(!data.insert(a))     // inserting in the dictionary
	  {
	    std::cout<<"Table Full - Rehashing the table ...\n";
      	    data.assign(flag);   // reassigning memory
	  }
	data.modifyFile();      // updates the database.txt as per dictionary in memory
	break;
      case 2:
	std::cout<<"Enter Key\n";
	std::cin>>key;
	if(data.search(key))       //search for a key
	  std::cout<<"Found!!\n";
	else
	  std::cout<<"Not Found!!\n";
	break;
      case 3:
	std::cout<<"Enter Key\n";
	std::cin>>key;
	if(data.delete1(key))     //deletes a key
	  std::cout<<"Deleted Successfully!!\n";
	else
	  std::cout<<"Not Found!!\n";
	break;
      case 4:
	std::cout<<"Enter Key\n";   
	std::cin>>key;
	if(!data.print(key))     //prints a data when its key is entered
	  std::cout<<"Not Found!!\n";
	break;
      }
    }

  return 0;
}
