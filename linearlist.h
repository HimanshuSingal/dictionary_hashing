#ifndef _LINEARLIST_H_INCLUDED_
#define _LINEARLIST_H_INCLUDED_
#include <iostream>
#include <string.h>
#include <stdlib.h>
template <class T1>
class LinearList{
	private:
		int MaxSize;
		T1* element;    // 1D dynamic array
              	int len;
	public:
		LinearList();
		LinearList(int  MaxSize);
		LinearList(const LinearList& temp);
		~LinearList();
		bool isEmpty();
		int  length();
		int  maxSize();
                void assign_size(int MaxListSize);
		T1& getElement(int k);
		bool find(int  k, T1 & x);
		int  search(T1 x);
		int search(T1 x,bool (* function)(T1 a,T1 b));
 		void deleteElement(int  k, T1 & x);
		void insert(int  k, T1 x);
		
};
template <class T1>
LinearList<T1>::LinearList()
{ // Constructor for the sequential linear list
	len = 0;
}
template <class T1>
LinearList<T1>::LinearList(int MaxListSize)
{ // Constructor for the sequential linear list
	MaxSize = MaxListSize;
       element = new T1[MaxSize];
	len = 0;
}
template <class T1>
void LinearList<T1>::assign_size(int MaxListSize)
{ // Constructor for the sequential linear list
	MaxSize = MaxListSize;
	 element = new T1[MaxSize];
	 // element = (T1*)malloc(MaxSize*sizeof(T1));

	len = 0;
}

template <class T1>
LinearList<T1>::LinearList(const LinearList& temp)
{ // Copy constructor
        MaxSize=temp.MaxSize;
	element = new T1[MaxSize];
	len=temp.len;
	memcpy(element, temp.element, MaxSize);
}
template <class T1>
LinearList<T1>::~LinearList()
{ // Distructor for the sequential linear list
  //delete[] element;
}
template <class T1>
bool  LinearList<T1>::isEmpty()
{ // Function that checks whether the list is empty
	 return   len == 0;
}
template <class T1>
int  LinearList<T1>::length()
{ // Function that returns the length of the list
	 return   len;
}
template <class T1>
int  LinearList<T1>::maxSize()
{ // Function that returns the length of the list
	 return   MaxSize;
}
template <class T1>
T1& LinearList<T1>::getElement(int k)
{ //Function that returns the k-th element of the list
	return element[k];
}
template <class T1>
bool  LinearList<T1>::find(int  k, T1 & x)
{ // Set x to the kth element and return true if kth element is present otherwise return false.
	 if (k < 0 || k >= len)   return   false;
	 x = element[k];
	 return   true;
}
template <class T1>
int  LinearList<T1>::search(T1 x)
{ // Search for x and return the position if found, else return 0.
	 for  (int  i=0; i < len;  i++)
	 	if  (element[i] == x)    return   i;
	 return   0;
}
template <class T1>
int  LinearList<T1>::search(T1 x,bool (* function)(T1 a,T1 b))
{ // Search for x and return the position if found, else return 0.
	 for(int  i=0; i < len;  i++)
	 	if(function(element[i],x))
                    return   i;
	 return   0;
}

template <class T1>
void LinearList<T1>::deleteElement(int  k, T1 & x)
{ // Set x to the kth element and delete it.
	x = element[k];
	T1 a;
	element[k]=a;
     len--;
}
template <class T1>
void LinearList<T1>::insert(int  k, T1 x)
{ // Insert x at kth element.
	 element[k] = x;
     len++;
}
#endif
