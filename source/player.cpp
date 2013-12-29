#include <algorithm>
#include <stdexcept>
#include <typeinfo>
#include "player.h"

Player::Player(int health, Position pos)
  : m_health(health), m_position(pos)
{

}

Player::~Player()
{
  while( !m_inventory.empty() )
    {
      auto temp = m_inventory.front();
      m_inventory.erase( my_inventory.begin() );
      delete temp;
    }
}

void Player::setHealth(int health)
{
  m_health = health;
}

void Player::addHealth(int temp)
{
  m_health += temp;
}

int Player::getHealth() const
{
  return m_health;
}

void Player::addStatus(Status sta)
{
  eStatus temp = sta.getStatus();
  auto it = std::find(m_statuses.cbegin(), m_statuses.cend(), temp);
  if( it == std::vector::end() )
    m_statuses.push_back(sta);
  else // if the status exists, take the status with highest duration 
    {
      if( m_statuses.at(it) < sta.getDuration() ) // made an operator for Status which compares with the int part if compared with an int
	m_statuses.at(it) = sta;
    }
}

std::vector<Status> Player::getStatuses() const
{
  return m_statuses;
}

void Player::removeStatus(eStatus eSta)
{
  auto it = std::find(m_statuses.cbegin(), m_statuses.cend(), eSta);
  if( it != std::vector::end() )
    m_statuses.erase(it);
}

void Player::clearStatuses()
{
  m_statuses.clear();
}

void Player::setPosition(Position pos)
{
  m_position = pos;
}

Position Player::getPosition() const
{
  return m_position;
}

void Player::addItem(Item* item)
{
  auto it = std::find( m_inventory.cbegin(), m_inventory.cend(), item);
  if( it != m_inventory.end() )
    {
      if( item->hasQuantity() )
	{
	  m_inventory.at(it).addQuantity( item->getQuantity() );
	}
      else
	{
	  throw std::out_of_range("Player::addItem(): Can't add a unique item that allready exists");
	}
    }
  else
    {
      m_inventory.push_back(item);
    }
}

std::vector<Item*> Player::getInventory() const
{
  return m_inventory;
}

void Player::clearInventory()
{
  while( !m_inventory.empty() )
    {
      auto temp = m_inventory.front();
      m_inventory.erase( my_inventory.begin() );
      delete temp;
    }
}
