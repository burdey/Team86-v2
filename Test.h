//
// Created by Satori on 2022/5/25.
//

#ifndef TEAM86_V2_TEST_H
#define TEAM86_V2_TEST_H


#include "Capital.cpp"
#include <iostream>

class Animal{
public:
    string Type;
    int value;
    int size;
    bool alive;
    int storage=0;
    virtual void add_storage()=0;
    virtual bool ifAlive()=0;
    //virtual void sell(int pig_Prise, int sellNumber)=0;
    virtual void eat()=0;

};

class Pig:public Animal{
    string type = "pig";
    int pig_number;
    int value = 100;
    int size = 4;
    bool alive = true;

public:
    void add_pig(int pig_number);
    int getValue();
    void add_storage();
    bool ifAlive();
    void sell(int pig_Prise, int sellNumber);
    void eat();
};

class Sheep:public Animal{

    string type = "sheep";
    int sheep_number;
    int value = 200;
    int size = 2;
    bool alive = true;

public:
    void add_sheep(int sheep_number);
    int getValue();
    void add_storage();
    bool ifAlive();
    void sell(int sheep_Prise, int sellNumber);
    void eat();

};

class Crop{
public:
    string type;
    int value;
    int size;
    bool alive;
    int storage;
    virtual void add_storage()=0;
    virtual bool ifAlive()=0;
    //virtual void sell()=0;
    virtual void kill_insect()=0;
};

class Wheat:public Crop{

    string type = "Wheat";
    int wheat_number;
    int value = 1000;
    int size = 25;
    bool alive = true;

public:
    void add_wheat(int wheat_number);
    int getValue();
    void add_storage();
    bool ifAlive();
    void sell(int wheat_Prise, int sellNumber);
    void kill_insect();
};

class Corn:public Crop{

    string type = "Corn";
    int corn_number;
    int value = 500;
    int size = 15;
    bool alive = true;

public:
    void add_corn(int corn_number);
    int getValue();
    void add_storage();
    bool ifAlive();
    void sell(int corn_Prise, int sellNumber);
    void kill_insect();
};


#endif //TEAM86_V2_TEST_H
