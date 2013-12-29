#include "item.h"
#include <algorithm>

const std::string Item::getName() const
{
  return m_name;
}

const std::string Item::getDescription() const
{
  return m_description;
}

std::vector<eProperty> Item::getProperties() const
{
  return m_properties;
}

bool Item::hasQuantity() const
{
  return m_has_quantity;
}

bool Item::addProperty(eProperty property)
{
  if( std::find( m_properties.cbegin(), m_properties.cend(), property ) == m_properties.end() )
    {
      m_properties.push_back(property);
      return true;
    }
  return false;
}

bool Item::operator==(const Item* item) const
{
  if( item->getName() == m_name &&
      item->getDescription() == m_description && 
      item->hasQuantity() == m_has_quantity )
    return true;
  return false;
}

Unique_Item* Unique_Item::clone() const
{
  return (new Unique_Item(*this) );
}

int Not_Unique_Item::getQuantity() const
{
  return m_quantity;
}

void Not_Unique_Item::addQuantity(int quantity)
{
  if( m_quantity != 99 ) 
    {
      m_quantity += quantity;
      if( m_quantity > 99 )
	m_quantity = 99;
    }
}

void Not_Unique_Item::decreaseQuantity(int quantity)
{
  if( m_quantity != 0 )
    {
      m_quantity -= quantity;
      if( m_quantity < 0 )
	m_quantity = 0;
    }
}

Not_Unique_Item* Not_Unique_Item::clone() const
{
  return (new Not_Unique_Item(*this) );
}
