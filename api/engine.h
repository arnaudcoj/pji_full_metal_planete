#ifndef ENGINE_H
#define ENGINE_H


class Engine
{
public:
    enum class Type : char {TERRESTRIAL_ENGINE, HEAVY_TERRESTRIAL_ENGINE, MARINE_ENGINE, NO_ENGINE};
    Engine(Type type);

    bool isTerrestrial();
    bool isMarine();
    bool canClimb();

private:
    Type m_type;

};

#endif // ENGINE_H
