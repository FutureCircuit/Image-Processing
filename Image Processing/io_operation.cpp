#include <iostream>
#include <fstream>
#include <string>
#include "io_operation.h"
#include "view.h"
#include "BMP.h"
using namespace std;

BMPData* importFile() throw() {
	string fileName = InputView::inputFilenameToImport();
	ifstream fin(fileName, ios::in | ios::binary);
	if (fin.fail()) {
		throw "Can't import file \"" + fileName + '\"';
	}

	BMPData* img = new BMPData(fin);
	fin.close();
	return img;
}

void exportFile(BMPData* img) throw() {
	if (img == NULL) {
		throw "No imported file";
	}

	string fileName = InputView::inputFilenameToExport();
	ofstream fout(fileName, ios::out | ios::binary);
	if (fout.fail()) {
		throw "Can't export file \"" + fileName + '\"';
	}

	bmpFHeader tmp1 = img->getFHeader();
	bmpIHeader tmp2 = img->getIHeader();
	fout.write(reinterpret_cast<char*>(&tmp1), sizeof(bmpFHeader));
	fout.write(reinterpret_cast<char*>(&tmp2), sizeof(bmpIHeader));
	for (int i = 0; i < img->getColors(); i++) {
		fout.write(reinterpret_cast<char*>(&(img->getRGBQuad()[i])), sizeof(RGBQUAD));
	}

	for (int i = 0; i < img->getBmpHeight(); i++) {
		for (int j = 0; j < img->getBmpWidth(); j++) {
			fout.write(reinterpret_cast<char*>(&(img->getImgData()[i][j])), sizeof(BYTE));
		}
	}
	fout.close();
}