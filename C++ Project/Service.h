//
// Created by User on 5/5/2024.
//

#ifndef LAB9_10_SERVICE_H
#define LAB9_10_SERVICE_H
#include "Repository.h"
#include "FileRepository.h"
#include <vector>

class Service{
private:
//    static Repository defaultRepo;
    fileRepo &fRepo;
public:
    Service(fileRepo &frepo): fRepo(frepo){};
    ~Service();

    void addElem(const Entity &e);
    void deleteElem(int pos);
    void updateElem(int pos, const Entity &e);
    vector<Entity> getAll();
    Entity getElem(int pos);
    int size();
    Repository getRepo();
    void setRepo(Repository repo);
    Service& operator=(const Service &other);
    bool operator==(const Service &other);
    void saveToFile();
};

Service::~Service() {
}

void Service::addElem(const Entity &e) {
    fRepo.addElem(e);
}

void Service::deleteElem(int pos) {
    fRepo.deleteElem(pos);
}

void Service::updateElem(int pos, const Entity &e) {
    fRepo.updateElem(pos, e);
}

vector<Entity> Service::getAll() {
    return fRepo.getAll();
}

Entity Service::getElem(int pos) {
    return fRepo.getElem(pos);
}

int Service::size() {
    return fRepo.size();
}

Repository Service::getRepo() {
    return fRepo;
}

void Service::setRepo(Repository repo) {
    fRepo = repo;
}

Service &Service::operator=(const Service &other) {
    fRepo = other.fRepo;
    return *this;
}

bool Service::operator==(const Service &other) {
    return fRepo == other.fRepo;
}

void Service::saveToFile() {
    fileRepo fr;
    fr = fRepo;
    fr.saveToFile();
}


//Repository Service::defaultRepo = Repository();

#endif //LAB9_10_SERVICE_H
