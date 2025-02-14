#include "Light.h"

Light::Light(glm::vec3 position, glm::vec4 color)
{
	this->position = position;
	this->color = color;
	this->angle = 0;
	this->radius = 100;
	this->worldPoint = glm::vec3(0.0, 0.0, 0.0);
}
Light::Light(glm::vec3 position, glm::vec3 diffuseColor, glm::vec3 specularColor)
{
	this->position = position;
	this->diffuseColor = diffuseColor;
	this->specularColor = specularColor;
	this->ambientColor = glm::vec3(0.1, 0.1, 0.1);

	this->constant = 1.0f;
	this->linear = 0.09f;
	this->quadratic = 0.032f;
}

Light::Light(glm::vec3 position, glm::vec3 colorAll) : Light(position, colorAll, colorAll) {}

glm::vec3 Light::getLightPosition()
{
	return this->position;
}

glm::vec4 Light::getLightColor()
{
	return this->color;
}

void Light::updatePosition(Shader* shader)
{
	this->angle += 0.1;
	if (this->angle == 360) {
		this->angle = 0;
	}
	float x = this->worldPoint.x + this->radius * cos(angle);
	float y = this->worldPoint.y + this->radius * sin(angle);
	float z = this->worldPoint.z + this->radius * sin(angle);
	this->position = glm::vec3(x, 0, z);
	shader->sendUniformVec3("lightPosition", this->position);
}

void Light::set_shader_properties(Shader* shader)
{
	shader->sendUniformVec3("lightPosition", this->position);
	shader->sendUniformVec4("lightColor", this->color);
}

void Light::setShaderProperties(Shader* shader, int index)
{
	//shader->use(); //pouziti prave aktualniho shaderu
	string prefix = "lights[" + std::to_string(index) + "].";
	this->setShaderProperties(shader, prefix);

}

void Light::setShaderProperties(Shader* shader, string name)
{
	shader->sendUniformVec4((name + "position").c_str(), glm::vec4(this->position, 1));
	shader->sendUniformVec4((name + "diffuse").c_str(), glm::vec4(this->diffuseColor, 1));
	shader->sendUniformVec4((name + "specular").c_str(), glm::vec4(this->specularColor, 1));
	shader->sendUniformVec4((name + "ambient").c_str(), glm::vec4(this->ambientColor, 1));

	shader->setUniform1f((name + "constant").c_str(), this->constant);
	shader->setUniform1f((name + "linear").c_str(), this->linear);
	shader->setUniform1f((name + "quadratic").c_str(), this->quadratic);
}
