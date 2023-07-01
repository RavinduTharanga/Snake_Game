#include <iostream>
// #include <conio.h>
#include <stdio.h>
// #include <Windows.h>

using namespace std;

bool gameOver;

const int width =20;
const int height=20;

int x, y, fruitX, fruitY, score;

int tailX[100], tailY[100];
int nTail;

string fruit = "*";

enum eDirections{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirections dir;


// void Setup{

//     gameOver=false;
//     dir = STOP;
//     x = width/2;
//     y = width/2;
//     fruitX = rand()% width +1;
//     fruitY = rand()% height +1;
//     score =0;

// }
void Draw()
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
    for (int i = 1; i <= height; i++)
    {
        for (int j = 1; j <= width + 1; j++)
        {
            if (j == 1 || j == width + 1)
                std::cout << "#";
            if (i == y && j == x)
            {
                std::cout << "O";
            }
            else if (j == fruitX && i == fruitY)
            {
                std::cout << fruit;
            }
            else
            {
                bool print = false;
                for (int k = 0; k < nTail; k++)
                {
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        std::cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
    for (int i = 0; i < width + 2; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;
    std::cout << "Score: " << score << std::endl;
}

int main(){

    Draw();

    return 0;
}
