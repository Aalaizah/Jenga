#pragma once
#include "System.h"

class Camera
{
public:

	//location vectors
	glm::vec3 position; //xyz location
	glm::vec3 up;	//"positive" up (0, 1, 0)
	glm::vec3 center;	//way camera is facing (0, 0, 0)
	glm::vec3 positions[8];	//all 8 camera locations to cycle through
	int posIndex;

	Camera(void);
	Camera(GLfloat x, GLfloat y, GLfloat z);
	~Camera(void);

	void Idle();

	void LookAt();

	//Projection
	void CalculateProjection();
	void SetProjection(glm::mat4 a_mProjection);
	glm::mat4 GetProjection();
	__declspec(property(put = SetProjection, get = GetProjection)) glm::mat4 Projection;

	void ChangeView(bool next);
	void ChangeView(glm::vec3 vector);
};