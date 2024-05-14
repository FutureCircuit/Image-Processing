#ifndef __IO_OPERATION_H__
#define __IO_OPERATION_H__

#include "BMP.h"

BMPData* importFile() throw();
void exportFile(BMPData* img) throw();

#endif