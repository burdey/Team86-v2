#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <string>
#include<cstring>
using namespace std;

#include "Address.cpp"
#include "Test.h"

//---------------------menu--------------------//

double pig_Prise;
double sheep_Prise;
double corn_Prise;
double wheat_Prise;

// -----------------------------------------//

void menu1(){
    cout << "please enter your choice: "<<endl ;
    cout << "1. Create"<< endl;
    cout << "2. Load"<< endl;
    cout << "X. Over"<< endl;

}

void menu2(){
    cout<< "Today's market--------" <<endl;
    cout<< "Pig:" << pig_Prise <<endl;
    cout<< "sheep:" << sheep_Prise <<endl;
    cout<< "corn:" << corn_Prise <<endl;
    cout<< "wheat:" << wheat_Prise <<endl;

    cout << "3. Save"<< endl;
    cout << "4. Buy"<< endl;
    cout << "5. sell"<< endl;
    cout << "6. assert"<< endl;
}

//--------------------menu---------------------//

//--------------------function-----------------//

//------Create, Load, Save-------//
void create(Capital* cp,Pig* pg, Sheep* sp, Corn* cr, Wheat* wheat){

    string farmname;
    string cou;

    cout << "Welcome to 0086 Farm Management System" <<endl;
    cout << "Welcome to 0086 Farm Management System, Please enter your farm Name: " ;
    cin >> farmname;

    cout << "Farm name set as " << farmname << ", Please type your farm's location" << endl;

    cout << "Country: ";
    cin >> cou;

    cout << "Farms location saved. " << endl;
    cout << "Please enter your initial capital(in numbers): " ;
    cin >> cp->initialCapital;

    //cout << "Please set your farm storage: ";
    //cin >> allstorage;
    //cout << "the storage set" << endl;
    cout<<"Building finished!"<<endl;

    menu2();
}

void load(){
    freopen("C:\\Develop\\SAVE1.txt","r",stdin);
    menu2();
}

void save(){
    freopen("C:\\Develop\\SAVE1.txt","w",stdout);
    menu1();
}

/*void load(){
    std::ifstream in;
    in.open("save1.txt");
    if(in.fail()){
    	cout<<"请将读入文件与此文件放在同一个路径。";
    	exit(1);
    }//这一段可以改为 exit(in.fail());

    int i;

    cout<<"上次，你输入的值是";//<-把这里换成需要读取的数据，显示它。

    in>>i;
    cout<<i;
    in.close();

    system("cls");

    cout<< "已读取."<<endl;
    menu2();
}


void save(){
    std::ofstream out;
	out.open("save1.txt");
	if(out.fail())
	{
		cout<<"请将读出文件与此文件放在同一个路径。";
		exit(1);
	}
	cout<<"输入一个数：";
	cin>>i;
	out<<i;
	out.close();

	out.open("save1.txt");
	out<<i;
	out.close();
	cout<<"已将此值存放。"<<endl;
	return 0;
}*/


//------Create, Load, Save-------//

//------Buy and sell-------//
void buy(Capital* cp, Pig* pg, Sheep* sp, Corn* cr, Wheat* wheat){

    string type1;
    int sheep_number;
    int pig_number;
    int corn_number;
    int wheat_number;
    cout<<"What do you want to buy?"<<endl;
    cout<<"If finish,you can return through the 'Z' key"<<endl;
    cin >> type1;
    while(type1!="Z"){
        if (type1 == "sheep") {
            cout << "Please enter how much to buy: " << endl;
            cin >> sheep_number;
            sp->add_sheep(sheep_number);
            cp->initialCapital = cp->initialCapital-sheep_number * sp->getValue();
            cout<<"Transaction completed!"<<endl;
        }
        else if (type1 == "pig") {
            cout << "Please enter how much to buy: " << endl;
            cin >> pig_number;
            pg->add_pig(pig_number);
            cp->initialCapital = cp->initialCapital-pig_number * pg->getValue();
            cout<<"Transaction completed!"<<endl;
        }
        else if (type1 == "corn") {
            cout << "Please enter how much to buy: " << endl;
            cin >> corn_number;
            cr->add_corn(corn_number);
            cp->initialCapital = cp->initialCapital-corn_number *cr->getValue();
            cout<<"Transaction completed!"<<endl;
        }
        else if (type1 =="wheat") {
            cout << "Please enter how much to buy: " << endl;
            cin >> wheat_number;
            wheat->add_wheat(sheep_number);
            cp->initialCapital = cp->initialCapital-wheat_number * wheat->getValue();
            cout<<"Transaction completed!"<<endl;
        }
        else {
            cout << "You are not entering a commodity" <<endl;
        }
            /*if(input = "Z"){
                //menu2();  //<-因其不确定性，我把这玩意给注释了。  //这里如果有需要更正的代码可以写一下，因为我不确定是否能回到menu2.
            }*/

        cout<<"What do you want to buy?"<<endl;
        cout<<"If finish,you can return through the 'Z' key"<<endl;
        cin >> type1;
    }
}

