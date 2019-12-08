#pragma once
#include "Texture.h"
#include <map>
enum class TEXTURE {
	BARN,
	HOUSE,
	LOG,
	MONKEY,
	NONE
};

class TextureFactory
{
public:
	Texture* getProduct(TEXTURE type);
	TextureFactory();
private:
	map<TEXTURE, Texture*> textures;
	void createTextures();
};

