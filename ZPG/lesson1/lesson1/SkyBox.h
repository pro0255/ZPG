#pragma once
#include "Texture.h"
#include "ObjectAssimp.h"
#include "Camera.h"

class SkyBox : public ObjectAssimp
{
public:
	SkyBox(string prefix, Camera* camera);
	void draw();
	Shader* shader;
	Camera* camera;
private:
	Texture* load(string prefix);
	void createShader(Camera* camera);
	void setShaderProperties();
};

