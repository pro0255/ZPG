#version 330
layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;
layout(location=2) in vec2 uv;

//uniform mat4 modelMatrix; //poslani matice dovnitr
uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out vec3 TexCoords;

void main () {
	TexCoords = position;
	vec4 pos = (projectionMatrix*viewMatrix) * vec4(position, 1.0);
	gl_Position = pos.xyww;
};