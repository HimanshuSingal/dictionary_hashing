#include "chainhashing.h"
int main()
{
  record a;
  Chain_Hashing dict(10);
  
  strcpy(a.item_num,"B13312");
  //strcpy(a.item_name,"Check");
  strcpy(a.address,"Check");
  strcpy(a.manu_comp,"Check");
  strcpy(a.address_manu,"Check");
  // a.price=10;
  record b;
  //b=a;
  strcpy(b.item_num,"X13320");
  dict.insert(a);
  dict.insert(b);
  dict.delete1("B1332");
  std::cout<<dict.print("B13312");
  //std::cout<<obj.map(a)<<"\n";
}
