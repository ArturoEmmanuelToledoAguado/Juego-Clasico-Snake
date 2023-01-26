#include <iostream>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <time.h>

#define MAXSNKSIZE 100
#define VentanaX 119
#define VentanaY 30

using  namespace std;

/*Función que permite desplazar el cursor a una posición determinada.*/
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

/**
 * Establece la posición del cursor en las coordenadas x e y que especifiques.
 * @param x La coordenada x del cursor.
 * @param y La coordenada y del cursor.
 **/
void gotoxy(int x, int y){
    CursorPosition.X = x;
    CursorPosition.Y = y;
    SetConsoleCursorPosition(console,CursorPosition);
}

/* Es una clase que representa un punto en un espacio 2D */
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
            if(y>VentanaY)
                y=0;
        }
        void TurnDown(){
            y--;
            if(y<0)
                y=VentanaY;
        }
        void TurnLeft(){
            x--;
            if(x<0)
                x=VentanaX;
        }
        void TurnRight(){
            x++;
            if(x>VentanaX)
                x=0;
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

/* Es una clase que representa una serpiente */
class Snake{
    private:
        Point * cell[MAXSNKSIZE];//Array que representa a la serpiente
        int size;//Tamano actual de la serpiente
        int dir;//Dirección actual de la serpiente
        Point fruit;
    /**
     * La serpiente se mueve haciendo que el cuerpo siga a la cabeza, y la cabeza se mueve cambiando la dirección de la cabeza.
     * @param x La coordenada x de la celda
     * @param y La coordenada y de la esquina superior izquierda del rectángulo a rellenar.
     */
    public:
        Snake(){
            size=1;//Tamano por defecto
            cell[0]=new Point(20,20);//Posicion por defecto (20,20)
            for(int i=1;i<MAXSNKSIZE;i++){
                cell[i]=NULL;
            }
            fruit.SetPoint(rand()%VentanaX, rand()%VentanaY);
        }
        void AddCell(int x,int y){
            cell[size++] = new Point(x,y);
        }
        void TurnDown(){
            if(dir!=80)
            dir = 72;//Mover arriba (flecha)
        }
        void TurnUp(){
            if(dir!=72)
            dir = 80;//Mover abajo (flecha)
        }
        void TurnLeft(){
            if(dir!=77)
            dir = 75;//Mover izquierda (flecha)
        }
        void TurnRight(){
            if(dir!=75)
            dir = 77;//Mover derecha (flecha)
        }
        void Move(){
            //Limpiar la pantall
            system("cls");

            //Hacer que el cuerpo siga a la cabeza
            for(int i=size-1;i>0;i--){
                cell[i-1]->CopyPos(cell[i]);
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

            //Comer fruta
            if(fruit.GetX()==cell[0]->GetX() && fruit.GetY()==cell[0]->GetY()){
                AddCell(0,0);
                fruit.SetPoint(rand()%VentanaX, rand()%VentanaY);
            }

            //Dibujar la serpiente
            for(int i=0;i<size;i++)
                cell[i]->Draw();
            fruit.Draw();

            //Debug();

            Sleep(100);
        }
        void Debug(){
            for(int i=0; i<size;i++){
                cell[i]->Debug();
            }
        }
};

int main(){
    //Generación no random
    srand((unsigned)time(NULL));

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