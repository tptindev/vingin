#ifndef ENGINE_H
#define ENGINE_H

#include "EngineEnums.h"

class Engine
{
public:
    static Engine *instance();
    bool Initialize();
    void Loop();
    void Quit();

private:
    EngineEnums::EnginState m_state;
    static Engine *s_instance;
    Engine();
    ~Engine();
};

#endif // ENGINE_H
