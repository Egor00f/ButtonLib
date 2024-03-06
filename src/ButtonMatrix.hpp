#ifndef __BUTTON_MATRIX_HPP__
#define __BUTTON_MATRIX_HPP__

#include <Arduino.h>

/// @brief Класс для работы с матрицой кнопок
/// @brief Матриуа кнопок
class ButtonMatrix
{
private:
	/// @brief указатель на массив пинов использемых как входы
	uint8_t *_xPins;

	/// @brief указатель на массив пинов использемых как выходы
	uint8_t *_yPins;
	
	/// @brief Размеры по осям x и y
	uint8_t _x, _y;

public:

	/// @brief Конструктор
	/// @tparam X размер массива @link _xPins
	/// @tparam Y размер массива @link _yPins
	/// @param xPins массив пинов
	/// @param yPins массив пинов
	template <uint8_t X, uint8_t Y>
	ButtonMatrix(uint8_t (&xPins)[X], uint8_t (&yPins)[Y]);

	/// @brief Деструктор
	~ButtonMatrix();

	/// @brief Получить размер матрицы по x
	/// @return 
	uint8_t GetSizeX();

	/// @brief Получить размер матрицы по y
	/// @return 
	uint8_t GetSizeY();

	/// @brief проверить какая кнопка в марице нажата
	/// @return порядковый номер кнопки, -1 если ниодна кнопка не нажата
	int8_t check();
};


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

int8_t ButtonMatrix::check()
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

#endif

template <uint8_t X, uint8_t Y>
ButtonMatrix::ButtonMatrix(uint8_t (&xPins)[X], uint8_t (&yPins)[Y])
{
	_xPins = (uint8_t)malloc(x);
	_yPins = (uint8_t)malloc(y);

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
