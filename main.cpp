#include <iostream>
#include <vector>
#include "rapidjson/document.h"

using namespace std;

struct Date {
	int day;
	int month;
	int year;
	Date(int _day, int _month, int _year): day(_day), month(_month), year(_year){};
	bool operator == (Date const &that) {
		if(year == that.year && month == that.month && day == that.day)
			return true;
		else return false;
	}

	bool operator < (Date const &that) {
		if(year < that.year)
			return true;
		else if(year == that.year) {
			if(month < that.month)
				return true;
			else if(month == that.month) {
				if(day < that.day)
					return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}

	bool operator > (Date const &that) {
		if(year > that.year)
			return true;
		else if(year == that.year) {
			if(month > that.month)
				return true;
			else if(month == that.month) {
				if(day > that.day)
					return true;
				else return false;
			}
			else return false;
		}
		else return false;
	}
};

class MaintenanceJob {
protected:
	string what;
	Date when;
	string where;
	int mileage;
public:
	MaintenanceJob(string _what, int _day, int _month, int _year, string _where, int _mileage) : what(_what), when(_day, _month, _year), where(_where), mileage(_mileage) {};

	void printsth() {
		cout << what << "   ";
		cout << when.day << "/" << when.month << "/" << when.year << "   ";
		cout << where << "   ";
		cout << mileage << "   ";
	}

	int operator - (MaintenanceJob const &that) {
		return mileage - that.mileage;
	}
	bool operator == (MaintenanceJob const &that) {
		if(when == that.when)
			return true;
		else return false;
	}
	bool operator < (MaintenanceJob const &that) {
		if(when < that.when)
			return true;
		else return false;
	}
	bool operator > (MaintenanceJob const &that) {
		if(when > that.when)
			return true;
		else return false;
	}
};

struct ServiceHistory {
	string record;
	ServiceHistory(string _record) : record(_record) {};
	vector <MaintenanceJob*> JobHistory;
	void print_JobHistory() {
		int size = JobHistory.size();
		for(int i = 0; i < size; i++) {
			JobHistory[i]->printsth();
			cout << endl;
		}
	}
};

class Vehicle {
protected:
	int days;
	string ID;
	string color;
	vector <ServiceHistory*> VehicleHistory;
public:
	int cost;
	Vehicle(int _days, string _ID, string _color): days(_days), ID(_ID), color(_color) {};

	void showHistory() {
		int size = VehicleHistory.size();
		for(int i = 0; i < size; i++) {
			int _day, _month, _year, _mileage;
			string _address;
			cout << "More detailed information: " << endl;
			cout << "Job: " << VehicleHistory[i]->record << endl;
			cout << "When you did it? (dd/mm/yyyy) : ";
			cin >> _day >> _month >> _year;
			cout << "Where you did it? : ";
			cin.ignore();
			getline(cin, _address);
			cout << "How long have you traveled since the last maintenance job? : ";
			cin >> _mileage;
			MaintenanceJob* temp = new MaintenanceJob(VehicleHistory[i]->record, _day, _month, _year, _address, _mileage);
			VehicleHistory[i]->JobHistory.push_back(temp);
			cout << endl;
		}

		for(int i = 0; i < size; i++) {
			VehicleHistory[i]->print_JobHistory();
		}

	}

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
	Sedan(int _days, string _ID, string _color, double _trunk_cap) : Vehicle(_days, _ID, _color), trunk_cap(_trunk_cap) {}

	void Print2Console() {
		cout << "Car Type: \t\tSedan" << endl;
		cout << "ID: \t\t\t" << ID << endl;
		cout << "Color: \t\t\t" << color << endl;
		cout << "Trunk Capacity: \t" << trunk_cap << endl;
		cout << "Rented Days: \t\t" << days << endl;
		cost = days * 1000;
		cout << "Price: \t\t\t" << cost << " (USD)" << endl;
	}

	void serviceEngine() {
		int choice;
		cout << "This is our Engine service. What do you want for your Sedan?" << endl;
		cout << "(1.Oil change, 2.Minor, 3.Major)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Oil change");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Minor");
			VehicleHistory.push_back(temp);
		} else if(choice == 3) {
			ServiceHistory* temp = new ServiceHistory("Major");
			VehicleHistory.push_back(temp);
		}
	}

