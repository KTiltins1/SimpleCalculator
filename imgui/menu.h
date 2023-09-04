#pragma once
#include "imgui/imgui.h"	// uses: ImGui namespace
#include <string>			// uses: std::string
#include <cctype>			// uses: std::isdigit
#include "hash/xorstr.h"	// uses: hashing strings 

namespace C
{
	void RenderCalculator();

	// needs a recode
	__forceinline double CalculateStringToFloat(const std::string& strExp)
	{
		// variables
		double dbResult = 0.0;
		double dbNumber = 0.0;
		char szChar = '+';
		bool bNextIsNegative = false;

		// todo: replace else if's to switch cases maybe
		for (char ch : strExp)
		{
			if (std::isdigit(ch))
				dbNumber = dbNumber * 10 + (ch - '0');
			else if (ch == '*' || ch == '/' || ch == '+' || ch == '-') {

				if (bNextIsNegative)
				{
					dbNumber = -dbNumber;
					bNextIsNegative = false;
				}

				if (szChar == '*')
					dbResult *= dbNumber;
				else if (szChar == '/')
					dbResult /= dbNumber;
				else if (szChar == '+')
					dbResult += dbNumber;
				else if (szChar == '-')
					dbResult -= dbNumber;

				szChar = ch;
				dbNumber = 0;
			}

			// todo: add support for parentheses
			// else if (ch == '(') {}
			// else if (ch == ')') {}

			else if (ch == '-')
				// Handle negative numbers
				bNextIsNegative = true;
		}

		// Handle the last number in the expression
		if (bNextIsNegative)
			dbNumber = -dbNumber;

		if (szChar == '*')
			dbResult *= dbNumber;
		else if (szChar == '/')
			dbResult /= dbNumber;
		else if (szChar == '+')
			dbResult += dbNumber;
		else if (szChar == '-')
			dbResult -= dbNumber;

		return dbResult;
	}

}

