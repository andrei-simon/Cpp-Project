//
// Created by User on 5/12/2024.
//

#ifndef LAB9_10_FILEREPOSITORY_H
#define LAB9_10_FILEREPOSITORY_H
#include "Repository.h"
#include <fstream>

class fileRepo: public Repository{
private:
    char* fileName;
public:
    fileRepo() : Repository() {};
    fileRepo(const char* filename);
    void saveToFile();
    void loadFromFile();
    void addElem(const Entity &e);
    vector<Entity>& getAll();
    Entity getElem(int pos) const;
    int size();
    void deleteElem(int pos);
    void updateElem(int pos, const Entity &e);
    fileRepo& operator=(Repository& repo);
    ~fileRepo();
};

fileRepo::fileRepo(const char *file) : Repository() {
    fileName = (char*)file;
    loadFromFile();
}

void fileRepo::saveToFile() {
    ofstream f(fileName);
    for(int i = 0; i < size(); i++)
        f << getElem(i).getCode() << ' ' << getElem(i).getTime() << ' ' << getElem(i).getPrice() << "\n";
    f.close();
}

void fileRepo::loadFromFile() {
    ifstream f(fileName);
    int code, time, price;
    while(f >> code >> time >> price) {
        Entity e(code, time, price);
        addElem(e);
        cout << "Loaded entity: " << code << " " << time << " " << price << endl;

    }
    f.close();
}

fileRepo::~fileRepo() {

}

fileRepo &fileRepo::operator=(Repository &repo) {
    Repo = repo.getAll();
    fileName = "Parking.txt";
    return *this;
}

void fileRepo::addElem(const Entity &e) {
    Repository::addElem(e);
}

vector<Entity> &fileRepo::getAll() {
    return Repository::getAll();
}

Entity fileRepo::getElem(int pos) const {
    return Repository::getElem(pos);
}

int fileRepo::size() {
    return Repository::size();
}

void fileRepo::deleteElem(int pos) {
    Repository::deleteElem(pos);
}

void fileRepo::updateElem(int pos, const Entity &e) {
    Repository::updateElem(pos, e);
}


#endif //LAB9_10_FILEREPOSITORY_H
