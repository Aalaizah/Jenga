#pragma once
//#include "Manager.h"
#include "System.h"

class Camera
{
public:
	static Camera* GetInstance(); // Singleton Accessor
	void ReleaseInstance(void); //Singleton Release

	//Rotate
	void Rotate(float a_fAngX, float a_fAngY);

	//Translate
	void MoveSideways(float a_fDistance = 0.1f);
	void MoveVertical(float a_fDistance = 0.1f);
	void MoveForward(float a_fDistance = 0.1f);

	//Projection
	void CalculateProjection();
	void SetProjection(glm::mat4 a_mProjection);
	glm::mat4 GetProjection();
	__declspec(property(put = SetProjection, get = GetProjection)) glm::mat4 Projection;

	//View
	void SetPosition(glm::vec3 a_Position);
	void SetDirection(glm::vec3 a_vDirection);
	void SetUp(glm::vec3 a_vDirection);
	void CalculateView();
	void SetView(glm::mat4 a_mView);
	__declspec(property(put = SetView)) glm::mat4 View;
	glm::vec3 GetPosition(void);

	//MVP
	glm::mat4 GetMVP(glm::mat4 a_mModel);
	glm::mat4 GetMVP();
	__declspec(property(get = GetMVP)) glm::mat4 VMP;

private:
	static Camera* m_pInstance;//Singleton
	SystemClass* m_pSystem;

	glm::mat4 m_mProjection; //Projection
	glm::mat4 m_mView; //View
	glm::mat4 m_mMVP; //MVP

	glm::vec3 m_vPosition; //CameraPosition
	glm::vec3 m_vForward; //Camera view vector
	glm::vec3 m_vUp; //Camera up vector

	Camera(void); // Constructor
	Camera(Camera const& other); //Copy Constructor
	Camera& operator=(Camera const& other); // Copy Assignment Operator
	~Camera(void); //Destructor

	void Release(void);// Releases the memory
	void Init(void); //Init the values*/
};

