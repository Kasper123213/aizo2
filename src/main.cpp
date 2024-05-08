#include <iostream>
#include <windows.h>
#include "tests/ManualTests.h"
#include "tests/AutoTests.h"

using namespace std;
int main() {
    SetConsoleOutputCP(CP_UTF8);    //ustawianie polskich znaków


    srand(time(NULL)); //inicjacja generatora liczb pseudolosowych

    cout << "Autor: Kasper Radom 264023" << endl << endl;


    char choice = 'b';
    do{
        cout<<"Który problem chcesz rozwiązać:"<<endl
            <<"a) Testy automatyczne"<<endl
            <<"b) Testy manualne"<<endl
            <<"q) Wyjście"<<endl<<">>";
//        cin>>choice;
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
