#include "Header Files/Objects.h"

void Objects::Draw()
{
	num += 0.01f;

	float redValue = std::abs(std::sin(num));

	float blueValue = std::abs(std::sin(num * 0.5));

	float greenValue = std::abs(std::cos(num));

	glBegin(GL_QUADS);

	//top right corner
	glColor3f(redValue, 0.0f, 0.0f);
	glVertex3f(GetX(0), GetY(0), GetZ(0));

	//bottom right corner
	glColor3f(0.0f, greenValue, 0.0f);
	glVertex3f(GetX(1), GetY(1), GetZ(1));

	//bottom left corner
	glColor3f(0.0f, 0.0f, blueValue);
	glVertex3f(GetX(2), GetY(2), GetZ(2));

	//top left corner
	glColor3f(redValue, 0.0f, blueValue);
	glVertex3f(GetX(3), GetY(3), GetZ(3));

	glEnd();

	static bool isErrorChecked = false;

	if (!isErrorChecked)
	{
		Utility::CheckGLError();
		isErrorChecked = true;
	}
}

float Objects::GetX(int corner)
{
	switch (Corners(corner))
	{
	case Corners::TopRight:
		return std::sin(Input::Instance()->GetMousePositionX() + Input::Instance()->GetMouseWheel());
		break;

	case Corners::BottomRight:
		return std::sin(Input::Instance()->GetMousePositionX() + Input::Instance()->GetMouseWheel());
		break;

	case Corners::BottomLeft:
		return std::sin(Input::Instance()->GetMousePositionX() - Input::Instance()->GetMouseWheel());
		break;

	case Corners::TopLeft:
		return std::sin(Input::Instance()->GetMousePositionX() - Input::Instance()->GetMouseWheel());
		break;

	default:
		Utility::Log("Error in setting corner coordinates");
		return 0.0f;
	}
}

float Objects::GetY(int corner)
{
	switch (Corners(corner))
	{
	case Corners::TopRight:
		return std::sin(Input::Instance()->GetMousePositionY() + Input::Instance()->GetMouseWheel());
		break;

	case Corners::BottomRight:
		return std::sin(Input::Instance()->GetMousePositionY() - Input::Instance()->GetMouseWheel());
		break;

	case Corners::BottomLeft:
		return std::sin(Input::Instance()->GetMousePositionY() - Input::Instance()->GetMouseWheel());
		break;

	case Corners::TopLeft:
		return std::sin(Input::Instance()->GetMousePositionY() + Input::Instance()->GetMouseWheel());
		break;

	default:
		Utility::Log("Error in setting corner coordinates");
		return 0.0f;
	}
}

float Objects::GetZ(int corner)
{
	switch (Corners(corner))
	{
	case Corners::TopRight:
		return Input::Instance()->GetMousePositionZ() + 0.0f;
		break;

	case Corners::BottomRight:
		return Input::Instance()->GetMousePositionZ() + 0.0f;
		break;

	case Corners::BottomLeft:
		return Input::Instance()->GetMousePositionZ() + 0.0f;
		break;

	case Corners::TopLeft:
		return Input::Instance()->GetMousePositionZ() + 0.0f;
		break;

	default:
		Utility::Log("Error in setting corner coordinates");
		return 0.0f;
	};
}
