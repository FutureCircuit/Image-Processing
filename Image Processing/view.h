#ifndef __VIEW_H__
#define __VIEW_H__

#include <string>
using namespace std;

enum Menu {
	IMPORT_FILE = 1,
	ARITHMETIC_OPR,
	EXPORT_FILE,
	EXIT_PROGRAM,
	MENU_MAX_NUM
};

class InputView {
public:
	static int inputMenuNumber() throw();
	static string inputFilenameToImport();
	static string inputFilenameToExport();
};

class OutputView {
	static string menuText[MENU_MAX_NUM];
public:
	static void printProgramName();
	static void printMenu();
	static void printErrorMessage(const char* s);
	static void printErrorMessage(string s);
};

#endif