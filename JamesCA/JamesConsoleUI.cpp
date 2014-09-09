#include "JamesConsoleUI.h"
#include "JamesCurses.h"
#include <stdio.h>
#include <time.h>

WINDOW* JamesConsoleUI::setUp(int scrHeight, int scrWidth)
{
	WINDOW* mainWindow = JamesCurses::initscr();
	JamesCurses::noecho();
	JamesCurses::cbreak();
	JamesCurses::curs_set(0);
	JamesCurses::resize_term(scrHeight, scrWidth);

	loadColors();

	return mainWindow;
}

void JamesConsoleUI::loadColors()
{
	JamesCurses::start_color();
	JamesCurses::init_pair(static_cast<int>(Color::Red_Black), COLOR_RED, COLOR_BLACK);
	JamesCurses::init_pair(static_cast<int>(Color::Green_Black), COLOR_GREEN, COLOR_BLACK);
	JamesCurses::init_pair(static_cast<int>(Color::Yellow_Red), COLOR_YELLOW, COLOR_RED);
	JamesCurses::init_pair(static_cast<int>(Color::Cyan_Black), COLOR_CYAN, COLOR_BLACK);
	JamesCurses::init_pair(static_cast<int>(Color::Yellow_Black), COLOR_YELLOW, COLOR_BLACK);
	JamesCurses::init_pair(static_cast<int>(Color::White_Black), COLOR_WHITE, COLOR_BLACK);
	JamesCurses::init_pair(static_cast<int>(Color::White_Green), COLOR_WHITE, COLOR_GREEN);
	JamesCurses::init_pair(static_cast<int>(Color::White_Yellow), COLOR_BLACK, COLOR_YELLOW);
	JamesCurses::init_pair(static_cast<int>(Color::White_Red), COLOR_WHITE, COLOR_RED);
	JamesCurses::init_pair(static_cast<int>(Color::Black_Black), COLOR_BLACK, COLOR_BLACK);
	JamesCurses::init_pair(static_cast<int>(Color::Magenta_Black), COLOR_MAGENTA, COLOR_BLACK);

	JamesCurses::init_pair(static_cast<int>(Color::Blue_Cyan), COLOR_BLUE, COLOR_CYAN);
	JamesCurses::init_pair(static_cast<int>(Color::Yellow_Cyan), COLOR_YELLOW, COLOR_CYAN);

	JamesCurses::init_pair(static_cast<int>(Color::Blue_Green), COLOR_BLUE, COLOR_GREEN);

	JamesCurses::init_pair(static_cast<int>(Color::Green_Yellow), COLOR_GREEN, COLOR_YELLOW);

	JamesCurses::init_pair(static_cast<int>(Color::Blue_Yellow), COLOR_BLACK, COLOR_YELLOW);

	JamesCurses::init_pair(static_cast<int>(Color::Green_Cyan), COLOR_GREEN, COLOR_CYAN);

	JamesCurses::init_pair(static_cast<int>(Color::Black_Green), COLOR_BLACK, COLOR_GREEN);
}

void JamesConsoleUI::showDateTime(WINDOW* win, int y, int x)
{

	char date[9];
	char time[9];

	_strdate_s(date);
	_strtime_s(time);

	
	JamesCurses::mvwprintw(win, y,  x, "Date: %s", date);
	JamesCurses::mvwprintw(win, y+1, x, "Time: %s", time);
	 
}

WINDOW* JamesConsoleUI::titleBox()
{
	WINDOW *win = JamesCurses::newwin(5, 40, 2, (COLS/2) - 20);
	JamesCurses::wbox(win, 0, 183);
	//JamesCurses::init_pair(2, COLOR_BLACK, COLOR_GREEN );
	JamesCurses::wbkgd(win, COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Black_Green)));



	JamesCurses::wrefresh(win);

	return win;
}



bool JamesConsoleUI::popUpConfirm(char* choice)
{
	char *menuItems[] = {

		"Continue",
		"Back"
	};

	int menuItemSelection;

	WINDOW *win = popUpWindow();


	JamesCurses::wattron(win, A_BOLD);
	JamesCurses::mvwprintw(win, 2, 2, "Thanks for selecting <%s>", choice);
	JamesCurses::wattroff(win, A_BOLD);


	menuItemSelection = navigationMenu(win, menuItems, 2);

	if (menuItemSelection == 1)
	{
		JamesCurses::werase(win);
		return true;
	}
	JamesCurses::wrefresh(win);
	return false;
}

