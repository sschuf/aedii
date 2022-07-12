#ifndef utils
#define utils

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <limits>
#include <windows.h>

using namespace std;

extern string DEFAULT_LEFT_SPACING, DEFAULT_TOP_SPACING, DEFAULT_SPACING;
extern int DEFAULT_WAIT;

void pause() {
	cin.get();
}

int get_int() {
	string input;

	getline(cin, input);
	input = input.substr(0, 2);
	
	char* check;
	long n = strtol(input.c_str(), &check, 10);
	if (*check) return (-1);

	return n;
}

void noOption() {
	cout << DEFAULT_LEFT_SPACING;
	cout << DEFAULT_NO_OPT_ERROR_MESSAGE;
	cout << DEFAULT_BOTTOM_SPACING;
	pause();
}

void clear() {
	system("cls");
	cout << DEFAULT_TOP_SPACING;
}

void loading() {
	clear();
	for (int i=0; i<3; i++) {
		if (i%2 == 0) {
			cout << DEFAULT_LEFT_SPACING << "/";
		} else {
			cout << DEFAULT_LEFT_SPACING << "\\";	
		}
		Sleep(DEFAULT_WAIT);
		clear();
	}
}

void print(string line) {
	cout << DEFAULT_LEFT_SPACING;
	cout << line;
}

void paddingLeft() {
	cout << DEFAULT_LEFT_SPACING;
}

void breakLine() {
	cout << endl;
}

void breakLine(int n) {
	for (int i=0; i<n; i++) {
		cout << endl;
	}
}

#endif
