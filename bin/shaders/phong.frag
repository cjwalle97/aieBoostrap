// fragment shader 
#version 410

uniform vec3 direction;
uniform vec3 Id;
uniform vec3 Is;
uniform vec3 Ia;

uniform vec3 Ka;
uniform vec3 Kd;
uniform vec3 Ks;
uniform float a;

in vec4 vNormal;
in vec4 vPosition;
in vec4 vColor;
in vec2 vUV;
in vec4 vTangent;

out vec4 FragColor;

void main()
{
	vec4 L = vec4(direction, 1);
	vec4 N = vNormal;
	float diffuse = max(0, dot(-L, N));
	FragColor = vec4(1) * diffuse;
}