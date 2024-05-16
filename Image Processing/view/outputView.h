#ifndef __OUTPUTVIEW_H__
#define __OUTPUTVIEW_H__

#include <string>
using namespace std;

enum Menu {
	IMPORT_FILE = 1,
	ARITHMETIC_OPR,
	EXPORT_FILE,
	EXIT_PROGRAM,
	MENU_MAX_NUM
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