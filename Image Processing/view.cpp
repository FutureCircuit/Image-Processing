#include <iostream>
#include "view.h"
using namespace std;

int InputView::inputMenuNumber() throw() {
	int num;
	cout << "Select menu: ";
	cin >> num;
	if (cin.fail()) {
		throw "Please input numbers only.";
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

void OutputView::printInvalidInput() {
	cout << "Invalid number. Try again. \n";
}