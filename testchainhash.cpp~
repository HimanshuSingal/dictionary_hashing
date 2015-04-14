#include "openhashing.h"
int main()
{
  record a;
  Open_hashing dict(11,5);
  
  strcpy(a.item_num,"B13312");
  //strcpy(a.item_name,"Check");
  strcpy(a.address,"Check");
  strcpy(a.manu_comp,"Check");
  strcpy(a.address_manu,"Check");
  // a.price=10;
  record b;
  //b=a;
  strcpy(b.item_num,"X13320");
  dict.doublehashing(a);
  dict.doublehashing(b);
  //dict.lineardelete("B13320");
  std::cout<<dict.doubleprint("X13320");
  //std::cout<<obj.map(a)<<"\n";
}
