#include "GenericError.h"

const char* GenericError::what() const { return error; }