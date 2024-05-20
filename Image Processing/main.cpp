#include <iostream>
#include <fstream>
#include "view/inputView.h"
#include "view/outputView.h"
#include "BMP.h"
#include "io_operation.h"
#include "arithmetic_operation.h"
#include "menu.h"
using namespace std;

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