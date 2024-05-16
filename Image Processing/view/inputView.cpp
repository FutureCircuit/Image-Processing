#include <iostream>
#include <string>
#include <cctype>
#include "inputView.h"
using namespace std;

string InputView::inputMenuNumber() {
	string s;
	cout << "Select menu: ";
	getline(cin, s);
	return s;
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