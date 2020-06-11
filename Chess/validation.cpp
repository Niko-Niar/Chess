#include "validation.h"

validation::validation()
{

}

int validation::chooser(Square *temp)
{
    switch(temp->figureName)
    {
    case 'P': flag=validatePawn(temp);
              break;

    case 'R': flag=validateRook(temp);
              break;

    case 'H': flag=validateHorse(temp);
              break;

    case 'K': flag=validateKing(temp);
              break;

    case 'Q': flag=validateQueen(temp);
              break;

    case 'B': flag=validateBishop(temp);
              break;

    }

    green();

    return flag;
}

//Пешки
int validation::validatePawn(Square *temp)
{
    int row,col;

    row=temp->row;
    col=temp->col;
    retVal=0;

    if(temp->figureColor)
    {
        if(row-1>=0 && !square[row-1][col]->figure)
        {
            exp[max++]=square[row-1][col]->squareNum;
            retVal=1;
        }

        if(row==6 && !square[5][col]->figure && !square[4][col]->figure)
        {
            exp[max++]=square[row-2][col]->squareNum;
            retVal=1;
        }

        if(row-1>=0 && col-1>=0)
        {
            if(square[row-1][col-1]->figureColor!=temp->figureColor && square[row-1][col-1]->figure)
            {
            exp[max++]=square[row-1][col-1]->squareNum;
            retVal=1;
            }
        }

        if(row-1>=0 && col+1<=7)
        {
            if(square[row-1][col+1]->figureColor!=temp->figureColor && square[row-1][col+1]->figure)
            {
                exp[max++]=square[row-1][col+1]->squareNum;
                retVal=1;
            }
        }
    }
    else
    {
        if(row+1<=7 && !square[row+1][col]->figure)
        {
            exp[max++]=square[row+1][col]->squareNum;
            retVal=1;
        }

        if(row==1 && !square[2][col]->figure && !square[3][col]->figure)
        {
            exp[max++]=square[row+2][col]->squareNum;
            retVal=1;
        }

        if(row+1<=7 && col-1>=0)
        {
            if(square[row+1][col-1]->figureColor!=temp->figureColor && square[row+1][col-1]->figure)
            {
                exp[max++]=square[row+1][col-1]->squareNum;
                retVal=1;
            }
        }

        if(row+1<=7 && col+1<=7)
        {
            if(square[row+1][col+1]->figureColor!=temp->figureColor && square[row+1][col+1]->figure)
            {
                exp[max++]=square[row+1][col+1]->squareNum;
                retVal=1;
            }
        }
    }

    return retVal;
}


//Ладьи
int validation::validateRook(Square *temp)
{
    int r,c;

    retVal=0;

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }


    return retVal;
}


//Кони
int validation::validateHorse(Square *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;

    if(r-2>=0 && c-1>=0)
    {
        if(square[r-2][c-1]->figureColor!=temp->figureColor || !square[r-2][c-1]->figure)
        {
            exp[max++]=square[r-2][c-1]->squareNum;
            retVal=1;
        }
    }

    if(r-2>=0 && c+1<=7)
    {
        if(square[r-2][c+1]->figureColor!=temp->figureColor || !square[r-2][c+1]->figure)
        {
            exp[max++]=square[r-2][c+1]->squareNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c-2>=0)
    {
        if(square[r-1][c-2]->figureColor!=temp->figureColor || !square[r-1][c-2]->figure)
        {
            exp[max++]=square[r-1][c-2]->squareNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c+2<=7)
    {
        if(square[r-1][c+2]->figureColor!=temp->figureColor || !square[r-1][c+2]->figure)
        {
            exp[max++]=square[r-1][c+2]->squareNum;
            retVal=1;
        }
    }

    if(r+2<=7 && c+1<=7)
    {
        if(square[r+2][c+1]->figureColor!=temp->figureColor || !square[r+2][c+1]->figure)
        {
            exp[max++]=square[r+2][c+1]->squareNum;
            retVal=1;
        }
    }

    if(r+2<=7 && c-1>=0)
    {
        if(square[r+2][c-1]->figureColor!=temp->figureColor || !square[r+2][c-1]->figure)
        {
            exp[max++]=square[r+2][c-1]->squareNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c-2>=0)
    {
        if(square[r+1][c-2]->figureColor!=temp->figureColor || !square[r+1][c-2]->figure)
        {
            exp[max++]=square[r+1][c-2]->squareNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c+2<=7)
    {
        if(square[r+1][c+2]->figureColor!=temp->figureColor || !square[r+1][c+2]->figure)
        {
            exp[max++]=square[r+1][c+2]->squareNum;
            retVal=1;
        }
    }

    return retVal;
}


//Короли
int validation::validateKing(Square *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;

    if(r-1>=0)
    {
        if(!square[r-1][c]->figure || square[r-1][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r-1][c]->squareNum;
            retVal=1;
        }
    }

    if(r+1<=7)
    {
        if(!square[r+1][c]->figure || square[r+1][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r+1][c]->squareNum;
            retVal=1;
        }
    }

    if(c-1>=0)
    {
        if(!square[r][c-1]->figure || square[r][c-1]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c-1]->squareNum;
            retVal=1;
        }
    }

    if(c+1<=7)
    {
        if(!square[r][c+1]->figure || square[r][c+1]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c+1]->squareNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c-1>=0)
    {
        if(!square[r-1][c-1]->figure || square[r-1][c-1]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r-1][c-1]->squareNum;
            retVal=1;
        }
    }

    if(r-1>=0 && c+1<=7)
    {
        if(!square[r-1][c+1]->figure || square[r-1][c+1]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r-1][c+1]->squareNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c-1>=0)
    {
        if(!square[r+1][c-1]->figure || square[r+1][c-1]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r+1][c-1]->squareNum;
            retVal=1;
        }
    }

    if(r+1<=7 && c+1<=7)
    {
        if(!square[r+1][c+1]->figure || square[r+1][c+1]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r+1][c+1]->squareNum;
            retVal=1;
        }
    }

    return retVal;
}


//Ферзи
int validation::validateQueen(Square *temp)
{
    int r,c;

    retVal=0;

    r=temp->row;
    c=temp->col;
    while(r-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(c-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }


    return retVal;
}

//Слоны
int validation::validateBishop(Square *temp)
{
    int r,c;
    retVal=0;

    r=temp->row;
    c=temp->col;
    while(r-->0 && c++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r-->0 && c-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c++<7)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    r=temp->row;
    c=temp->col;
    while(r++<7 && c-->0)
    {
        if(!square[r][c]->figure)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
        }

        else if(square[r][c]->figureColor==temp->figureColor)
            break;

        else if(square[r][c]->figureColor!=temp->figureColor)
        {
            exp[max++]=square[r][c]->squareNum;
            retVal=1;
            break;
        }
    }

    return retVal;
}
 int validation::check(Square *temp)
{
    retVal=0;

    return retVal;
}
void validation::green()
{
    int i;

    for(i=0;i<max;i++)
        square[exp[i]/8][exp[i]%8]->setStyleSheet("QLabel {background-color: green;}");
}