	void serviceTransmission() {
		int choice;
		cout << "This is our Transmission service. What do you want for your Sedan?" << endl;
		cout << "(1.Fluid change, 2.Minor, 3.Overhaul)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Fluid change");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Minor");
			VehicleHistory.push_back(temp);
		} else if(choice == 3) {
			ServiceHistory* temp = new ServiceHistory("Overhaul");
			VehicleHistory.push_back(temp);
		}
	}
	void serviceTires() {
		int choice;
		cout << "This is our Tires service. What do you want for your Sedan?" << endl;
		cout << "(1.Adjustment, 2.Replacement)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Adjustment");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Replacement");
			VehicleHistory.push_back(temp);
		}
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
		cout << "Price: \t\t\t" << cost << " (USD)" << endl;
	}

	void serviceEngine() {
		int choice;
		cout << "This is our Engine service. What do you want for your Pick Up?" << endl;
		cout << "(1.Oil change, 2.Minor, 3.Major)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Oil change");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Minor");
			VehicleHistory.push_back(temp);
		} else if(choice == 3) {
			ServiceHistory* temp = new ServiceHistory("Major");
			VehicleHistory.push_back(temp);
		}
	}

	void serviceTransmission() {
		int choice;
		cout << "This is our Transmission service. What do you want for your Pick Up?" << endl;
		cout << "(1.Fluid change, 2.Minor, 3.Overhaul)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Fluid change");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Minor");
			VehicleHistory.push_back(temp);
		} else if(choice == 3) {
			ServiceHistory* temp = new ServiceHistory("Overhaul");
			VehicleHistory.push_back(temp);
		}
	}

	void serviceTires() {
		int choice;
		cout << "This is our Tires service. What do you want for your Pick Up?" << endl;
		cout << "(1.Adjustment, 2.Replacement)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Adjustment");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Replacement");
			VehicleHistory.push_back(temp);
		}
	}
};

class SUV : public Vehicle {
protected:
	int seats;
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
		cost = days * 2000;
		cout << "Price: \t\t\t" << cost << " (USD)" << endl;
	}

	void serviceEngine() {
		int choice;
		cout << "This is our Engine service. What do you want for your SUV?" << endl;
		cout << "(1.Oil change, 2.Minor, 3.Major)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Oil change");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Minor");
			VehicleHistory.push_back(temp);
		} else if(choice == 3) {
			ServiceHistory* temp = new ServiceHistory("Major");
			VehicleHistory.push_back(temp);
		}
	}

	void serviceTransmission() {
		int choice;
		cout << "This is our Transmission service. What do you want for your SUV?" << endl;
		cout << "(1.Fluid change, 2.Minor, 3.Overhaul)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Fluid change");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Minor");
			VehicleHistory.push_back(temp);
		} else if(choice == 3) {
			ServiceHistory* temp = new ServiceHistory("Overhaul");
			VehicleHistory.push_back(temp);
		}
	}

	void serviceTires() {
		int choice;
		cout << "This is our Tires service. What do you want for your SUV?" << endl;
		cout << "(1.Adjustment, 2.Replacement)" << endl;
		cout << "Your choice: ";
		cin >> choice;
		if(choice == 1) {
			ServiceHistory* temp = new ServiceHistory("Adjustment");
			VehicleHistory.push_back(temp);
		} else if (choice == 2) {
			ServiceHistory* temp = new ServiceHistory("Replacement");
			VehicleHistory.push_back(temp);
		}
	}

};

class CarRentalManagement{
protected:
	string name;
	int age;
	int identityNumber;
	int PhoneNumber;
	int moreCar;
	vector <Vehicle*> Contracts;
	int TotalPrice;
	//
	double mileage;
	int engine_cond;
	int tires_cond;
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

