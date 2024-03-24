#ifndef BUTTON_HPP
#define BUTTON_HPP 

#include <Arduino.h>

/// @brief Пространство имён библиотеки ButtonLib
/// @author Egor00f
namespace ButtonLib
{
	/// @brief Класс для удобной работы с кнопками
	class Button
	{
	private:
		
		/// @brief Пин
		uint8_t _pin;


	public:
		/// @brief Конструктор
		/// @param PIN
		Button(uint8_t PIN);

		/// @brief Сменить пин кнопки
		/// @param pin 
		void SetPin(uint8_t pin);
		

		/// @brief Получить пин
		/// @return значение _pin
		uint8_t GetPin();

		/// @brief Проверить нажата ли кнопка
		/// @return true если кнопка нажата
		/// @return false если кнопка не нажата
		bool click();
	};
}



#endif
