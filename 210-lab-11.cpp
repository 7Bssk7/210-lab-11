// COMSC 210 | Lab 11 | Arkhip Finski
// IDE used: Visual studio
#include <iostream>
#include <string>
using namespace std;

const int NUM_CARS = 3;

struct Car{
    string make, model;
    int year, miles;
};

void inputCars(Car *);
void outputCars(Car *);

int main(){

    Car *list = new Car[NUM_CARS];
    
    for(int i = 0; i < NUM_CARS; ++i){
        inputCars(&list[i]);
    }



    return 0;
}

void inputCars(Car *c){

    static int num = 1;
    cout << "Enter information about car #" << num << endl;
    cout << "Make: ";
    getline(cin, c->make);
    cout << "Model: ";
    getline(cin, c->model);
    cout<< "Enter the year of manufacture: ";
    cin >> c->year;
    cout << "Enter a car mileage: ";
    cin >> c->miles;
    cout << "\n";
    cin.ignore();

}