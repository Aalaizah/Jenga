/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2014
This application will create a constant number of points and we will assign positions to them as they
would be present in a circumference. Then generate a buffer and display them using different modes
--------------------------------------------------------------------------------------------------*/

#include "Application.h" //Include our application library
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")//this line hides the command window

const int NUM = 100;//Number of points to be generated
const GLfloat RADIUS = 0.5;//radius of the circle

//Init will do all the basic set up of the information that we are going to be processing for our application
void Init( void )
{
	// Load shaders using the CompileShader function from the Angel library and create an OpenGL Program to use.
	//This will be loaded into memory somewhere, we do not know where, but think of this as if it was a memory
	//location you can then assign, it is basically an index, though you might find it in literature as a "pointer"
	//because its pointing to something, do not confuse it with a regular pointer
    GLuint program = CompileShader( "Shaders\\vshader.glsl", "Shaders\\fshader.glsl" );
    
	//After we compile the shader and get the index of where is stored in memory by OpenGL we let it know that that
	//is the one that we currently cant to use, we can have many different ones loaded into memory, that is why it is
	//important to let it know.
	glUseProgram( program );

	//GLM is going to be a topic for other class do not mind that now, but know that this is an actual bi-dimensional
	//vector (x,y kind of vector, not data structure kind of vector, seems silly to explain this but I've been asked before,
	//so I rather play it safe). This is a simple array of NUM number of points in space.
	glm::vec2 points[NUM];

	//We are going to store information on some regular floats, the fact that they are GLfloats as explained in class is
	//that they are always the same size OpenGL expects in different processors and Operating Systems
    GLfloat x, y, theta = 0;

	//This algorithm will just give the already allocated points a place in space, we will divide PI over the number of steps
	//and that will divide our angles evenly, then Cos of that angle will be our x and sin of that angle will be our y for each
	//point.
    for (int i=0; i < NUM ; i++)
	{
        // you could condense the following, but I expanded it to clarify the algorithm:
        theta += static_cast<GLfloat>(2*M_PI/NUM);
        x = static_cast<GLfloat>(RADIUS*cos(theta));
        y = static_cast<GLfloat>(RADIUS*sin(theta));
        points[i] = glm::vec2(x,y);
    }

    // -- Create a Vertex Array Object --
	//So... what is a VAO and what do I do with it? For now just leave it as its something you need in order to make OpenGL Happy
	//or keep on reading: a VAO is an object that describes how the vertex attributes are stored in a Vertex Buffer Object (or VBO).
	//This means that the VAO is not the actual object storing the vertex data, but the descriptor of the vertex data. 
    GLuint vao; //Generate the identifier that is going to store it
    glGenVertexArrays( 1, &vao ); //Generate the Vertex Array and provide the address of our identifier so OpenGL can write in that address
    glBindVertexArray( vao ); //Bind the array that OpenGL will use to the one we already generated

    // -- Create and initialize a buffer object --
	//This is going to be the VBO "Old" OpenGL required a lot of code to translate an actual vertex array to a VBO (this would be a buffered
	//object living in your graphics card) but shader based OpenGL reduced it to 4 lines of code (nifty!).
    GLuint buffer; //This is going to be an index.
    glGenBuffers( 1, &buffer );//that index is going to be passed to OpenGL so it allocates space for it.
    glBindBuffer( GL_ARRAY_BUFFER, buffer );//Now that we got a working identifier, we will bind it as an array buffer
    glBufferData( GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW );//for that purpose we need to specify how this information is stored

    // -- Initialize the vertex position attribute from the vertex shader --
    //After reading the shaders we know that there is a variable there named vPosition, and we cant really access anything directly in the GPU but
	//we can locate stuff using an index, so we are going to ask the program we previously compiled about a variable named vPosition and assign it
	//to the loc identifier
	GLuint loc = glGetAttribLocation( program, "vPosition" );
    glEnableVertexAttribArray( loc ); //We enable this attribute as a vertex attribute array
    glVertexAttribPointer( loc, 2, GL_FLOAT, GL_FALSE, 0, (void*)0 );// and tell it how to read the data, describe loc, as something that has 2 
	//values as floats

	//this will clear the background color
    glClearColor( 0.0, 0.0, 0.0, 1.0 ); // black background
}

void display( void )
{
    glClear( GL_COLOR_BUFFER_BIT );     // clear the window
	//More information about the following in // http://www.opengl.org/sdk/docs/man/xhtml/glDrawArrays.xml
    glDrawArrays(GL_POINTS, 0, NUM);	// Draw as points
    //glDrawArrays(GL_LINES,0,NUM);		// Draw as lines (each 2 points will make a line)
    //glDrawArrays(GL_TRIANGLES,0,NUM);	// Draw as triangles (each 3 points will make a triangle, as we are using consecutive points it will not work)
    //glDrawArrays(GL_LINE_STRIP,0,NUM);// Draw as a line strip (continuous line from first to last point)
    //glDrawArrays(GL_LINE_LOOP,0,NUM);	 // Draw as a line loop (like a line strip but connected in the ends)
    //glDrawArrays(GL_TRIANGLE_STRIP, 0, NUM); //Draw as an array of triangles, will not work as the format in which it was generated is not correct.
	//glDrawArrays(GL_TRIANGLE_FAN,0,NUM); // this is the one we want, but see what the others do...
    glFlush(); //flush the buffer
}

int main( int argc, char **argv )
{
    glutInit( &argc, argv ); //Init OpenGL with the arguments we receive from the console
    glutInitDisplayMode( GLUT_RGBA );//Initialize the display mode to include Red Green Blue and Alphas
    glutInitWindowSize( 512, 512 ); //The size of the window

    // If you are using freeglut, the next two lines will check if 
    // the code is truly 3.2. Otherwise, comment them out
    glutInitContextVersion( 3, 2 );
    glutInitContextProfile( GLUT_CORE_PROFILE );

    glutCreateWindow("Circle"); //We will create our window and we will name it as the argument we are accepting

	//The following lines are necessary for GLEW
    glewExperimental = GL_TRUE;
    glewInit();

	//We initialize the function that is going to start all the information
    Init();

	//We set the function glut is going to use as a callback to display and render, this is a function pointer
    glutDisplayFunc( display );

	//We start the glut Main Loop surrendering all control of our program to glut
    glutMainLoop();


    return 0;// ending the program after glut returns the control to our window.
}