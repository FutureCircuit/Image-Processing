#include <iostream>
#include <fstream>
#include "view.h"
#include "BMP.h"
using namespace std;

void writeData(ofstream& fout, BMPData& data) throw() {
	bmpFHeader tmp1 = data.getFHeader();
	bmpIHeader tmp2 = data.getIHeader();
	fout.write(reinterpret_cast<char*>(&tmp1), sizeof(bmpFHeader));
	fout.write(reinterpret_cast<char*>(&tmp2), sizeof(bmpIHeader));
	for (int i = 0; i < data.getColors(); i++) {
		fout.write(reinterpret_cast<char*>(&(data.getRGBQuad()[i])), sizeof(RGBQUAD));
	}

	for (int i = 0; i < data.getBmpHeight(); i++) {
		for (int j = 0; j < data.getBmpWidth(); j++) {
			fout.write(reinterpret_cast<char*>(&(data.getImgData()[i][j])), sizeof(BYTE));
		}
	}
}

int main() {
	OutputView::printProgramName();
	ifstream fin("map.bmp", ios::in | ios::binary);
	ofstream fout("copied.bmp", ios::out | ios::binary);
	BMPData img(fin);
	fin.close();
	
	while (true) {
		OutputView::printMenu();
		int menuNum;

		try {
			menuNum = InputView::inputMenuNumber();
			
			if (menuNum != EXIT_PROGRAM) {
				switch (menuNum) {
				case HISTOGRAM_EQ:
					//img.printBMPInfo();
					cout << img.getColors() << '\n';
					break;
				case CONV_FILTER:
					writeData(fout, img);
					break;
				default:
					break;
				}
			}
			else break;
		}
		catch(const char* s) {
			OutputView::printErrorMessage(s);
			cin.clear();
			cin.ignore(1000, '\n');
		}

		cout << '\n';
	}

	return 0;
}