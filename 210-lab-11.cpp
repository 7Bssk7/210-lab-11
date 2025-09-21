// COMSC 210 | Lab 11 | Arkhip Finski
// IDE used: Visual studio
#include <iostream>
#include <string>
using namespace std;

const int NUM_CARS = 3;

struct Car{
    string make, model;
    int year, miles, pOwners;
    string *owners;

    ~Car(){
        if(owners){
            delete [] owners;
        }
        owners = nullptr;
    }
   
};

void inputCars(Car *);
void inputEx();
void outputCars(Car *);

int main(){
    Car *list = new Car[NUM_CARS];
    
    inputEx();
    for(int i = 0; i < NUM_CARS; ++i){
        inputCars(&list[i]);
    }
    cout << "List of the used cars: "  << " \n "<< endl;
    for(int i = 0; i < NUM_CARS; ++i){
        outputCars(&list[i]);
    }

    delete [] list;

    return 0;
}

void inputCars(Car *c){
    static int num = 1;
    cout << "Enter information about car #" << num << endl;
    cout << "Enter the vehicle manufacturer: ";
    getline(cin, c->make);
    cout << "Enter the vehicle model: ";
    getline(cin, c->model);
    cout<< "Enter the year of manufacture: ";
    cin >> c->year;
    cout << "Enter a car mileage: ";
    cin >> c->miles;
    cout << "Enter the number of previous owners: ";
    cin >> c->pOwners;
    while((c->pOwners < 1) || (c->pOwners > 15)){
        cout << "Invalid input" << endl;
        cout << "Please enter the number of previous owners: ";
        cin >> c->pOwners;
    }
    cin.ignore();
    cout << "Previous owners: "<< endl;
    c-> owners = new string[c->pOwners];
    for(int i = 0; i < c->pOwners; ++i){
        cout << "Owner #" << i+1 << ": ";
        getline(cin, c->owners[i]);
    }
    cout << endl;
    num++;
}

void inputEx(){
    cout << "Input example:" << endl;
    cout<< "Enter information about car #" << 1 << endl;
    cout << "Enter the vehicle manufacturer: " << "BMW" << endl;
    cout << "Enter the vehicle model: " << "328i" << endl;
    cout << "Enter the year of manufacture: " << "2014" << endl;
    cout << "Enter a car mileage: " << "120412" << endl;
    cout << "Enter the number of previous owners: " << "2" << endl;
    cout << "Previous owners: "<< endl;
    cout << "Owner #1 2014 - 2019" << endl;
    cout << "Owner #2 2019 - current" << endl;  
    cout << endl;
}
void outputCars(Car *c){
    static int num = 0;
    cout<< "Car #" << num+1 << endl;
    cout << "Make: " << c->make << endl;
    cout << "Model: " << c->model << endl;
    cout << "Year of manufacture: " << c-> year << endl;
    cout << "Car's mileage: " << c->miles << " miles" << endl;
    cout << "Previous owners: "<< endl;
    for(int i = 0; i < c->pOwners; ++i){
        cout << "Owner #" << i+1 << " " << c->owners[i] << endl;
    }
    cout << endl;
    num++;
}