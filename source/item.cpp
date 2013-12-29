#include "item.h"
#include <algorithm>

std::string Item::getName() const
{
  return m_name;
}

std::string Item::getDescription() const
{
  return m_description;
}

std::vector<eProperty> Item::getProperties() const
{
  return m_properties;
}

bool Item::addProperty(eProperty property)
{
  if( find( m_properties.cbegin(), m_properties.cend(), property ) == std::vector::end() )
    {
      m_properties.push_back(property);
      return true;
    }
  return false;
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
