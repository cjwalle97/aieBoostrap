#include <glm\glm.hpp>
#include <glm\ext.hpp>
using glm::mat4;
using glm::vec4;
using glm::vec3;
using glm::cross;
using glm::normalize;
using glm::inverse;
#pragma once

class Camera
{
private:
	vec3 m_cameraPosition;
	mat4 m_localSpace;
	mat4 m_modelMatrx;
	mat4 m_worldTransform = m_localSpace * m_modelMatrx;
	mat4 m_viewTransform = inverse(m_worldTransform);
	mat4 m_projectionTransform;
	mat4 m_projectionViewTransform;

public:
	Camera(mat4 l, mat4 m);
	~Camera();

	virtual void update(float deltaTime);
	void setOrthographic(float Left, float Right, float Bottom, float Top, float Near, float Far);
	void setPerspective(float fieldOfView, float aspectRatio, float Near, float Far);
	void setLookAt(vec3 eye, vec3 center, vec3 up);
	void setPosition(vec3 position);
	mat4 getWorldTransform();
	mat4 getView();
	mat4 getProjection();
	mat4 getProjectionView();
	void UpdateProjectionViewTransform();

};