#include <iostream>
#include <cmath>

int main()
{
    char figure = 0;
    do
    {
        std::cout << "What figure walks?" << std::endl;
        std::cin >> figure;
    }
    while ((figure != 'p') && (figure != 'N') &&
            (figure != 'Q') && (figure != 'R') && (figure != 'B'));
    std::pair<char, int> movablefFigure;
    std::pair<char, int> staticfFigure;
    staticfFigure.first = 'd';
    staticfFigure.second = 5;
    do
    {
        std::cout << "Initial coordinate?" << std::endl;
        std::cin >> movablefFigure.first >> movablefFigure.second;
    }
    while (((movablefFigure.second > 8) ||
            ((movablefFigure.first != 'a') && (movablefFigure.first != 'b') &&
                    (movablefFigure.first != 'c') && (movablefFigure.first != 'd') &&
                    (movablefFigure.first != 'e') && (movablefFigure.first != 'f') &&
             (movablefFigure.first != 'h'))) || ((movablefFigure.first == staticfFigure.first)
                                                 && (movablefFigure.second == staticfFigure.second)));
    std::pair<char, int> nextCell;
    do
    {
        std::cout << "Next coordinate?" << std::endl;
        std::cin >> nextCell.first >> nextCell.second;
    }
    while ((movablefFigure.second > 8) || ((movablefFigure.first != 'a') &&
            (movablefFigure.first != 'b') && (movablefFigure.first != 'c') &&
            (movablefFigure.first != 'd') && (movablefFigure.first != 'e') &&
            (movablefFigure.first != 'f') && (movablefFigure.first != 'h')));
    std::cout << "Answer: " << std::endl;
    if (figure == 'p')
    {
        if (((nextCell.first == movablefFigure.first) &&
                (nextCell.second - 1 == movablefFigure.second)) &&
            ((nextCell.first != staticfFigure.first) &&
                    (nextCell.second != staticfFigure.second)))
        {
            std::cout << "True" << std::endl;
            if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                && (std::abs(staticfFigure.second - nextCell.second) <= 1))
            {
                std::cout << "Your figure will be eaten" << std::endl;
            }
        }
        else if ((movablefFigure.second == 2) &&
                (nextCell.second - 2 == movablefFigure.second) &&
                   (nextCell.first == movablefFigure.second))
        {
            std::cout << "True" << std::endl;
            if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                && (std::abs(staticfFigure.second - nextCell.second) <= 1))
            {
                std::cout << "Your figure will be eaten" << std::endl;
            }
        }
        else if ((std::abs(movablefFigure.first - 'd') == 1) &&
                (movablefFigure.second == 4)
                   && ((nextCell.first == staticfFigure.first) &&
                (nextCell.second == staticfFigure.second)))
        {
            std::cout << "True" << std::endl;
            if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                && (std::abs(staticfFigure.second - nextCell.second) <= 1))
            {
                std::cout << "Your figure will be eaten" << std::endl;
            }
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
    if (figure == 'R')
    {
        if ((nextCell.first == movablefFigure.first) ||
                (nextCell.second == movablefFigure.second))
        {
            if ((std::abs(movablefFigure.first - nextCell.first) >
                    std::abs(movablefFigure.first - staticfFigure.first)) ||
                (std::abs(movablefFigure.second - nextCell.second) >
                        std::abs(movablefFigure.second - staticfFigure.second)))
            {
                std::cout << "False" << std::endl;
            }
            else
            {
                std::cout << "True" << std::endl;
                if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                    && (std::abs(staticfFigure.second - nextCell.second) <= 1))
                {
                    std::cout << "Your figure will be eaten" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
    if (figure == 'B')
    {
        if (std::abs(movablefFigure.first - movablefFigure.first) ==
                std::abs(nextCell.second - movablefFigure.second))
        {
            if ((std::abs(nextCell.first - staticfFigure.first) ==
                    std::abs(nextCell.second - staticfFigure.second)) &&
                    ((std::abs(movablefFigure.first - staticfFigure.first) ==
                            std::abs(movablefFigure.second - staticfFigure.second))))
            {
                if ((std::abs(movablefFigure.first - nextCell.first) >
                        std::abs(movablefFigure.first - staticfFigure.first)) ||
                    (std::abs(movablefFigure.second - nextCell.second) >
                            std::abs(movablefFigure.second - staticfFigure.second)))
                {
                    std::cout << "False" << std::endl;
                }
                else
                {
                    std::cout << "True" << std::endl;
                    if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                        && (std::abs(staticfFigure.second - nextCell.second) <= 1))
                    {
                        std::cout << "Your figure will be eaten" << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "True" << std::endl;
                if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                    && (std::abs(staticfFigure.second - nextCell.second) <= 1))
                {
                    std::cout << "Your figure will be eaten" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
    if (figure == 'Q')
    {
        if ((nextCell.first == movablefFigure.first) ||
                (nextCell.second == movablefFigure.second) &&
                (std::abs(movablefFigure.first - movablefFigure.first) ==
                        std::abs(nextCell.second - movablefFigure.second)))
        {
            if ((std::abs(nextCell.first - staticfFigure.first) ==
                    std::abs(nextCell.second - staticfFigure.second)) &&
                    ((std::abs(movablefFigure.first - staticfFigure.first) ==
                            std::abs(movablefFigure.second - staticfFigure.second))))
            {
                if ((std::abs(movablefFigure.first - nextCell.first) >
                        std::abs(movablefFigure.first - staticfFigure.first)) ||
                    (std::abs(movablefFigure.second - nextCell.second) >
                            std::abs(movablefFigure.second - staticfFigure.second)))
                {
                    std::cout << "False" << std::endl;
                }
                else
                {
                    std::cout << "True" << std::endl;
                    if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                        && (std::abs(staticfFigure.second - nextCell.second) <= 1))
                    {
                        std::cout << "Your figure will be eaten" << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "True" << std::endl;
                if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                    && (std::abs(staticfFigure.second - nextCell.second) <= 1))
                {
                    std::cout << "Your figure will be eaten" << std::endl;
                }
            }
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
    if (figure == 'N')
    {
        if (((std::abs(movablefFigure.first - nextCell.first) == 1) &&
                (std::abs(movablefFigure.second - nextCell.second) == 2)) ||
                ((std::abs(movablefFigure.first - nextCell.first) == 2) &&
                        (std::abs(movablefFigure.second - nextCell.second) == 1)))
        {
            std::cout << "True" << std::endl;
            if ((std::abs(staticfFigure.first - nextCell.first) <= 1)
                && (std::abs(staticfFigure.second - nextCell.second) <= 1))
            {
                std::cout << "Your figure will be eaten" << std::endl;
            }
        }
        else
        {
            std::cout << "False" << std::endl;
        }
    }
    return 0;
}
