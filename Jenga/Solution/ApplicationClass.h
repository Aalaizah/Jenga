/*--------------------------------------------------------------------------------------------------
Created by Alberto Bobadilla (labigm@rit.edu) in 2013
--------------------------------------------------------------------------------------------------*/
#ifndef __APPLICATION_H_
#define __APPLICATION_H_


#include "SystemClass.h"

class ApplicationClass
{
	static ApplicationClass* m_pInstance;
	SystemClass* m_pSystem;
	//Circle* m_pCircle;

public:

	static ApplicationClass* GetInstance(); //Singleton Accessor
	void ReleaseInstance(void); //Singleton Release

	void Display (void);
	void Idle (void);
	void Reshape(int a_nWidth, int a_nHeight);
	void Keyboard(unsigned char key, int x, int y);
	void KeyboardUp(unsigned char key, int x, int y);
	void OnSpecial(int key, int x, int y);
	void OnSpecialUp(int key, int x, int y);
	void Mouse(int button, int state, int x, int y);
	void MouseWheel(int wheel, int direction, int x, int y);

private:
	ApplicationClass(void);
	ApplicationClass(ApplicationClass const& input);
	ApplicationClass& operator=(ApplicationClass const& input);
	~ApplicationClass();
	void Release(void);
	void Init();
};

#endif //_APPLICATION_H