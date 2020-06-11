#include "square.h"
#include "validation.h"

validation *valid = new validation();

extern int count,turn;
extern QWidget *myWidget;
extern Square *click;
extern Square *square[8][8];

void validate(Square *temp,int c);
void disGreen();

void Square::mousePressEvent(QMouseEvent *event)
{
    validate(this,++count);
}

void Square::display(char elem)
{
    this->figureName=elem;

    if(this->figureColor && this->figure)
    {
        switch(elem) //Извлекаем текстуры фигур и для удобства называем по первой букве
        {
            case 'P': this->setPixmap(QPixmap(":/Images/pawn_white.svg"));
                      break;
            case 'R': this->setPixmap(QPixmap(":/Images/rook_white.svg"));
                      break;
            case 'H': this->setPixmap(QPixmap(":/Images/knight_white.svg"));
                      break;
            case 'K': this->setPixmap(QPixmap(":/Images/king_white.svg"));
                      break;
            case 'Q': this->setPixmap(QPixmap(":/Images/queen_white.svg"));
                      break;
            case 'B': this->setPixmap(QPixmap(":/Images/bishop_white.svg"));
                      break;
        }
    }

    else if(this->figure)
    {
        switch(elem)
        {
        case 'P': this->setPixmap(QPixmap(":/Images/pawn_black.svg"));
                  break;
        case 'R': this->setPixmap(QPixmap(":/Images/rook_black.svg"));
                  break;
        case 'H': this->setPixmap(QPixmap(":/Images/knight_black.svg"));
                  break;
        case 'K': this->setPixmap(QPixmap(":/Images/king_black.svg"));
                  break;
        case 'Q': this->setPixmap(QPixmap(":/Images/queen_black.svg"));
                  break;
        case 'B': this->setPixmap(QPixmap(":/Images/bishop_black.svg"));
                  break;
        }
    }
    else
        this->clear();
}

void validate(Square *temp, int c)
{
    int retValue,i;

    if(c==1)
    {
        if(temp->figure && (temp->figureColor==turn))
        {
            exp[max++]=temp->squareNum;
            retValue=valid->chooser(temp);

            if(retValue)
            {
                click= new Square();
                temp->setStyleSheet("QLabel {background-color: rgb(176, 48, 96);}");
                click=temp;
            }
            else
            {
                temp->setStyleSheet("QLabel {background-color: red;}");
                click=temp;
            }
        }
        else
        {
            count=0;
        }
    }

    else
    {

        if(temp->squareNum==click->squareNum)
        {
            click->squareDisplay();
            disGreen();
            max=0;
            count=0;
        }

        for(i=0;i<max;i++)
        {            
            if(temp->squareNum==exp[i])
            {
                click->figure=0;
                temp->figure=1;

                temp->figureColor=click->figureColor;
                temp->figureName=click->figureName;

                click->display(click->figureName);
                temp->display(click->figureName);

                click->squareDisplay();
                temp->squareDisplay();

                retValue=valid->check(click);

                if(retValue)
                {
                    square[wR][wC]->setStyleSheet("QLabel {background-color: red;}");
                }


                disGreen();

                max=0;

                turn=(turn+1)%2;
                count=0;
            }

            else
                count=1;
        }
    }
}

void Square::squareDisplay()
{

    if(this->squareColor)
        this->setStyleSheet("QLabel {background-color: rgb(238, 221, 130);}:hover{background-color: rgb(176, 48, 96);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(184, 134, 11);}:hover{background-color: rgb(176, 48, 96);}");
}

void disGreen()
{
    int i;

    for(i=0;i<max;i++)
        square[exp[i]/8][exp[i]%8]->squareDisplay();

}
