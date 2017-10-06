#pragma once
#include "Gizmos.h"
#include "Input.h"
#include "Application.h"
#include "Shader.h"
#include "Mesh.h"

#include <imgui_glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/mat4x4.hpp>

using glm::vec3;
using glm::vec4;

struct DirectionalLight
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	vec3 direction;
	vec3 normal;
};


struct Material
{
	vec3 ambient;
	vec3 diffuse;
	vec3 specular;
	float specularPower;
};

class LightingApplication : public aie::Application {
private:
	// Shader and Mesh pointers
	Shader* m_shader;
	Mesh* m_mesh;
	DirectionalLight m_directionalLight;
	vec4 m_ambientLight;
	Material m_material;
public:
	LightingApplication();
	virtual ~LightingApplication();

	virtual bool startup();
	virtual void shutdown();
	virtual void update(float deltaTime);
	virtual void draw();
	
	void generateSphere(unsigned int segments, unsigned int rings,
	unsigned int& vao, unsigned int& vbo, unsigned int& ibo, 
	unsigned int& indexCount);

protected:
	// camera transforms
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};