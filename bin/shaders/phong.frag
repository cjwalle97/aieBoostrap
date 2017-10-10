// fragment shader 
#version 410

uniform vec3 direction;
uniform vec3 Id;
uniform vec3 Is;
uniform vec3 Ia;

vec3 Ka;
vec3 Kd;
vec3 Ks;
float a;

in vec4 vNormal;
in vec4 vPosition;
in vec4 vColor;
in vec2 vUV;
in vec4 vTangent;



out vec4 FragColor;

void main()
{

	Ka = vec3(1f, 1.f, 1.f);
	vec4 ambient = vec4(Ka, 1) * vec4(Ia, 1);
	
	Kd = vec3(1, 1.f, 1.f);
	vec4 diffuse = vec4(Kd, 1) * max(0.0f, dot(vec4(direction, 1), vNormal)) * vec4(Id,1);

	Ks = vec3(1.f, 1.f, 1.f);
	//vec4 specular = vec4(Ks, 1) * dot() * Is;

	FragColor = ambient + diffuse;
	
}