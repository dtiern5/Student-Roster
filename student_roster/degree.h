#ifndef DEGREE_H
#define DEGREE_H
#include <string>

/* Creating an enum for degree programs,
	adding an UNKNOWN, other values will be checked
	against it as we parse the roster */

enum DegreeProgram { UNKNOWN, SECURITY, NETWORK, SOFTWARE };

// For printing Degree Program strings, using DegreeProgram as index
static const std::string degreeProgramStrings[] = { "UNKNOWN", "SECURITY", "NETWORK", "SOFTWARE" };

#endif
