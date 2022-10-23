#include "Objects.h"

void Objects::Draw()
{
	num += 0.01f;

	float redValue = std::abs(std::sin(num));

	float blueValue = std::abs(std::sin(num * 0.5));

	float greenValue = std::abs(std::cos(num));

	//std::cout << "Red Value: " << redValue << ", Blue Value: " << blueValue << ", Green Value: " << greenValue << std::endl;

	glBegin(GL_QUADS);

	//top right corner
	glColor3f(redValue, 0.0f, 0.0f);
	glVertex3f(GetX(0), GetY(0), GetZ(0));

	//std::cout << "X Value: " << GetX(0) << ", Y Value: " << GetY(0) << ", Z Value: " << GetZ(0) << std::endl;

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

	/*for (int i = 0; i < 3; i++)
	{
		std::cout << "X value for corner" << i << ": " << GetX(i) << ", Y value for corner" << i << ": " << GetY(i) << ", Z value for corner" << i << ": " << GetZ(i) << std::endl;
	}*/
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
		std::cout << "Error in setting corner coordinates" << std::endl;
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
		std::cout << "Error in setting corner coordinates" << std::endl;
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
		std::cout << "Error in setting corner coordinates" << std::endl;
		return 0.0f;
	};
}
