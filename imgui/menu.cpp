#include "menu.h"

// external libraries used:
// imgui  | https://github.com/ocornut/imgui

// project start date:  04.09.2023
// project last update: 05.09.2023

// todo:
// fix hardcoded button sizes
// remove the background

void C::RenderCalculator() 
{
	// math equation string :)
	static std::string strValue;

	ImGui::Begin("Simple Calculator", nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize);
	{
		// main value text box on top
		{
			ImGui::Text(strValue == "" ? "0" : "%s", strValue.c_str());

			// with the input text box we need to push the width to the GetContentRegionAvail and then pop it!
			//const char* szString = strValue.c_str();
			//ImGui::InputText("##", (char*)szString, IM_ARRAYSIZE((char*)szString), ImGuiInputTextFlags_CharsDecimal | ImGuiInputTextFlags_EscapeClearsAll);
		}

		ImGui::Separator();

		// 1ST ROW
		{
			// backspace
			if (ImGui::Button("<-", ImVec2(68, 30)) || ImGui::IsKeyPressed(ImGuiKey_Backspace))
				// remove 1 char from string
				strValue = strValue.substr(0, strValue.size() - 1);

			// clear
			if (ImGui::SameLine(); ImGui::Button("C", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_C) || ImGui::IsKeyPressed(ImGuiKey_Escape))
				strValue.clear(); ImGui::SameLine();

			// result
			if (ImGui::SameLine(); ImGui::Button("=", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter) || ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEqual) || ImGui::IsKeyPressed(ImGuiKey_Equal))
			{
				// Convert the string to a double
				strValue = CalculateString(strValue);

				// Round the result
				strValue = RoundString(strValue, 2);
			}
		}

		// 2ND ROW
		{
			if (ImGui::Button("7", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_7))
				strValue += "7"; ImGui::SameLine();

			if (ImGui::Button("8", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_8))
				strValue += "8"; ImGui::SameLine();

			if (ImGui::Button("9", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_9))
				strValue += "9"; ImGui::SameLine();

			// multiplication
			if (ImGui::Button("x", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_KeypadMultiply))
				strValue += "*";
		}

		// 3RD ROW
		{
			if (ImGui::Button("4", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_4))
				strValue += "4"; ImGui::SameLine();

			if (ImGui::Button("5", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_5))
				strValue += "5"; ImGui::SameLine();

			if (ImGui::Button("6", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_6))
				strValue += "6"; ImGui::SameLine();

			// division 
			if (ImGui::Button("/", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_KeypadDivide))
				strValue += "/";
		}

		// 4TH ROW
		{
			if (ImGui::Button("1", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_1))
				strValue += "1"; ImGui::SameLine();

			if (ImGui::Button("2", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_2))
				strValue += "2"; ImGui::SameLine();

			if (ImGui::Button("3", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_3))
				strValue += "3"; ImGui::SameLine();

			// addition
			if (ImGui::Button("+", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_KeypadAdd))
				strValue += "+";
		}

		// 5TH ROW
		{
			if (ImGui::Button("0", ImVec2(68, 30)) || ImGui::IsKeyPressed(ImGuiKey_0))
				strValue += "0"; ImGui::SameLine();

			// dot
			if (ImGui::Button(".", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_Period))
				strValue += "."; ImGui::SameLine();

			// subtraction
			if (ImGui::Button("-", ImVec2(30, 30)) || ImGui::IsKeyPressed(ImGuiKey_KeypadSubtract))
				strValue += "-";
		}
	}
	ImGui::End();
}