#include <iostream>
#include <string>
#include <cctype>
#include "view.h"
using namespace std;

string OutputView::menuText[MENU_MAX_NUM] = {
	"",
	"Import File",
	"Arithmetic Operation",
	"Export File",
	"Exit"
};

int InputView::inputMenuNumber() throw() {
	string s;
	cout << "Select menu: ";
	getline(cin, s);
	
	if (s.length() != 1 || !isdigit(s[0])) {
		throw "Please input 1-digit number.";
	}

	int num = s[0] - '0';
	if (num <= 0 || num >= MENU_MAX_NUM) {
		throw "Invalid menu number.";
	}
	return num;
}

string InputView::inputFilenameToImport() {
	string fileName;
	cout << "Enter the file name to import: ";
	getline(cin, fileName);
	return fileName;
}

string InputView::inputFilenameToExport() {
	string fileName;
	cout << "Enter the file name to export: ";
	getline(cin, fileName);
	return fileName;
}

void OutputView::printProgramName() {
	cout << "Image Processing Program ver.1.0.0 \n";
}

void OutputView::printMenu() {
	for (int i = 1; i < MENU_MAX_NUM; i++) {
		cout << i << ". " << menuText[i] << '\n';
	}
}

void OutputView::printErrorMessage(const char* s) {
	cout << "Error: " << s << '\n';
}

void OutputView::printErrorMessage(string s) {
	cout << "Error: " << s << '\n';
}