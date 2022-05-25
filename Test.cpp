//
// Created by Satori on 2022/5/25.
//

#include "Test.h"

//-------------------------------------------------//

void Pig::add_pig(int pig_number){
     this->pig_number = this->pig_number+pig_number;
     storage = this->pig_number* size;
};

int Pig::getValue(){return value;};

void Pig::add_storage(){cout<<"hello"<<endl;};

bool Pig::ifAlive(){
    return alive;
};

void Pig::sell(int pig_Prise, int sellNumber){
    int sellprice = pig_Prise*sellNumber;
    int sellStorage = sellNumber * Pig::size;
    storage = storage - sellStorage;
    cout<<"The farm solded "<<sellNumber<<" unit of Pig, with a total income is: "<< sellprice <<". The selling price per unit is: "<< pig_Prise <<endl;
};

void Pig::eat(){
    cout<<"pig eat"<<endl;
};

//--------------------------------------------//

void Sheep::add_sheep(int sheep_number){
    this->sheep_number = this->sheep_number+sheep_number;
    storage = this->sheep_number* size;
};

int Sheep::getValue(){return value;};

void Sheep::add_storage(){cout<<"hello"<<endl;};

bool Sheep::ifAlive(){
    return alive;
};

void Sheep::sell(int sheep_Prise, int sellNumber){
    int sellprice = sheep_Prise*sellNumber;
    int sellStorage = sellNumber * Sheep::size;
    storage = storage - sellStorage;
    cout<<"The farm solded "<<sellNumber<<" unit of sheep, with a total income is: "<< sellprice <<". The selling price per unit is: "<< sheep_Prise <<endl;
};

void Sheep::eat(){
    cout<<"sheep eat"<<endl;
};

//-----------------------------------------------//

void Wheat::add_wheat(int wheat_number){
    this->wheat_number = this->wheat_number+wheat_number;
    storage = this->wheat_number* size;
};

int Wheat::getValue(){return value;}
void Wheat::add_storage(){cout<<"hello"<<endl;};
bool Wheat::ifAlive(){
    return alive;
};

void Wheat::sell(int wheat_Prise, int sellNumber){
    int sellprice = wheat_Prise*sellNumber;
    int sellStorage = sellNumber * Wheat::size;
    storage = storage - sellStorage;
    cout<<"The farm solded "<<sellNumber<<" KG of wheat, with a total income is: "<< sellprice <<". The selling price per unit is: "<< wheat_Prise <<endl;
    //写一个卖出后的余额变化，并显示余额多少;
};

void Wheat::kill_insect(){
    cout<<"Insert removal"<<endl;
};

//------------------------------------------------------------//

void Corn::add_corn(int corn_number){
    this->corn_number = this->corn_number+corn_number;
    storage = this->corn_number* size;
};

int Corn::getValue(){return value;};

void Corn::add_storage(){cout<<"hello"<<endl;};

bool Corn::ifAlive(){
    return alive;
};

void Corn::sell(int corn_Prise, int sellNumber){
    int sellprice = corn_Prise*sellNumber;
    int sellStorage = sellNumber * Corn::size;
    storage = storage - sellStorage;
    cout<<"The farm solded "<<sellNumber<<" KG of Corn, with a total income is: "<< sellprice <<". The selling price per unit is: "<< corn_Prise <<endl;
};

void Corn::kill_insect(){
    cout<<"Insert removal"<<endl;
};