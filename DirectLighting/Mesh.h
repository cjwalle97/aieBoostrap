#pragma once
#include <gl_core_4_4.h>
#include <stdio.h>
#include <assert.h>
#include <glm\vec4.hpp>
#include <glm\vec3.hpp>
#include <glm\vec2.hpp>
#include <glm\glm.hpp>
#include <glm\ext.hpp>
#include <iostream>
#include <vector>

using glm::vec2;
using glm::vec4;

struct Vertex
{
	vec4 position;
	vec4 color;
	vec4 normal;
	vec4 tangent;
	vec4 bitangent;
	vec2 texcoord;
};

class Mesh
{
public:
	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;
	std::vector<unsigned int> m_indices;
	std::vector<Vertex> m_vertices;

	Mesh();
	~Mesh();
	void CreateBuffers();
	void Bind();
	void Unbind();
	void initialize(std::vector<Vertex> verts, std::vector<unsigned int> indices);
	unsigned int m_index_Count;
	unsigned int m_vertex_Count;
};
