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
out vec4 VertColor;

void main()
{
	vec4 ambient = vec4(Ka, 1) * vec4(Ia, 1);
	
	vec4 diffuseColor = vec4(1.0f, 0.25f, 1.0f, 1) * vec4(0.25, 1.0f, 1.0f, 1);
	vec4 diffuse = diffuseColor * max(0.0f, dot(vNormal, vec4(-direction, 1)));

	vec4 specular = vec4(Ks, 1) * vec4(Is, 1) * dot(vec4(vUV, 0, 1), vTangent);

	FragColor = diffuse;
}