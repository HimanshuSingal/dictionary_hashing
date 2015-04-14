#include "hashing.h"
int main()
{
  Hashing h;
  h.assign(33,10);
  record a;
  strcpy(a.item_num,"X13320");
  std::cout<<h.map(a)<<"\n";

}
