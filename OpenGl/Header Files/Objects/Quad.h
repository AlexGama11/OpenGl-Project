#pragma once

#include "Header Files/Components/Buffer.h"

//class Shape


class Quad //public Shape //inheritance (is-A) 
{
public:
	void Update(float deltaTime);
	void Render();

private:
	Buffer buffer; //composition (has-a)
};
