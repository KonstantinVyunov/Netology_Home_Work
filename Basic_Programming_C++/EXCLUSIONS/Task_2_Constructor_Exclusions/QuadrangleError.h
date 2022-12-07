#pragma once
#include "GenericError.h"

class QuadrangleError : public GenericError {
private:
	const char* error = "sum of angles is not 360 degree.";
public:
	const char* what() const override;
};