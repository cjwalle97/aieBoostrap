#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::CreateBuffers()
{
	glGenVertexArrays(1, &m_vao);

	glBindVertexArray(m_vao);

	glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

	glBufferData(GL_ARRAY_BUFFER, m_vertex_Count * sizeof(Vertex), this->m_vertices.data(), GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_index_Count * sizeof(unsigned int), m_indices.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);

	//Start the Clean up
	glBindVertexArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::Bind()
{
	glBindVertexArray(m_vao);
}

void Mesh::Unbind()
{
	glBindVertexArray(0);
}

void Mesh::initialize(std::vector<Vertex> verts, std::vector<unsigned int> indices)
{
	for (auto v : verts)
	{
		this->m_vertices.push_back(v);
	}
	this->m_vertex_Count = m_vertices.size();
	for (auto i : indices)
	{
		this->m_indices.push_back(i);
	}
	this->m_index_Count = m_indices.size();
}
