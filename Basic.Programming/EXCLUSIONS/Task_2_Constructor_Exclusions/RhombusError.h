#pragma once
#include "GenericError.h"

class RhombusError : public GenericError {
private:
	const char* error = "sides a, b, c, d are not equal or angles A, C and B, D are not equal respectively.";
public:
	const char* what() const override;
};