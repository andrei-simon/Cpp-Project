//
// Created by User on 5/5/2024.
//

#ifndef LAB9_10_UI_H
#define LAB9_10_UI_H
#include "Service.h"
#include "Validators.h"
#include <iostream>
#include <vector>
#include <map>
#include <cstring>
using namespace std;

class UI{
private:
    Service service;
    map<int, int> availableMoney;
    bool checkMoney() {
        int ok = 5;
        for(auto it = availableMoney.rbegin(); it != availableMoney.rend(); it++)
            if(it->second <= 0)
                ok--;
        if(ok == 0)
            return false;
        else
            return true;
    }
    map<int,int> rest(int sum) {
        map<int,int> solution;
        int c;
        for(auto it = availableMoney.rbegin(); it != availableMoney.rend(); it++){
            c = sum / it->first;
            if(c > it->second)
                c = it->second;
            if(c) {
                solution[it->first] = c;
                sum -= c * it->first;
            }
            if(sum == 0){
                for(auto it = solution.rbegin(); it != solution.rend(); it++)
                    availableMoney[it->first] -= it->second;
                return solution;
            }
        }
    }

public:
    UI(Service service) : service(service) {
        loadMoneyFromFile();
    };
    ~UI(){
        saveMoneyToFile();
        service.saveToFile();
    }

    void add();
    void remove();
    void update();
    void printAll();
    void printMenu();
    void saveMoneyToFile();
    void loadMoneyFromFile();
    void addMoney();
    void printMoney();
    void run();
};


void UI::add() {
    MoneyValidator moneyValidator("1", "5", "10", "50", "100");
    CodeValidator codeValidator('1', '2', '3');
    int code, time, price;
    char codeC;
    map<int,int> introducedMoney;
    try{
        cout << "Code x: Time-Price:\n code 1: 1h-5lei\n code 2: 2h-10lei\n code 3: 24h-100lei\n";
        cout << "Enter code: ";
        cin >> codeC;
        codeValidator.validate(codeC);
        code = codeC - '0';
        if(code == 1)
            time = 1, price = 5;
        else if(code == 2)
            time = 2, price = 10;
        else if(code == 3)
            time = 24, price = 100;
        int sum = 0;
        while(sum < price) {
            string banknoteS;
            int banknote;
            cout << "Enter bancknote: ";
            cin >> banknoteS;
            moneyValidator.validate(banknoteS);
            banknote = stoi(banknoteS);
            sum += banknote;
            introducedMoney[banknote]++;
        }
        if (sum == price) {
            for(auto it = introducedMoney.begin(); it != introducedMoney.end(); it++)
                availableMoney[it->first] += it->second;
            cout << "Transaction complete\n";
            Entity e(code, time, price);
            service.addElem(e);
        } else {
            map<int, int> restMap = rest(abs(price - sum));
            if (restMap.size() == 0)
                cout << "Not enough money\n";
            else {
                cout << "Transaction complete\n";
                Entity e(code, time, price);
                service.addElem(e);
                for(auto it = introducedMoney.begin(); it != introducedMoney.end(); it++)
                    availableMoney[it->first] += it->second;
                cout << "Rest: ";
                for (auto it = restMap.begin(); it != restMap.end(); it++)
                    cout << it->first <<" lei: " << ' ' << it->second << ' ' << endl;
                cout << endl;
            }
        }
    }
    catch(InvalidCodeException &e){
        cout << e.what() << endl;
    }
    catch(InvalidMoneyValueException &e){
        cout << e.what() << endl;
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }
    catch(...){
        cout << "Unknown exception" << endl;
    }
}

void UI::remove() {
    PositionValidator positionValidator(service.size() - 1);
    int pos;
    printAll();
    try{
        cout << "Enter a position(int): ";
        cin >> pos;
        positionValidator.validate(pos);
        service.deleteElem(pos);
    }
    catch(InvalidPositionException &e){
        cout << e.what() << endl;
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }
    catch(...){
        cout << "Unknown exception" << endl;
    }
}

void UI::update() {
    CodeValidator codeValidator('1', '2', '3');
    PositionValidator positionValidator(service.size() - 1);
    int pos, code, time, price;
    char codeC;
    try {
        printAll();
        cout << "Enter a position: ";
        cin >> pos;
        positionValidator.validate(pos);
        cout << "Code x: Time-Price:\n code 1: 1h-5lei\n code 2: 2h-10lei\n code 3: 24h-100lei\n";
        cout << "Enter code: ";
        cin >> codeC;
        code = codeC - '0';
        codeValidator.validate(codeC);
        if (code == 1)
            time = 1, price = 5;
        else if (code == 2)
            time = 2, price = 10;
        else if (code == 3)
            time = 24, price = 100;
        Entity e(code, time, price);
        service.updateElem(pos, e);
    }
    catch (InvalidPositionException &e) {
        cout << e.what() << endl;
    }
    catch (InvalidCodeException &e) {
        cout << e.what() << endl;
    }
    catch (invalid_argument &e) {
        cout << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown exception" << endl;
    }
}


void UI::printAll() {
    int i = 0;
    for(Entity e : service.getAll())
        cout << "pos " << i++ << ' ' << e << endl;
}

void UI::printMenu() {
    cout << "1. Add\n2. Remove\n3. Update\n4. Print all\n5. Add Money\n6. Print Money\nx. Exit\n";
}

void UI::run() {
    bool run = true;
    char option;
    while(run && checkMoney()) {
        printMenu();
        cin >> option;
        switch(option) {
            case '1':
            {
                add();
                break;
            }
            case '2':
            {
                remove();
                break;
            }
            case '3':
            {
                update();
                break;
            }
            case '4':
            {
                printAll();
                break;
            }
            case '5':
            {
                addMoney();
                break;
            }
            case '6':
            {
                printMoney();
                break;
            }
            case 'x':
            {
                run = false;
                break;
            }
            default:
                cout << "Invalid option" << endl;
        }
    }
}

void UI::addMoney() {
    MoneyValidator moneyValidator("1", "5", "10", "50", "100");
    NumberValidator numberValidator(1);
    int banknote, amount;
    string banknoteS;
    try{
        cout << "Enter banknote: ";
        cin >> banknoteS;
        cout << "Enter amount: ";
        cin >> amount;
        moneyValidator.validate(banknoteS);
        numberValidator.validate(amount);
        banknote = stoi(banknoteS);
        availableMoney[banknote] += amount;
    }
    catch(InvalidMoneyValueException &e){
        cout << e.what() << endl;
    }
    catch(InvalidNumberException &e){
        cout << e.what() << endl;
    }
    catch(invalid_argument &e){
        cout << e.what() << endl;
    }
    catch(...){
        cout << "Unknown exception" << endl;
    }
}

void UI::printMoney() {
    for(auto it = availableMoney.begin(); it != availableMoney.end(); it++)
        if(it->second > 0)
        cout << it->first << "lei: " << it->second << endl;
}

void UI::saveMoneyToFile() {
    ofstream f("Money.txt");
    for(auto it = availableMoney.begin(); it != availableMoney.end(); it++)
        f << it->first << ' ' << it->second << '\n';
    f.close();

}

void UI::loadMoneyFromFile() {
    ifstream f("Money.txt");
    int banknote, amount;
    while(f >> banknote >> amount)
        availableMoney[banknote] = amount;
    f.close();

}

#endif //LAB9_10_UI_H
