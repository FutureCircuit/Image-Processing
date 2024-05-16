#ifndef __INPUTVIEW_H__
#define __INPUTVIEW_H__

#include <string>
using namespace std;

class InputView {
public:
	static int inputMenuNumber() throw();
	static string inputFilenameToImport();
	static string inputFilenameToExport();
};

#endif