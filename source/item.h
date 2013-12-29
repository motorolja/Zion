#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include "property.h"

class Item
{
 public:
  Item() = delete;
  virtual ~Item() noexcept
    {}

  std::string getName() const; // returns name of the item
  std::string getDescription() const; // returns description of the item
  std::vector<eProperty> getProperties() const; // returns properties

  bool hasQuantity() const;
  bool addProperty(eProperty); // adds a property to the item

 protected:
  explicit Item(std::string& name = "invalid item", std::string& description = "invalid", bool has_quantity = true)
    : Item(), m_name(name), m_description(description), m_has_quantity(has_quantity) 
  {}

 private:
  std::string m_name;
  std::string m_description;
  bool m_has_quantity;
  std::vector<eProperty> m_properties;
};

class Unique_Item : public Item
{
 public:
 Unique_Item(std::string& name = "invalid item", std::string& description = "invalid", bool has_quantity = false)
   : Item(name,description,has_quantity)
    {}
};

class Not_Unique_Item : public Item
{
 public:
 Not_Unique_Item(std::string& name = "invalid item", std::string& description = "invalid", bool has_quantity = true, int quantity)
   : Item(name,description,has_quantity), m_quantity(quantity)
    {}
  int getQuantity() const;
  void addQuantity(int);
  void decreaseQuantity(int);
  

 private:
  int m_quantity;
};

#endif
