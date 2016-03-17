#include "engine.h"

Engine::Engine(Engine::Type type)
    : m_type(type)
{
}

bool Engine::isTerrestrial()
{
    switch(m_type) {
    case Type::TERRESTRIAL_ENGINE:
    case Type::HEAVY_TERRESTRIAL_ENGINE:
        return true;
    default:
        return false;
    }
}

bool Engine::isMarine()
{
    return m_type == Type::MARINE_ENGINE;
}

bool Engine::canClimb()
{
    return m_type == Type::TERRESTRIAL_ENGINE;
}
