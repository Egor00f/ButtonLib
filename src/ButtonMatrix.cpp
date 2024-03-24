#include "ButtonMatrix.hpp"

using namespace ButtonLib;

ButtonMatrix::ButtonMatrix(const uint8_t * xPins, const uint8_t * yPins, uint8_t X, uint8_t Y)
{
    _xPins = (uint8_t*)malloc(X);
    _yPins = (uint8_t*)malloc(Y);

    _x = X;
    _y = Y;

    for (uint8_t i = 0; i < X; i++)
    {
        _xPins[i] = xPins[i];
    }

    for (uint8_t i = 0; i < Y; i++)
    {
        _yPins[i] = yPins[i];
    }



    for (uint8_t i = 0; i < X; i++)
    {
        pinMode(_xPins[i], INPUT);
    }

    for (uint8_t i = 0; i < Y; i++)
    {
        pinMode(_yPins[i], OUTPUT);
    }
}

ButtonMatrix::~ButtonMatrix()
{
	free(_xPins);
	free(_yPins);
}

uint8_t ButtonMatrix::GetSizeY()
{
	return _y;
}

uint8_t ButtonMatrix::GetSizeX()
{
	return _x;
}

int16_t ButtonMatrix::check()
{
	for(uint8_t i = 0; i < _x; i++)
	{
		digitalWrite(_xPins[i], HIGH);
		for(uint8_t j = 0; j < _y; j++)
		{
			if(digitalRead(_yPins[j]))
			{
				return (_x * i) + j;
			}
		}
		digitalWrite(_xPins[i], LOW);
	}
	return -1;								//Если ниодна кнопка не была нажата
}