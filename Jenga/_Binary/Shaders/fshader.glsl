#version 150

//fColor is the name of an output variable of the type vec4
//(explained in vshader.glsl) this needs to be out because it
//is what we are sending out of the shader to be rendered by the
//graphics card

out vec4  fColor;

//Again this looks like a C/C++ main method.
void main()
{
	//fColor is going to be initialized with another vec4, this time
	//we are not getting the information out of anything in our CPU so
	//we are going to create those values, for this example everything is
	//going to be white, the format is [R,G,B,A]

    fColor = vec4( 1.0, 1.0, 1.0, 1.0 );
}