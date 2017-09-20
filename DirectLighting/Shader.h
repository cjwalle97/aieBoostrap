#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <gl_core_4_4.h>

class Shader
{
public:
	Shader();
	~Shader();
	void Bind();
	void Unbind();
	void load(const char * filename, unsigned int type);
	void attach();
	void defaultLoad();
	unsigned int getUniform(const char* name);

	unsigned int m_vertexShader;
	unsigned int m_fragmentShader;
	const char* m_vsSource;
	const char* m_fsSource;


private:
	unsigned int m_program;
};

