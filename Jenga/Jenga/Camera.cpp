#include "Camera.h"

Camera* Camera::m_pInstance = nullptr;

Camera* Camera::GetInstance()
{
	if(m_pInstance == nullptr)
	{
		m_pInstance = new Camera();
	}
	return m_pInstance;
}

Camera::Camera(){Init();}
Camera::Camera(Camera const& other){}
Camera& Camera::operator=(Camera const& other) {	return *this; }
Camera::~Camera(){Release();};
void Camera::ReleaseInstance()
{
	if(m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

//--- Non Standard Singleton Methods
void Camera::Release()
{
	Init();
	m_pSystem = nullptr;
}

void Camera::Init()
{
	m_pSystem = SystemClass::GetInstance();
	
	// View
	m_vPosition = glm::vec3(0.0f, 0.0f, 5.0f);
	m_vForward = glm::vec3(0.0f, 0.0f, -1.0f);
	m_vUp = glm::vec3(0.0f, 1.0f, 0.0f);

	CalculateView();
	CalculateProjection();

	GetMVP();
}

//Projection
void Camera::CalculateProjection()
{
	float y = static_cast<float> (m_pSystem->WindowWidth);
	float x = static_cast<float> (m_pSystem->WindowHeight);
	if(x == 0)
		x = 1;

	float fFieldOfView = 45.0f;
	float fAspectRatio = y / x;
	float fNear = 0.01f;
	float fFar = 500.0f;

	Projection = glm::perspective(	fFieldOfView,
									fAspectRatio,
									fNear,
									fFar);
}
void Camera::SetProjection(glm::mat4 a_mProjection)
{
	m_mProjection = a_mProjection;
}

glm::mat4 Camera::GetProjection()
{
	return m_mProjection;
}

//View
void Camera::CalculateView()
{
	m_mView = glm::lookAt(	m_vPosition,
							m_vPosition + m_vForward, 
							m_vUp);
}
void Camera::SetView(glm::mat4 a_mView)
{
	m_mView = a_mView;
}
//MVP
glm::mat4 Camera::GetMVP(glm::mat4 a_mModel)
{
	m_mMVP = m_mProjection * m_mView * a_mModel;
	return m_mMVP;
}
glm::mat4 Camera::GetMVP()
{
	return m_mMVP;
}

void Camera::Rotate(float a_fAngX, float a_fAngY)
{
	//direction: Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(a_fAngX) * sin(a_fAngY), 
		sin(a_fAngX),
		cos(a_fAngX) * cos(a_fAngY)
	);

	//right vector
	glm::vec3 right = glm::vec3(
		sin(a_fAngY -  PI/2.0f), 
		0,
		cos(a_fAngY - PI/2.0f)
	);

	// Up vector
	glm::vec3 up = glm::cross( right, direction );

	m_vForward = -direction;
	m_vUp = up;

	//SetDirection(-direction);
	//SetUp(up);
	CalculateView();
}

//Translation
void Camera::SetPosition(glm::vec3 a_Postion)
{
	//INCORRECT CALCULATION
	//do not use. Redownload zip
	m_vPosition = a_Postion;


	glm::vec3 v3At = a_Postion + glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 v3Up = glm::vec3(0.0f, 1.0f, 0.0f);

	m_mView = glm::lookAt( a_Postion, v3At, v3Up );
}
glm::vec3 Camera::GetPosition(void)
{
	return m_vPosition;
}
void Camera::SetDirection(glm::vec3 a_vDirection)
{
	m_vForward = a_vDirection;
}
void Camera::SetUp(glm::vec3 a_vDirection)
{
	m_vUp = a_vDirection;
}
void Camera::MoveForward(float a_fDisntance)
{
	m_vPosition += m_vForward * a_fDisntance;
}
void Camera::MoveVertical(float a_fDisntance)
{
	m_vPosition += m_vUp * a_fDisntance;
}

void Camera::MoveSideways(float a_fDisntance)
{
	glm::vec3 right = glm::cross(m_vForward, m_vUp);
	m_vPosition += right * a_fDisntance;
}

/*

*/