#include <iostream>
#include <windows.h>
#include "tests/ManualTests.h"
#include "tests/AutoTests.h"

using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);    //ustawianie polskich znaków


    srand(static_cast<unsigned int>(time(0)));; //inicjacja generatora liczb pseudolosowych

    cout << "Autor: Kasper Radom 264023" << endl << endl;


    char choice;
    do{
        cout<<"Który problem chcesz rozwiązać:"<<endl
            <<"a) Testy automatyczne"<<endl
            <<"b) Testy manualne"<<endl
            <<"q) Wyjście"<<endl<<">>";
        cin>>choice;
        cout<<endl<<endl;

        switch (choice) {
            case 'a': {
                AutoTests *autoTests = new AutoTests();

                delete autoTests;
                break;
            }
            case 'b': {
                ManualTests *manualTests = new ManualTests();

                delete manualTests;
                break;
            }
        }
    }while(choice!='q');

    return 0;
}

//#include "structures/Table.h"
//#include <iostream>
//using namespace std;
//int main(){
//    Table* t = new Table();
//    t->push(4);
//    t->push(4);
//    t->clear();
//    t->push(4);
//    t->clear();
//    t->clear();
//    t->clear();
//    t->push(4);
//    t->push(4);
//    t->clear();
//    t->push(4);
//
//    t->push(4);
//    t->push(4);
//
//    for(int i=0; i<t->getSize(); i++){
//        cout<<t->get(i)<<endl;
//    }
//}