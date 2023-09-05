#pragma once
#include "imgui/imgui.h"					// uses: ImGui namespace
#include <string>							// uses: std::string
#include "muParser/muParser/muParser.h"		// uses: muparser
#include <iomanip>							// uses: setprecision

namespace C
{
	// render the main window
	void RenderCalculator();

	__forceinline std::string RoundString(const std::string& input, int precision) {
		std::istringstream iss(input);
		double value;
		if (!(iss >> value)) {
			// Invalid input, return the original string
			return input;
		}

		// Round the double value to the specified precision
		std::ostringstream oss;
		oss << std::fixed << std::setprecision(precision) << value;
		return oss.str();
	}

	__forceinline std::string CalculateString(const std::string& strExp)
	{
		// get the muparser
		mu::Parser muParser;

		try {
			
			// parse it
			muParser.SetExpr(strExp);

			return std::to_string(muParser.Eval());
		}
		catch (mu::Parser::exception_type &e) 
		{
			// not right :(
			return "Error: " + e.GetMsg();
		}
	}
}

