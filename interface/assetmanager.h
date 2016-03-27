#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
private:
    std::map<std::string, sf::Texture> m_textures;
    static const std::string PATH;

    //AssetManager is a singleton, so only one instance can exist at a time
    static AssetManager* sInstance; // holds a static pointer to the single manager instance

public:
    AssetManager();
    static sf::Texture& getTexture(std::string const& filename);
};

#endif // ASSETMANAGER_H
