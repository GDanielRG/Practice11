//Gerardo Daniel Rodriguez
//A01036056
//Convert practice

#include "Convert.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

//Responsible for converting a string binary number in ascii to an integer
//Params: 
//	-asci: The string in ascii that contains the binary number
//Returns:
//	-iResult: integer containing the result

int asciiBinaryToInt(char *asci) 
{
	int iResult = 0;
	while ((*asci) && ((*asci == '1') || (*asci == '0'))) 
	{
		iResult *= 2;
		iResult += (*asci - '0');
		asci++;
	}

	return iResult;

}

//Responsible for converting a string hexadecimal number in ascii to an integer
//Params: 
//	-asci: The string in ascii that contains the hexadecimal number
//Returns:
//	-iResult: integer containing the result

int asciiHEXToInt(char *asci) 
{
	int iResult = 0;

	while ((*asci) && (((*asci >= '0') && (*asci <= '9')) || ((*asci >= 'A') && (*asci <= 'F')) || ((*asci >= 'a') && (*asci <= 'f')))) 
	{
		*asci = (char)toupper(*asci);
		iResult *= 16;
		if ((*asci >= '0') && (*asci <= '9'))
			iResult += (*asci - '0');
		else if ((*asci >= 'A') && (*asci <= 'F'))
			iResult += (*asci - '7');
		asci++;
	}

	return iResult;
}

//Responsible for converting a string number in ascii to a double
//Params: 
//	-asci: The string in ascii that contains the string number
//Returns:
//	-dResult: double containing the result
double asciiToDouble(char *asci) {
	int iPos = 1;
	double dResult = 0;
	int iPow = 1;
	double dAft = 0.0;

	if (*asci == '-') 
	{
		iPos = 0;
		asci++;
	}
	else if (*asci == '+') 
	{
		iPos = 1;
		asci++;
	}

	while (*asci != '.' || ((*asci >= '0') && (*asci <= '9'))) 
	{
		dResult *= 10;
		dResult += (*asci - '0');
		asci++;
	}

	while (*asci == '.' || ((*asci >= '0') && (*asci <= '9'))) 
	{
		if ((*asci >= '0') && (*asci <= '9')) 
		{
			dAft = dAft + ((*asci - '0') / pow(10.0, iPow));
			iPow++;
		}
		asci++;
	}

	dResult = dResult + dAft;

	if (!iPos)
		dResult = -dResult;

	return dResult;
}


