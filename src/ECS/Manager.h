#ifndef MANAGER_H
#define MANAGER_H


#include <unordered_map>
#include <vector>
#include "AEntity.h"


class EntityManager
{
public:
    EntityManager(const EntityManager &) = delete;
    EntityManager(EntityManager &&) = delete;
    EntityManager &operator=(const EntityManager &) = delete;
    EntityManager &operator=(EntityManager &&) = delete;
    static EntityManager *Instance();
    static void ResetInstance();
    ~EntityManager();

public:
    void LoadEntity(AEntity* entity, void* scene);
    void DestroyEntity(AEntity* entity, void* scene);
    void DestroyEntities();

private:
    static EntityManager* s_instance;
    EntityManager();
    std::unordered_map<void*, std::unordered_map<int, AEntity*>> m_entities;

};

#endif // MANAGER_H
