#pragma once

#include "King.h"

class Field
{
private:
    std::vector<std::vector<bool>> field;
    Figure* figure;
public:
    Field(Figure* figure_)
        :field(8, std::vector<bool>(8, false))
        , figure(figure_)
    {}
    bool ComputerTurn(int& i, int& j);
    bool TurnCheck(int i, int j);
    bool OutOfOrderCheck(int i, int j);
    void Print();
    void Run();
    void Turn(int i, int j);
};

void Transformation(int& i, int& j);