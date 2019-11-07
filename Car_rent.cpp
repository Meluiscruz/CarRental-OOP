#include <iostream>

using namespace std;

class Vehicle {
protected:
	int days;
	string ID;
	string color;
public:
	Vehicle(int _days, string _ID, string _color): days(_days), ID(_ID), color(_color) {};
	virtual void Print2Console() = 0;
	virtual void serviceEngine() = 0;
	virtual void serviceTransmission() = 0;
	virtual void serviceTires() = 0;
};

/*
 *	
 */

class Sedan : public Vehicle {
protected:
	double trunk_cap;
public:
	int cost;
	Sedan(int _days, string _ID, string _color, double _trunk_cap) : Vehicle(_days, _ID, _color), trunk_cap(_trunk_cap) {}
	void Print2Console() {
		cout << "Car Type: \t\tSedan" << endl;
		cout << "ID: \t\t\t" << ID << endl;
		cout << "Color: \t\t\t" << color << endl;
		cout << "Trunk Capacity: \t" << trunk_cap << endl;
		cout << "Rented Days: \t\t" << days << endl;
		cost = days * 1000;
		cout << "Price: \t\t" << cost << " (USD)" << endl;
	}
	void serviceEngine() {

	}
	void serviceTransmission() {

	}
	void serviceTires() {

	}
};

struct Dimension{
	int width;
	int length;
	int height;
};

class PickUp : public Vehicle {
protected:
	Dimension trunk_dim;
public:
	int cost;
	void GetDim(int _width, int _length, int _height) {
		trunk_dim.width = _width;
		trunk_dim.length = _length;
		trunk_dim.height = _height;
	}
	PickUp(int _days, string _ID, string _color) : Vehicle(_days, _ID, _color) {}
	void Print2Console() {
		cout << "Car Type: \t\tPickUp" << endl;
		cout << "ID: \t\t\t" << ID << endl;
		cout << "Color: \t\t\t" << color << endl;
		cout << "Trunk Dimension: \t" << trunk_dim.width << " x " << trunk_dim.length << " x " << trunk_dim.height << " (m)" << endl;
		cout << "Rented Days: \t\t" << days << endl;
		cost = days * 1500;
		cout << "Price: \t\t" << cost << " (USD)" << endl;
	}
	void serviceEngine() {

	}
	void serviceTransmission() {

	}
	void serviceTires() {

	}


};

class SUV : public Vehicle {
protected:
	int seats;
public:
	int cost;
	bool isFourSeat() {
		if(seats == 4)
			return true;
		else return false;
	}
	SUV(int _days, string _ID, string _color, int _seats) : Vehicle(_days, _ID, _color), seats(_seats) {};
	void Print2Console() {
		cout << "Car Type: \t\tSUV" << endl;
		cout << "ID: \t\t\t" << ID << endl;
		cout << "Color: \t\t\t" << color << endl;
		cout << "Four seats: \t\t";
		if(isFourSeat())
			cout << "Yes" << endl;
		else cout << "No" << endl;
		cout << "Rented Days: \t\t" << days << endl;
		cost = days * 2000;
		cout << "Price: \t\t" << cost << " (USD)" << endl;
	}
	void serviceEngine() {

	}
	void serviceTransmission() {

	}
	void serviceTires() {

	}

};

struct Record{
	double mileage;
	int engine_cond;
	int tires_cond;
};

class CarRentalManagement{
protected:
	string name;
	int age;
	int identityNumber;
	int PhoneNumber;
	int carType;
	int days;
	string ID;
	string color;
	int moreCar;
	CarRentalManagement* carArr;
	int TotalPrice;
	Record VehicleHistory;
public:
	void GetInfo() {
		cout << "Your fullname: ";
		getline(std::cin, name);
		cout << "Your Age: ";
		cin >> age;
		cout << "Your Identity number: ";
		cin >> identityNumber;
		cout << "Phone number: ";
		cin >> PhoneNumber;
	}
	void GetRentedInfo() {
		cout << "Choose the type of car you want to rent: 1.Sedan  2.PickUp  3.SUV" << endl;
		cout << "Your choice: "; 
		cin >> carType;
		cout << "How many days you rented: ";
		cin >> days;
		cout << "Car's ID in the database: ";
		cin >> ID;
		cout << "Choose color: ";
		cin >> color;
	}
	void addCar() {
		cout << "How many car you want to rent? : ";
		cin >> moreCar;
		carArr = new CarRentalManagement[moreCar];
		for(int i = 0; i < moreCar; i++) {
			carArr[i].GetRentedInfo();
		}
	}
	void PrintBill() {
		TotalPrice = 0;
		cout << "------------------------------------" << endl;
		cout << "             TOTAL BILL             " << endl;
		cout << "Name: \t\t\t" << name << endl;
		cout << "Age: \t\t\t" << age << endl;
		cout << "Identity number: \t" << identityNumber << endl;
		cout << "Phone number: \t\t" << PhoneNumber << endl;
		cout << "Number of cars rented: " << moreCar + 1 << endl;
		cout << "..." <<endl;

		for(int i = 0; i < moreCar; i++) {
			if(carArr[i].carType == 1) {
				int trunk_cap = 10;
				Sedan myCar(carArr[i].days, carArr[i].ID, carArr[i].color, trunk_cap);
				myCar.Print2Console();
				TotalPrice += myCar.cost;
			} else if(carArr[i].carType == 2) {
				PickUp myCar(carArr[i].days, carArr[i].ID, carArr[i].color);
				myCar.GetDim(1, 2, 3);
				myCar.Print2Console();
				TotalPrice += myCar.cost;
			} else if(carArr[i].carType == 3) {
				SUV myCar(carArr[i].days, carArr[i].ID, carArr[i].color, 4);
				myCar.Print2Console();
				TotalPrice += myCar.cost;
			}
		cout << endl;
		}
		cout << "Total Price: \t\t" << TotalPrice << " (USD)" << endl;
		cout << "------------------------------------" << endl;
	}
	void ServiceFleet() {
		
	}
};

//
//
//


int main(){
	CarRentalManagement a;
	a.GetInfo();
	a.addCar();
	a.PrintBill();

	return 0;
}
