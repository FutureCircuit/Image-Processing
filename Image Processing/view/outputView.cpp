#include <iostream>
#include <string>
#include <cctype>
#include "outputView.h"
using namespace std;

string OutputView::menuText[MENU_MAX_NUM] = {
	"",
	"Import File",
	"Arithmetic Operation",
	"Export File",
	"Exit"
};

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