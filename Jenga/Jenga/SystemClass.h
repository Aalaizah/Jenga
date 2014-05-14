//***System singleton for camera***
#pragma once
#include "System.h"

class SystemClass
{
public:
	static SystemClass* GetInstance(); // Singleton Accessor
	void ReleaseInstance(void); //Singleton Release

	// Window Width Property
	__declspec(property(get = GetWindowWidth, put = SetWindowWidth)) int WindowWidth;
	void SetWindowWidth(int nWidth);
	int GetWindowWidth(void);

	// Window Height Property
	__declspec(property(get = GetWindowHeight, put = SetWindowHeight)) int WindowHeight;
	void SetWindowHeight(int nHeight);
	int GetWindowHeight(void);

	// WindowX Property
	__declspec(property(get = GetWindowX, put = SetWindowX)) int WindowX;
	void SetWindowX(int nX);
	int GetWindowX(void);

	// WindowY Property
	__declspec(property(get = GetWindowY, put = SetWindowY)) int WindowY;
	void SetWindowY(int nY);
	int GetWindowY(void);

	// Window Name Property
	__declspec(property(get = GetWindowName, put = SetWindowName)) std::string WindowName;
	void SetWindowName(std::string sWindowName);
	std::string GetWindowName(void);

	// WindowX Property
	__declspec(property(get = GetFPS)) int FPS;
	int GetFPS(void);

	// Display functor Property
	void SetDisplayFunctor(void (*Functor) (void));
	__declspec(property(put = SetDisplayFunctor)) void (*Display) (void);

	// Reshape functor Property
	void SetReshapeFunctor(void (*Functor) (int, int));
	__declspec(property(put = SetReshapeFunctor)) void (*Reshape) (int, int);

	// Idle functor Property
	void SetIdleFunctor(void (*Functor) (void));
	__declspec(property(put = SetIdleFunctor)) void (*Idle) (void);

	// OnTime functor Property
	void SetOnTimeFunctor(void (*Functor) (int));
	__declspec(property(put = SetOnTimeFunctor)) void (*OnTime) (int);

	// Keyboard functor Property
	void SetKeyboardFunctor(void (*Functor)(unsigned char, int, int));
	__declspec(property(put = SetKeyboardFunctor)) void (*Keyboard) (unsigned char, int, int);

	// KeyboardUp functor Property
	void SetKeyboardUpFunctor(void (*Functor)(unsigned char, int, int));
	__declspec(property(put = SetKeyboardUpFunctor)) void (*KeyboardUp) (unsigned char, int, int);

	// OnSpecialFunctor Property
	void SetOnSpecialFunctor(void (*Functor)(int, int, int));
	__declspec(property(put = SetOnSpecialFunctor)) void (*OnSpecial) (int, int, int);

	// OnSpecialUpFunctor Property
	void SetOnSpecialUpFunctor(void (*Functor)(int, int, int));
	__declspec(property(put = SetOnSpecialUpFunctor)) void (*OnSpecialUp) (int, int, int);

	// MouseFunctor Property
	void SetMouseFunctor(void (*Functor)(int, int, int, int));
	__declspec(property(put = SetMouseFunctor)) void (*Mouse) (int, int, int, int);

	// MouseWheelFunctor Property
	void SetMouseWheelFunctor(void (*Functor)(int, int, int, int));
	__declspec(property(put = SetMouseWheelFunctor)) void (*MouseWheel) (int, int, int, int);

	bool InitRenderingContext(int* argc, char **argv); // Creates the OpenGL "hooks"

	void StartRenderLoop(void); // Initiates the renderLoop

	void UpdateTime(void);//Updates the current time
	void StartClock(void);//Starts a time count
	float StopClock(void);//Stops the time count and returns the number of seconds passed
	float LapClock(void);//Checks the time difference between startclock and current call

	//FolderClass* m_pFolder;

private:
	SystemClass(void); // Constructor
	SystemClass(SystemClass const& other); //Copy Constructor
	SystemClass& operator=(SystemClass const& other); // Copy Assignment Operator
	~SystemClass(void); // Destructor

	void Release(void); // Release Memory
	void Init(void); // Initialize variables

	static SystemClass* m_pInstance; // Singleton

	bool m_bGlutInitialized; //Glut is running in the system

	int m_nWindowWidth; // Window width
	int m_nWindowHeight; // Window height
	int m_nWindowX; // Window Position X
	int m_nWindowY; // Window Position Y
	std::string m_sWindowName; // Window Name

	DWORD m_dTimerStart; //Start time of the program
	DWORD m_dStartingTime; //Start time of the program
	DWORD m_dLastFPS; //Last time the time was called
	int m_nFPS; //Frames per Second
	int m_nFrames; //Frames Passed

	void (*m_pDisplay) (void); //Display Functor
	void (*m_pReshape) (int nWidht, int nHeight); // Reshape Functor
	void (*m_pIdle) (void); // Idle Functor
	void (*m_pKeyboard) (unsigned char key, int x, int y); // Keyboard Functor
	void (*m_pKeyboardUp) (unsigned char key, int x, int y); // KeyboardUp Functor
	void (*m_pOnSpecial) (int key, int x, int y); // OnSpecial Functor
	void (*m_pOnSpecialUp) (int key, int x, int y); // OnSpecialUp Functor
	void (*m_pMouse) (int button, int state, int x, int y); //Mouse Functor
	void (*m_pMouseWheel) (int wheel, int direction, int x, int y); //Mouse Wheel Functor

	bool InitCallbacks(void); // Indicates OpenGL what functors are going to be used as callbacks
};

//***end***