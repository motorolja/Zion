#include "item.h"
#include <typeinfo>
#include <iostream>
#include <vector>

void test(Item* i)
{
  Item* temp = i->clone(); // makes a copy of i
  Not_Unique_Item* n = dynamic_cast<Not_Unique_Item*>(i);
  if( n != nullptr )
    {
      std::cout << "Name: \t" << n->getName() << '\n'
		<< "Description: \t" << n->getDescription() << '\n';
      if( n->hasQuantity() )
	std::cout << "Has quantity\n";
      std::vector<eProperty> v = n->getProperties();
      for( int i = 0; i < v.size(); ++i )
	std::cout << "Property nr:" << i << '\t' << v.at(i) << std::endl;
    }

     
  Unique_Item* u = dynamic_cast<Unique_Item*>(i);
  if( u != nullptr )
    {
      std::cout << "Name: \t" << u->getName() << '\n'
		<< "Description: \t" << u->getDescription() << '\n';
      if( u->hasQuantity() )
	{
	  std::cout << "Has quantity: " << '\n';
	}
      std::vector<eProperty> v = u->getProperties();
      for( int i = 0; i < v.size(); ++i )
	std::cout << "Property nr:" << i << '\t' << v.at(i) << std::endl;
    }

  delete temp; // removes the copy
}

int main()
{
  Item* u1 = new Unique_Item("Awsome", "yes");
  //  Item* u2 = new Unique_Item();
 
  Item* n1 = new Not_Unique_Item(22,"not", "no");
  //  Item* n2 = new Not_Unique_Item();

  n1->addProperty(junk);
  n1->addProperty(edible);
  u1->addProperty(poisonous);
  u1->addProperty(speed);

  test(u1);
  //  test(u2);  
  test(n1);
  //  test(n2);
 
  delete u1;
  //  delete u2;
  delete n1;
  //  delete n2;

  return 0;
}
