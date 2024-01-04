#ifndef __BUTTON_MATRIX_HPP__
#define __BUTTON_MATRIX_HPP__


/// @brief Класс для работы с матрицой кнопок
class ButtonMatrix
{
private:
	/// @brief ссылка на массив пинов использемых как входы
	uint8_t *_inputPins;
	/// @brief ссылка на массив пинов использемых как выходы
	uint8_t *_outputPins;
public:
	/// @brief
	/// @param inputPins массив пинов
	/// @param outputPins массив пинов
	ButtonMatrix(uint8_t *inputPins, uint8_t *outputPins);
	~ButtonMatrix();

	unsigned GetSizeX();
	unsigned GetSizeY();

	/// @brief проверить какая кнопка в марице нажата
	/// @return порядковый номер кнопки(от 1 до sizeof(unsigned)), 0 если ниодна кнопка не нажата
	unsigned check();
};

ButtonMatrix::ButtonMatrix(uint8_t* inputPins, uint8_t* outputPins)
{
	unsigned i = 0;
	while (inputPins[i] != 0)
	{
		_inputPins[i] = inputPins[i];
		i++;
	}
	_inputPins[i] = 0;

	i = 0;
	while (outputPins[i] != 0)
	{
		_oututPins[i] = outputPins[i];
		i++;
	}
	_outputPins[i] = 0;


	i = 0;
	while (inputPins[i] != 0)
	{
		pinMode(_inputPins[i], INPUT);
		i++;
	}

	i = 0;
	while (outputPins[i] != 0)
	{
		pinMode(_outputPins[i], OUTPUT);
		i++;
	}
}

ButtonMatrix::~ButtonMatrix()
{
	
}

unsigned ButtonMatrix::GetSizeY()
{
	unsigned i = 0;
	while (_inputPins[i] != 0)
	{
		i++;
	}
	return i;
}

unsigned ButtonMatrix::GetSizeX()
{
	unsigned i = 0;
	while (_outputPins[i] != 0)
	{
		i++;
	}
	return i;
}

unsigned ButtonMatrix::check()
{
	for(unsigned i = 0; i < GetSizeX(); i++)
	{
		digitalWrite(_outputPins[i], HIGHT);
		for(unsigned j = 0; j < GetSizeY(); j++)
		{
			if(digitalRead(_inputPins[j]))
			{
				return (GetSizeX() * j) + i + 1;
			}
		}
		digitalWrite(_outputPins[i], LOW);
	}
	return 0;								//Если ниодна кнопка не была нажата
}

#endif