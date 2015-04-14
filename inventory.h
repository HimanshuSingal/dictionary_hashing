#ifndef _INVENTORY_INCLUDED_
#define _INVENTORY_INCLUDED_
#include <string.h>
#include <iostream>
#include <fstream>
class record
{
  public:
  char item_num[10];
  char item_name[50];
  char manu_comp[50];
  int num;
  float price;
  char address_manu[100];
  int flag;
  int null;
  record();
  void print();
  void tofile(std::ofstream & outfile);
  void input(std::ifstream & infile);
  void input();
};
record::record()
{
  item_num[0]='\0';
  item_name[0]='\0';
  manu_comp[0]='\0';
  address_manu[0]='\0';
  flag=0;
  null=0;
  num=0;
  price=0;
}
void record::print()
{
  std::cout<<"Item Num :"<<item_num<<"\n";
  std::cout<<"Item Name :"<<item_name<<"\n";
  std::cout<<"Pieces :"<<num<<"\n";
  std::cout<<"Price :"<<price<<"\n";
 std::cout<<"Manufacturing Comp :"<<manu_comp<<"\n";
  std::cout<<"Manufacturer's Address :"<<address_manu<<"\n";
 
}
void record::tofile(std::ofstream & outfile)
{
  
outfile<<item_num<<" "<<item_name<<" "<<" "<<num<<" "<<price<<" "<<manu_comp<<" "<<address_manu<<"\n";
}
void record::input(std::ifstream & infile)
{
  infile>>item_num>>item_name>>num>>price>>manu_comp>>address_manu;
}
void record::input()
{
  std::cin>>item_num>>item_name>>num>>price>>manu_comp>>address_manu;
}
bool comp(record a,record b)
{
  if(strcmp(a.item_num,b.item_num)==0)
    return true;
  else
    return false;
}
#endif
