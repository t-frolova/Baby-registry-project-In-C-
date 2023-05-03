//Tatiana Frolova
//08/01/2022
//Baby Registry Project, this program will help mom and friends and family and being used for baby shower and baby registry. In order to use this program you just need to click run the program and you will see instructions on the screen, you need to pick your choice and follow the instruction. Pick of your choice and who are and your role at that registry, if you would like to purchase gift or not, also will give you a time and date for the baby shower. The program will display the main menu 2 times therefore friends can get more than one option. 

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;
const int ROWS = 5;
const int COLS = 2;

void momListFunction(); 
void showMenu(); 
void friendsList();
int main() {
	
	int choice;
		
	cout << "~*~*~*~***		Welcome to Tatiana's baby registry		~*~*~*~***~\n" << endl;
	do {            
		showMenu(); 
		cin >> choice;
	
	switch (choice)
	{
	case 1:
		cout << "Your choice is 1. It is your registry. There is still something left for you in your basket. " << endl;
		cout << "\n";
		momListFunction();
		cout << "Please go to Amazon webpage to Tatiana's registry in order to purchase those items, therefore they will be shiped to your house. " << endl;
		break;
	case 2:
		cout << "Your choice is 2. That means you are a friend!" << endl;
		cout << "Thank you for being a part of this journey with us. \n" << endl;
		friendsList();
		break;
	case 3:
		cout << "Your choice is 3. That means you are stranger. " << endl;
		cout << "Sorry it is a privat registry, please exit." << endl;
		break;
	case 4:
		cout << "Your choice is 4." << endl;
		cout << "Thank you for visiting!" << endl;
	default:
		break;
	}
	} while (choice != 4);
	
	cout << endl << endl;
	system("pause");
	return 0;
}
void showMenu() {
	
		cout << "\nThe road ahead is filled with adventure. How will yours begin?" << endl;
		cout << "1. It is my registry. " << endl;
		cout << "2. I am a family friend." << endl;
		cout << "3. I think I don't know those people. " << endl;
		cout << "4. exit" << endl;
		cout << "please enter your choice 1, 2, 3, or 4 : ";
		
}
void momListFunction() {

	string Items[ROWS] = { "Baby Teething Toys", "Sensory Toy with Teether", "Muslin Baby Washcloths", "Baby Muslin Bath Towels", "Baby Bath Thermometer" };
	double itemDetail[ROWS][COLS] = { {9.90, 1}, {14.90, 1}, {1.99, 10},{11.99, 2}, {13.99, 1} };
	double totalPrice = 0, itemCounter = 0, averagePrice;

	for (int r = 0; r < ROWS; r++) {
		cout << Items[r] << " ";
		for (int c = 0; c < COLS; c++) {

			if (c == 0) {
				cout << " $ " << itemDetail[r][c];
			}
			else if (c == 1) {
				cout << " x " << itemDetail[r][c];
				itemCounter += itemDetail[r][c];
			}
		}
		cout << endl;
		totalPrice += (itemDetail[r][0] * itemDetail[r][1]);
	}
	 
	averagePrice = totalPrice / itemCounter;
	
	cout << "\nHere is a short summary of your shopping basket:" << endl;
	cout << "The average price for all your " << itemCounter << " items is : $ " << setprecision(2) << fixed << averagePrice << endl;
	cout << "Total price for all your items is: $" << totalPrice << setprecision(2) << fixed << endl;
	
	ofstream outputFile; 

	outputFile.open("output.txt");
	if (outputFile.is_open()) {
		cout << "File is opened" << endl;
	}
	else {
		cout << "file is not opened";
	}
	outputFile << "\nHere is a short summary of your shopping basket:" << endl;
	outputFile << "The average price for all your " << itemCounter << " items is : $ " << setprecision(2) << fixed << averagePrice << endl;
	outputFile << "Total price for all your items is: $" << totalPrice << setprecision(2) << fixed << endl;

	outputFile.close();
}
void friendsList() {
	double friendPrice;
	double babyGym = 50.99;
	double pillow = 45.00;
	double babyNursery = 150.00;
	int friendChoice;
	char ch;

		cout << "Please see your options: " << endl;
		cout << "1. Washable Baby Gym Activity Center with Animal Play Mat and baby gym, the price is $50.99" << endl;
		cout << "2. Pregnancy Pillows, U Shaped Full Body Maternity, the price is $45.00 " << endl;
		cout << "3. Baby nursery Center, the price is $ 150.00" << endl;
		cout << "4. exit";
		cout << "\n";
		
		cout << "Would you like to puchice item for Tatiana? Enter 'Y' for yes, or 'N' for no. Please enter your choice: ";
		cin >> ch;
	
	if (ch == 'Y') {
		cout << "You can purchase any item from the list. Please enter option 1, 2, or 3. ";
		cin >> friendChoice;
		if (friendChoice == 1) {
			cout << "Your choice is a washable baby gym activity center with an animal play mat, the price is $ " << babyGym << " Please go to Amazon webpage to Tatiana's registry in order to purchase and ship that item." << endl;
			cout << "\nWe will see you at the Baby shower on September 30th at 12:00 pm. Please see the invitation for the address.  " << endl;
			cout << "Thank you for being our friend and being with us on that journey! We really appreciate this!" << endl;
		}
		else if(friendChoice == 2) {
			cout << "Your choice is a Pregnancy Pillows, U Shaped Full Body Maternity, the price is $ " << pillow << " Please go to Amazon webpage to Tatiana's registry in order to purchase and ship that item. " << endl;
			cout << "\nWe will see you at the Baby shower on September 30th at 12:00 pm. Please see the invitation for the address. " << endl;
			cout << "Thank you for being our friend and being with us on that journey! We really appreciate this!" << endl;
		}
		else if (friendChoice == 3) {
			cout << "Your choice is a Baby nursery Center, the price is $ " << babyNursery << " Please go to Amazon webpage to Tatiana's registry in order to purchase and ship that item." << endl;
			
			cout << "Would you like to share that cost with your other friend? Please enter Y for yes, or N for no: ";
			cin >> ch;
			if (ch == 'Y') {
				cout << "You choose to split the cost with another friend, please pay on checkout $ " << babyNursery / 2 << " Please go to Amazon webpage to Tatiana's registry to see following instruction in order to purchase and ship that item."<< endl;
			}
			else if (ch == 'N') {
				cout << "You choose to pay full price for Baby nursery Center, the price is $ " << babyNursery << " Please go to Amazon webpage to Tatiana's registry in order to purchase and ship that item." << endl;
				}
			cout << "\nWe will see you at the Baby shower on September 30th at 12:00 pm. Please see the invitation for the address. " << endl;
			cout << "Thank you for being our friend and being with us on that journey! We really appreciate this!" << endl;
		}
		
	}
	else if (ch == 'N') { 
			
		ifstream input;  
		string message;

		input.open("input.txt");
		if (input.is_open()) {
			cout << "File is opened" << endl;
		}
		else {
			cout << "file is not opened";
		}
		cout << "read data from file" << endl;
		while (input >> message) {
			cout << message << " ";
		}

		input.close();
		cout << "\nWe will see you at the Baby shower on September 30th at 12:00 pm. Please see the invitation for the address." << endl;
		cout << "Thank you for being our friend and being with us on that journey! We really appreciate this!" << endl;
	}
	
}