#ifndef _HASHING_H_INCLUDED_
#define _HASHING_H_INCLUDED_
#include "inventory.h"
#include "linearlist.h"
#include <math.h>
#include <string.h>
class Hashing
{
 private:
  int x;           //polynomial hash code c
  double A;        //
  int m;           //maximum size
  int m_re; 
public:
  Hashing();
  Hashing(int x,int m);
  Hashing(int x,int m,int m_re);
  long long int hashcode(record a);
  int map(record a);
  long long int hashcode(char a[]);
  int map(char a[]);
  int map2(record a);
  int map2(char a[]);
  int map2_re(record a);
  int map2_re(char a[]);
  void assign(int x,int m);
  void assign(int x,int m,int m_re);
};
Hashing::Hashing()
{
  A=0.61803398875;
  x=33;
  m=100;
  m_re=7;
}
Hashing::Hashing(int a,int b)
{
  x=a;
  m=b;
  A=0.61803398875;
}
Hashing::Hashing(int a,int b,int c)
{
  x=a;
  m=b;
  A=0.61803398875;
  m_re=c;
}
void Hashing::assign(int a,int b)
{ 
  x=a;
  m=b;
  A=0.61803398875;	
}
void Hashing::assign(int a,int b,int c)
{ 
  x=a;
  m=b;
  A=0.61803398875;
  m_re=c;	
}
long long int Hashing::hashcode(record a)
{
  long long int val=0;
  int l=strlen(a.item_num);
  for(int i=0;i<l;i++)
     val=val+((long long int)a.item_num[i])*(long long int)pow(x,i);
  //Hashing::long long int val=val; 
 return val;
}
int Hashing::map(record a)
{
  long long int key=hashcode(a);
  double val=key*A;
  double dec=val-floor(val);
  val=dec*m;
  //std::cout<<this.val<<"\n";
  return floor(val);
}
long long int Hashing::hashcode(char key[])
{
  long long int val=0;
  int l=strlen(key);
  for(int i=0;i<l;i++)
     val=val+((long long int)key[i])*(long long int)pow(x,i);
  //Hashing::long long int val=val; 
 return val;
}
int Hashing::map(char key[])
{
  long long int mapkey=hashcode(key);
  double val=mapkey*A;
  double dec=val-floor(val);
  val=dec*m;
  //std::cout<<this.val<<"\n";
  return floor(val);
}
int Hashing::map2(record a)
{
  long long int key=hashcode(a);
  int val=key%m;
  return val;
}
int Hashing::map2(char key[])
{
  long long int mapkey=hashcode(key);
  return mapkey%m;
}
int Hashing::map2_re(record a)
{
  long long int key=hashcode(a);
  int val=m_re-(key%m_re);
  return val;
}
int Hashing::map2_re(char key[])
{
  long long int mapkey=hashcode(key);
  return m_re-(mapkey%m_re);
}

#endif
