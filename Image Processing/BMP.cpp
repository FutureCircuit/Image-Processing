#include "pch.h"
#include <iostream>
#include <fstream>
#include "BMP.h"
using namespace std;

BMPData::BMPData(ifstream& fin) throw() {
	fin.read(reinterpret_cast<char*>(&(this->fh)), sizeof(bmpFHeader));
	fin.read(reinterpret_cast<char*>(&(this->ih)), sizeof(bmpIHeader));
	this->colors = 1 << (this->ih.biBitCount);
	this->rgb = new RGBQUAD[this->colors];
	for (int i = 0; i < this->colors; i++) {
		fin.read(reinterpret_cast<char*>(&(this->rgb[i])), sizeof(RGBQUAD));
	}

	this->bmpWidth = WIDTHBYTES(this->ih.biWidth * this->ih.biBitCount);
	this->bmpHeight = this->ih.biHeight;

	this->imgData = new BYTE * [this->bmpHeight];
	for (int i = 0; i < this->bmpHeight; i++) {
		(this->imgData)[i] = new BYTE[this->bmpWidth];
		for (int j = 0; j < this->bmpWidth; j++) {
			fin.read(reinterpret_cast<char*>(&(this->imgData)[i][j]), sizeof(BYTE));
		}
	}
}

BMPData::~BMPData() {
	delete[] this->rgb;
	for (int i = 0; i < this->bmpHeight; i++) {
		delete[] (this->imgData)[i];
	}
	delete[] this->imgData;
}

bmpFHeader BMPData::getFHeader() {
	return this->fh;
}

bmpIHeader BMPData::getIHeader() {
	return this->ih;
}

RGBQUAD* BMPData::getRGBQuad() {
	return this->rgb;
}

BYTE** BMPData::getImgData() {
	return this->imgData;
}

int BMPData::getColors() {
	return this->colors;
}

int BMPData::getBmpWidth() {
	return this->bmpWidth;
}

int BMPData::getBmpHeight() {
	return this->bmpHeight;
}

void BMPData::printBMPInfo() {
	cout << hex << this->fh.bfType << '\n' << dec << this->fh.bfSize << '\n';
	cout << this->fh.bfReserved1 << '\n' << this->fh.bfReserved2 << '\n' << this->fh.bfOffBits << "\n\n";

	cout << this->ih.biSize << '\n' << this->ih.biWidth << '\n' << this->ih.biHeight << '\n';
	cout << this->ih.biPlanes << '\n' << this->ih.biBitCount << '\n' << this->ih.biCompression << '\n';
	cout << this->ih.biSizeImage << '\n' << this->ih.biXPelsPerMeter << '\n' << this->ih.biYPelsPerMeter << '\n';
	cout << this->ih.biClrUsed << '\n' << this->ih.biClrImportant << '\n';

	for (int i = 0; i < this->colors; i++) {
		cout << this->rgb[i].rgbBlue << ' ' << this->rgb[i].rgbGreen << ' ' << this->rgb[i].rgbRed << '\n';
	}
}