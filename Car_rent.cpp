#include <iostream>

using namespace std;

class Vehicle {
protected:
	int days;
	string ID;
	string color;
public:
	Vehicle(int _days, string _ID, string _color): days(_days), ID(_ID), color(_color) {};
	void setID(string _ID){ID = _ID;}
    string getID(){return ID;}
	virtual void Print2Console() = 0;
	virtual void serviceEngine() = 0;
	virtual void serviceTransmission() = 0;
	virtual void serviceTires() = 0;
};

/*
 *	
 */

class Sedan : public Vehicle {
private:
	double trunk_cap;
	int cost = 1000;
public:
	Sedan(int _days, string _ID, string _color, double _trunk_cap) : Vehicle(_days, _ID, _color), trunk_cap(_trunk_cap) {}
	void Print2Console() {
		cout << "Car Type: \t\tSedan" << endl;
		cout << "ID: \t\t\t" << ID << endl;
		cout << "Color: \t\t\t" << color << endl;
		cout << "Trunk Capacity: \t" << trunk_cap << endl;
		cout << "Rented Days: \t\t" << days << endl;
		cout << "Total price: \t\t" << cost * days << " (USD)" << endl;
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
private:
	Dimension trunk_dim;
	int cost = 1500;
public:
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
		cout << "Total price: \t\t" << cost * days << " (USD)" << endl;
	}
	void serviceEngine() {

	}
	void serviceTransmission() {

	}
	void serviceTires() {

	}


};

class SUV : public Vehicle {
	int seats;
	int cost = 2000;
public:
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
		cout << "Total price: \t\t" << cost * days << " (USD)" << endl;
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
	int DrivingExpe;
	int carType;
	int days;
	string ID;
	string color;
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
		cout << "Your choice: "; cin >> carType;
		cout << "How many days you rented: ";
		cin >> days;
		cout << "Car's ID in the database: ";
		cin >> ID;
		cout << "Choose color: ";
		cin >> color;
	}
	void addCar() {
		cout << "Do you want to rent more car?" << endl;
		int yesno;
		cout << "Yes (1) / No (0): "; cin >> yesno;
		if(yesno == 1) {
			cout << "How many you want to rent? : ";
			int n;
			cin >> n;
			CarRentalManagement* carArr = new CarRentalManagement[n];
			for(int i = 0; i < n; i++) {
				carArr[i].name = name;
				carArr[i].age = age;
				carArr[i].ID = ID;
				carArr[i].PhoneNumber = PhoneNumber;
				carArr[i].GetRentedInfo();
				cout << "Thanks for using our service, here is your bill." << endl;
				carArr[i].PrintBill();
			}
		} else cout << "Thanks for using our service, here is your bill." << endl;
	}
	void PrintBill() {
		cout << "------------------------------------" << endl;
		cout << "             TOTAL BILL             " << endl;
		cout << "Name: \t\t\t" << name << endl;
		cout << "Age: \t\t\t" << age << endl;
		cout << "Identity number: \t" << identityNumber << endl;
		cout << "Phone number: \t\t" << PhoneNumber << endl;
		if(carType == 1) {
			int trunk_cap = 10;
			Sedan myCar(days, ID, color, trunk_cap);
			myCar.Print2Console();
		} else if(carType == 2) {
			PickUp myCar(days, ID, color);
			myCar.GetDim(1, 2, 3);
			myCar.Print2Console();
		} else if(carType == 3) {
			SUV myCar(days, ID, color, 4);
			myCar.Print2Console();
		}
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
	a.GetRentedInfo();
	a.PrintBill();
	a.addCar();

	return 0;
}