	void AskforAmount() {
		cout << "How many car you want to rent? : ";
		cin >> moreCar;

		int carType;
		int _days;
		string _ID;
		string _color;
		for(int i = 0; i < moreCar; i++) {
			cout << "Choose the type of car you want to rent: 1.Sedan  2.PickUp  3.SUV" << endl;
			cout << "Your choice: "; 
			cin >> carType;
			cout << "How many days you rented: ";
			cin >> _days;
			cout << "Car's ID in the database: ";
			cin >> _ID;
			cout << "Choose color: ";
			cin >> _color;
			
			if(carType == 1) {
				Vehicle* temp = new Sedan(_days, _ID, _color, 10);
				Contracts.push_back(temp);
			}
			else if(carType == 2) {
				Vehicle* temp = new PickUp(_days, _ID, _color);
				Contracts.push_back(temp);
			}
			else if(carType == 3) {
				Vehicle* temp = new SUV(_days, _ID, _color, 4);
				Contracts.push_back(temp);
			}
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
		cout << "Number of cars rented: \t" << moreCar << endl;
		cout << "..." << endl;
		for(int i = 0; i < moreCar; i++) {
			Contracts[i]->Print2Console();
			TotalPrice += Contracts[i]->cost;
			cout << endl;
		}
		
		cout << "Total Price: \t\t" << TotalPrice << " (USD)" << endl;
		cout << "------------------------------------" << endl;
	}

	void ServiceFleet() {
		cout << "      Car Service       " << endl;
		for(int i = 0; i < moreCar; i++) {
			cout << "Tell us about your car[" << i + 1 << "]'s status: " << endl;
			cout << "1.Bad  2.Normal  3.Good" << endl;
			cout << "Your car's tires condition: ";
			cin >> tires_cond;
			cout << "Your car's engine condition: ";
			cin >> engine_cond;
			cout << "Traveled distance (miles): ";
			cin >> mileage;

			// TIRES' CONDITION
			cout << endl;
			if(tires_cond == 3)
				cout << "There's nothing of your cars' tires need to be adjusted" << endl;
			else if(tires_cond == 2) {
				cout << "Do you want to adjust or replace something of your cars' tires? 1.Yes  2.No" << endl;
				cout << "Your choice: ";
				int yesno; cin >> yesno;
				if(yesno == 1) {
					Contracts[i]->serviceTires();
				}
				else cout << "OK, bye!!!" << endl;
			}
			else {
				cout << "Your tires must be adjust or replace for the safety!!!" << endl;
				Contracts[i]->serviceTires();
			}

			// ENGINE'S CONDITION
			cout << endl;
			if(engine_cond == 3)
				cout << "There's nothing of your car's engine need to be adjusted" << endl;
			else if(engine_cond == 2) {
				cout << "Do you want to adjust or replace something of your car's engine? 1.Yes  2.No" << endl;
				cout << "Your choice: ";
				int yesno; cin >> yesno;
				if(yesno == 1) {
					Contracts[i]->serviceEngine();
				}
				else cout << "OK, bye!!!" << endl;
			}
			else {
				cout << "Your car's engine must be adjust or replace for the safety!!!" << endl;
				Contracts[i]->serviceEngine();
			}
			//	TRAVELED DISTANCE
			cout << endl;
			if(mileage > 3000) 
				Contracts[i]->serviceTransmission();
			else cout << "Your car is still good in transmission, comeback later!" << endl;
			cout << endl;
		}
	}

	void print_ServiceHistory() {
		for(int i = 0; i < moreCar; i++) {
			cout << "Car " << i + 1 << ":  ";
			Contracts[i]->showHistory();
			cout << endl;
		}
	}

	void Show() {
		for(int i = 0; i < moreCar; i++) {
			cout << "Car " << i + 1 << ":  " << endl;

			Contracts[i]->showHistory();
			cout << endl;
		}
	}
};



class BookandRent : public CarRentalManagement {
protected:
	Date Book_Date;
	Date Return_Date;
public:
	void setTime() {
		cout << "You want to take the car from (dd/mm/yyyy): ";
		cin >> Book_Date.day;
		cin >> Book_Date.month;
		cin >> Book_Date.year;
		
		cout << "And return at (dd/mm/yyyy): ";
		cin >> Return_Date.day;
		cin >> Return_Date.month;
		cin >> Return_Date.year;
		
		cout << "From : " << Book_Date.day << "/" << Book_Date.month << "/" << Book_Date.year;
		cout << " to " << Return_Date.day << "/" << Return_Date.month << "/" << Return_Date.year;
	}
};

int main(){
	CarRentalManagement a;
	//a.GetInfo();
	a.AskforAmount();
	//a.PrintBill();
	a.ServiceFleet();
	a.Show();

	return 0;
}