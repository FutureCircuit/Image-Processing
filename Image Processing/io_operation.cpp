#include <iostream>
#include <fstream>
#include <string>
#include "io_operation.h"
#include "view/inputView.h"
#include "BMP.h"
using namespace std;

void importFile(BMPData** img) throw() {
	if (*img != NULL) {
		delete[] *img;
	}

	string fileName = InputView::inputFilenameToImport();
	ifstream fin(fileName, ios::in | ios::binary);
	if (!fin) {
		string s = "Can't import file \"" + fileName + '\"';
		throw s;
	}

	*img = new BMPData(fin);
	fin.close();
}

void exportFile(BMPData* img) throw() {
	if (img == NULL) {
		throw "No imported file";
	}

	string fileName = InputView::inputFilenameToExport();
	ofstream fout(fileName, ios::out | ios::binary);
	if (!fout) {
		string s = "Can't export file \"" + fileName + '\"';
		throw s;
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