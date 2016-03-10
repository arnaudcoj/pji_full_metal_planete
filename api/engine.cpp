#include "engine.h"

Engine::Engine(Engine::Type type) : m_type(type)
{

}

bool Engine::isTerrestrial() {
    return m_type != Type::MARINE_ENGINE;
}

bool Engine::isMarine() {
    return m_type == Type::MARINE_ENGINE;
}

bool Engine::canClimb() {
    return m_type == Type::TERRESTRIAL_ENGINE;
}
