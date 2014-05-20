#include "Camera.h"


Camera::Camera()
{
}

Camera::Camera(GLfloat x, GLfloat y, GLfloat z)
{
	up = glm::vec3(0.0f, 1.0f, 0.0f);
	center = glm::vec3((GLUT_WINDOW_WIDTH / 2), 0, 0.0f);
	position = glm::vec3(x, y, z);
	posIndex = 0;
	for (int x = 0; x < 8; x++)
	{
		if (x % 2 == 0)
			positions[x] = position;
		else
			positions[x] = glm::vec3(0.25f, 0.0f, -0.25f);
	}
}

Camera::~Camera()
{
}

void Camera::LookAt()
{
	gluLookAt(position.x, position.y, position.z,
			  (center.x + position.x), (center.y + position.y), (center.z + position.y), 
			  up.x, up.y, up.z);
}

//For changing camera location to the next fixed location
void Camera::ChangeView(bool next)
{
	//If next = true, iterate forward.
	//Else, go backwards
	if (next)
	{
		if (posIndex >= 8)	//max num of camera locations
			posIndex = -1;	//adding one reaches 0
		posIndex++;
	}
	else
	{
		if (posIndex = 0)
			posIndex = 8;
		posIndex--;
	}
	//set new camera position
	position = positions[posIndex];
}

void Camera::ChangeView(glm::vec3 vector)
{
	position = vector;
}

void Camera::Idle()
{
	LookAt();
}