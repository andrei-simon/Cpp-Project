//
// Created by User on 4/24/2024.
//

#ifndef LAB9_10_REPOSITORY_H
#define LAB9_10_REPOSITORY_H
#include "Entity.h"
#include <vector>

class Repository{
protected:
    vector<Entity> Repo;
public:
    Repository();
    Repository(vector<Entity> Repo);
    Repository(const Repository& Repo);
    ~Repository();

    void setRepo(Repository Repo);
    void addElem(const Entity &e);
    vector<Entity>& getAll();
    Entity getElem(int pos) const;
    int size();
    void deleteElem(int pos);
    void updateElem(int pos, const Entity &e);

    Repository& operator=(const Repository& other);
    bool operator==(const Repository& other);
};

Repository::Repository() {

}

Repository::Repository(vector<Entity> Repo) {
    this->Repo = Repo;
}

Repository::Repository(const Repository &Repo) {
    this->Repo = Repo.Repo;
}

Repository::~Repository() {

}

void Repository::addElem(const Entity &e) {
    Repo.push_back(e);
}

vector<Entity> &Repository::getAll() {
    return Repo;
}

Entity Repository::getElem(int pos) const {
    return Repo[pos];
}

int Repository::size() {
    return Repo.size();
}

void Repository::deleteElem(int pos) {
    Repo.erase(Repo.begin() + pos);
}

Repository &Repository::operator=(const Repository &other) {
    Repo = other.Repo;
    return *this;
}

bool Repository::operator==(const Repository &other) {
    return Repo == other.Repo;
}

void Repository::updateElem(int pos, const Entity &e) {
    Repo[pos] = e;
}

void Repository::setRepo(Repository Repo) {
    this->Repo = Repo.Repo;
}


#endif //LAB9_10_REPOSITORY_H