WINDOW* JamesConsoleUI::popUpWindow()
{
	WINDOW *win = JamesCurses::newwin(9, 50, 16, 20);
	JamesCurses::wbox(win, 0, 0);

	//init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	JamesCurses::wbkgd(win, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));
	JamesCurses::wrefresh(win);

	return win;
}

//void JamesConsoleUI::inputPopUpWindow(char* prompt)
//{
//	char input[80];
//
//	WINDOW *win = JamesConsoleUI::popUpWindow();
//
//
//
//	JamesCurses::wattron(win, A_BOLD | WA_BLINK );
//	JamesCurses::mvwprintwCentered(win, 6, "CONTINUE");
//	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);
//
//	JamesCurses::mvwprintwCentered(win, 1, prompt);
//	JamesCurses::mvwprintwCentered(win, 3, " ");
//	JamesCurses::wrefresh(win);
//
//	WINDOW *inputBox = JamesCurses::newwin(3, 30, 18, 30);
//	JamesCurses::wbox(inputBox, 0, 0);
//	JamesCurses::wrefresh(inputBox);
//
//
//	
//	
//
//	
//}

WINDOW* JamesConsoleUI::largePopUpWindow()
{
	WINDOW *win = JamesCurses::newwin(20, 74, 10, 8);
	JamesCurses::wbox(win, 0, 0);

	//init_pair(1, COLOR_YELLOW, COLOR_BLACK);
	JamesCurses::wbkgd(win, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));

	JamesCurses::wrefresh(win);

	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintwCentered(win, 17, "BACK");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);

	return win;
}



int JamesConsoleUI::navigationMenu(WINDOW *win, char* menuItems[], int numMenuItems)
{
	int highlight = 1;
	int choice = 0;
	int keyPress;

	int n_menuChoices = numMenuItems;

	keypad(win, TRUE);


	printMenuItems(win, menuItems, numMenuItems, highlight);

	//infinite loop
	while (true)
	{
		//pause for key input
		keyPress = wgetch(win);

		//test key input
		switch (keyPress)
		{

			//if key up 
		case KEY_UP:
			//if 
			if (highlight == 1)
			{
				highlight = n_menuChoices;
			}
			else
			{
				--highlight;
			}
			break;

			//if key down
		case KEY_DOWN:
			if (highlight == n_menuChoices)
			{
				highlight = 1;
			}
			else
			{
				++highlight;
			}
			break;

			//if ENTER key
		case 10:
			//set user choice to highlighted choice
			choice = highlight;
			break;

		default:
			//mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", keyPress, keyPress);
			refresh();
			break;
		}

		printMenuItems(win, menuItems, numMenuItems, highlight);
		if (choice != 0)	// User did a choice come out of the infinite loop 
		{
			break;
		}

	}

	return choice;

}

void JamesConsoleUI::printMenuItems(WINDOW *win, char* menuItems[], int numMenuItems, int highlight)
{
	int n_menuChoices = numMenuItems;

	int x, y, i;

	x = 7;
	y = 5;

	JamesCurses::wbox(win, 0, 0);


	for (i = 0; i < n_menuChoices; ++i)
	{
		if (highlight == i + 1) /* High light the present choice */
		{
			//init_pair(1, COLOR_YELLOW, COLOR_BLACK);
			JamesCurses::wattron(win, A_BOLD | WA_BLINK | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));
			JamesCurses::mvwprintw(win, y, x, menuItems[i]);
			JamesCurses::wattroff(win, A_BOLD | WA_BLINK | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));
		}
		else

			JamesCurses::mvwprintw(win, y, x, menuItems[i]);
		y++;
	}




	JamesCurses::wrefresh(win);
}

void JamesConsoleUI::hitEnter(WINDOW *win)
{
	int keyPress;
	bool pressedEnter = false;

	while (true)
	{
		//pause for key input
		keyPress = JamesCurses::wgetch(win);

		//test key input
		if (keyPress == 10)
		{
			break;
		}

	}

}

