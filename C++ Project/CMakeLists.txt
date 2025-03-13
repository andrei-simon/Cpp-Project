cmake_minimum_required(VERSION 3.27)
project(lab9_10)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab9_10 main.cpp
        Entity.h
        Repository.h
        Tests.h
        UI.h
        Service.h
        FileRepository.h
        Exceptions.h
        Validators.h)
