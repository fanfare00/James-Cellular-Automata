#include "curses.h"
#include <string>
using namespace std;

class JamesConsoleUI
{
public: 

	static WINDOW* setUp(int scrHeight, int scrWidth);
	static void loadColors();
	static void colorOn();
	static void colorOff();

	static void showDateTime(WINDOW* win, int y, int x);


	static bool popUpConfirm(char* choice);

	/*static void inputPopUpWindow(char* prompt);*/
	static WINDOW* titleBox();
	static WINDOW* messageFrame();
	static WINDOW* largeMessageFrame();
	
	static void hitEnter(WINDOW* win);
	static int navigationMenu(WINDOW *win, char* menuItems[], int numMenuItems);
	static void printMenuItems(WINDOW *win, char* menuItems[], int numMenuItems, int highlight);


	static string showInputMessage(WINDOW* parentWindow, string title, string message);
	static void showConfirmationMessage(WINDOW* parentWindow, string title, string message);
	static void showMessage(WINDOW* parentWindow, string title, string message);
	static void showLargeMessage(WINDOW* parentWindow, string title, string message);

	enum class Color
	{
		None = 0,
		Red_Black = 1,
		Green_Black = 2,
		Magenta_Black = 3,
		Cyan_Black = 4,
		Yellow_Black = 5,
		White_Black = 6,
		White_Green = 7,
		White_Yellow = 8,
		White_Red = 9,
		Black_Black = 10,
		Yellow_Red = 11,
		Blue_Cyan = 12,
		Yellow_Cyan = 13,
		Blue_Green = 14,
		Green_Yellow = 15,
		Blue_Yellow = 16,
		Green_Cyan = 17,
		Black_Green = 18

	};
};