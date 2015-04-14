#ifndef _OPEN_HASHING_H_INCLUDED_
#define _OPEN_HASHING_H_INCLUDED_
#include "inventory.h"
#include "linearlist.h"
#include "hashing.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
class Open_hashing
{
 private:
    LinearList<record> table;
    int m;           //maximum size
    int m_re;
    Hashing f; 
 public:
    Open_hashing();
  Open_hashing(int m);
  Open_hashing(int m,int m_re);
  ~Open_hashing();
  void assign(int m);
  void assign(int m,int m_re);
  bool linearprobing(record a);
  bool linearsearch(char key[]);
  bool linearprint(char key[]);
  bool lineardelete(char key[]);
  bool doublehashing(record a);
  bool doublesearch(char key[]);
  bool doubleprint(char key[]);
  bool doubledelete(char key[]);
  void printAll(); 
};
Open_hashing::Open_hashing()
{
  
}

Open_hashing::Open_hashing(int m)
{
   this->m=m;
   table.assign_size(m);
   f.assign(33,m);
}
Open_hashing::Open_hashing(int m,int m_re)
{
   this->m=m;
   this->m_re=m_re;
   table.assign_size(m);
   f.assign(33,m,m_re);
}

Open_hashing::~Open_hashing()
{ // Distructor for the sequential linear list
  //delete[] &table;
  //delete[] &f;
  }
void Open_hashing::assign(int m)
{
  this->m=m;
   table.assign_size(m);
   f.assign(33,m);
}
void Open_hashing::assign(int m,int m_re)
{
   this->m=m;
   this->m_re=m_re;
   table.assign_size(m);
   f.assign(33,m,m_re);
}

bool Open_hashing::linearprobing(record a)
{
  int pos=f.map(a);
  int i=0;
  while(((table.getElement(pos).null)!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
      pos=(pos+1)%m;
      i++;
    }
  if(i==m)
    return false;
  a.null=1;
  table.getElement(pos)=a;
  return true;
}
bool Open_hashing::linearsearch(char key[])
{
  int pos=f.map(key);
  int i=0;
  while(((table.getElement(pos).null)!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
      if(table.getElement(pos).flag == 0)
      if(strcmp(table.getElement(pos).item_num,key)==0)
	return true;
      pos=(pos+1)%m;
      i++;
    }
    return false;
}
bool Open_hashing::linearprint(char key[])
{
  int pos=f.map(key);
  int i=0;
  while(((table.getElement(pos).null)!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
 if(table.getElement(pos).flag == 0)
           if(strcmp(table.getElement(pos).item_num,key)==0)
	{
	  table.getElement(pos).print();
	  return true;
	}
      pos=(pos+1)%m;
      i++;
    }
    return false;
}

bool Open_hashing::lineardelete(char key[])
{
  int pos=f.map(key);
  int i=0;
  while((strcmp(table.getElement(pos).item_num,"")!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
      if(strcmp(table.getElement(pos).item_num,key)==0)
	{
	  record a;
	  a.flag=1;
	  table.getElement(pos)=a;	
	  return true;
	 
	}
      pos=(pos+1)%m;
      i++;
    }
    return false;
}

bool Open_hashing::doublehashing(record a)
{
  int pos=f.map2(a);
  int i=0;
  int offset=f.map2_re(a);
  while(((table.getElement(pos).null)!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
      pos=(pos+offset)%m;
      i++;
    }
  if(i==m)
    return false;
  a.null=1;
  table.getElement(pos)=a;
  return true;
}


bool Open_hashing::doublesearch(char key[])
{
  int pos=f.map2(key);
  int i=0;
  int offset=f.map2_re(key);
  while(((table.getElement(pos).null)!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
      if(table.getElement(pos).flag == 0)
      if(strcmp(table.getElement(pos).item_num,key)==0)
	return true;
      pos=(pos+offset)%m;
      i++;
    }
    return false;
}
bool Open_hashing::doubleprint(char key[])
{
  int pos=f.map2(key);
  int i=0;
  int offset=f.map2_re(key);
  while(((table.getElement(pos).null)!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
 if(table.getElement(pos).flag == 0)
           if(strcmp(table.getElement(pos).item_num,key)==0)
	{
	  table.getElement(pos).print();
	  return true;
	}
      pos=(pos+offset)%m;
      i++;
    }
    return false;
}

bool Open_hashing::doubledelete(char key[])
{
  int pos=f.map2(key);
  int i=0;
  int offset=f.map2_re(key);
  while((strcmp(table.getElement(pos).item_num,"")!=0 || table.getElement(pos).flag == 1 ) && i!=m)
    {
      if(strcmp(table.getElement(pos).item_num,key)==0)
	{
	  record a;
	  a.flag=1;
	  table.getElement(pos)=a;	
	  return true;
	 
	}
      pos=(pos+offset)%m;
      i++;
    }
    return false;
}
void Open_hashing::printAll()
{
  std::ofstream outfile;
  outfile.open("database.txt",std::ofstream::out);
  
  for(int i=0;i<m;i++)
    {
      if(table.getElement(i).null==1 && table.getElement(i).flag==0)
	{
	  table.getElement(i).tofile(outfile);
	}
    }
  outfile.close();
}

#endif
