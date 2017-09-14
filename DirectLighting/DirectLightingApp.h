#pragma once

#include "Application.h"
#include <glm/mat4x4.hpp>

class DirectLightingApp : public aie::Application {
public:

	DirectLightingApp();
	virtual ~DirectLightingApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	// camera transforms
	glm::mat4	m_viewMatrix;
	glm::mat4	m_projectionMatrix;
};