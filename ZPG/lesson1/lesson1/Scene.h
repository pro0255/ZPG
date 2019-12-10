#pragma once

#include "Object.h"
#include "Shader.h"
#include "Camera.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Light.h"
#include "Mesh.h"
#include "ObjectAssimp.h"
#include "SkyBox.h"
#include "FlashLight.h"
#include "ObjFactory.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "DirectionLight.h"
#include "ShadowMap.h"
#include "Renderer.h"

class Renderer;
class Scene
{
private:
	vector<ObjectAssimp*> objects;
	GLFWwindow* window;

	Camera* camera;
	Shader* objectShader;
	Shader* debugShadowShader;
	ShadowMap* shadowMap;
	SkyBox* skybox;

	vector<PointLight*> pointLights;
	vector<SpotLight*> spotLights;
	DirectionLight* directionLight;
	FlashLight* flashlight;

	void draw_objects();
	void draw_objects(Shader* new_shader);

	ObjFactory* objFac;
	ColorFactory* colFac;

	void init();
public:
	int selectedObjectId;
	Scene(GLFWwindow* window);



	Camera* getCamera();
	void createObjects();




	void draw();


	void createFactories();
	void createPointLights();
	void createSpotLights();
	void createDirectionLight();
	void renderQuad();
};

