// fragment shader 
#version 410 
in vec4 vColor; 
in vec4 vPosition; 
uniform vec4 LightDir; 
uniform vec4 LightColor; 
out vec4 fragColor;


void main() 
{ 
vec3 L = normalize(LightDir).xyz;
vec3 N = normalize(vPosition).xyz;
float d = max(0, dot(N, -L));
fragColor = vec4(LightColor.xyz * vColor.xyz * d, 1);
}