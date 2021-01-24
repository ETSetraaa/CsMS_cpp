#include <iostream>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define max 100
using namespace std;

//Class Customer
class Customer
{
public:
	char name[100];
	char address[100];
	char phone[12];
	char from_date[20];
	char to_date[20];
	float payment_advance;
	int booking_id;
};


class Car
{
public:
	char clr[100];
	char trans[100];
	char mdl[100];
	int carNumber;
	int rent;
	int status;

	class Customer cust;
	class Car addCar(int);
	void searchCar(int);
	void deleteCar(int);
	void displayCar(Car);
};

//Global Declarations
class Car cars[max];
int count = 0;


Car Car::addCar(int id)
{
	class Car car;
	car.carNumber = id;
	cout << "\nType Model of Car: ";
	cin >> car.mdl;
	cout << "\nType Color of Car: ";
	cin >> car.clr;
	cout << "\nType Transmission(Auto/Mech): ";
	cin >> car.trans;
	cout << "\nDaily Rent($): ";
	cin >> car.rent;
	car.status = 0;

	cout << "\n Car Added Successfully!";
	Sleep(1000);
	cin.get();
	return car;
}


void Car::searchCar(int id)
{
	int i, found = 0;
	for (i = 0; i < ::count; i++)
	{
		if (cars[i].carNumber == id)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		cout << "Car Details\n";
		if (cars[i].status == 1)
		{
			cout << "\nCar is Reserved";
		}
		else
		{
			cout << "\nCar is available";
		}
		displayCar(cars[i]);
		Sleep(4000);
		cin.get();
	}
	else
	{
		cout << "\nCar not found";
		Sleep(2000);
		cin.get();
	}
}

void Car::deleteCar(int)
{
}

void Car::displayCar(Car tempCar)
{
	cout << "\nCar Number: \t" << tempCar.carNumber;
	cout << "\nType AC/Non-AC (A/N) " << tempCar.mdl;
	cout << "\nType Comfort (S/N) " << tempCar.clr;
	cout << "\nType Size (B/S) " << tempCar.trans;
	cout << "\nRent: " << tempCar.rent;
}

//car management class
class CarMgnt :protected Car
{
public:
	void checkIn();
	void getAvailCar();
	void searchCustomer(char*);
	void checkOut(int);
	void guestSummaryReport();
};


void CarMgnt::guestSummaryReport() {

	if (::count == 0) {
		cout << "\n No Info!";
		Sleep(2000);
	}
	for (int i = 0; i < ::count; i++)
	{
		if (cars[i].status == 1)
		{
			cout << "\n Customer First Name : " << cars[i].cust.name;
			cout << "\n Car Number : " << cars[i].carNumber;
			cout << "\n Address (only city) : " << cars[i].cust.address;
			cout << "\n Phone : " << cars[i].cust.phone;
			cout << "\n---------------------------------------";
			Sleep(2000);
		}

	}

	cin.get();
}

//car management reservation of car
void CarMgnt::checkIn()
{
	int i, found = 0, id;

	class Car car;
	cout << "\nEnter Car ID : ";
	cin >> id;
	for (i = 0; i < ::count; i++)
	{
		if (cars[i].carNumber == id)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		if (cars[i].status == 1)
		{
			cout << "\nCar is already Booked";
			Sleep(1000);
			cin.get();
			return;
		}

		cout << "\nEnter booking id: ";
		cin >> cars[i].cust.booking_id;

		cout << "\nEnter Customer Name (First Name): ";
		cin >> cars[i].cust.name;

		cout << "\nEnter Address (only city): ";
		cin >> cars[i].cust.address;

		cout << "\nEnter Phone: ";
		cin >> cars[i].cust.phone;

		cout << "\nEnter From Date: ";
		cin >> cars[i].cust.from_date;

		cout << "\nEnter to  Date: ";
		cin >> cars[i].cust.to_date;

		cout << "\nEnter Advance Payment: ";
		cin >> cars[i].cust.payment_advance;

		cars[i].status = 1;

		cout << "\n Customer Checked-in Successfully..";
		Sleep(1000);
		cin.get();
	}
}


//car management shows available cars
void CarMgnt::getAvailCar()
{
	int i, found = 0;
	for (i = 0; i < ::count; i++)
	{
		if (cars[i].status == 0)
		{
			displayCar(cars[i]);
			Sleep(3000);
			found = 1;
			cin.get();
		}
	}
	if (found == 0)
	{
		cout << "\nAll cars are reserved";
		Sleep(1000);
		cin.get();
	}
}


