// fragment shader 
#version 410 
in vec4 vNormal; 
in vec4 vPosition; 
out vec4 FragColor;
uniform vec3 LightDir; 
uniform vec3 LightColour; 

void main() 
{ 
float d = max(0, dot(normalize(vNormal.xyz),LightDir ) ); 
FragColor = vec4(LightColour * d, 1); 
}