void sell(Pig* pg,Sheep* sp, Corn* cr, Wheat* wheat, Capital* cp){
//----random number generator----//
    int seed = 100000;
      // <-看看这个随机数重置器是否管用，如果不行可以试试 srand((unsigned)time(NULL));
    srand((unsigned)time(NULL));
    //---Pigvalue---//
    const int MIN_PigValue = 30;
    const int MAX_PigValue = 600;
    pig_Prise =  rand() % (MAX_PigValue - MIN_PigValue + 1) + MIN_PigValue;
    //---Sheepvalue---//
    const int MIN_SheepValue = 10;
    const int MAX_SheepValue = 400;
    sheep_Prise =  rand() % (MAX_SheepValue - MIN_SheepValue + 1) + MIN_SheepValue;
    //---Cornvalue---//
    const int MIN_CornValue = 400;
    const int MAX_CornValue = 4000;
    corn_Prise =  rand() % (MAX_CornValue - MIN_CornValue + 1) + MIN_CornValue;
    //---Wheatvalue---//
    const int MIN_WheatValue = 100;
    const int MAX_WheatValue = 2000;
    wheat_Prise =  rand() % (MAX_WheatValue - MIN_WheatValue + 1) + MIN_WheatValue;
//----random number generator----//
    string type2;
    cout << "What kind of goods do you want to sell?:";
    cout<<"If finish,you can return through the 'C' key"<<endl;
    cin >> type2;
    while(type2!="C"){
        if(type2 == "pig"){
            string sellNumber;
            cout << "Please enter how much to sell: ";
            cin >> sellNumber;
            pg->sell(pig_Prise, std::stoi(sellNumber)); //如上
            cp->initialCapital = cp->initialCapital+stoi(sellNumber)*pig_Prise;
            cout<<"Finish!"<<endl;//另外我很担心上面的Pig()::sell()出错，所以如果后来者要修改的话可以帮忙查查这玩意的对错，下面的各动物同理。
        }
        else if(type2 == "sheep"){
            string sellNumber;
            cout << "Please enter how much to sell: ";
            cin >> sellNumber;
            sp->sell(sheep_Prise, std::stoi(sellNumber)); //如上
            cp->initialCapital = cp->initialCapital+stoi(sellNumber)*sheep_Prise;
            cout<<"Finish!"<<endl;
        }
        else if(type2 == "corn"){
            string sellNumber;
            cout << "Please enter how much to sell: ";
            cin >> sellNumber;
            cr->sell(corn_Prise, std::stoi(sellNumber)); //如上
            cp->initialCapital = cp->initialCapital+stoi(sellNumber)*corn_Prise;
            cout<<"Finish!"<<endl;
        }
        else if(type2 == "wheat"){
            string sellNumber;
            cout << "Please enter how much to sell: ";
            cin >> sellNumber;
            wheat->sell(wheat_Prise, std::stoi(sellNumber)); //如上
            cp->initialCapital = cp->initialCapital+stoi(sellNumber)*wheat_Prise;
            cout<<"Finish!"<<endl;
        }
        else{
            cout << "The input in invalid,please try again." <<endl;
        }
        cout << "What kind of goods do you want to sell?:";
        cout<<"If finish,you can return through the 'C' key"<<endl;
        cin >> type2;
    }
}
//------buy and sell-------//

void assets(Capital* cp){
    cout<<cp->initialCapital<<endl;
    cout<<"Check!1"<<endl;

}

//----------------function-----------------//



int main(){
    Capital cp = Capital();
    Pig pg = Pig();
    Sheep sp = Sheep();
    Wheat wheat = Wheat();
    Corn cr = Corn();

    //create(&cp,&pg,&sp,&cr,&wheat);
    //void create(Capital* cp,Animal* an,Crop* co)
    //buy(&cp,&pg,&sp,&cr,&wheat);
    //void buy(Capital* cp, Pig* pg, Sheep* sp, Corn* cr, Wheat* wheat)
    //sell(&pg,&sp,&cr,&wheat,&cp);
    //void sell(Pig* pg,Sheep* sp, Corn* cr, Wheat* wheat, Capital* cp)


    menu1();

    char input;
    cout << "Please enter your choice: ";
    cin>>input;
    while(input!='X'){

        switch (input) {
            case '1':create(&cp,&pg,&sp,&cr,&wheat);break;
            case '2':load();break;
            case '3':save();break;
            case '4':buy(&cp,&pg,&sp,&cr,&wheat);break;
            case '5':sell(&pg,&sp,&cr,&wheat,&cp);break;
            case '6':assets(&cp);break;
        }

        cout << "Please enter your choice: ";
        cin>>input;
    }

    return 0;

}