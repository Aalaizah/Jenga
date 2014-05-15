#include "ApplicationClass.h"

double rotate_y=0; 
double rotate_x=0;

ApplicationClass* ApplicationClass::m_pInstance = nullptr;
ApplicationClass* ApplicationClass::GetInstance()
{
	if(m_pInstance == nullptr)
	{
		m_pInstance = new ApplicationClass();
	}
	return m_pInstance;
}
ApplicationClass::ApplicationClass(){Init();}
ApplicationClass::ApplicationClass(ApplicationClass const& other){}
ApplicationClass& ApplicationClass::operator=(ApplicationClass const& other) {	return *this; }
ApplicationClass::~ApplicationClass(){Release();};
void ApplicationClass::ReleaseInstance()
{
	if(m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}
// Redefinable Functions
void ApplicationClass::Init(void)
{
	m_pSystem = SystemClass::GetInstance();
	m_pSystem->WindowName = "Jenga";
	m_pCamera = CameraClass::GetInstance();
	
	// #TODO: generate shapes?
	myBlock = new Block();

}
void ApplicationClass::Release(void)
{

	// #TODO: Release blocks?
	/*
	if(m_pPolygon != nullptr)
	{
		delete m_pPolygon;
		m_pPolygon = nullptr;
	}
	*/
	m_pCamera->ReleaseInstance();
}
void ApplicationClass::Display(void)
{
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );     // clear the window

	printf("FPS: %d\r", m_pSystem->FPS);

	
#pragma region RENDER_BLOCKS
	//#TODO: Render Blocks

	myBlock->Render();

#pragma endregion

	glutSwapBuffers();
	m_pSystem->UpdateTime();
}
void ApplicationClass::Idle(void)
{
	glutPostRedisplay();
}
void ApplicationClass::Reshape(int a_nWidth, int a_nHeight)
{
	m_pSystem->WindowWidth = a_nWidth;
	m_pSystem->WindowHeight = a_nHeight;
}
void ApplicationClass::Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'A':
		case 'a':
			break;
		case 'R':
		case 'r':
			break;
	}
}
void ApplicationClass::KeyboardUp(unsigned char key, int x, int y)
{
	switch ( key )
	{
	case 033:
	case 13:
        exit( EXIT_SUCCESS );
		break;
	case 'F':
	case 'f':
		break;
    }
}

void ApplicationClass::OnSpecial(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
				m_pCamera->MoveForward(1.1f);
			m_pCamera->MoveForward(0.1f);
			break;
		case GLUT_KEY_DOWN:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
				m_pCamera->MoveForward(-1.1f);
			m_pCamera->MoveForward(-0.1f);
			break;
		case GLUT_KEY_LEFT:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
				m_pCamera->MoveSideways(1.1f);
			m_pCamera->MoveSideways(0.1f);
			break;
		case GLUT_KEY_RIGHT:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
				m_pCamera->MoveSideways(-1.1f);
			m_pCamera->MoveSideways(-0.1f);
			break;
		case GLUT_KEY_PAGE_UP:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
				m_pCamera->MoveVertical(1.1f);
			m_pCamera->MoveVertical(0.1f);
			break;
		case GLUT_KEY_PAGE_DOWN:
			if (glutGetModifiers() == GLUT_ACTIVE_SHIFT)
				m_pCamera->MoveVertical(-1.1f);
			m_pCamera->MoveVertical(-0.1f);
			break;
	}
}

void ApplicationClass::OnSpecialUp(int key, int x, int y)
{
	switch (key)
	{
		case GLUT_KEY_UP:
			break;
		case GLUT_KEY_DOWN:
			break;
		case GLUT_KEY_LEFT:
			break;
		case GLUT_KEY_RIGHT:
			break;
		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;
	}
}

void ApplicationClass::Mouse(int button, int state, int x, int y)
{
	switch(button)
	{
	case GLUT_LEFT_BUTTON :
		switch(state)
		{
		case GLUT_UP:
			break;
		case GLUT_DOWN:
			break;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		switch(state)
		{
		case GLUT_UP:
			break;
		case GLUT_DOWN:
			break;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		switch(state)
		{
		case GLUT_UP:
			break;
		case GLUT_DOWN:
			break;
		}
		break;
	}
}

void ApplicationClass::MouseWheel(int wheel, int direction, int x, int y)
{
}