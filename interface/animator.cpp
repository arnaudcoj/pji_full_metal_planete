#include "animator.h"

#include "assetmanager.h"

Animator::Animator(sf::Sprite& sprite)

    : m_Sprite(sprite)
    , m_CurrentTime()
    , m_CurrentAnimation(nullptr)

{
}

Animator::Animation& Animator::createAnimation(std::string const& name,

    std::string const& textureName,
    sf::Time const& duration,
    bool loop)

{

    m_Animations.push_back(

        Animator::Animation(name, textureName, duration, loop));

    // If we don't have any other animations, use that as current animation

    if(m_CurrentAnimation == nullptr)

        switchAnimation(&m_Animations.back());

    return m_Animations.back();
}

Animator::Animation* Animator::findAnimation(std::string const& name)

{

    for(auto it = m_Animations.begin(); it != m_Animations.end(); ++it)

    {

        if(it->m_Name == name)

            return &*it;
    }

    return nullptr;
}

void Animator::update(sf::Time const& dt)

{

    // If we don't have any animations yet return

    if(m_CurrentAnimation == nullptr)

        return;

    m_CurrentTime += dt;

    // Get the current animation frame

    float scaledTime = (m_CurrentTime.asSeconds() / m_CurrentAnimation->m_Duration.asSeconds());

    int numFrames = m_CurrentAnimation->m_Frames.size();

    int currentFrame = static_cast<int>(scaledTime * numFrames);

    // If the animation is looping, calculate the correct frame

    if(m_CurrentAnimation->m_Looping)

        currentFrame %= numFrames;

    else if(currentFrame >= numFrames) // if the current frame is greater than the number of frames

        currentFrame = numFrames - 1; // Show last frame

    // Set the texture rectangle, depending on the frame

    m_Sprite.setTextureRect(m_CurrentAnimation->m_Frames[currentFrame]);
}

bool Animator::switchAnimation(std::string const& name)

{

    auto animation = findAnimation(name);

    if(animation != nullptr)

    {

        switchAnimation(animation);

        return true;
    }

    return false;
}

void Animator::switchAnimation(Animator::Animation* animation)

{

    // Change the sprite texture

    if(animation != nullptr)

    {

        m_Sprite.setTexture(AssetManager::getTexture(animation->m_TextureName));
    }

    m_CurrentAnimation = animation;

    m_CurrentTime = sf::Time::Zero; // Reset the time
}

std::string Animator::getCurrentAnimationName() const

{

    if(m_CurrentAnimation != nullptr)

        return m_CurrentAnimation->m_Name;

    // If no animation is playing, return empty string

    return "";
}
