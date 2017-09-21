// fragment shader 
#version 410 
in vec4 vColor; 
in vec4 vPosition; 
out vec4 FragColor;
uniform vec3 LightDir; 
uniform vec3 LightColor; 

void main() 
{ 
float d = max(0, dot(normalize(vPosition.xyz),LightDir ) ); 
FragColor = vec4(LightColor * d, 1);

}