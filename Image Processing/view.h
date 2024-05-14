#ifndef __VIEW_H__
#define __VIEW_H__

#include <string>
using namespace std;

enum Menu {
	INPUT_FILE = 1,
	OUTPUT_FILE,
	EXIT_PROGRAM,
	MENU_NUM_RANGE
};

class InputView {
public:
	static int inputMenuNumber() throw();
	static string inputFilenameToImport();
	static string inputFilenameToExport();
};

class OutputView {
public:
	static void printProgramName();
	static void printMenu();
	static void printErrorMessage(const char* s);
	static void printErrorMessage(string s);
};

#endif