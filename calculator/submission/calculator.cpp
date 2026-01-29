#include "calculator.h"

void Calculator::Set(Number value)
{
    number_ = value;
}

void Calculator::Add(Number value)
{
    number_ += value;
}

void Calculator::Sub(Number value)
{
    number_ -= value;
}

void Calculator::Mul(Number value)
{
    number_ *= value;
}

void Calculator::Div(Number value)
{
    number_ /= value;
}

void Calculator::Pow(Number value)
{
    number_ = std::pow(number_, value);
}

Number Calculator::GetNumber() const
{
    return number_;
}
