#pragma once
#include <exception>

class GenericError : public std::exception {
private:
	const char* error = "Reason: generic error.";
public:
	const char* what() const override;
};