#include <iostream>
#include <string>
#include <cctype>
#include "view.h"
using namespace std;

int InputView::inputMenuNumber() throw() {
	string s;
	cout << "Select menu: ";
	getline(cin, s);
	
	if (s.length() != 1 || !isdigit(s[0])) {
		throw "Please input 1-digit number.";
	}

	int num = s[0] - '0';
	if (num <= 0 || num >= MENU_NUM_RANGE) {
		throw "Invalid menu number.";
	}
	return num;
}

const char* InputView::inputFileName() {
	char fileName[30];
	cout << "Input file name: ";
	cin >> fileName;
	return fileName;
}

void OutputView::printProgramName() {
	cout << "Image Processing Program ver.1.0.0 \n";
}

void OutputView::printMenu() {
	cout << "1. Histogram Equalization \n";
	cout << "2. Convolution Filter \n";
	cout << "3. Exit \n";
}

void OutputView::printErrorMessage(const char* s) {
	cout << "Error: " << s << '\n';
}