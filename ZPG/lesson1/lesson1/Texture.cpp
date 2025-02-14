#include "Texture.h"

unsigned int Texture::COUNTER = 0;

Texture::Texture(vector<string> faces)
{
	this->id = COUNTER++; //prideleni id texture
	glActiveTexture(GL_TEXTURE0 + this->id); //aktivace texturovaci jednotky
	const GLuint textureId = SOIL_load_OGL_cubemap(
		faces[0].c_str(),
		faces[1].c_str(),
		faces[2].c_str(),
		faces[3].c_str(),
		faces[4].c_str(),
		faces[5].c_str(),
		SOIL_LOAD_RGBA,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureId);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
}

Texture::Texture(const char* path)
{
	this->id = COUNTER++; //prideleni id texture
	glActiveTexture(GL_TEXTURE0 + this->id); //aktivace texturovaci jednotky

	GLuint textureId = SOIL_load_OGL_texture(path, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	glBindTexture(GL_TEXTURE_2D, textureId);
}


Texture::Texture() : Texture("./textures/test.png") {}

void Texture::setShaderProperties(Shader* shader)
{
	shader->setUniform1i("textureUnitId", this->id);
	glActiveTexture(GL_TEXTURE + this->id);

}
