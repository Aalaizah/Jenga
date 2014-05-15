#include "Main.h"

#pragma region Callbacks
void Display( void )
{
	App->Display();
}

void Reshape (int w, int h)
{
	App->Reshape( w, h );
}

void Idle( void )
{		
	App->Idle();
}

void Keyboard( unsigned char key, int x, int y )
{
	App->Keyboard( key, x, y);
}

void KeyboardUp( unsigned char key, int x, int y )
{
	App->KeyboardUp( key, x, y);
}

void OnSpecial(int key, int x, int y)
{
	App->OnSpecial( key, x, y);
}

void OnSpecialUp(int key, int x, int y)
{
	App->OnSpecialUp( key, x, y);
}

void Mouse( int button, int state, int x, int y)
{
	App->Mouse(button, state, x, y);
}

void MouseWheel( int wheel, int direction, int x, int y)
{
	App->MouseWheel(wheel, direction, x, y);
}

#pragma endregion

int main(int argc, char **argv )
{	
	//Get System Instance
	SystemClass* pSystem = SystemClass::GetInstance();

	//Configure System Settings
	pSystem->WindowWidth = 1280;
	pSystem->WindowHeight = 720;
	pSystem->WindowName = "Jenga";

	//Init System & Rendering Context
	pSystem->InitRenderingContext(&argc, argv);

	//Get Application Instance
	App = ApplicationClass::GetInstance();
	
	//Configure System Callbacks
	pSystem->Display = &Display;
	pSystem->Reshape = &Reshape;
	pSystem->Idle = &Idle;
	pSystem->Keyboard = &Keyboard;
	pSystem->KeyboardUp = &KeyboardUp;
	pSystem->OnSpecial = &OnSpecial;
	pSystem->OnSpecialUp = &OnSpecialUp;
	pSystem->Mouse = &Mouse;
	pSystem->MouseWheel = &MouseWheel;

	//Init the callback calls
	pSystem->InitCallbacks();
	
	//Start the RenderLoop
	pSystem->StartRenderLoop();
	
	//Release App Information
	App->ReleaseInstance();
	pSystem->ReleaseInstance();

	return 0;
}
