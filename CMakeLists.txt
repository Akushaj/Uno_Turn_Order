cmake_minimum_required(VERSION 3.26)
project(Uno_Turn_Order)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Uno_Turn_Order
        main.cpp
        Data.h
        ArrayList.h
        LinkedList.h
        List.h
        Node.h
        Player.h
        Stack.h
)