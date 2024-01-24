#pragma once
#include "GenericError.h"

class TriangleError : public GenericError {
private:
	const char* error = "sum of angles is not 180 degree.";
public:
	const char* what() const override;
};