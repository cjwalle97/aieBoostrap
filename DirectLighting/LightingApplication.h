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

class LightingApplication : public aie::Application {
private:
	// Shader and Mesh pointers
	Shader* m_shader;
	Mesh* m_mesh;

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