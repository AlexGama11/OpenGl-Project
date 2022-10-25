#pragma once
#include <math.h>
#include "gl.h"
#include "Input.h"
#include "Utility.h"


class Objects
{

public:

	void Draw();

	// Corner Numbers link to Corners enum. 0 = Top Right. 1 = Bottom Right. 2 = Bottom Left. 3 = Top Left.
	float GetX(int corner);
	
	// Corner Numbers link to Corners enum. 0 = Top Right. 1 = Bottom Right. 2 = Bottom Left. 3 = Top Left.
	float GetY(int corner);

	// Corner Numbers link to Corners enum. 0 = Top Right. 1 = Bottom Right. 2 = Bottom Left. 3 = Top Left.
	float GetZ(int corner);



private:

	enum class Corners
	{
		TopRight,
		BottomRight,
		BottomLeft,
		TopLeft
	};

	float num{ 0.01f };

	float redValue;
	float blueValue;
	float greenValue;

};

