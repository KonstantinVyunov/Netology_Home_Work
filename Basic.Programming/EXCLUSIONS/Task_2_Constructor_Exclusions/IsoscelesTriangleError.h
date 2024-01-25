#pragma once
#include "GenericError.h"

class IsoscelesTriangleError : public GenericError {
private:
	const char* error = "sides a and c or angles A and C are not equal respectively.";
public:
	const char* what() const override;
};