#include "item.h"
#include <algorithm>

Item::Item(std::string& name, std::string& description)
  : m_name(name), m_description(description)
{

}

Item::~Item()
{}

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
