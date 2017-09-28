#pragma once

#include "Gizmos.h"
#include "Input.h"
#include "Application.h"
#include <glm/glm.hpp>

#include <imgui_glfw3.h>
class _5_TexturesApp : public aie::Application 
{
public:

	_5_TexturesApp();
	virtual ~_5_TexturesApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	// camera transforms
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};