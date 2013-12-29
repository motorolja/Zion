#ifndef ITEM_H
#define ITEM_H

#include <vector>
#include <string>
#include "property.h"

class Item
{
 public:
  Item() = delete;
  virtual ~Item() noexcept = default;

  const std::string getName() const; // returns name of the item
  const std::string getDescription() const; // returns description of the item
  std::vector<eProperty> getProperties() const; // returns properties
  virtual Item* clone() const = 0;

  bool hasQuantity() const;
  bool addProperty(eProperty); // adds a property to the item

 protected:
  explicit Item(bool has_quantity, const std::string& name = "invalid item",const std::string& description = "invalid")
    : m_name(name), m_description(description), m_has_quantity(has_quantity)
  {}
  Item(const Item&) = default; 

 private:
  Item& operator=(const Item&) = delete;

  const std::string m_name;
  const std::string m_description;
  bool m_has_quantity;
  std::vector<eProperty> m_properties;
};

class Unique_Item : public Item
{
 public:
  Unique_Item() = delete;
  explicit Unique_Item(const std::string& name = "invalid item",const std::string& description = "invalid")
    : Item(false,name,description)
    {}
  Unique_Item& operator=(const Unique_Item&) = delete;

  virtual Unique_Item* clone() const override;

 protected:
  Unique_Item(const Unique_Item&) = default;
};

class Not_Unique_Item : public Item
{
 public:
   Not_Unique_Item() = delete;
   explicit Not_Unique_Item(int quantity, const std::string& name = "invalid item",const std::string& description = "invalid")
     : Item(true,name,description), m_quantity(quantity)
   {}
  Not_Unique_Item& operator=(const Unique_Item&) = delete;

  int getQuantity() const;
  void addQuantity(int);
  void decreaseQuantity(int);
  
  virtual Not_Unique_Item* clone() const override;

 protected:
  Not_Unique_Item(const Not_Unique_Item&) = default;

 private:
  Not_Unique_Item& operator=( const Item&) = delete;
  int m_quantity;
};

#endif
