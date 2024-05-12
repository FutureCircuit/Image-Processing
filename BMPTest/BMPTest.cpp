#include "pch.h"
#include "CppUnitTest.h"
#include "../Image Processing/BMP.h"
#include <fstream>
using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BMPTest
{
	TEST_CLASS(BMPTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			ifstream fin("C:\\Users\\user\\source\\repos\\Image Processing\\Image Processing\\map.bmp", ios::in | ios::binary);
			BMPData data(fin);
			Assert::AreEqual(256, data.getColors());
		}
	};
}
