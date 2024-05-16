#include <iostream>
#include <fstream>
#include "view/inputView.h"
#include "view/outputView.h"
#include "BMP.h"
#include "io_operation.h"
#include "arithmetic_operation.h"
using namespace std;

int getMenuNumber(string s) throw() {
	if (s.length() != 1 || !isdigit(s[0])) {
		throw "Please input 1-digit number.";
	}

	int num = s[0] - '0';
	if (num <= 0 || num >= MENU_MAX_NUM) {
		throw "Invalid menu number.";
	}
	return num;
}

int main() {
	OutputView::printProgramName();
	BMPData* img = NULL;
	
	while (true) {
		OutputView::printMenu();
		int menuNum;

		try {
			menuNum = getMenuNumber(InputView::inputMenuNumber());
			
			if (menuNum != EXIT_PROGRAM) {
				switch (menuNum) {
				case IMPORT_FILE:
					importFile(&img);
					break;
				case ARITHMETIC_OPR:
					arithmeticOperation(&img);
					break;
				case EXPORT_FILE:
					exportFile(img);
					break;
				default:
					break;
				}
			}
			else break;
		}
		catch (const char* s) {
			OutputView::printErrorMessage(s);
		}
		catch(string s) {
			OutputView::printErrorMessage(s);
		}

		cout << '\n';
	}

	if (img != NULL) {
		delete img;
	}
	return 0;
}