//
// Created by User on 4/24/2024.
//

#ifndef LAB9_10_ENTITY_H
#define LAB9_10_ENTITY_H
#include <iostream>
using namespace std;

class Entity{
private:
    int time;
    int code;
    int price;
public:
    Entity() = default;
    Entity(int c, int t, int p): code(c), time(t), price(p){};
    Entity(Entity const &e): code(e.code), time(e.time), price(e.price){};
    ~Entity() = default;

    int getCode();
    int getTime();
    int getPrice();
    void setCode(int code);
    void setTime(int time);
    void setPrice(int price);

    Entity& operator=(const Entity &e);
    bool operator==(const Entity &e) const;
    friend ostream& operator<<(ostream& os, const Entity& e);
};

int Entity::getCode() {
    return code;
}

int Entity::getTime() {
    return time;
}

int Entity::getPrice() {
    return price;
}

void Entity::setCode(int code) {
    this->code = code;
}

void Entity::setTime(int time) {
    this->time = time;
}

void Entity::setPrice(int price) {
    this->price = code;
}

Entity &Entity::operator=(const Entity &e) {
    this->code = e.code;
    this->time = e.time;
    this->price = e.price;
    return *this;
}

bool Entity::operator==(const Entity &e) const {
    return (this->code == e.code && this->time == e.time && this->price == e.price);
}

ostream &operator<<(ostream &os, const Entity &e) {
    os << "Code: " << e.code << " Time: " << e.time << " Price: " << e.price;
    return os;
}

#endif //LAB9_10_ENTITY_H
