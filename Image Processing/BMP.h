#ifndef __BMP_H__
#define __BMP_H__

#include <Windows.h>
#include <fstream>
#define WIDTHBYTES(bits)	(((bits) + 31) / 32 * 4)
using bmpFHeader = BITMAPFILEHEADER;
using bmpIHeader = BITMAPINFOHEADER;
using namespace std;

class BMPData {
	bmpFHeader fh;
	bmpIHeader ih;
	RGBQUAD* rgb;
	BYTE** imgData;
	int colors;
	int bmpWidth;
	int bmpHeight;
public:
	BMPData(ifstream& fin) throw();
	~BMPData();
	bmpFHeader getFHeader();
	bmpIHeader getIHeader();
	RGBQUAD* getRGBQuad();
	BYTE** getImgData();
	int getColors();
	int getBmpWidth();
	int getBmpHeight();
	void printBMPInfo();
};

#endif