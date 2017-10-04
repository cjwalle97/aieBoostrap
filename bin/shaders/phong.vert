#version 410
layout(location = 0) in vec4 position;
layout(location = 1) in vec4 color;
layout(location = 2) in vec4 normal;
layout(location = 3) in vec2 Uv;
layout(location = 4) in vec4 tangent;

out vec4 vPosition;
out vec4 vColor;
uniform mat4 ProjectionViewModel;
void main() 
{ 
    vPosition = position;
    vColor = color;
    gl_Position = ProjectionViewModel * position;
}