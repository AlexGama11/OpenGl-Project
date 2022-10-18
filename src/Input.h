#pragma once
#include <iostream>
#include <SDL.h>


class Input
{

public:

	static Input* Instance();

	void Update();

	float GetMousePositionX();
	float GetMousePositionY();
	float GetMousePositionZ();
	float GetMouseWheel();

	char GetKey();

	bool GetQuit();

private:

	Input() {};
	Input(const Input&);
	Input& operator = (const Input&);

	struct Vec3
	{
		float x{ 0.0f };
		float y{ 0.0f };
		float z{ 0.0f };
	};

	struct Size
	{
		float increment{ 0.0f };
	};

	Size mouseWheel;
	
	Vec3 mouseMotion;
	Vec3 mousePosition;

	char key;

	bool quit{ false };
	//auto mouseButton;


};

