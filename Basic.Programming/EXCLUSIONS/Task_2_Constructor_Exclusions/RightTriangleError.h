#pragma once
#include "GenericError.h"

class RightTriangleError : public GenericError {
private:
	const char* error = "the angle C is not 90 degree.";
public:
	const char* what() const override;
};