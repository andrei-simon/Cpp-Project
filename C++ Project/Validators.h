//
// Created by User on 5/24/2024.
//

#ifndef LAB9_10_VALIDATORS_H
#define LAB9_10_VALIDATORS_H
#include "Exceptions.h"

class CodeValidator{
private:
    char code1;
    char code2;
    char code3;
public:
    CodeValidator(char firstValue, char secondValue, char thirdValue) : code1(firstValue),
                                                                     code2(secondValue), code3(thirdValue){
    }

    void validate(char value){
        if (value != code1 && value != code2 && value != code3)
            throw InvalidCodeException("Ivalid code, the given code must be '1' , '2' or '3'!");
    }

};

class NumberValidator{
private:
    int validNo;
public:
    NumberValidator(int no) : validNo(no){
    }

    void validate(int no){
        if (no < validNo)
            throw InvalidNumberException("The given number is invalid!");
    }

};

class MoneyValidator{
private:
    string validBanknote1;
    string validBanknote2;
    string validBanknote3;
    string validBanknote4;
    string validBanknote5;
public:
    MoneyValidator(string firstValue, string secondValue, string thirdValue, string forthValue, string fifthValue) : validBanknote1(firstValue),
                                                                                                      validBanknote2(secondValue), validBanknote3(thirdValue), validBanknote4(forthValue), validBanknote5(fifthValue){
    }
    void validate(string value){
        if (value != validBanknote1 && value != validBanknote2 && value != validBanknote3 && value != validBanknote4 && value != validBanknote5)
            throw InvalidMoneyValueException("Invalid banknote value!");
    }
};

class PositionValidator{
private:
    int validPosition;
public:
    PositionValidator(int position) : validPosition(position){
    }

    void validate(int position){
        if (position > validPosition || position < 0)
            throw InvalidPositionException("The given position is invalid!");
    }
};
#endif //LAB9_10_VALIDATORS_H
