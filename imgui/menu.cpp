#include "menu.h"

// external libraries used:
// imgui  | https://github.com/ocornut/imgui
// xorstr | https://github.com/JustasMasiulis/xorstr

// project start date:  04.09.2023
// project last update: 04.09.2023

// notes:
// badly hardcoded button size values
// it ignores the order of operators
// todo:
// remove the background
// rounding the main value
// maybe add getting the input of the keyboard too?

void C::RenderCalculator() 
{
	// math equation string :)
	static std::string strValue;

	ImGui::Begin(X("Simple Calculator"), nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize);
	{
		// main value text on top
		// not really good but it works
		ImGui::Text(strValue == X("") ? X("0") : X("%s"), strValue.c_str());

		ImGui::Separator();

		// 1ST ROW
		{
			// backspace
			if (ImGui::Button(X("<-"), ImVec2(106, 30)))
				// remove 1 char from string
				strValue = strValue.substr(0, strValue.size() - 1);

			// division 
			if (ImGui::SameLine(); ImGui::Button(X("/"), ImVec2(30, 30)))
				strValue += X(" / ");
		}

		// 2ND ROW
		{
			if (ImGui::Button(X("7"), ImVec2(30, 30)))
				strValue += X("7"); ImGui::SameLine();

			if (ImGui::Button(X("8"), ImVec2(30, 30)))
				strValue += X("8"); ImGui::SameLine();

			if (ImGui::Button(X("9"), ImVec2(30, 30)))
				strValue += X("9"); ImGui::SameLine();

			// multiplication
			if (ImGui::Button(X("x"), ImVec2(30, 30)))
				strValue += X(" * ");
		}

		// 3RD ROW
		{
			if (ImGui::Button(X("4"), ImVec2(30, 30)))
				strValue += X("4"); ImGui::SameLine();

			if (ImGui::Button(X("5"), ImVec2(30, 30)))
				strValue += X("5"); ImGui::SameLine();

			if (ImGui::Button(X("6"), ImVec2(30, 30)))
				strValue += X("6"); ImGui::SameLine();

			// subtraction
			if (ImGui::Button(X("-"), ImVec2(30, 30)))
				strValue += X(" - ");
		}

		// 4TH ROW
		{
			if (ImGui::Button(X("1"), ImVec2(30, 30)))
				strValue += X("1"); ImGui::SameLine();

			if (ImGui::Button(X("2"), ImVec2(30, 30)))
				strValue += X("2"); ImGui::SameLine();

			if (ImGui::Button(X("3"), ImVec2(30, 30)))
				strValue += X("3"); ImGui::SameLine();

			// addition
			if (ImGui::Button(X("+"), ImVec2(30, 30)))
				strValue += X(" + ");
		}

		// 5TH ROW
		{
			if (ImGui::Button(X("0"), ImVec2(68, 30)))
				strValue += X("0"); ImGui::SameLine();

			// clear
			if (ImGui::Button(X("C"), ImVec2(30, 30)))
				strValue.clear(); ImGui::SameLine();

			// result
			if (ImGui::Button(X("="), ImVec2(30, 30)))
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