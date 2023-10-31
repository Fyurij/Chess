#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <math.h>
#include "King.h"
#include "Field.h"

int main()
{
    int i = -1;
    int j = -1;
    std::cout << "Enter starting position of King: ";
    Transformation(i, j);
    Figure* king = new King(i, j);
    Field game(king/*horse*/);
    game.Print();
    try
    {
        game.Run();
    }
    catch (std::out_of_range& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch (std::invalid_argument& ex)
    {
        std::cout << ex.what() << std::endl;
    }
}