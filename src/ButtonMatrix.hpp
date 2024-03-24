#ifndef __BUTTON_MATRIX_HPP__
#define __BUTTON_MATRIX_HPP__

#include <Arduino.h>

/// @brief Пространство имён библиотеки ButtonLib
/// @author Egor00f
namespace ButtonLib
{
	/// @brief Класс для работы с матрицей кнопок
	class ButtonMatrix
	{
	public:
		/// @brief Конструктор
		/// @param xPins указатель на массив пинов
		/// @param yPins указатель на массив пинов
		/// @param X размер массива xPins
		/// @param Y размер массива yPins
		ButtonMatrix(const uint8_t *xPins, const uint8_t *yPins, uint8_t X, uint8_t Y);

		/// @brief Деструктор
		~ButtonMatrix();

		/// @brief Получить размер матрицы по x
		/// @return размер массива _xPins
		uint8_t GetSizeX();

		/// @brief Получить размер матрицы по y
		/// @return размер массива _yPins
		uint8_t GetSizeY();

		/// @brief проверить какая кнопка в марице нажата
		/// @return порядковый номер кнопки, -1 если ни одна кнопка не нажата
		int16_t check();

	private:
		/// @brief указатель на массив пинов использемых как входы
		uint8_t *_xPins;

		/// @brief указатель на массив пинов использемых как выходы
		uint8_t *_yPins;

		/// @brief Размеры по x и y
		uint8_t _x, _y;
	};
}

#endif