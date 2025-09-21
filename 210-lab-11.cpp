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
    for(int i = 0; i < NUM_CARS; ++i){
        outputCars(&list[i]);
    }


    return 0;
}

void inputCars(Car *c){
    static int num = 0;
    cout << "Enter information about car #" << num << endl;
    cout << "Enter the vehicle manufacturer: ";
    getline(cin, c->make);
    cout << "Enter the vehicle model: ";
    getline(cin, c->model);
    cout<< "Enter the year of manufacture: ";
    cin >> c->year;
    cout << "Enter a car mileage: ";
    cin >> c->miles;
    cout << "\n";
    cin.ignore();
    num++;
}

void outputCars(Car *c){
    static int num = 1;
    cout << "List of the cars" << endl;
    cout<< "Car #" << num+1 << endl;
    cout << "Make: " << c->make << endl;
    cout << "Model: " << c->model << endl;
    cout << "Year of manufacture: " << c-> year << endl;
    cout << "Cars mileage: " << c->miles << endl;
    num++;
}