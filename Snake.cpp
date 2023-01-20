#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>

#define MAXSNKSIZE 100

using  namespace std;

/* A function that allows you to move the cursor to a specific position*/
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

/**
 * It sets the cursor position to the x and y coordinates you specify.
 * @param x The x coordinate of the cursor.
 * @param y The y coordinate of the cursor.
 **/
void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
}

/* It's a class that represents a point in a 2D space */
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
        void TurnUp(){
            y++;
        }
        void TurnDown(){
            y--;
        }
        void TurnLeft(){
            x--;
        }
        void TurnRight(){
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
        void CopyPos(Point * p){
            p->x=x;
            p->y=y;
        }
        void Debug(){
            cout<<"("<<x<<","<<y<<")";
        }
};

/* It's a class that represents a snake */
class Snake{
    private:
        Point * cell[MAXSNKSIZE];//Array que representa a la serpiente
        int size;//Tamano actual de la serpiente
        int dir;//Dirección actual de la serpiente
        Point fruit;
    /**
     * The snake moves by making the body follow the head, and the head moves by changing the direction of the head.
     * @param x The x coordinate of the cell
     * @param y The y-coordinate of the upper-left corner of the rectangle to be filled.
     */
    public:
        Snake(){
            size=1;//Tamano por defecto
            cell[0]=new Point(20,20);//Posicion por defecto (20,20)
            for(int i=1;i<MAXSNKSIZE;i++){
                cell[i]=NULL;
            }
        }
        void AddCell(int x,int y){
            cell[size++] = new Point(x,y);
        }
        void TurnDown(){
            dir = 72;//Mover arriba (flecha)
        }
        void TurnUp(){
            dir = 80;//Mover abajo (flecha)
        }
        void TurnLeft(){
            dir = 75;//Mover izquierda (flecha)
        }
        void TurnRight(){
            dir = 77;//Mover derecha (flecha)
        }
        void Move(){
            //Limpiar la pantall
            system("cls");

            //Hacer que el cuerpo siga a la cabeza
            for(int i=size-1;i>0;i--){
                cell[i]->CopyPos(cell[i-1]);
            }

            //Cabeza de la serpiente
            switch(dir){
                case 72:
                    cell[0]->TurnDown();
                    break;
                case 75:
                    cell[0]->TurnLeft();
                    break;
                case 77:
                    cell[0]->TurnRight();
                    break;
                case 80:
                    cell[0]->TurnUp();
                    break;
            }

            //Dibujar la serpiente
            for(int i=0;i<size;i++)
                cell[i]->Draw();
            Sleep(200);
        }
};

int main(){
    //Probamos la serpiente
    Snake snake;
    char op='l';
    do{
        if(kbhit())
            op=getch();
        switch(op){
            case 72:
                snake.TurnDown();
                break;
            case 75:
                snake.TurnLeft();
                break;
            case 77:
                snake.TurnRight();
                break;
            case 80:
                snake.TurnUp();
                break;
        }
        snake.Move();
    }while(op!='e');

    return 0;
}