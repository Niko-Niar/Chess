#ifndef TILE_H
#define TILE_H
#include <QLabel>

class Square: public QLabel
{
public:

    //Fields
    int squareColor,figure,figureColor,row,col,squareNum;
    char figureName;

    //Constructors
    Square(QWidget* pParent=0, Qt::WindowFlags f=0) : QLabel(pParent, f) {};
    Square(const QString& text, QWidget* pParent = 0, Qt::WindowFlags f = 0) : QLabel(text, pParent, f){};

    //Methods
    void mousePressEvent(QMouseEvent *event);
    void display(char elem);
    void squareDisplay();
};

#endif // TILE_H
