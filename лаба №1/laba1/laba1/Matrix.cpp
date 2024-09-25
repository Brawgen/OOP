#include "Matrix.h"


Matrix::Matrix() : matrix(0) // способ инициализации полей
{
}

double Matrix::pechat()
{
	return matrix+matrix;
}
