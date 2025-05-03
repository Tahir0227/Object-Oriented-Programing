#include<iostream>
#include<vector>

using namespace std;

class Vehicle{
	public:
		string vehicleID;
		string make;
		string model;
		int year;
		bool isRented;
		double dailyRentalCost;
		
		Vehicle(){
			vehicleID = "\0";
			make = "\0";
			model = "\0";
			year = 0;
			isRented = false;
			dailyRentalCost = 0;
		}
		
		Vehicle(string vehicleID, string make, string model, int year, bool isRented, double dailyRentalCost){
			this->vehicleID = vehicleID ;
			this->make = make;
			this->model = model;
			this->year = year;
			this->isRented = isRented;
			this->dailyRentalCost = dailyRentalCost;
		}
		
		virtual double calculateRentalCost(int days) = 0; 
		
		virtual void displayDetails(){
			cout << "VehicleID = " << vehicleID << endl ;
			cout << "Make = "  << make << endl ;
			cout << "Model = "  << model << endl ;
			cout << "Year = "  << year << endl ;
			cout << "Is Rented = "  << isRented << endl ;
			cout << "Daily Rental Cost = "  << dailyRentalCost << endl ;
		}
		
		void rentVehicle(){
			isRented = true;
		}
		
		void returnVehicle(){
			isRented = false;
		}
};

class Car : public Vehicle{
	public:
		int numberOfDoors;
		string fuelType;
		double total_cost;
		
		Car(string vehicleID, string make, string model, int year, double dailyRentalCost, int doors, string fuel)
    	: Vehicle(vehicleID, make, model, year, false, dailyRentalCost) {
       		 numberOfDoors = doors;
        		fuelType = fuel;
		}
		
		double calculateRentalCost(int days){
			total_cost = dailyRentalCost * days ;
			return total_cost;
		}
		
		void displayDetails(){
			Vehicle::displayDetails();
			cout << "Number Of Doors = "   << numberOfDoors <<endl;
			cout << "Fuel Type = "   << fuelType <<endl <<endl ;
		}
};

class Motorcycle : public Vehicle{
	public:
	    string engineType;
		bool hasSidecar;
		double total_cost;
		
		Motorcycle(string vehicleID, string make, string model, int year, double dailyRentalCost, string engineType, bool hasSidecar)
    	: Vehicle(vehicleID, make, model, year, false, dailyRentalCost) { // Fix: added `false`
      		  this->engineType = engineType;
       		 this->hasSidecar = hasSidecar;
		}
		
		double calculateRentalCost(int day){
			total_cost = dailyRentalCost * day+(hasSidecar ? 20 * day : 0 );
			return total_cost;
		}
		
		void displayDetails(){
			Vehicle::displayDetails();
			cout << "Engine Type = "  << engineType <<endl;
			cout << "Has Sidecar = "  << hasSidecar <<endl <<endl;
		}
};

class Truck : public Vehicle{
	public:
	    double cargoCapacity ;
		int numberOfAxles;
		double total_cost;
		
		Truck(string vehicleID, string make, string model, int year, double dailyRentalCost, double cargoCapacity, int axles)
    	: Vehicle(vehicleID, make, model, year, false, dailyRentalCost) { // Fix: added `false`
     		   this->cargoCapacity = cargoCapacity;
       		   this->numberOfAxles = axles;
		}
		
		double calculateRentalCost(int day){
			total_cost = dailyRentalCost * day+(cargoCapacity * 10 *day);
			return total_cost;
		}
		
		void displayDetails(){
			Vehicle::displayDetails();
			cout << "Cargo Capacity = "  << cargoCapacity <<endl;
			cout << "Number Of Axles = "  << numberOfAxles <<endl <<endl;
		}
};

class RentalSystem{
	private:
		vector<Vehicle*> vehicles;
		
	public:
		
		void addVehicle(Vehicle *obj){
			vehicles.push_back(obj);
		}
		
		void displayAvailableVehicle(){
			for (size_t i=0; i<vehicles.size(); i++) { 
    			if (!vehicles[i]->isRented) { 
        			vehicles[i]->displayDetails(); 
    			} 
			}
		}
		
		Vehicle* findVehicle(string ID){
			for (size_t i=0; i<vehicles.size(); i++) { 
    			if (vehicles[i]->vehicleID == ID) { 
        			return  vehicles[i];
    			} 
			}
			return 0;
		}
		
		void rentVehicle(string ID, int days){
			Vehicle *obj = findVehicle(ID);
			
			if(!obj->isRented){
				obj->rentVehicle();
				cout << "Vehicle rented for " <<days <<" days. Total cost: " <<obj->calculateRentalCost(days) <<endl <<endl;				
			}
			else
				cout << "Vehicle not found or already rented" <<endl <<endl;
		}
		
		void returnVehicle(string ID){
			Vehicle *obj = findVehicle(ID);
	
			if(obj->isRented){
				obj->returnVehicle();
				cout << "Vehicle returned successfully!" <<endl <<endl;
			}
			else
				cout << "Vehicle not found or already rented" <<endl <<endl;
		}
		
		~RentalSystem(){
    		for (size_t i = 0; i < vehicles.size(); i++) {
        		delete vehicles[i];
    		}
		}

};

int main(){
	RentalSystem rentalSystem;
	
	rentalSystem.addVehicle(new Car("C1", "Toyota", "Corolla", 2020, 50, 4, "Gasoline"));
    rentalSystem.addVehicle(new Car("C2", "Honda", "Civic", 2019, 45, 4, "Gasoline"));
    rentalSystem.addVehicle(new Motorcycle("M1", "Yamaha", "R1", 2021, 40, "1000cc", false));
    rentalSystem.addVehicle(new Motorcycle("M2", "Harley", "Sportster", 2018, 35, "1200cc", true));
    rentalSystem.addVehicle(new Truck("T1", "Ford", "F-150", 2022, 100, 5.0, 2));
	
	int choice;
	string vehicleID;
	int days;
	
	while(1){
		cout << "----------------------------------\nMenu" <<endl;
		cout << "1.Display available vehicles" <<endl;
		cout << "2.Rent a vehicle" <<endl;
		cout << "3.Return a vehicle" <<endl;
		cout << "4.Find a Vehicle and Display its details" <<endl;
		cout << "5.Exit" <<endl <<endl;
		
		cout << "Enter Your Choice:";
		cin >> choice ;
		
		switch(choice){
			case 1 :
				rentalSystem.displayAvailableVehicle();
				break;
				
			case 2 :
				cout <<"Enter vehicle ID: ";
				cin >> vehicleID;
				cout <<"Enter no of days:";
				cin >> days;
				rentalSystem.rentVehicle(vehicleID, days);
				break; 
				
			case 3 :
				cout << "Enter vehicle ID to return: ";
                cin >> vehicleID;
                rentalSystem.returnVehicle(vehicleID);
				break; 
				
			case 4 :
				cout <<"Enter vehicle ID to find: ";
                cin >> vehicleID;
                
                Vehicle* obj;
                obj = rentalSystem.findVehicle(vehicleID);
                if(obj) 
					obj->displayDetails();
                else 
					cout << "Vehicle not found!" <<endl;
                
				break; 
				
			case 5 : return 0;
				break;
				  
		}
	}
}

