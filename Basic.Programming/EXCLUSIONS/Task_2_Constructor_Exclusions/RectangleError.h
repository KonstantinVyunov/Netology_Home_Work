#pragma once
#include "GenericError.h"

class RectangleError : public GenericError {
private:
	const char* error = "sides a, c and b, d are not equal respectively or angles A, B, C, D are not 90 degree.";
public:
	const char* what() const override;
};