//car management shows all persons that have booked car
void CarMgnt::searchCustomer(char* pname)
{
	int i, found = 0;
	for (i = 0; i < ::count; i++)
	{
		if (cars[i].status == 1 && _stricmp(cars[i].cust.name, pname) == 0)
		{
			cout << "\nCustomer Name: " << cars[i].cust.name;
			cout << "\nCar Number: " << cars[i].carNumber;

			cout << "\n\nPress enter for next record";
			found = 1;
			Sleep(2000);
			cin.get();
		}
	}
	if (found == 0)
	{
		cout << "\nPerson not found.";
		Sleep(1000);
		cin.get();
	}
}


//car managemt generates the bill of the expenses
void CarMgnt::checkOut(int carNum)
{
	int i, found = 0, days, billAmount = 0, id;
	for (i = 0; i < ::count; i++)
	{
		if (cars[i].status == 1 && cars[i].carNumber == carNum)
		{
			found = 1;
			break;
		}
	}
	if (found == 1)
	{
		cout << "\nEnter Number of Days:\t";
		cin >> days;
		billAmount = days * cars[i].rent;

		cout << "\n\t######## CheckOut Details ########\n";
		cout << "\nCustomer Name : " << cars[i].cust.name;
		cout << "\nCar Number : " << cars[i].carNumber;
		cout << "\nAddress : " << cars[i].cust.address;
		cout << "\nPhone : " << cars[i].cust.phone;
		cout << "\nTotal Amount Due : " << billAmount << " /";
		cout << "\nAdvance Paid: " << cars[i].cust.payment_advance << " /";
		cout << "\n*** Total Payable: " << billAmount - cars[i].cust.payment_advance << "/ only";

		cars[i].status = 0;
	}
	Sleep(3000);
	cin.get();
}


//managing cars (adding and searching available cars)
void manageCars()
{
	class Car car;
	int opt, id, i, flag = 0;
	char ch;
	do
	{
		system("cls");
		cout << "\n### Manage Cars ###";
		cout << "\n1. Add Car";
		cout << "\n2. Search Car";
		cout << "\n3. Back to Main Menu";
		cout << "\n\nEnter Option: ";
		cin >> opt;

		switch (opt)
		{
		case 1:
			cout << "\nEnter Car ID: ";
			cin >> id;
			i = 0;
			for (i = 0; i < ::count; i++)
			{
				if (cars[i].carNumber == id)
				{
					flag = 1;
				}
			}
			if (flag == 1)
			{
				cout << "\nCar Number is Present.\nPlease enter unique Number";
				flag = 0;
				cin.get();
			}
			else
			{
				cars[::count] = car.addCar(id);
				::count++;
			}
			break;
		case 2:
			cout << "\nEnter car ID: ";
			cin >> id;
			car.searchCar(id);
			break;
		case 3:
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 3);
}

int main()
{
	class CarMgnt cm;
	int i, j, opt, id;
	char ch;
	char pname[100];

	system("cls");

	do
	{
		system("cls");
		cout << "######## Carsharing Management System #########\n";
		cout << "\n1. Manage Cars";
		cout << "\n2. Check-In Car";
		cout << "\n3. Available Cars";
		cout << "\n4. Search Customer";
		cout << "\n5. Check-Out Car";
		cout << "\n6. Guest Summary Report";
		cout << "\n7. Exit";
		cout << "\n\nEnter Option: ";
		cin >> opt;
		switch (opt)
		{
		case 1:
			manageCars();
			break;
		case 2:
			if (::count == 0)
			{
				cout << "\nCars data is not available.\nPlease add the cars first.";
				Sleep(2000);
				cin.get();
			}
			else
				cm.checkIn();
			break;
		case 3:
			if (::count == 0)
			{
				cout << "\nCars data is not available.\nPlease add the cars first.";
				Sleep(2000);
				cin.get();
			}
			else
				cm.getAvailCar();
			break;
		case 4:
			if (::count == 0)
			{
				cout << "\nCars are not available.\nPlease add the cars first.";
				Sleep(2000);
				cin.get();
			}
			else
			{
				cout << "Enter Customer Name: ";
				cin >> pname;
				cm.searchCustomer(pname);
			}
			break;
		case 5:
			if (::count == 0)
			{
				cout << "\nCars are not available.\nPlease add the cars first.";
				Sleep(2000);
				cin.get();
			}
			else
			{
				cout << "Enter Car Number : ";
				cin >> id;
				cm.checkOut(id);
			}
			break;
		case 6:
			cm.guestSummaryReport();
			break;
		case 7:
			cout << "\nTHANK YOU! FOR USING SOFTWARE";
			break;
		default:
			cout << "\nPlease Enter correct option";
			break;
		}
	} while (opt != 7);

	cin.get();
}