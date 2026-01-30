#pragma once

#include <cmath>

using Number = double;

class Calculator {
public:
    Calculator() = default;

    void Set(Number value);
    void Add(Number value);
    void Sub(Number value);
    void Mul(Number value);
    void Div(Number value);
    void Pow(Number value);

    Number GetNumber() const;

private:
    Number number_ = 0.0;
};
