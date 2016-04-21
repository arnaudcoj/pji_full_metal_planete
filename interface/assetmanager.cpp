#include "assetmanager.h"
#include <assert.h>

const std::string AssetManager::IMG_PATH = { "../../assets/tiles/" };
const std::string AssetManager::SOUND_PATH = { "../../assets/sounds/" };
const std::string AssetManager::FONT_PATH = { "../../assets/fonts/" };

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager()
{
    // Only allow one AssetManager to exist

    // Otherwise throw an exception
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture& AssetManager::getTexture(std::string const& filename)
{
    auto& texMap = sInstance->m_Textures;

    // See if the texture is already loaded
    auto pairFound = texMap.find(filename);

    // If yes, return the texture
    if(pairFound != texMap.end()) {
        return pairFound->second;
    } else // Else, load the texture and return it
    {
        // Create an element in the texture map
        auto& texture = texMap[filename];
        texture.loadFromFile(IMG_PATH + filename + ".png");
        return texture;
    }
}

sf::SoundBuffer& AssetManager::getSoundBuffer(std::string const& filename)
{
    auto& sBufferMap = sInstance->m_SoundBuffers;
    auto pairFound = sBufferMap.find(filename);

    if(pairFound != sBufferMap.end()) {
        return pairFound->second;
    } else {
        // Create an element in the SoundBuffer map
        auto& sBuffer = sBufferMap[filename];
        sBuffer.loadFromFile(SOUND_PATH + filename);
        return sBuffer;
    }
}

sf::Font& AssetManager::getFont(std::string const& filename)
{
    auto& fontMap = sInstance->m_Fonts;
    auto pairFound = fontMap.find(filename);

    if(pairFound != fontMap.end()) {
        return pairFound->second;
    } else {
        // Create an element in the Fonts map
        auto& font = fontMap[filename];
        font.loadFromFile(FONT_PATH + filename);
        return font;
    }
}
