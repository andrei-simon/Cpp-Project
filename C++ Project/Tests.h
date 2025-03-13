//
// Created by User on 4/24/2024.
//

#ifndef LAB9_10_TESTS_H
#define LAB9_10_TESTS_H

#include "Entity.h"
#include "Repository.h"
#include "Service.h"
#include "FileRepository.h"
#include <cassert>
#include <iostream>

using namespace std;

void testEntity(){
    Entity e(1, 12, 100);
    assert(e.getCode() == 1);
    assert(e.getTime() == 12);
    assert(e.getPrice() == 100);
    e.setCode(2);
    assert(e.getCode() == 2);
    Entity e2;
    e2 = e;
    assert(e == e2);
    cout << "Entity tests complete" << endl;
}

void testRepository(){
    Repository repo;
    repo.addElem(Entity(1, 1, 5));
    repo.addElem(Entity(2, 2, 10));
    repo.addElem(Entity(3, 24, 100));
    vector<Entity> test;
    test.push_back(Entity(1,1,5));
    test.push_back(Entity(2,2,10));
    test.push_back(Entity(3,24,100));
    assert(repo.getElem(0) == test[0]);
    assert(repo.getAll() == test);
    assert(repo.size() == 3);
    repo.deleteElem(0);
    assert(repo.getElem(0) == test[1]);
    assert(repo.size() == 2);
    repo.updateElem(0, Entity(2, 2, 10));
    assert(repo.getElem(0) == Entity(2, 2, 10));
    cout << "fRepo tests complete" << endl;
}

void testService(){
    fileRepo fRepo;
    Service service(fRepo);
    service.addElem(Entity(1,1,5));
    service.addElem(Entity(2,2,10));
    service.addElem(Entity(3,24,100));
    vector<Entity> test;
    test.push_back(Entity(1,1,5));
    test.push_back(Entity(2,2,10));
    test.push_back(Entity(3,24,100));
    assert(service.getElem(0) == test[0]);
    assert(service.getAll() == test);
    assert(service.size() == 3);
    service.deleteElem(0);
    assert(service.getElem(0) == test[1]);
    assert(service.size() == 2);
    service.updateElem(0, Entity(2, 2, 10));
    assert(service.getElem(0) == Entity(2, 2, 10));
    cout << "Service tests complete" << endl;
}

void testFileRepo(){
    fileRepo repo("test.txt");
    fileRepo repo2;
    repo2.addElem(Entity(1, 1, 5));
    repo2.addElem(Entity(2, 2, 10));
    repo2.addElem(Entity(3, 24, 100));
    assert(repo.getAll() == repo2.getAll());
    cout << "FileRepo tests complete" << endl;
}

void test_all(){
    testEntity();
    testRepository();
    testService();
    testFileRepo();
}
#endif //LAB9_10_TESTS_H
