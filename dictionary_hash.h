#ifndef _DICTIONARY_H_INCLUDED_
#define _DICTIONARY_H_INCLUDED_
#include "openhashing.h"
#include "chainhashing.h"
#include "primegen.h"
class Dictionary
{
  int flag;
  int m;
  int m_re;
  PrimeGen prime;
  Open_hashing data2;
  Chain_Hashing data1;
  bool insert_inside(record a);
  public:
  Dictionary();
  Dictionary(int flag);
   ~Dictionary();
  void assign(int flag);
   bool insert(record a);
  bool search(char key[]);
 bool print(char key[]);
 bool delete1(char key[]);
 void modifyFile();
};
Dictionary::Dictionary()
{
  
}

Dictionary::Dictionary(int flag)
{
  this->flag=flag;
  system("wc -l database.txt > temp.txt");
  std::ifstream infile;
  infile.open("temp.txt");
  int line;
  infile>>line;
  infile.close();
  if(line>=10)
    {
      m=2*line;
      m_re=prime.nextprime((int)line/2);
    }
  else
    {
      m=17;
      m_re=7;
    }
  if(flag==1)
    {
    data1.assign(m);
    }
  if(flag==2)
    {
    data2.assign(m);
    }
  if(flag==3)
    {
      m=prime.nextprime(m);
      data2.assign(m,m_re);
    }

  record tmp;
  infile.open("database.txt");
  for(int i=1;i<=line;i++)
    {
      tmp.input(infile);
      if(!insert(tmp))
	break;
    }
  infile.close();
 
}

void Dictionary::assign(int flag)
{
  this->flag=flag;
  system("wc -l database.txt > temp.txt");
  std::ifstream infile;
  infile.open("temp.txt");
  int line;
  infile>>line;
  infile.close();
  if(line>=10)
    {
      m=2*line;
      m_re=prime.nextprime((int)line/2);
    }
  else
    {
      m=17;
      m_re=7;
    }
  if(flag==1)
    {
      data1.assign(m);
    }
  if(flag==2)
    {
      data2.assign(m);
    }
  if(flag==3)
    {
      m=prime.nextprime(m);
      data2.assign(m,m_re);
    }

  record tmp;
  infile.open("database.txt");
  for(int i=1;i<=line;i++)
    {
      tmp.input(infile);
      if(!insert(tmp))
	break;
    }
  infile.close();
}


Dictionary::~Dictionary()
{
}
bool Dictionary::insert_inside(record a)
{
  if(flag==1)
    {
     return data1.insert(a);
    }
  if(flag==2)
    {
      return data2.linearprobing(a);
    }
  if(flag==3)
    {
      return data2.doublehashing(a);
    }
  return false;
}
bool Dictionary::insert(record a)
{
  if(insert_inside(a))
    {
    return true;
    }
  else
    {
      //  std::cout<<"Table Full!!Rehashing required\n";
      return false;
    }
  
}
bool Dictionary::search(char key[])
{
  if(flag==1)
    {
     return data1.search(key);
    }
  if(flag==2)
    {
      return data2.linearsearch(key);
    }
  if(flag==3)
    {
      return data2.doublesearch(key);
    }
  return false;

}
bool Dictionary::print(char key[])
{
  if(flag==1)
    {
     return data1.print(key);
    }
  if(flag==2)
    {
      return data2.linearprint(key);
    }
  if(flag==3)
    {
      return data2.doubleprint(key);
    }
  return false;
}

bool Dictionary::delete1(char key[])
{
  if(flag==1)
    {
      modifyFile();
     return data1.delete1(key);
    }
  if(flag==2)
    {
      modifyFile();
      return data2.lineardelete(key);
    }
  if(flag==3)
    {
      modifyFile();
      return data2.doubledelete(key);
    }
  return false;
}
void Dictionary::modifyFile()
{
  if(flag==1)
    data1.printAll();
  else
    data2.printAll();
}

#endif
