#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "property.h"

class Item
{
 public:
  Item(std::string& name = "none", std::string& description = "none");
  ~Item();
  
  std::string getName() const; // returns name of the item
  std::string getDescription() const; // returns description of the item
  std::vector<eProperty> getProperties() const; // returns properties

  bool addProperty(eProperty); // adds a property to the item

 private:
  std::string m_name;
  std::string m_description;
  std::vector<eProperty> m_properties;
};

#endif
