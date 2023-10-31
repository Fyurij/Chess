#include <iostream>
#include "King.h"

void King::Move(int i_, int j_)
{
    i = i_;
    j = j_;
}

bool King::FigureCheck(int x, int y)
{
    bool check = true;
    if (std::max(abs(x - i), abs(y - j)) > 1 && (abs(x - i) != 0 || abs(y - j) != 0))
    {
        check = false;
    }
    return check;
}

std::string King::GetSymbol(int x, int y)
{
    return " K";
}

void Queen::Move(int i_, int j_)
{
    i = i_;
    j = j_;
}

bool Queen::FigureCheck(int x, int y)
{
    bool check = true;
    if (x != i && y != j)
    {
        check = false;
    }
    return check;
}

std::string Queen::GetSymbol(int x, int y)
{
    return " Q";
}