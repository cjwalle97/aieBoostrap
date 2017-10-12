//classic Phong equation
#version 410

uniform vec4 Position;
uniform vec4 Color;
uniform vec4 Normal;
uniform vec2 UV;
uniform vec4 Tangent;

uniform mat4 ProjectionViewModel;
out vec4 vNormal;
out vec4 vPosition;
out vec4 vColor;
out vec2 vUV;
out vec4 vTangent;

void main()
{
	vColor = vec4(0.0f, 1.0f ,1.0f, 1.0f);
	vPosition = Position;
	vNormal = vec4(1.0f, 1.0f, 1.0f, 1.0f);
	vUV = UV;
	vTangent = Tangent;

	gl_Position = ProjectionViewModel * Position;
}