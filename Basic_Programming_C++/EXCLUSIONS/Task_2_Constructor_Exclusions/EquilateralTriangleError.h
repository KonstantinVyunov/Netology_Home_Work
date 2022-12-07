#pragma once
#include "GenericError.h"

class EquilateralTriangleError : public GenericError {
private:
	const char* error = "sides a, b, and c or angles A, B, and C are not equal respectively.";
public:
	const char* what() const override;
};