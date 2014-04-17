#version 150

//We need to send information from the CPU and receive it here
//the next variable is an input variable that has 4 floats values
//not so different than an array of floats but with some extra properties

in vec4 vPosition;

//This is our main entry point to our vertex shader program
//It looks like a regular C/C++ main function with some differences

void main()
{
    gl_Position = vPosition; //We have not defined gl_Position yet we are assigning information to it
	//here its why this is possible https://www.opengl.org/sdk/docs/man4/html/gl_Position.xhtml
}