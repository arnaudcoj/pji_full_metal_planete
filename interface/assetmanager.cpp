#include "assetmanager.h"
#include <assert.h>

const std::string AssetManager::PATH = { "../../assets/tiles/" };

AssetManager* AssetManager::sInstance = nullptr;

AssetManager::AssetManager() {
    // Only allow one AssetManager to exist
    // Otherwise throw an exception
    assert(sInstance == nullptr);
    sInstance = this;
}

sf::Texture& AssetManager::getTexture(std::string const& filename) {
    auto& textMap = sInstance->m_textures;

    // See if the texture is already loaded
    auto pairFound = textMap.find(filename);
    // If yes, return the texture
    if(pairFound != textMap.end()) {
        return pairFound->second;
    } else { // Else, load the texture and return it
        // Create an element in the texture map
        auto& texture = textMap[filename];
        texture.loadFromFile(PATH + filename  + ".png");
        return texture;
    }
}
