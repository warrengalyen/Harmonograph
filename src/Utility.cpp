#include "Utility.h"

bool mouseClickedOnce(Mouse::Button const& button, bool &clickedLastFrame) 
{
	bool result = false;
	if(Mouse::isButtonPressed(button) && clickedLastFrame == false)
	{
		result = true;
		clickedLastFrame = true;
	}
	else if (Mouse::isButtonPressed(button) && clickedLastFrame == true) 
	{
		result = false;
		clickedLastFrame = true;
	}
	else
	{
		result = false;
		clickedLastFrame = false;
	}
	return result;
}