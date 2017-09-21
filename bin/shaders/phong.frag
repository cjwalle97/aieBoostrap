// fragment shader 
#version 410 
in vec4 vColor; 
in vec4 vPosition; 
out vec4 FragColor;
uniform vec4 LightDir; 
uniform vec4 LightColor; 

void main() 
{ 
float d = max(0, dot(normalize(vPosition.xyz),LightDir ) ); 
FragColor = vec4(LightColor * vColor * d, 1);

}