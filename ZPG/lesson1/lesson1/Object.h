#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include  "Model.h"
#include "Shader.h"
#include "Texture.h"
class Object
{
private:
	static int GENERATE_ID;
	//float *color;
	int id;
	Model* model;
	glm::mat4 modelMatrix;
	glm::vec4 color;
	Texture* texture;

public:
	glm::mat4 getModelMatrix();
	int getCountVertex();
	void bind();
	int getId();
	glm::vec4 getObjectColor();
	void rotateObject(float angle, glm::vec3 vector);
	void translateObject(glm::vec3 vector);
	void scaleObject(glm::vec3 vector);
	void resetObject();
	void set_shader_properties(Shader* shader);
	Object(Model* model);
	Object(Model* model, glm::vec4 color);
	~Object();
};

