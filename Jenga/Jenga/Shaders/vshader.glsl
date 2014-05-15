#version 150

in vec4 vPosition; //Vertex position

uniform mat4 MVP; //Final Composed Matrix

void
main()
{
	gl_Position = MVP * vPosition;
}