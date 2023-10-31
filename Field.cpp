#include <iostream>
#include <vector>
#include <exception>
#include "Field.h"
#include "King.h"

enum Player
{
    First,
    Second
};

bool Field::ComputerTurn(int& i, int& j)
{
    bool check = false;
    if (figure->getI() % 2 == 0)
    {
        i = figure->getI() + 1;
    }
    else
    {
        i = figure->getI() - 1;
    }
    for (int k = -1; k < 2; k++)
    {
        if (figure->getJ() + k < 0)
        {
            continue;
        }
        if (!field[i][figure->getJ() + k] && OutOfOrderCheck(i, figure->getJ() + k) && TurnCheck(i, j))
        {
            j = figure->getJ() + k;
            //i = position[0] - 'A';
            //j = 7 - (position[1] - '1');  j = 7 - (x - 1)
            std::string pos;
            pos.push_back(i + 'A');
            pos.push_back(7 - j + '1');
            std::cout << "Computer turn: " << pos << std::endl;
            check = true;
            break;
        }
    }
    return check;
}

bool Field::TurnCheck(int i, int j)
{
    return !field[j][i];
}

bool Field::OutOfOrderCheck(int i, int j)
{
    bool check = true;
    if (i < 0 || i > 8 || j < 0 || j > 8)
    {
        check = false;
    }
    return check;
}

void Field::Print()
{
    std::cout << "  A B C D E F G H   " << std::endl;
    for (int i = 0; i < field.size(); i++)
    {
        std::cout << 8 - i;
        for (int j = 0; j < field.size(); j++)
        {

        }
        std::cout << " " << 8 - i << std::endl;
    }
    std::cout << "  A B C D E F G H   " << std::endl;
}

void Field::Run()
{
    Player player = First;
    while (true)
    {
        switch (player)
        {
        case First:
            std::cout << "First player turn. Enter starting koordiantes: ";
            player = Second;
            break;
        case Second:
            std::cout << "Second player turn. Enter starting koordiantes: ";
            player = First;
            break;
        }
        int i = -1;
        int j = -1;
        Transformation(i, j);
        bool check = OutOfOrderCheck(i, j);
        if (!check)
        {
            throw std::out_of_range("Out of border");
        }
        check = figure->FigureCheck(i, j);
        if (!check)
        {
            throw std::invalid_argument("Figure can't go there");
        }
        check = TurnCheck(i, j);
        if (!check)
        {
            throw std::invalid_argument("error");
        }
        Turn(i, j);
    }
}

void Field::Turn(int i, int j)
{
    figure->Move(i, j);
    Print();
    //field[j][i] = true;
}

void Transformation(int& i, int& j)
{
    std::string position;
    while (i == -1 || j == -1)
    {
        std::cin >> position;
        while (position.size() != 2)
        {
            std::cout << "Incorrect argument. Example:D4" << std::endl;
            std::cout << "Try again: ";
            std::cin >> position;
        }
        if (position[0] >= 'A' && position[0] <= 'H')
        {
            i = position[0] - 'A';
        }
        else
        {
            std::cout << "Incorrect first position (A-H) " << std::endl;
            std::cout << "Try again: ";
            continue;
        }
        if (position[1] >= '1' && position[1] <= '8')
        {
            j = 7 - (position[1] - '1');
        }
        else
        {
            std::cout << "Incorrect second position (1-8) " << std::endl;
            std::cout << "Try again: ";
        }
    }
}