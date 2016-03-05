#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
public:
    AssetManager();

    static sf::Texture& GetTexture(std::string const& filename);

private:
    std::map<std::string, sf::Texture> m_textures;

    //AssetManager is a singleton, so only one instance can exist at a time
    static AssetManager* sInstance; // holds a static pointer to the single manager instance
};

#endif // ASSETMANAGER_H
