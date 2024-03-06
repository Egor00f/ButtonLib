#ifndef BUTTON_HPP
#define BUTTON_HPP 

//"Поддержка" для raspberry pi pico sdk
#ifdef _PICO_H

#include "pico/stdlib.h"

#else

#include <Arduino.h>

#endif



namespace ButtonLib
{
	/// @brief Класс для удобной работы с кнопками
	/// @class Кнопка
	class Button
	{
	private:
		#ifdef _PICO_H
		unsigned _pin; // пин кнопки
		#else
		uint8_t _pin;
		#endif

	public:
		#ifdef _PICO_H
		// Конструктор
		Button(unsigned PIN);
		#else
		// Конструктор
		Button(uint8_t PIN);
		#endif
		

		void SetPin(uint8_t pin)
		{
			_pin = pin;
			#ifdef _PICO_H
			gpio_set_dir(_pin);
			#else
			pinMode(_pin, INPUT);
			#endif
		}

		/// @brief Получить пин
		uint8_t GetPin();

		// проверяет нажата ли кнопка
		bool click();
	};

	uint8_t Button::GetPin()
	{
		return _pin;
	}

	bool Button::click()
	{
		#ifdef _PICO_H
		bool clk = gpio_get(_pin);
		#else
		bool clk = digitalRead(_pin);
		#endif
		return clk;
	}

	Button::Button(uint8_t PIN)
	{
		_pin = PIN;
		#ifdef _PICO_H
		gpio_init(_pin);
		gpio_set_dir(_pin, GPIO_IN);
		#else
		pinMode(_pin, INPUT);
		#endif
	}
}



#endif
