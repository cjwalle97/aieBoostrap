// fragment shader 
#version 410

uniform vec3 direction;
uniform vec3 Id;
uniform vec3 Is;
uniform vec3 Ia;

uniform vec3 Ka;
uniform vec3 Kd;
uniform vec3 Ks;
float a;

in vec4 vNormal;
in vec4 vPosition;
in vec4 vColor;
in vec2 vUV;
in vec4 vTangent;



out vec4 FragColor;

void main()
{
	vec4 ambient = vec4(Ka, 1) * vec4(Ia, 1);
	
	vec4 diffuse = vec4(Kd, 1) * max(0.0f, dot(vec4(direction, 1), vNormal)) * vec4(Id, 1);

	vec4 specular = vec4(Ks, 1) * dot(vec4(vUV, 0, 1), vTangent) * vec4(Is, 1);

	FragColor = specular;
}