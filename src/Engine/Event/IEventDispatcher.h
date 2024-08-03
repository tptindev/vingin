#ifndef IEVENTDISPATCHER_H
#define IEVENTDISPATCHER_H


class IEventDispatcher
{
public:
    virtual void AddListener() = 0;
    virtual void RemoveListener() = 0;
    virtual void Dispatch() = 0;
};

#endif // IEVENTDISPATCHER_H
