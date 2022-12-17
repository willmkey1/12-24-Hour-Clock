#include <stdio.h>
//I use multiple methods from conio.h. I know this only supports windows, but I had a hard time figuring out portable ways to do these things
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include <string>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

//function that adds a '0' to the front of single digit values
string twoDigitString(unsigned int n) {
	//adds leading '0' if n is in range 0 to 9
	//then converts value to string
	if (n >= 0 && n < 10) {
		return '0' + to_string(n);
	}
	else {
		return to_string(n);
	}
}

//function that prints a character, c, n times
string nCharString(size_t n, char c) {
	//initializing a string printC with empty string
	string printC = "";
	//for loop that adds one char c to printC for each iteration from i = 0 to i = n-1
	for (size_t i = 0; i < n; ++i) {
		printC += c;
	}
	return printC;
}

//function that takes the h, m, and s values and formats them into 24 hr time "00:00:00"
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

//function that takes the h, m, and s values and formats them into 12 hr time "00:00:00"
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	//subtracts 12 from hour if value greater than 12
	if (h > 12) {
		h -= 12;
	}
	//sets hour to 0 if value is 12
	if (h == 0) {
		h = 12;
	}
	//reused formatTime24 here. Just needed the above if statements to make it 12 hour time
	return formatTime24(h, m, s);
}

//function that prints menu with menu options by iterating through an array of option listings of size numStrings
void printMenu(const char* strings[], unsigned int numStrings) {
	//prints upper border of menu
	cout << nCharString(15, ' ') << nCharString(26, '*') << endl;

	//iterates through and prints each string in strings[] preceded by 15 spaces to center menu
	for (unsigned int i = 0; i < numStrings; ++i) {
		cout << nCharString(15, ' ') << strings[i] << endl;
	}
	//prints lower border of menu
	cout << nCharString(15, ' ') << nCharString(26, '*') << endl;
}

//function that only accepts user input if it is an int between 1 and maxChoice
unsigned int getUserChoice(unsigned int maxChoice) {
	//declare int opt to later store user choice
	int opt;
	//do while loop that repetitively prompts user for input until it falls within range
	do {
		//assigns opt with user input
		cin >> opt;
		//if input is outside of range, erase input, prompt user again, and repeat
		if (opt < 1 || opt > maxChoice) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "Please enter 1, 2, 3, or 4." << endl;
		}
		//if input is within range, exit do while loop
		else {
			break;
		}
	} while (true);
	return opt;
}

//function that prints clock design with h, m, and s values
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	//ptints upper border of both menus separated by 5 spaces
	cout << nCharString(26, '*');
	cout << nCharString(5, ' ');
	cout << nCharString(26, '*') << endl;

	//prints second row of meun with clock titles
	cout << '*' << nCharString(6, ' ');
	cout << "12-Hour Clock";
	cout << nCharString(5, ' ') << '*';
	cout << nCharString(5, ' ') << '*';
	cout << nCharString(6, ' ');
	cout << "24-Hour Clock";
	cout << nCharString(5, ' ') << '*' << endl;

	//skips line
	cout << endl;

	//prints 12 hour clock
	cout << "*" << nCharString(6, ' ') << formatTime12(h, m, s);
	//prints "A M" if time is before 12:00
	if (h < 12) {
		cout << " A M";
	}
	//prints "P M" if time is 12:00 or later
	else {
		cout << " P M";
	}

	cout << nCharString(6, ' ') << '*';
	cout << nCharString(5, ' ') << '*';
	cout << nCharString(8, ' ');

	//prints 24 hour clock
	cout << formatTime24(h, m, s);;
	cout << "        *" << endl;

	//prints bottom border of clock
	cout << nCharString(26, '*');
	cout << nCharString(5, ' ');
	cout << nCharString(26, '*') << endl;

	cout << nCharString(12, ' ');
	//prompts user to press a key to set clock
	cout << "!!!PRESS ANY KEY TO SET CLOCK!!!" << endl;

	cout << endl;
}

/*function that progresses each interval of the clock in time and
 *resets each interval when they exceed their maximum value*/
/*pass in hr, mins, and secs by reference so function can change their values
 *(I am just learning pointers, but I think this is right :) )*/
void checkClock(unsigned int * h, unsigned int * m, unsigned int * s) {
	//if value of s reaches 60, increment value of m, and reset value of s to 0
	if (*s == 60) {
		++*m;
		*s = 0;
	}
	//if value of m reaches 60, increment value of h, and reset value of m to 0
	if (*m == 60) {
		++*h;
		*m = 0;
	}
	//if value of h reaches 24, reset value of h to 0
	if (*h == 24) {
		*h = 0;
	}
}

//increments value of s by passing it in by reference
void addSecond(unsigned int *s) {
	++*s;
}

//increments value of m by passing it in by reference
void addMinute(unsigned int *m) {
	++*m;
}

//increments value of h by passing it in by reference
void addHour(unsigned int *h) {
	++*h;
}

int main() {
	//initializing hr, mn, and sec to 0
	unsigned int hr = 0;
	unsigned int mn = 0;
	unsigned int sec = 0;
	//initializing string array menuItems[] with menu option values
	const char* menuItems[4] = {"* 1 - Add One Hour       *", "* 2 - Add One Minute     *", "* 3 - Add One Second     *", "* 4 - Exit Program       *"};
	//declaring unsigned int opt to later be assigned with value of user choice
	unsigned int opt;

	//while loop that contains entire clock functionality
	while (true) {

		//calls displayClocks() function
		displayClocks(hr, mn, sec);

		//program waits for 1 second
		sleep_for(seconds(1));

		//increments sec by one
		++sec;
		 
		//calls checkClock() function after each second to update hr, mn, and sec properly
		checkClock(&hr, &mn, &sec);

		//detects keyboard hit using _kbhit() (from the conio.h library)
		//if keyboard is hit, menu is activated
		if (_kbhit()) {
			//_getch() reads value from _kbhit(), and removes it from buffer (from the conio.h library)
			_getch();

			//print menu
			printMenu(menuItems, 4);
			
			//set opt to value obtained by getUserChoice(4)
			opt = getUserChoice(4);

			//breaks out of while loop if user enters 4
			if (opt == 4) {
				break;
			}
			
			//switch statement to increment each value based on user choice
			switch (opt)
			{
			case 1:
				addHour(&hr);
				break;
			case 2:
				addMinute(&mn);
				break;
			case 3:
				addSecond(&sec);
				break;
			default:
				break;
			}

			//update clock again after manually incrementing values
			checkClock(&hr, &mn, &sec);
		}
		/*clearing the screen using system("cls").I have read that
		this is a potential security issue, so I am not sure if I should be using it,
		but I had a hard time figuring out another way to clear the console*/
		system("cls");
	}
	return 0;
}