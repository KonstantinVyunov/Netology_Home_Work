#pragma once
#include "GenericError.h"

class ParallelogramError : public GenericError {
private:
	const char* error = "sides a, c and b, d are not equal respectively or angles A, C and B, D are not equal respectively.";
public:
	const char* what() const override;
};