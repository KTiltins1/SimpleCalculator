#include "menu.h"
#include <cctype> // std::isspace

// external libraries used:
// imgui  | https://github.com/ocornut/imgui

// project start date:  04.09.2023
// project last update: 05.09.2023

// todo:
// add parentheses
// fix:
// only do decimal numbers when its not a whole number

enum EButtonSize : int
{
	EButtonNormal = 0,
	EButtonDouble,
	EButtonMax
};

void C::RenderCalculator() 
{
	// math equation string :)
	static std::string strValue;

	// hardcoded values woohoo
	ImVec2 vecButtonSize[EButtonMax];
	vecButtonSize[EButtonNormal] = ImVec2(30, 30);
	vecButtonSize[EButtonDouble] = ImVec2(68, 30);

	ImGui::Begin("Simple Calculator", nullptr, ImGuiWindowFlags_::ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_::ImGuiWindowFlags_NoMove);
	{
	
		// save the size of the calculator)
		vecCalculatorSize = ImGui::GetWindowSize();

		// main value text box on top
		{
			// main value text
			char buffer[256];
			strcpy(buffer, strValue.c_str());

			// with the input text box we need to push the width to the GetContentRegionAvail and then pop it!
			ImGui::PushItemWidth(ImGui::GetContentRegionAvail().x - 1);
			{
				ImGui::InputText("##", buffer, sizeof(buffer));
			}
			ImGui::PopItemWidth();
		}

		ImGui::Separator();

		// 1ST ROW
		{
			// backspace
			if (ImGui::Button("<-", vecButtonSize[EButtonDouble]) || ImGui::IsKeyPressed(ImGuiKey_Backspace))
			{
				if (!strValue.empty())
				{
					// Find the position of the last non-space character in the string
					size_t lastNonSpacePos = strValue.size() - 1;
					while (lastNonSpacePos >= 0 && std::isspace(strValue[lastNonSpacePos]))
						lastNonSpacePos--;

					if (lastNonSpacePos >= 0) 
						// Remove 1 character from the string starting at the position of the last non-space character
						strValue = strValue.substr(0, lastNonSpacePos);
				}			
			}

			// clear
			if (ImGui::SameLine(); ImGui::Button("C", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_C) || ImGui::IsKeyPressed(ImGuiKey_Escape))
				strValue.clear(); ImGui::SameLine();
			
			// calculate | make it a cool color
			ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_Button, (ImVec4)ImColor(0.76f, 0.59f, 0.88f, 0.40f));
			ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_ButtonHovered, (ImVec4)ImColor(0.76f, 0.59f, 0.88f, 1.f));
			ImGui::PushStyleColor(ImGuiCol_::ImGuiCol_ButtonActive, (ImVec4)ImColor(0.56f, 0.53f, 0.88f, 1.f));
			if (ImGui::SameLine(); ImGui::Button("=", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_KeypadEnter) || ImGui::IsKeyPressed(ImGuiKey_Enter) || ImGui::IsKeyPressed(ImGuiKey_KeypadEqual) || ImGui::IsKeyPressed(ImGuiKey_Equal))
			{
				// Convert the string to a double
				strValue = CalculateString(strValue);

				// Round the result
				strValue = RoundString(strValue, 2);
			}
			ImGui::PopStyleColor(3);

			//if (ImGui::SameLine(); ImGui::Button("(", vecButtonSize[EButtonNormal]))
			//	strValue += "("; ImGui::SameLine();
			
			//if (ImGui::SameLine(); ImGui::Button(")", vecButtonSize[EButtonNormal]))
			//	strValue += ")"; ImGui::SameLine();
		}

		// 2ND ROW
		{
			if (ImGui::Button("7", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_7) || ImGui::IsKeyPressed(ImGuiKey_Keypad7))
				strValue += "7"; ImGui::SameLine();

			if (ImGui::Button("8", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_8) || ImGui::IsKeyPressed(ImGuiKey_Keypad8))
				strValue += "8"; ImGui::SameLine();

			if (ImGui::Button("9", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_9) || ImGui::IsKeyPressed(ImGuiKey_Keypad9))
				strValue += "9"; ImGui::SameLine();

			// multiplication
			if (ImGui::Button("x", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_KeypadMultiply))
				strValue += " * ";
		}

		// 3RD ROW
		{
			if (ImGui::Button("4", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_4) || ImGui::IsKeyPressed(ImGuiKey_Keypad4))
				strValue += "4"; ImGui::SameLine();

			if (ImGui::Button("5", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_5) || ImGui::IsKeyPressed(ImGuiKey_Keypad5))
				strValue += "5"; ImGui::SameLine();

			if (ImGui::Button("6", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_6) || ImGui::IsKeyPressed(ImGuiKey_Keypad6))
				strValue += "6"; ImGui::SameLine();

			// division 
			if (ImGui::Button("/", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_KeypadDivide))
				strValue += " / ";
		}

		// 4TH ROW
		{
			if (ImGui::Button("1", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_1) || ImGui::IsKeyPressed(ImGuiKey_Keypad1))
				strValue += "1"; ImGui::SameLine();

			if (ImGui::Button("2", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_2) || ImGui::IsKeyPressed(ImGuiKey_Keypad2))
				strValue += "2"; ImGui::SameLine();

			if (ImGui::Button("3", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_3) || ImGui::IsKeyPressed(ImGuiKey_Keypad3))
				strValue += "3"; ImGui::SameLine();

			// addition
			if (ImGui::Button("+", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_KeypadAdd))
				strValue += " + ";
		}

		// 5TH ROW
		{
			if (ImGui::Button("0", vecButtonSize[EButtonDouble]) || ImGui::IsKeyPressed(ImGuiKey_0) || ImGui::IsKeyPressed(ImGuiKey_Keypad0))
				strValue += "0"; ImGui::SameLine();

			// dot
			if (ImGui::Button(".", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_Period))
				strValue += "."; ImGui::SameLine();

			// subtraction
			if (ImGui::Button("-", vecButtonSize[EButtonNormal]) || ImGui::IsKeyPressed(ImGuiKey_KeypadSubtract) || ImGui::IsKeyPressed(ImGuiKey_Minus))
				strValue += " - ";
		}
	}
	ImGui::End();
}