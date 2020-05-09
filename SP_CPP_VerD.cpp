#include <iostream>
#include <string>
#define road1_speed 80
#define road2_speed 100

using namespace std;
// chars for some coices 
	char state , driver_officer_choice , plate_or_driver  ;
	/// to choose the name of driver or plate number 
	string driver_name , plate_number;
	string rcars;

//// fines struct 
struct fines
{
/// the stored fines of d1,d2,d3
	int finesd1[100] = {100};
};
///information of drivers ///////////////////
struct dinfo
{
	string name[100];
	string license_number[100];
	string birthdate[100];
	string cars[100];
	string car_plate[100];
	fines fine;
	int  car_counter = 0;
}driver;

void Register();
void search_dc(char pd);
void fine_check();
void pay_fine();

int main()
{
	do {
		cout << "      Welcome in traffic system      " << endl;
		cout << " [o] for officer \n [d] for driver \n [e] for exit \n Your choice :  ";
		cin >> state;
		//checks if the user is driver and to enter his choice
		if (state == 'D' || state == 'd') {
			cout << " [r]Register a car\n [c] Check your fines\n [p] Pay a fine\n [s] Search for a car/diver\n\n Your answer : ";
			cin >> driver_officer_choice;
			if (driver_officer_choice == 's' || driver_officer_choice == 'S') {
				//to determine how user want to search 
				cout << " [d] Driver name\n [p] car plate\n\n Your answer : ";
				cin >> plate_or_driver;
				search_dc(plate_or_driver);
			}
			/// to register a car //////////////////
			if (driver_officer_choice == 'r' || driver_officer_choice == 'R') {
				 Register();
			}
			///// to check the fines 
			if (driver_officer_choice == 'c' || driver_officer_choice == 'C') {
				fine_check();
			}
			if (driver_officer_choice == 'p' || driver_officer_choice == 'P') {
				pay_fine();
			}
				
		}
		//checks if the user is traffic officer and to enter his choice 
		if (state == 'o' || state == 'O') {
			cout << " [c] Record a fine\n [s] Search for a car/driver\n\n Your answer : ";
			cin >> driver_officer_choice;
			if (driver_officer_choice == 's' || driver_officer_choice == 'S') {
				//to determine how user want to search 
				cout << " [d] Driver name\n [p] car plate\n\n Your answer : ";
				cin >> plate_or_driver;
				search_dc(plate_or_driver);
			}
		}
	} while (state != 'e');

	return 0;
}

void Register() {
	
		cout << " Enter your name : ";
		cin >> driver_name;
		driver.name[driver.car_counter] = driver_name;
		cout << "\n Enter license number : ";
		cin >> driver.license_number[driver.car_counter];
		cout << "\n Enter Birthdate : ";
		cin >> driver.birthdate[driver.car_counter];
		do {
			if (driver.car_counter <= 3) {
				driver.name[driver.car_counter] = driver_name;
				cout << " Enter a car : ";
				cin >> rcars;
				cout << " plate number : ";
				cin >> plate_number;
				cout << endl;
				driver.cars[driver.car_counter] = rcars;
				driver.car_plate[driver.car_counter] = plate_number;
				driver.car_counter++;
			}
			else {
		     cout << "cars limit excideed\n";
			return;
	        }
			char choice;
			cout << "Do you want to register another car (y/n) : ";
			cin >> choice;
			if (choice != 'y' || choice == 'Y') {
				return;
			}
		} while (true);

	
	
}

void search_dc(char pd ) {
	char choice;
	if (pd == 'd') {
		cout << " Enter a name : ";
		cin >> driver_name;
		/// to display the driver 1 
		for (int i = 0; i < driver.car_counter; i++) {
		    if (driver_name == driver.name[i]) {
			cout << " Name : " << driver.name[i] << "\n license number : " << driver.license_number[i] << "\n Birthdate : " << driver.birthdate[i] << "\n His cars : ";
			     for (int i = 0; i < driver.car_counter; i++) {
				   cout << " " << driver.cars[i] << ",";
			     }
				 break;
			}
			else {
				cout << "\nthere's no driver with that name,please register your name ";
			}
	    }
		
	}

	if (pd == 'p') {
		cout << " Enter plate number :  ";
		cin >> plate_number;
		/////////////  display the cars of driver 1
		
	    for (int i = 0; i < driver.car_counter; i++)
		{
		     if (plate_number == driver.car_plate[i]) 
			 {
				cout << " Car : " << driver.cars[i] << "\n Fines on car : ";
				cout << " " << driver.fine.finesd1[i] << " ";
				cout  <<  "\n Owner : " << driver.name[i];	
			 } 
		}
	
	}
	cout << "\n\n Search for another car or return to main menu : (s/m)";
	cin >> choice;
	if (choice == 's') {
		//to determine how user want to search 
		cout << " [d] Driver name\n [p] car plate\n\n Your answer : ";
		cin >> pd;
		search_dc(pd);
	}
	else {
		cout << "\n\n";
		return;
	}
}

void fine_check() {
	cout << "Enter your name : "; 
	cin >> driver_name;
	
	for (int i = 0; i < driver.car_counter; i++) {
		if (driver_name == driver.name[i]) {
			cout << " " << driver.cars[i] << " fines : " << driver.fine.finesd1[i] << endl;
		}
	}
		if (driver.car_counter == 0) {
			cout << "there's no cars,please register your car.\n\n";
		}
	
	
	char choice;
	cout << "Do you want check for another one fines (y/n) : ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		fine_check();
	}
	else { cout << "\n"; return; }
	
	
}

void pay_fine() {

}


