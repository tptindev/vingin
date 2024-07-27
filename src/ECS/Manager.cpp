#include "Manager.h"
#include <iostream>


EntityManager *EntityManager::s_instance = nullptr;
EntityManager *EntityManager::Instance()
{
    if (EntityManager::s_instance == nullptr)
    {
        EntityManager::s_instance = new EntityManager();
    }
    return EntityManager::s_instance;
}

void EntityManager::ResetInstance()
{
    if (EntityManager::s_instance != nullptr)
    {
        delete EntityManager::s_instance;
        EntityManager::s_instance = nullptr;
    }
    return;
}

EntityManager::~EntityManager()
{
    DestroyEntities();
    std::cout << __FUNCTION__ << std::endl;
}

void EntityManager::LoadEntity(AEntity *entity, void* scene)
{
    if (entity != nullptr)
    {
        this->m_entities[scene][entity->id()] = entity;
    }
}

void EntityManager::DestroyEntity(AEntity *entity, void* scene)
{
    if (entity != nullptr)
    {
        this->m_entities[scene].erase(this->m_entities[scene].find(entity->id()));
        delete entity;
        entity = nullptr;
    }
}

void EntityManager::DestroyEntities()
{
    std::unordered_map<void*, std::unordered_map<int, AEntity*>>::iterator it = this->m_entities.begin();
    while (it != this->m_entities.end())
    {
        std::unordered_map<int, AEntity*>::iterator tmpIt = it->second.begin();
        while (tmpIt != it->second.end())
        {
            it->second.erase(tmpIt);
            delete (tmpIt->second);
            tmpIt->second = nullptr;
            tmpIt++;
        }
        it++;
    }
}

EntityManager::EntityManager()
{
    std::cout << __FUNCTION__  << std::endl;
}