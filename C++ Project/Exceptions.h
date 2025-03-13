//
// Created by User on 5/24/2024.
//

#ifndef LAB9_10_EXCEPTIONS_H
#define LAB9_10_EXCEPTIONS_H
#include <stdexcept>
using namespace std;
class InvalidNumberException : public invalid_argument{
    private:
        char* prompt;
    public:
        InvalidNumberException(char* msg):
                invalid_argument(msg), prompt(msg){
        }
        char* what(){
            return prompt;
        }
};

class InvalidCodeException : public invalid_argument{
    private:
        char* prompt;
    public:
        InvalidCodeException(char* msg):
                invalid_argument(msg), prompt(msg){
        }
        char* what(){
            return prompt;
        }

};

class InvalidMoneyValueException : public invalid_argument{
    private:
        char* prompt;
    public:
        InvalidMoneyValueException(char* msg):
                invalid_argument(msg), prompt(msg){
        }
        char* what(){
            return prompt;
        }
};

class InvalidPositionException : public invalid_argument{
    private:
        char* prompt;
    public:
        InvalidPositionException(char* msg):
                invalid_argument(msg), prompt(msg){
        }
        char* what(){
            return prompt;
        }
};
#endif //LAB9_10_EXCEPTIONS_H
