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
	//// to determine if the fine is baid or not 
	bool paid = false ;

//// fines struct 
struct fines
{
/// the stored fines of drivers
	int finesd1[200];
	string road[200];
	string date[200];
	string time[200];
	string plate[200];
	int fine_index=0;
}fine;
///information of drivers ///////////////////
struct dinfo
{
	string name[200];
	string license_number[200];
	string birthdate[200];
	string cars[200];
	string car_plate[200];
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
	
		cout << " Enter your name (without spaces) : ";
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
			
			return;
	        }
			
			char choice;
			cout << "Do you want to register another car (y/n) : ";
			cin >> choice;
			if (choice != 'y' || choice == 'Y') {
				driver.car_counter = 0;
				return;
			}
		} while (true);
        
	
	
}
//to search for a driver by name or plate number of his car 
void search_dc(char pd ) {
	char choice;
	bool found = true ;
	int cnt = 0;
	if (pd == 'd') {
		cout << " Enter a name : ";
		cin >> driver_name;
		/// to display the driver 1 
		for (int i = 0; i <=person_counter; i++) {
			if (driver_name == driver.name[i]) {
				cout << " Name : " << driver.name[i] << "\n license number : " << driver.license_number[i] << "\n Birthdate : " << driver.birthdate[i] << "\n His cars : ";
				for (int i = 0; i < person_counter; i++) {
					if (driver_name == driver.name[i]) {
						if (driver.cars[i] != "") {
							cout << " " << driver.cars[i] << ",";
						}
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
		int sum_fine = 0;
	    for (int i = 0; i < person_counter; i++)
		{
		     if (plate_number == driver.car_plate[i]) 
			 {
				cout << " Car : " << driver.cars[i] << "\n Fines on car : ";
				for (int j = 0; j < fine.fine_index; j++) {
					if (driver.car_plate[i] == fine.plate[j]) {
						sum_fine += fine.finesd1[j];
						
					}
				}
				cout << " " << sum_fine << " ";
				cout  <<  "\n Owner : " << driver.name[i];
				
			 }	 
		}
		//// to check if the plate number is found in the system 
		for (int i = 0; i < person_counter; i++)
		{
			if (plate_number == driver.car_plate[i])
			{
				cnt++;
				break;
			}
		}
		if (cnt<1|| person_counter == 0) {
			cout << "\n there's no car with that plate number ,please register a car ";
		}sum_fine = 0;
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
	cout << " Enter your name : "; 
	cin >> driver_name;
	int found = 0;
	for (int i = 0; i < person_counter ; i++) {
		if (driver_name == driver.name[i]) {
			for (int j = 0; j < fine.fine_index; j++) {
				if (driver.car_plate[i] == fine.plate[j]) {
					if (fine.finesd1[j] == 0) {
						paid = true;
					}
					if (!paid) {
					cout << " " << driver.cars[i] << " fines : " << fine.finesd1[j] << endl;
					cout << " Recorded in " << fine.road[j] << " on " << fine.date[j] << " at " << fine.time[j] << endl;
					}
					else {
						cout << " " << driver.cars[i] << " fines : " << fine.finesd1[j] << " (paid) "<< endl;
						cout << " Recorded in " << fine.road[j] << " on " << fine.date[j] << " at " << fine.time[j] << endl;
					}
					paid = false;
					found++;
				}
			}
		}
	}
	 if (found==0) {
			cout << " There's no fines on you.... \n\n";
			return;
		}
	
	char choice;
	cout << "Do you want to pay your fine (y/n) : ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y') {
		pay_fine();
	}
	else { cout << "\n";  }
	
	
}
//to pay the drivers fines 
void pay_fine() {
	int fine_payer;
	int sum_of_fines=0;
	cout << "Enter your name : ";
	cin >> driver_name;
	for (int i = 0; i <= person_counter; i++) {
		if (driver_name == driver.name[i]) {
			for (int j = 0; j < fine.fine_index; j++) {
				if (driver.car_plate[i] == fine.plate[j]) {
					sum_of_fines += fine.finesd1[j];
				}
				
			}
		}
	}
	do {
		if (sum_of_fines > 0) {
			cout << " pay your fine : " << "( " << sum_of_fines << " ) : ";
			cin >> fine_payer;
			if (fine_payer != sum_of_fines) {
				cout << " Enter the right value.... \n";
			}
		}
		else { cout << " There's no fines on you.... \n\n"; return; }
	} while (fine_payer != sum_of_fines);
	cout << " your fine paid successfully...\n\n ";
	for (int i = 0; i <= person_counter; i++) {
		if (driver_name == driver.name[i]) {
			for (int j = 0; j < fine.fine_index; j++) {
				if (driver.car_plate[i] == fine.plate[j]) {
					 fine.finesd1[j]=0;
				}
			}
		}
	}
	sum_of_fines = 0;
}
/// to record a fine on the driver 
void record_fine() {
	char choice;
		int speed,found = 0 ;
		string road,name,car,date,time;
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
					fine.plate[fine.fine_index] = plate_number;
					fine.finesd1[fine.fine_index] = 2 * abs(speed - road1_speed);
					fine.road[fine.fine_index] = road;
					fine.date[fine.fine_index] = date;
					fine.time[fine.fine_index] = time;
					fine.fine_index++;
		        }

				if (speed > road2_speed) {
					fine.plate[fine.fine_index] = plate_number;
					fine.finesd1[fine.fine_index] = 2 * abs(speed - road2_speed);
					fine.road[fine.fine_index] = road;
					fine.date[fine.fine_index] = date;
					fine.time[fine.fine_index] = time;
					fine.fine_index++;
				}
			}	
		}
		//to check if the plate number is saved in the system or not /////////
		for (int i = 0; i < person_counter; i++) {
			if (plate_number == driver.car_plate[i]) {
				found = 1;
				break;
			}
			else {
				found = 0;
			}
		}
        
		if (found<1 || person_counter == 0) {
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



