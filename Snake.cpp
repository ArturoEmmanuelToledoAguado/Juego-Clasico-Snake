#include <iostream>
#include <conio.h>
#include <windows.h>

using  namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
}

class Point{
    private:
        int x,y;
    public:
        Point(){
            x=y=10;
        }
        Point(int x,int y){
            this->x=x;
            this->y=y;
        }
        void SetPoint(int x,int y){
            this->x=x;
            this->y=y;
        }
        int GetX(){
            return x;
        }
        int GetY(){
            return y;
        }
        void MUp(){
            y--;
        }
        void MDown(){
            y++;
        }
        void MLeft(){
            x--;
        }
        void MRight(){
            x++;
        }
        void Draw(){
            gotoxy(x,y);
            cout<<"*";
        }
        void Borrar(){
            gotoxy(x,y);
            cout<<" ";
        }
        void Debug(){
            cout<<"("<<x<<","<<y<<")";
        }
};

int main(){
    Point p(5,20);
    p.Draw();

    return 0;
}