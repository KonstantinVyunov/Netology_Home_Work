#pragma once
#include "GenericError.h"

class SquareError : public GenericError {
private:
	const char* error = "sides a, c, b, d are not equal or angles A, B, C, D are not 90 degree.";
public:
	const char* what() const override;
};