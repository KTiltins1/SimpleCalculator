#include "menu.h"

// external libraries used:
// imgui  | https://github.com/ocornut/imgui
// xorstr | https://github.com/JustasMasiulis/xorstr

// project start date:  04.09.2023
// project last update: 04.09.2023
// notes:
// badly hardcoded button size values
// it ignores the order of operators (CalculateStringToFloat() very bad)

void C::RenderCalculator() 
{
	// math equation string :)
	static std::string strValue;

	ImGui::Begin(xorstr_("Simple Calculator"), nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize);
	{
		// main value text on top
		// not really good but it works
		// rounding in the future?
		ImGui::Text(strValue == xorstr_("") ? xorstr_("0") : xorstr_("%s"), strValue.c_str());

		ImGui::Separator();

		// 1ST ROW
		{
			// backspace
			if (ImGui::Button(xorstr_("<-"), ImVec2(106, 30)))
				// remove 1 char from string
				strValue = strValue.substr(0, strValue.size() - 1);

			// division 
			if (ImGui::SameLine(); ImGui::Button(xorstr_("/"), ImVec2(30, 30)))
				strValue += xorstr_(" / ");
		}

		// 2ND ROW
		{
			if (ImGui::Button(xorstr_("7"), ImVec2(30, 30)))
				strValue += xorstr_("7"); ImGui::SameLine();

			if (ImGui::Button(xorstr_("8"), ImVec2(30, 30)))
				strValue += xorstr_("8"); ImGui::SameLine();

			if (ImGui::Button(xorstr_("9"), ImVec2(30, 30)))
				strValue += xorstr_("9"); ImGui::SameLine();

			// multiplication
			if (ImGui::Button(xorstr_("x"), ImVec2(30, 30)))
				strValue += xorstr_(" * ");
		}

		// 3RD ROW
		{
			if (ImGui::Button(xorstr_("4"), ImVec2(30, 30)))
				strValue += xorstr_("4"); ImGui::SameLine();

			if (ImGui::Button(xorstr_("5"), ImVec2(30, 30)))
				strValue += xorstr_("5"); ImGui::SameLine();

			if (ImGui::Button(xorstr_("6"), ImVec2(30, 30)))
				strValue += xorstr_("6"); ImGui::SameLine();

			// subtraction
			if (ImGui::Button(xorstr_("-"), ImVec2(30, 30)))
				strValue += xorstr_(" - ");
		}

		// 4TH ROW
		{
			if (ImGui::Button(xorstr_("1"), ImVec2(30, 30)))
				strValue += xorstr_("1"); ImGui::SameLine();

			if (ImGui::Button(xorstr_("2"), ImVec2(30, 30)))
				strValue += xorstr_("2"); ImGui::SameLine();

			if (ImGui::Button(xorstr_("3"), ImVec2(30, 30)))
				strValue += xorstr_("3"); ImGui::SameLine();

			// addition
			if (ImGui::Button(xorstr_("+"), ImVec2(30, 30)))
				strValue += xorstr_(" + ");
		}

		// 5TH ROW
		{
			if (ImGui::Button(xorstr_("0"), ImVec2(68, 30)))
				strValue += xorstr_("0"); ImGui::SameLine();

			// clear
			if (ImGui::Button(xorstr_("C"), ImVec2(30, 30)))
				strValue.clear(); ImGui::SameLine();

			// result
			if (ImGui::Button(xorstr_("="), ImVec2(30, 30)))
			{
				// replace the string equation to the calculated int
				const double iNewResult = CalculateStringToFloat(strValue);

				// convert the int back to a string
				// replace the new string with the value
				strValue = std::to_string(iNewResult);
			}
		}
	}
	ImGui::End();
}