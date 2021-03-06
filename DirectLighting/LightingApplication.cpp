#include "LightingApplication.h"

using glm::vec3;
using glm::vec4;
using glm::mat4;
using aie::Gizmos;

LightingApplication::LightingApplication() 
{

}

LightingApplication::~LightingApplication()
{

}

unsigned VAO, VBO, IBO, INDEXCOUNT;

bool LightingApplication::startup()
{
	m_shader = new Shader();

	m_ambientLight = vec4(1);
	setBackgroundColour(0.25f, 0.25f, 0.25f);

	m_directionalLight.direction = vec3(0.0f, 1.0f, 0.0f);
	m_directionalLight.ambient = vec3(0.25f, 0.50f, 0.50f);
	m_directionalLight.normal = vec3(0.0f, 1.f, 0.0f);
	m_directionalLight.diffuse = vec3(1.0f, 0.20f, 1.0f);
	m_directionalLight.specular = vec3(1.0f);
	vec3 m_ambientLight = vec3(0.25f);

	m_material.diffuse = vec3(1.0f, 0.20f, 1.0f);
	m_material.ambient = vec3(0.25f, 0.50f, 0.50f);
	m_material.specular = vec3(1.f);
	m_material.specularPower = 32;

	// initialise gizmo primitive counts
	Gizmos::create(1000,1000,1000,1000);

	m_shader->load("./shaders/phong.vert", GL_VERTEX_SHADER);
	m_shader->load("./shaders/phong.frag", GL_FRAGMENT_SHADER);

	m_shader->attach();

	// create simple camera transforms
	m_viewMatrix = glm::lookAt(vec3(10), vec3(0), vec3(0, 1, 0));
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f, 16.0f / 9.0f, 0.1f, 1000.0f);

	// Gets the camera's translation
	// ( 1 0 0 *1 )
	// ( 0 1 0 *0 )
	// ( 0 0 1 *0 )
	// ( 0 0 0 *1 )
	m_cameraTranslation = vec4(vec3(m_projectionMatrix[3]), 1.f);

	generateSphere(25, 25, VAO, VBO, IBO, INDEXCOUNT);

	return true;
}

void LightingApplication::shutdown()
{
	Gizmos::destroy();
}

