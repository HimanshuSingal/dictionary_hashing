#ifndef _CHAIN_HASHING_H_INCLUDED_
#define _CHAIN_HASHING_H_INCLUDED_
#include "inventory.h"
#include "linearlist.h"
#include "linkedlist.h"
#include "hashing.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
class Chain_Hashing
{
 private:
    LinearList<Chain<record> > table;
    int m;           //maximum size
    Hashing f; 
 public:
    Chain_Hashing();
  Chain_Hashing(int m);
  ~Chain_Hashing();
  void assign(int m);
  bool insert(record a);
  bool search(char key[]);
  bool delete1(char key[]);
  bool print(char key[]);
  void printAll();
  };
Chain_Hashing::Chain_Hashing(int m)
{
   this->m=m;
   table.assign_size(m);
   f.assign(33,m);
}
Chain_Hashing::Chain_Hashing()
{
 
}
void Chain_Hashing::assign(int m)
{
   this->m=m;
   table.assign_size(m);
   f.assign(33,m);
}

Chain_Hashing::~Chain_Hashing()
{ // Distructor for the sequential linear list
  //delete[] &table;
  //delete[] &f;
  }

bool Chain_Hashing::insert(record a)
{
  int pos=f.map(a);
  int i=0;
  if(table.getElement(pos).length() >= (m/2))
    return false;
  table.getElement(pos).append(a);
 
  return true;
}
bool Chain_Hashing::search(char key[])
{
  int pos=f.map(key);
  record a;
  strcpy(a.item_num,key);
  return (table.getElement(pos).search(a,comp)!=0);
}

bool Chain_Hashing::print(char key[])
{
  int pos=f.map(key);
  record a;
  record b;
  strcpy(a.item_num,key);
  if(table.getElement(pos).get(a,comp,b)!=0)
    {
      b.print();
  return true;
}
  return false;
}
void Chain_Hashing::printAll()
{
  std::ofstream outfile;
  outfile.open("database.txt",std::ofstream::out);
  for(int i=0;i<m;i++)
    {
      if(table.getElement(i).length()!=0)
	{
	  record a;
	  while(table.getElement(i).traverse(a))
	    {
	      a.tofile(outfile);
	    }
	}
    }
  outfile.close();
}
bool Chain_Hashing::delete1(char key[])
{
  int pos=f.map(key);
  record a;
  strcpy(a.item_num,key);
  int k=table.getElement(pos).search(a,comp);
  return table.getElement(pos).delete_elem(k,a);
}
#endif
