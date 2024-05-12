#ifndef __VIEW_H__
#define __VIEW_H__

enum Menu {
	HISTOGRAM_EQ = 1,
	CONV_FILTER,
	EXIT_PROGRAM
};

class InputView {
public:
	static int inputMenuNumber() throw();
	static const char* inputFileName();
};

class OutputView {
public:
	static void printProgramName();
	static void printMenu();
	static void printInvalidInput();
};

#endif