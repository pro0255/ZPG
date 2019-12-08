#pragma once
#include "ModelFactory.h"
#include "TextureFactory.h"
#include "ColorFactory.h"
#include "ObjectAssimp.h"
class ObjFactory
{
public:
	ObjFactory(ColorFactory* colorFactory);
	~ObjFactory();
	ObjectAssimp* getProduct(MODEL model, TEXTURE texture, COLOR color);
private:
	ColorFactory* colorFactory;
	TextureFactory* textureFactory;
	ModelFactory* modelFactory;
};

