#include <iostream>
#include <fstream>
#include "view.h"
#include "BMP.h"
#include "io_operation.h"
using namespace std;

int main() {
	OutputView::printProgramName();
	BMPData* img = NULL;
	
	while (true) {
		OutputView::printMenu();
		int menuNum;

		try {
			menuNum = InputView::inputMenuNumber();
			
			if (menuNum != EXIT_PROGRAM) {
				switch (menuNum) {
				case INPUT_FILE:
					img = importFile();
					break;
				case OUTPUT_FILE:
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

	return 0;
}