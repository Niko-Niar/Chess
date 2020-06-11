#include <QApplication>
#include "mainwindow.h"
#include "square.h"

int count=0,turn=1,exp[60],max=0;
int wR,wC,bR,bC;
Square *click;

Square *square[8][8] = { { NULL } };

class Border
{
public:
    Border();
    void outline(QWidget *baseWidget, int xPos, int yPos, int Pos)
    {
         QLabel *outLabel = new QLabel(baseWidget);

        if(!Pos)
            outLabel->setGeometry(xPos,yPos,560,28);        //Горизонтальные рамки

        else
            outLabel->setGeometry(xPos,yPos,28,520);        //Вертикальные рамки

        outLabel->setStyleSheet("QLabel { background-color :rgb(218, 165, 32); color : black; }");
    }
};

void chessBoard(QWidget *baseWidget, Square *square[8][8])
{
    int i,j,k=0,hor,ver;
    Border *border[4]={ NULL };

    //Отображение границ
    {
    border[0]->outline(baseWidget,0,0,0);
    border[1]->outline(baseWidget,00,536,0);
    border[2]->outline(baseWidget,00,20,1);
    border[3]->outline(baseWidget,536,20,1);
    }

    //Создание всех 64 клеток
    ver=24;
    for(i=0;i<8;i++)
    {
        hor=24;
        for(j=0;j<8;j++)
        {
            square[i][j] = new Square(baseWidget);
            square[i][j]->squareColor=(i+j)%2;
            square[i][j]->figure=0;
            square[i][j]->row=i;
            square[i][j]->col=j;
            square[i][j]->squareNum=k++;
            square[i][j]->squareDisplay();
            square[i][j]->setGeometry(hor,ver,64,64);
            hor+=64;
        }
        ver+=64;
    }

    //Расстановка белых пешек
    for(j=0;j<8;j++)
    {
        square[1][j]->figure=1;
        square[1][j]->figureColor=0;
        square[1][j]->display('P');
    }

    //Расстановка чёрных пешек
    for(j=0;j<8;j++)
    {
        square[6][j]->figure=1;
        square[6][j]->figureColor=1;
        square[6][j]->display('P');
    }

    //Расстановка остальных фигур
    for(j=0;j<8;j++)
    {
        square[0][j]->figure=1;
        square[0][j]->figureColor=0;
        square[7][j]->figure=1;
        square[7][j]->figureColor=1;
    }

    {
    square[0][0]->display('R');
    square[0][1]->display('H');
    square[0][2]->display('B');
    square[0][3]->display('Q');
    square[0][4]->display('K');
    square[0][5]->display('B');
    square[0][6]->display('H');
    square[0][7]->display('R');
    }


    {
    square[7][0]->display('R');
    square[7][1]->display('H');
    square[7][2]->display('B');
    square[7][3]->display('Q');
    square[7][4]->display('K');
    square[7][5]->display('B');
    square[7][6]->display('H');
    square[7][7]->display('R');
    }

    wR=7;
    wC=4;

    bR=0;
    bC=4;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *myWidget = new QWidget();
    myWidget->setGeometry(0,0,560,560);
    myWidget->setMaximumSize(560,560);
    myWidget->setMinimumSize(560,560);

    chessBoard(myWidget,square);

    myWidget->show();
    return a.exec();
}

