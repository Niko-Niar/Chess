#ifndef VALIDATION_H
#define VALIDATION_H
#include "square.h"

extern Square *square[8][8];
extern int exp[60],max,wR,wC;

class validation
{
    int flag,retVal;

public:
    validation();
    int chooser(Square *temp);
    int validateBishop(Square *temp);
    int validateQueen(Square *temp);
    int validateKing(Square *temp);
    int validateHorse(Square *temp);
    int validateRook(Square *temp);
    int validatePawn(Square *temp);
    void green();
    int check(Square *temp);
};

#endif // VALIDATION_H
