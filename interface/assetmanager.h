#ifndef ASSET_MANAGER_H
#define ASSET_MANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>

class AssetManager
{

public:
    AssetManager();

    static sf::Texture& getTexture(std::string const& filename);
    static sf::SoundBuffer& getSoundBuffer(std::string const& filename);
    static sf::Font& getFont(std::string const& filename);

private:
    static const std::string IMG_PATH;
    static const std::string SOUND_PATH;
    static const std::string FONT_PATH;
    
    std::map<std::string, sf::Texture> m_Textures;
    std::map<std::string, sf::SoundBuffer> m_SoundBuffers;
    std::map<std::string, sf::Font> m_Fonts;

    // AssetManager is a singleton, so only one instance can exist at a time
    // sInstacne holds a static pointer to the single manager instance
    static AssetManager* sInstance;
};

#endif
