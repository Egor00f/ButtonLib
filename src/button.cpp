#include "button.hpp"

ButtonLib::Button::Button(uint8_t PIN)
{
    _pin = PIN;
    pinMode(_pin, INPUT);
}

void ButtonLib::Button::SetPin(uint8_t pin)
{
    _pin = pin;
    pinMode(_pin, INPUT);
}

uint8_t ButtonLib::Button::GetPin()
{
    return _pin;
}

bool ButtonLib::Button::click()
{
    return digitalRead(_pin);
}

