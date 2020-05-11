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
/// the stored fines of drivers
	int finesd1[100];
	string road[100];
	string date[100];
	string time[100];
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
// to count the drivers the user enters  
int person_counter=0; 

void Register();
void search_dc(char pd);
void fine_check();
void pay_fine();
void record_fine();

int main()
{
	do {
		cout << "      Welcome in traffic system      " << endl;
		if (driver.name[0]=="") {
			cout << " You must register a car before doing anything \n";
		}
		cout << " [o] for officer \n [d] for driver \n [e] for exit \n Your choice :  ";
		cin >> state;
		//checks if the user is driver and to enter his choice
		if (state == 'D' || state == 'd') {
			cout << " [r] Register a car\n [c] Check your fines\n [p] Pay a fine\n [s] Search for a car/diver\n\n Your answer : ";
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
			//// to pay fines //
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

			if (driver_officer_choice == 'c' || driver_officer_choice == 'C') {
				record_fine();
			}
		}
	} while (state != 'e');

	return 0;
}
/// to register a new driver 
void Register() {
	
		cout << " Enter your name : ";
		cin >> driver_name;
		cout << "\n Enter license number : ";
		cin >> driver.license_number[person_counter];
		cout << "\n Enter Birthdate (day/month/year) : ";
		cin >> driver.birthdate[person_counter];
		///to count the number of cars user have 
		for (int i = 0; i < person_counter; i++) {
		    if (driver_name == driver.name[i]) {
                 driver.car_counter++;
		    }
	    }
		
		do {
			if (driver.car_counter <3) {
				driver.name[person_counter] = driver_name;
				cout << " Enter a car : ";
				cin >> rcars;
				cout << " plate number : ";
				cin >> plate_number;
				cout << endl;
				driver.cars[person_counter] = rcars;
				driver.car_plate[person_counter] = plate_number;
				person_counter++;
				driver.car_counter++;
			}
			else {
		     cout << " cars limit excideed.......\n";
			 driver.car_counter = 0;
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
//to search for a driver by name or plate number of his car 
void search_dc(char pd ) {
	char choice;
	bool found = true ;
	if (pd == 'd') {
		cout << " Enter a name : ";
		cin >> driver_name;
		/// to display the driver 1 
		for (int i = 0; i <person_counter; i++) {
			if (driver_name == driver.name[i]) {
				cout << " Name : " << driver.name[i] << "\n license number : " << driver.license_number[i] << "\n Birthdate : " << driver.birthdate[i] << "\n His cars : ";
				for (int i = 0; i < person_counter; i++) {
					if (driver_name == driver.name[i]) {
						cout << " " << driver.cars[i] << ",";
					}
				}
				found = true;
				break;
			}
			else found = false;
		}
		if(!found || person_counter == 0) {
				cout << "\nthere's no driver with that name,please register your name ";
		} 	
	}

	if (pd == 'p') {
		cout << " Enter plate number :  ";
		cin >> plate_number;
		/////////////  display the cars of driver 1
		
	    for (int i = 0; i < person_counter; i++)
		{
		     if (plate_number == driver.car_plate[i]) 
			 {
				cout << " Car : " << driver.cars[i] << "\n Fines on car : ";
				cout << " " << driver.fine.finesd1[i] << " ";
				cout  <<  "\n Owner : " << driver.name[i];
				found = true;	
			 }
			 else found = false;
			 
		}
		if (!found || person_counter == 0) {
			cout << "\n there's no car with that plate number ,please register a car ";
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
//to check the fines of driver 
void fine_check() {
	cout << "Enter your name : "; 
	cin >> driver_name;
	
	for (int i = 0; i < person_counter ; i++) {
		if (driver_name == driver.name[i]) {
			cout << " " << driver.cars[i] << " fines : " << driver.fine.finesd1[i] << endl;
			if (driver.fine.finesd1[i] != 0) {
				cout << " Recorded in " << driver.fine.road[i] << " on " << driver.fine.date[i] << " at " << driver.fine.time[i] << endl;
		}
		}
	}
		if (person_counter == 0) {
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
//to pay the drivers fines 
void pay_fine() {
	int fine_payer;
	int sum_of_fines=0;
	cout << "Enter your name : ";
	cin >> driver_name;
	for (int i = 0; i < person_counter; i++) {
		if (driver_name == driver.name[i]) {
			sum_of_fines += driver.fine.finesd1[i];
		}
	}
	do {
		cout << " pay your fine : " << "( " << sum_of_fines << " ) : ";
		cin >> fine_payer;
		if (fine_payer != sum_of_fines) {
			cout << " Enter the total value.... \n";
		}
	} while (fine_payer != sum_of_fines);
	cout << " your fine paid successfully...\n\n ";
	for (int i = 0; i < person_counter; i++) {
		if (driver_name == driver.name[i]) {
		 driver.fine.finesd1[i] = 0 ;
		}
	}
}
/// to record a fine on the driver 
void record_fine() {
	char choice;
		int sum_of_fines = 0;
		int speed;
		string road;
		string date;
		string time;
		int found = 0;
	do {
		cout << " Enter a plate number : ";
		cin >> plate_number;
		cout << " enter the road : ";
		cin >> road;
		cout << " enter the speed of the car (bigger than 80 for trucks)(bigger than 100 for cars) : ";
		cin >> speed;
		cout << " Enter the date (day/month/year) : ";
		cin >> date;
		cout << " Enter the time (hour/minute) ";
		cin >> time;
		for (int i = 0; i < person_counter; i++) {
			if (plate_number == driver.car_plate[i]) {
				if (speed > road1_speed && speed < road2_speed) {
					driver.fine.finesd1[i] = 2*abs(speed - road1_speed);
					driver.fine.road[i] = road;
					driver.fine.date[i] = date;
					driver.fine.time[i] = time;
					found = 1;
				}
				if (speed > road2_speed) {
					driver.fine.finesd1[i] = 2*abs(speed - road2_speed);
					driver.fine.road[i] = road;
					driver.fine.date[i] = date;
					driver.fine.time[i] = time;
					found = 1;
				}
			
			}
			
		}
		if (found < 1 || person_counter == 0) {
			cout << " Enter a valid plate number..... \n";
		}
		else {
			cout << " the fine has been recorded successfully\n";
		}

		cout << " Do you want to fine another car (y/n) : ";
		cin >> choice;
		cout << "\n";
	} while (choice == 'y');
}