void LightingApplication::update(float deltaTime)
{
	float time = getTime();
	time = 0;
	m_directionalLight.direction = vec3(sinf(time), 0, cosf(time));

	// wipe the gizmos clean for this frame
	Gizmos::clear();

	// draw a simple grid with gizmos
	vec4 white(1);
	vec4 black(0, 0, 0, 1);
	for (int i = 0; i < 21; ++i) 
	{
		Gizmos::addLine(vec3(-10 + i, 0, 10),
						vec3(-10 + i, 0, -10),
						i == 10 ? white : black);
		Gizmos::addLine(vec3(10, 0, -10 + i),
						vec3(-10, 0, -10 + i),
						i == 10 ? white : black);
	}

	// add a transform so that we can see the axis
	Gizmos::addTransform(mat4(1));

	// quit if we press escape
	aie::Input* input = aie::Input::getInstance();

	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void LightingApplication::draw()
{
	// wipe the screen to the background colour
	clearScreen();
	m_shader->Bind();
	// update perspective based on screen size
	m_projectionMatrix = glm::perspective(glm::pi<float>() * 0.25f, getWindowWidth() / (float)getWindowHeight(), 0.1f, 1000.0f);

	m_viewMatrix = glm::lookAt(glm::vec3(10, 10, 10), glm::vec3(0), glm::vec3(0, 1, 0));
	auto modelMatrix = glm::scale(glm::vec3(5));
	auto mvp = m_projectionMatrix * m_viewMatrix * modelMatrix;

	mat4 pvm = m_projectionMatrix * modelMatrix;

	int matUniform = m_shader->getUniform("ProjectionViewModel");
	glUniformMatrix4fv(matUniform, 1, GL_FALSE, &pvm[0][0]);

	matUniform = m_shader->getUniform("Normal");
	glUniform4fv(matUniform, 1, &m_directionalLight.normal[0]);

	int lightUniform = m_shader->getUniform("direction");
	glUniform3fv(lightUniform, 1, &m_directionalLight.direction[0]);

	lightUniform = m_shader->getUniform("Ia");
	glUniform3fv(lightUniform, 1, &m_directionalLight.ambient[0]);

	lightUniform = m_shader->getUniform("Id");
	glUniform3fv(lightUniform, 1, &m_directionalLight.diffuse[0]);

	lightUniform = m_shader->getUniform("Is");
	glUniform3fv(lightUniform, 1, &m_directionalLight.specular[0]);
	
	lightUniform = m_shader->getUniform("Ka");
	glUniform3fv(lightUniform, 1, &m_ambientLight[0]);
	
	lightUniform = m_shader->getUniform("Kd");
	glUniform3fv(lightUniform, 1, &m_material.diffuse[0]);
	
	lightUniform = m_shader->getUniform("Ks");
	glUniform3fv(lightUniform, 1, &m_material.specular[0]);

	lightUniform = m_shader->getUniform("a");
	glUniform1f(lightUniform, m_material.specularPower);

	lightUniform = m_shader->getUniform("cameraPosition");
	glUniform4fv(lightUniform, 1, &m_cameraTranslation[0]);

	Gizmos::draw(m_projectionMatrix * m_viewMatrix);

	glUniformMatrix4fv(m_shader->getUniform("ProjectionViewModel"),1, false, glm::value_ptr(mvp));
	
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, INDEXCOUNT, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	m_shader->Unbind();

	// ImGui
	ImGui::Begin("Lighting");
	ImGui::Text("This Works");
	ImGui::End();
}

void LightingApplication::generateSphere(unsigned int segments, unsigned int rings,
	unsigned int& vao, unsigned int& vbo, unsigned int& ibo,
	unsigned int& indexCount) 
{
	unsigned int vertCount = (segments + 1) * (rings + 2);
	indexCount = segments * (rings + 1) * 6;

	// using AIEVertex for now, but could be any struct as long as it has the correct elements
	Vertex* vertices = new Vertex[vertCount];
	unsigned int* indices = new unsigned int[indexCount];

	float ringAngle = glm::pi<float>() / (rings + 1);
	float segmentAngle = 2.0f * glm::pi<float>() / segments;

	Vertex* vertex = vertices;

	for (unsigned int ring = 0; ring < (rings + 2); ++ring)
	{
		float r0 = glm::sin(ring * ringAngle);
		float y0 = glm::cos(ring * ringAngle);

		for (unsigned int segment = 0; segment < (segments + 1); ++segment, ++vertex) 
		{
			float x0 = r0 * glm::sin(segment * segmentAngle);
			float z0 = r0 * glm::cos(segment * segmentAngle);

			vertex->position = glm::vec4(x0 * 0.5f, y0 * 0.5f, z0 * 0.5f, 1);
			vertex->normal = glm::vec4(x0, y0, z0, 0);
			vertex->color = glm::vec4(1, 1, 1, 1);

			vertex->tangent = glm::vec4(glm::sin(segment * segmentAngle + glm::half_pi<float>()), 0, glm::cos(segment * segmentAngle + glm::half_pi<float>()), 0);

			// not a part of the AIEVertex, but this is how w generate bitangents
			vertex->bitangent = glm::vec4(glm::cross(glm::vec3(vertex->normal), glm::vec3(vertex->tangent)), 0);

			vertex->texcoord = glm::vec2(segment / (float)segments, ring / (float)(rings + 1));
		}
	}

	unsigned int index = 0;
	for (unsigned i = 0; i < (rings + 1); ++i) {
		for (unsigned j = 0; j < segments; ++j) {
			indices[index++] = i * (segments + 1) + j;
			indices[index++] = (i + 1) * (segments + 1) + j;
			indices[index++] = i * (segments + 1) + (j + 1);

			indices[index++] = (i + 1) * (segments + 1) + (j + 1);
			indices[index++] = i * (segments + 1) + (j + 1);
			indices[index++] = (i + 1) * (segments + 1) + j;
		}
	}

	// generate buffers
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ibo);

	// generate vertex array object (descriptors)
	glGenVertexArrays(1, &vao);

	// all changes will apply to this handle
	glBindVertexArray(vao);

	// set vertex buffer data
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, vertCount * sizeof(Vertex), vertices, GL_STATIC_DRAW);

	// index data
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexCount * sizeof(unsigned int), indices, GL_STATIC_DRAW);

	// position
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	// colors
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4)));
	// normals
	glEnableVertexAttribArray(2);
	glVertexAttribPointer(2, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)(sizeof(glm::vec4) * 2));

	// texcoords
	glEnableVertexAttribArray(3);
	glVertexAttribPointer(3, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)(sizeof(glm::vec4) * 3));

	// tangents
	glEnableVertexAttribArray(4);
	glVertexAttribPointer(4, 4, GL_FLOAT, GL_TRUE, sizeof(Vertex), (void*)(sizeof(glm::vec4) * 3 + sizeof(glm::vec2)));

	// safety
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

	delete[] indices;
	delete[] vertices;
}