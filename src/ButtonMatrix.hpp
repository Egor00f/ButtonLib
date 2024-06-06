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
		ButtonMatrix(const uint8_t *xPins, const uint8_t *yPins, const uint8_t &X, const uint8_t &Y);

		/// @brief Деструктор
		~ButtonMatrix();

		/// @brief Получить размер матрицы по x
		/// @return размер массива _xPins
		const uint8_t& GetSizeX();

		/// @brief Получить размер матрицы по y
		/// @return размер массива _yPins
		const uint8_t& GetSizeY();

		/// @brief проверить какая кнопка в марице нажата
		/// @details почерёдно проверяет все пины указанные в конструкторе
		/// @return порядковый номер кнопки(слева направо, построчно вниз)
		/// @return -1 если ни одна кнопка не нажата
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