#include "Camera.h"
#include <assert.h>


Camera::Camera(mat4 l, mat4 m)
{
	m_localSpace = l;
	m_modelMatrx = m;
}

Camera::~Camera()
{

}

void Camera::update(float deltaTime)
{

}

void Camera::setOrthographic(float Left, float Right, float Bottom, float Top, float Near, float Far)
{
	float RLp = Right + Left;
	float RLn = Right - Left;
	float TBp = Top + Bottom;
	float TBn = Top - Bottom;
	float FNp = Far + Near;
	float FNn = Far - Near;
	mat4 Orthograph = mat4(
		vec4((2 / RLn), 0.f, 0.f, 0.f),
		vec4(0.f, (2 / TBn), 0.f, 0.f),
		vec4(0.f, 0.f, (-2 / FNn), 0.f),
		vec4((RLp / RLn), (TBp / TBn), (FNp / FNn), 1.f));
	/*mat4 Test = mat4(
	vec4(1.f, 0.f, 0.f, 0.f),
	vec4(0.f, 1.f, 0.f, 0.f),
	vec4(0.f, 0.f, -1.f, 0.f),
	vec4(3.f, 3.f, 3.f, 1.f));
	assert(Orthograph == Test);*/
	m_projectionTransform = Orthograph;
}

void Camera::setPerspective(float fieldOfView, float aspectRatio, float Near, float Far)
{
	mat4 Perspective = mat4(
		vec4(aspectRatio * (1 / (fieldOfView / 2)), 0.f, 0.f, 0.f),
		vec4(0.f, aspectRatio * (1 / (fieldOfView / 2)), 0.f, 0.f),
		vec4(0.f, 0.f, (Far + Near) / (Far - Near), -1.f),
		vec4(0.f, 0.f, (2 * (Far * Near)) / (Far - Near), 0.f));
	mat4 Test = mat4(
		vec4(0.5, 0.f, 0.f, 0.f),
		vec4(0.f, 0.5, 0.f, 0.f),
		vec4(0.f, 0.f, 3, -1.f),
		vec4(0.f, 0.f, 8, 0.f));
	assert(Perspective == Test);
	m_projectionTransform = Perspective;
}

void Camera::setPosition(vec3 position)
{
	m_cameraPosition = position;
}

void Camera::setLookAt(vec3 eye, vec3 center, vec3 up)
{
	vec3 f = eye - center;
	vec3 z = normalize(f);
	vec3 s = cross(up, z);
	vec3 x = normalize(s);
	vec3 u = cross(z, x);
	vec3 y = u;
	mat4 V = mat4(
		vec4(x[0], x[1], x[2], 0.f),
		vec4(y[0], y[1], y[2], 0.f),
		vec4(z[0], z[1], z[2], 0.f),
		vec4(0.f, 0.f, 0.f, 1.f));
	mat4 T = mat4(
		vec4(1.f, 0.f, 0.f, 0.f),
		vec4(0.f, 1.f, 0.f, 0.f),
		vec4(0.f, 0.f, 1.f, 0.f),
		vec4(-eye.x, -eye.y, -eye.z, 1.f));
	mat4 View = V * T;
	mat4 M = inverse(View);
}

mat4 Camera::getWorldTransform()
{
	return m_worldTransform;
}

mat4 Camera::getView()
{
	return m_viewTransform;
}

mat4 Camera::getProjection()
{
	return m_projectionTransform;
}

mat4 Camera::getProjectionView()
{
	return m_projectionViewTransform;
}

void Camera::UpdateProjectionViewTransform()
{
	m_projectionViewTransform = m_projectionTransform * m_viewTransform;
}