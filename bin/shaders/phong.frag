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

	vec3 L = normalize(direction.xyz);
	vec3 N = normalize(vNormal.xyz);

	vec4 ambient = vec4(Ka, 1) * vec4(Ia, 1);
	
	vec4 diffuseColor = vec4(Kd, 1.f) * vec4(Id, 1.0f);
	vec4 diffuse = diffuseColor * max(0.0f, dot(vec4(N, 1.0f), vec4(-L, 1.0f)));

	vec4 specularColor = vec4(1.0f, 1.0f, 1.0f, 1.0f) * vec4(1.0f, 1.0f, 1.0f, 1.0f);
	vec4 specular = specularColor * dot(vec4(vUV, 0, 1), vTangent);

	FragColor = diffuseColor;

}