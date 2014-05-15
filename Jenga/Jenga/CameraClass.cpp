#include "CameraClass.h"
//  CameraClass
CameraClass* CameraClass::m_pInstance = nullptr;
CameraClass* CameraClass::GetInstance()
{
	if(m_pInstance == nullptr)
	{
		m_pInstance = new CameraClass();
	}
	return m_pInstance;
}
CameraClass::CameraClass(){Init();}
CameraClass::CameraClass(CameraClass const& other){}
CameraClass& CameraClass::operator=(CameraClass const& other) {	return *this; }
CameraClass::~CameraClass(){Release();};
void CameraClass::ReleaseInstance()
{
	if(m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
//--- Non Standard Singleton Methods
void CameraClass::Release()
{
	//No pointers allocated, so nothing to do here
}

void CameraClass::Init()
{
	m_pSystem = SystemClass::GetInstance();
	SetProjection();
	SetView();
	CalculateProjection();
}

//Projection
void CameraClass::SetProjection()
{
	float y = static_cast<float> (m_pSystem->WindowWidth);
	float x = static_cast<float> (m_pSystem->WindowHeight);
	if(x == 0)
		x = 1;
	Projection = glm::perspective(45.0f, y / x, 0.1f, 500.0f);
}
void CameraClass::SetProjection(glm::mat4 a_mProjection)
{
	m_mProjection = a_mProjection;
}

//View
void CameraClass::SetView()
{
	m_mView = glm::lookAt(
							glm::vec3(0.0f,0.1f,5.0f),
							glm::vec3(0.0f,0.1f,0.0f),
							glm::vec3(0.0f,1.0f,0.0f)
							);
}
void CameraClass::SetView(glm::mat4 a_mView)
{
	m_mView = a_mView;
}
//MVP
glm::mat4 CameraClass::CalculateProjection(glm::mat4 a_mModel)
{
	m_mMVP = m_mProjection * m_mView * a_mModel;
	return m_mMVP;
}
glm::mat4 CameraClass::GetMVP()
{
	return m_mMVP;
}

//Translation
void CameraClass::MoveSideways(float a_fDisntance)
{
	m_mView = glm::translate(m_mView, glm::vec3(a_fDisntance, 0.0f, 0.0f));
}
void CameraClass::MoveForward(float a_fDisntance)
{
	m_mView = glm::translate(m_mView, glm::vec3(0.0f, 0.0f, a_fDisntance));
}
void CameraClass::MoveVertical(float a_fDisntance)
{
	m_mView = glm::translate(m_mView, glm::vec3(0.0f, a_fDisntance, 0.0f));
}