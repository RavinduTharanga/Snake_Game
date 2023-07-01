#include <iostream>
#include <ncurses.h>


// #include <conio.h>
// #include <windows.h>

using namespace std;

bool gameOver;
const int height =20;
const int width =20;

int x,y,fruitX,fruitY,score;
enum eDirection {STOP=0,UP,DOWN,LEFT,RIGHT};
eDirection dir;


void Setup(){

    gameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX=rand()%width;
    fruitY =rand()%height;
}
void Draw(){

    system("CLS");
    for(int i =0;i < width;i++){

        cout<<"#";
    }cout<<endl;
    for(int i=0;i< height;i++){

        for(int j=0;j<width;j++){

            if(j==0 || j==width-1){
                cout<<"#";
            }
            else if(i==y && j==x){
                cout<<"o";
            }
            else if(i==fruitY && j==fruitX){
                cout<<"F";
            }
            
            else{
                cout<<" ";
            }


        }cout<<endl;
        
    }

    for(int i =0;i < width;i++){

        cout<<"#";
    }cout<<endl;
    
}
int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}

void Input(){

    if(kbhit()){

        switch (getch())
        {
        case 'w':
            dir =UP;
            break;
        case 'a':
            dir =LEFT;
            break;
        case 's':
            dir =DOWN;
            break;
        case 'd':
            dir =RIGHT;
            break;
        
        default:
            break;
        }
    }
}

void Logic(){

    switch (dir)
    {
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    default:
        break;
    }
}



int main(){

    Setup();
    
        Draw();
        Input();
        Logic();
    
    return 0;
}


