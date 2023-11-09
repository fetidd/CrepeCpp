#include "Error.h"

bool operator== (const ErrorType& lhs, const ErrorType& rhs) { return lhs.code() == rhs.code(); }