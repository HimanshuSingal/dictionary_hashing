#ifndef _LINKEDLIST_H_INCLUDED_
#define _LINKEDLIST_H_INCLUDED_
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#define max 5000000
template <class T>
class Chain{
private:
  typedef struct _ChainNode
  {
    T data;
    _ChainNode *link;
  }ChainNode;
  ChainNode  *first;
  ChainNode  *last;
  ChainNode  *iter;
  int len;
public:
  Chain();
  ~Chain();
  void append(T x);
  bool insert(int k,T x);
  bool isEmpty();
  int length();
  int search(T x);
  int search(T x,bool (* function)(T a,T b));
  int get(T x,bool (* function)(T a,T b),T & set);
  bool find(int  k, T &x);
  bool delete_elem(int k,T &x);
  bool traverse(T & x);
  void join(Chain* x);
	

};
template <class T>
Chain<T>::Chain()
  { // Constructor for the linked linear list
    first = 0;
    last=0;
    len=0;
    iter=0;
  }
template <class T>
Chain<T>::~Chain()
  { // Distructor for the linked linear list. Delete all the nodes in chain
    ChainNode *next;  // Next node
    while (first){
      next = first -> link;
      delete  first;
      first = next;
    }
  }
  template <class T>
  bool Chain<T>::isEmpty()
  {
    return len==0;
  }
template <class T>
int Chain<T>::length()
  {
    return len;
  }
template <class T>
int Chain<T>::search(T x)
  {
    ChainNode *current=first;
    int i=1;
    while(current)
      {
	if((current->data)==x)
	  return i;
	current=current->link;
	i++;
      }
    return 0;
  }
template <class T>
int Chain<T>::search(T x,bool (* function)(T a,T b))
  {
    ChainNode *current=first;
    int i=1;
    while(current)
      {
	if(function(current->data,x))
	  return i;
	current=current->link;
	i++;
      }
    return 0;
  }
template <class T>
int Chain<T>::get(T x,bool (* function)(T a,T b),T & set)
  {
    ChainNode *current=first;
    int i=1;
    while(current)
      {
	if(function(current->data,x))
	  {
	    set=current->data;
	  return i;
	  }
	current=current->link;
	i++;
      }
    return 0;
  }

template <class T>
bool  Chain<T>::find(int  k, T & x)
  { // Set x to the kth element and return true if kth element is present otherwise return false.
    if (k < 1 || k > len)   return   false;
    ChainNode *current=first;
    int i=1;
    while(i<k)
      {
	current=current->link;
	i++;
      }
    x=current->data;
    return   true;
  }
template <class T>
void Chain<T>::append(T x)
  {  
    if(first==0)
      {
	first=(ChainNode*)malloc(sizeof(ChainNode));
    	first->data=x;
	first->link=0;
	last=first;
//std::cout<<this<<"\n";
      }
    else
      {
	ChainNode  *p=(ChainNode*)malloc(sizeof(ChainNode)) ; 
	p -> data = x;
	p -> link = 0;
	last->link=p;
	last=p;
      }
    iter=first;
    len++;
//std::cout<<this->len<<"\n";
  }
template <class T>
bool Chain<T>::insert(int k,T x)
  {  
    if (k < 1 || k > len)   return   false;
    ChainNode *current=first;
    int i=1;
    while(i<k)
      {
	current=current->link;
	i++;
      }
  
	ChainNode  *p=(ChainNode*)malloc(sizeof(ChainNode)) ; 
	p -> data = x;
	p -> link = current->link;
	current->link=p;
    iter=first;
    len++;
    return true;
  }
template <class T>
bool Chain<T>::delete_elem(int k,T &x)
{  
  if (k < 1 || k > len)   return   false;
  if(k==1)
  {
      x=first->data;
      if(len==1)
      {
         first=0;
         last=0;
      }
      else
      {
         first=first->link;
      }
  }
  else
  {
    ChainNode *current=first;
    int i=1;
    while(i<(k-1))
      {
	current=current->link;
	i++;
      }
  ChainNode* p=current->link;
  current->link=p->link;
  x = p->data;
  }
  iter=first;
  len--;

  return true;     
  }
template <class T>
bool Chain<T>::traverse(T & x)
  {
     if(iter)
        x=iter->data;
     else
        {
        iter=first;
        return false;
        }
    iter=iter->link;
    return true;
  }
template <class T>
void Chain<T>::join(Chain* x)
  {
    if(x->first)
      {
	last->link=x->first;
	last=x->last;}
  }
#endif
 
