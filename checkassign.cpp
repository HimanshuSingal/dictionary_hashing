#include <iostream>
#include <cstring>
using namespace std;
class Student
{
public:
 int marks;
 char roll[50];
};
int main()
{
Student s1;
s1.marks=23;
strcpy(s1.roll,"B13312");

Student s2;
s2.marks=25;
strcpy(s2.roll,"B13311");
Student s3=s2;
s3.marks=30;
cout<<s2.marks<<endl;

return 0;
}
