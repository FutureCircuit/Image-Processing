#include <iostream>
#include <string>
#include <cctype>
#include "inputView.h"
#include "outputView.h"
using namespace std;

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