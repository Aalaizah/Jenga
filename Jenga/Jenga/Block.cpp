#include "Block.h"
#define NUM_VERTICES 8


Block::Block(void): vertexData(nullptr), pCamera(CameraClass::GetInstance())
{
	vao = 0;
	vbo = 0;
	shaderProgram = 0;

	vShaderFile = "";
	fShaderFile = "";

	m_bCPUInitialized = false;
	m_bGPUInitialized = false;
}// end constructor

Block::Block(const Block& other) : vertexData(nullptr), pCamera(CameraClass::GetInstance())
{
	vao = 0;
	vbo = 0;
	shaderProgram = 0;

	//m_mModel = other.m_mModel;

	if(other.m_bCPUInitialized)
	{
		InitCPU(NUM_VERTICES);

		vertexData = new std::array<float, 96>(*other.vertexData); 
	}
	if(other.m_bGPUInitialized)
	{
		InitGPU();
	}
} // end copy constructor

Block::~Block(void)
{
} // end destructor

void Block::initBlock() {

	// init vars
	vbo = 0;
	vao = 0;
	drawType = GL_TRIANGLE_STRIP;
	drawStart = 0;
	drawCount = 6 * 2 * 3;
	// #TODO: Init texture and shaders

	// assign vertexData
	float vertexData[] = { 
		//  X     Y     Z       U     V
        // back
         0.15, -0.125, 0.5,   //0.0f, 0.0f, // BBR
         0.15, 0.125, 0.5,   //1.0f, 0.0f, // TBR
        -0.15, 0.125, 0.5,   //0.0f, 1.0f, // TBL
        -0.15, -0.125, 0.5,   //1.0f, 0.0f, // BBL

        // right
         0.15, -0.125, -0.5,   //0.0f, 0.0f, // BFR
         0.15, 0.125, -0.5,   //0.0f, 1.0f, // TFR
         0.15, 0.125, 0.5,   //1.0f, 0.0f, // TBR
         0.15, -0.125,  0.5,   //1.0f, 0.0f, // BBR

        // left
        -0.15, -0.125,  0.5,   //1.0f, 0.0f, // BBL
        -0.15, 0.125, 0.5,   //0.0f, 0.0f, // TBL
        -0.15, 0.125, -0.5,   //1.0f, 1.0f, // TFL
        -0.15, -0.125, -0.5,   //0.0f, 0.0f, // BFL

        // top
         0.15, 0.125,  0.5,   //0.0f, 0.0f, // TBR
         0.15, 0.125, -0.5,   //0.0f, 1.0f, // TFR
        -0.15, 0.125, -0.5,   //1.0f, 0.0f, // TFL
        -0.15, 0.125,  0.5,   //1.0f, 0.0f, // TBL

        // bottom
         0.15, -0.125, -0.5,   //0.0f, 1.0f, // BFR
         0.15, -0.125,  0.5,   //1.0f, 0.0f, // BBR
        -0.15, -0.125,  0.5,   //0.0f, 0.0f, // BBL
        -0.15, -0.125, -0.5,   //0.0f, 1.0f, // BFL

        // front
        -0.15, 0.125, -0.5,   //1.0f, 1.0f, // TFL
        -0.15, -0.125, -0.5,   //1.0f, 0.0f, // BFL
         0.15, -0.125, -0.5,   //0.0f, 0.0f, // BFR
         0.15, 0.125, -0.5   //1.0f, 1.0f, // TFR

	}; // end define vertexData

	// generate VBO
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, (12 * NUM_VERTICES) * sizeof(float), vertexData, GL_STATIC_DRAW);
	
	// generate VAO
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL); 

} // end initBlock


void Block::InitGPU(std::string a_sVShaderFile, std::string a_sFShaderFile)
{
    m_bGPUInitialized = true;
	vbo = 0;
	vao = 0;



    // Create a vertex array object
    glGenVertexArrays( 1, &vao );
    glBindVertexArray( vao );

    // Create and initialize a buffer object for each circle.
    glGenBuffers( 1, &vbo );
    glBindBuffer( GL_ARRAY_BUFFER, vbo );
    glBufferData( GL_ARRAY_BUFFER, (12 * NUM_VERTICES) * sizeof(float), vertexData, GL_STATIC_DRAW );

    vShaderFile = a_sVShaderFile;
    fShaderFile = a_sFShaderFile;

    // Initialize the shaders
    //m_ShaderProgram = CompileShader( "Shaders\\vshader.glsl", "Shaders\\fshader.glsl" );
    shaderProgram = CompileShader( vShaderFile.c_str(), fShaderFile.c_str() );
}


