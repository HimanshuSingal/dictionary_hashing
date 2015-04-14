#include <iostream>
class Test
{
public:
  int a;
  int b;
};
bool comp(Test a,Test b)
{
  if((a.a==b.a) && (a.b==b.b))
    return true;
  return false;
}
template <class T>
void output(T a,T b,bool (* function)(T a,T b))
{
  std::cout << (function(a,b)) << std::endl;
//std::cout << b << std::endl;
}
template <class T>
void output(T a,T b)
{
  std::cout << (a==b) << std::endl;

}
int main()
{
  Test a,b;
  a.a=11;
  a.b=13;
  b.a=12;
  b.b=13;
  output(a,b,comp);
   output(3.4,3.5);
//output("Himanshu");
return 0;
}
