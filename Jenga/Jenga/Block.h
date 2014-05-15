#pragma once
#include "System.h"
#include "CameraClass.h"

class Block
{
public:
	Block(void);
	Block(const Block& other);
	~Block(void);

	glm::mat4 m_mModel; //GLM Model Matrix

private:
	// VARS
	//------------------
	//#TODO: Shaders?
	//#TODO: Textures?
    GLuint vbo;
    GLuint vao;
    GLenum drawType;
    GLint drawStart;
    GLint drawCount;
	std::array<GLfloat,96> *vertexData;

	//  METHODS
	//-------------------
	
	void initBlock();

	//Sets the Model Matrix in base of another Matrix (No Parameters sets the Identity)
	void SetModelMatrix(const glm::mat4 a_mModel = glm::mat4(1.0f));
	//Returns the Model Matrix
	glm::mat4& GetModelMatrix(void);
	//Property of th ModelMatrix
	__declspec(property(put = SetModelMatrix, get = GetModelMatrix)) glm::mat4 ModelMatrix;

	// #TODO: ABSTRACT THIS TO BLOCK MANAGER
#pragma region SHADER_STUFF

	bool m_bCPUInitialized;
	bool m_bGPUInitialized;
	GLuint shaderProgram;

	std::string vShaderFile;
	std::string fShaderFile;

	CameraClass* pCamera;
	void InitGPU(	std::string a_sVShaderFile = "Shaders\\vshader.glsl", 
					std::string a_sFShaderFile = "Shaders\\fshader.glsl");

	virtual void InitCPU (const int a_nVertices = 3);
	virtual void Render(void);

#pragma endregion

};