void Block::InitCPU (const int a_nVertices)
{
	m_bCPUInitialized = true;
#pragma region VERTEX_DATA
		// assign vertexData
	std::array<float, 96> v = { 
		 -0.15, -0.125, -0.5,  0.15, -0.125, -0.5, -0.15, 0.125, -0.5,  0.15, 0.125, -0.5, // Front
		  0.15, -0.125, -0.5,  0.15, -0.125, 0.5,  0.15, 0.125, -0.5,  0.15, 0.125, 0.5, // Right
		  0.15, -0.125, 0.5, -0.15, -0.125, 0.5,  0.15, 0.125, 0.5, -0.15, 0.125, 0.5, // Back
		 -0.15, -0.125, 0.5, -0.15, -0.125, -0.5, -0.15, 0.125, 0.5, -0.15, 0.125, -0.5, // Left
		 -0.15, -0.125, 0.5,  0.15, -0.125, 0.5, -0.15, -0.125, -0.5,  0.15, -0.125, -0.5, // Bottom
		 -0.15, 0.125, -0.5,  0.15, 0.125, -0.5, -0.15, 0.125, 0.5,  0.15, 0.125, 0.5 // top

	}; // end define vertexData

	vertexData = new std::array<float, 96>(v); 
#pragma endregion

} // end initCPU


void Block::Render(void)
{
	//super::Render();
	// Use the buffer and shader for each figure.
	glUseProgram( shaderProgram );
	glBindBuffer( GL_ARRAY_BUFFER, vbo );

	// Get the GPU variables by their name and hook them to CPU variables
	GLuint color = glGetUniformLocation( shaderProgram, "fColorIn");
	GLuint MatrixID = glGetUniformLocation( shaderProgram, "MVP" );
	GLuint vPosition = glGetAttribLocation( shaderProgram, "vPosition" );

	//m_mModel = glm::translate(m_mModel, glm::vec3(0.01f,0.01f,0.01f));
		//glm::rotate(m_mModel, 0.1f, glm::vec3(0.0f, 1.0f, 0.0f));

	// Final Projection of the Camera
	glm::mat4 MVP = pCamera->CalculateProjection(m_mModel);
	glUniformMatrix4fv(MatrixID, 1, GL_FALSE, glm::value_ptr(MVP)); //using value_ptr to get the array of floats
	//glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

	//position
	
	//glVertexAttribPointer( vPosition, 3, GL_FLOAT, GL_FALSE, 0, (void*)0 );
	glVertexAttribPointer( vPosition, 3, GL_FLOAT, GL_FALSE, 0, vertexData);
	glEnableVertexAttribArray( vPosition );

	// Draw the array of this figure
	glUniform4f( color, 1.0f, 1.0f, 1.0f, 1.0f);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 4, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 8, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 12, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 16, 4);
    glDrawArrays(GL_TRIANGLE_STRIP, 20, 4);
	//glUniform4f( color, 1.0f, 0.0f, 0.0f, 1.0f);
	//glDrawArrays(GL_LINE_LOOP, 0, NUM_VERTICES);
}

void Block::SetModelMatrix(const glm::mat4 a_mModel)
{
	m_mModel = a_mModel;
}

glm::mat4& Block::GetModelMatrix(void)
{
	return m_mModel;
}

/*
-0.15, -0.125, -0.5, // A - BFL
 0.15, -0.125, -0.5, // B - BFR
-0.15, 0.125, -0.5, // C - TFL
 0.15, 0.125, -0.5, // D - TFR
-0.15, -0.125, 0.5, // E - BBL
 0.15, -0.125, 0.5, // F - BBR
-0.15, 0.125, 0.5, // G - TBL
 0.15, 0.125, 0.5, // H - TBR


*/

