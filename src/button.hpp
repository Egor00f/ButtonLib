#ifndef BUTTON_HPP
#define BUTTON_HPP 

#ifdef _PICO_H

#include "pico/stdlib.h"

#else

#include <Arduino.h>

#endif


/*
	Класс для удобной работы с кнопками
*/
class Button
{
private:
#ifdef _PICO_H
	unsigned _pin;	//пин кнопки
#else
	uint8_t _pin;
#endif

public:
#ifdef _PICO_H
	//Конструктор
	button(unsigned PIN)
#else
	// Конструктор
	button(uint8_t PIN)
#endif
	{
		_pin = PIN;
#ifdef _PICO_H
		gpio_init(_pin);
		gpio_set_dir(_pin, GPIO_IN);
#else
		pinMode(_pin, INPUT);
#endif
		
	}

	void SetPin(unit8_t pin)
	{
		_pin = pin;
		pinMode(_pin, INPUT);
	}

	//проверяет нажата ли кнопка 
	bool click()
	{
#ifdef _PICO_H
		bool clk = gpio_get(_pin);
#else
		bool clk = digitalRead(_pin);
#endif
		
		return clk;
	}
};



#endif
