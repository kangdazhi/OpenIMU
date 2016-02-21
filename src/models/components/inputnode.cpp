#include "inputnode.h"

template <class T>
InputNode<T>::InputNode()
{
    isActive = true;
}

template <class T>
InputNode<T>::~InputNode()
{

}

//Override
template <class T>
void InputNode<T>::Put(T value)
{
    valueBuf = value;
    if(isActive) Notify();
}

//Override
template <class T>
T InputNode<T>::Get()
{
    return valueBuf;
}

template <class T>
void InputNode<T>::SetActive(bool active)
{
    isActive = active;
}

template <class T>
void InputNode<T>::SetStringID(const std::string value)
{
    stringID = value;
}

template <class T>
std::string InputNode<T>::GetStringID()
{
    return stringID;
}

template <class T>
void InputNode<T>::Notify()
{
    observer->Notify(stringID);
}

