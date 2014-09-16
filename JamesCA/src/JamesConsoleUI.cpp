/*******************************************************************************
********************************************************************************
********************************************************************************

ID INFORMATION

Programmer		   :  James McCarthy
Assignment #	   :  TA #1.3CA
Assignment Name	   :  Cellular Automata
Course # and Title :  CISC 205 - OOPS
Class Meeting Time :  TTh 9:35 - 12:40
Instructor		   :  Professor Forman
Hours			   :  17
Difficulty		   :  5
Completion Date	   :  9/11/2014
Project Name	   :  JamesCA

********************************************************************************
********************************************************************************

"JamesConsoleUI.cpp" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/

#include "JamesConsoleUI.h"
#include "JamesCurses.h"
#include <stdio.h>
#include <time.h>
#include "consoleWordWrapper.h"

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


string JamesConsoleUI::showInputMessage(WINDOW* parentWindow, string title, string message)
{
	WINDOW* win = JamesConsoleUI::messageFrame();
	char * cMessage = (char*)message.c_str();
	char userInput[80];

	JamesCurses::curs_set(1);
	JamesCurses::echo();

	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintwCentered(win, 6, "CONTINUE");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);

	JamesCurses::mvwprintw(win, 1, 11, cMessage);
	JamesCurses::mvwprintw(win, 3, 11, " ");
	JamesCurses::wrefresh(win);

	WINDOW *inputBox = JamesCurses::newwin(3, 30, 18, 30);
	JamesCurses::wbox(inputBox, 0, 0);
	JamesCurses::wrefresh(inputBox);

	wgetstr(win, userInput);
	JamesCurses::werase(win);
	JamesCurses::werase(inputBox);

	JamesCurses::curs_set(0);
	JamesCurses::noecho();

	return (string)userInput;
}

void JamesConsoleUI::showConfirmationMessage(WINDOW* parentWindow, string title, string message)
{




}
void JamesConsoleUI::showMessage(WINDOW* parentWindow, string title, string message)
{
	char * cMessage = (char*)message.c_str();

	WINDOW* win = JamesConsoleUI::messageFrame();
	
	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintwCentered(win, 6, "CONTINUE");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);

	JamesCurses::mvwprintwCentered(win, 3, cMessage);
	JamesCurses::wrefresh(win);
	
	JamesConsoleUI::hitEnter(win);
	JamesCurses::werase(win);

}
void JamesConsoleUI::showLargeMessage(WINDOW* parentWindow, string title, string message)
{
	WINDOW* win = largeMessageFrame();
	WINDOW* textArea = derwin(win, 16, 71, 0, 2);
	 
	

	ConsoleWordWrapper::formatString(&message, 71);


	char* cTitle = (char*)title.c_str();
	char* cMessage = (char*)message.c_str();

	JamesCurses::wattron(win, A_BOLD | WA_BLINK);
	JamesCurses::mvwprintwCentered(win, 17, "CONTINUE");
	JamesCurses::wattroff(win, A_BOLD | WA_BLINK);

	JamesCurses::mvwprintwCentered(textArea, 2, cTitle);
	JamesCurses::mvwprintw(textArea, 4, 1, cMessage);

	JamesCurses::wrefresh(textArea);
	JamesCurses::wrefresh(win);

	JamesConsoleUI::hitEnter(win);


}

int JamesConsoleUI::showNavMenu(WINDOW* parentWindow, string title, char* menuItems[], int nMenuItems)
{
	int choice;
	char* cTitle = (char*)title.c_str();

	WINDOW *win = JamesCurses::newwin(15, 40, 14, (COLS / 2) - 20);
	WINDOW *shadowWin = JamesCurses::newwin(15, 40, 15, (COLS / 2) - 19);
	JamesCurses::wbkgd(win, COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::White_Yellow)));
	JamesCurses::mvwprintw(win, 2, 15, cTitle);
	JamesCurses::wrefresh(shadowWin);
	JamesCurses::wrefresh(win);

	choice = JamesConsoleUI::navigationMenu(win, menuItems, nMenuItems);


	return choice;


}

WINDOW* JamesConsoleUI::titleBox()
{
	WINDOW *win = JamesCurses::newwin(5, 40, 2, (COLS/2) - 20);
	WINDOW *shadowWin = JamesCurses::newwin(5, 40, 3, (COLS / 2) - 19);
	JamesCurses::wbox(win, 0, 183);

	JamesCurses::wbkgd(win, COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Black_Green)));



	JamesCurses::wrefresh(shadowWin);
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

	WINDOW *win = messageFrame();


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

WINDOW* JamesConsoleUI::messageFrame()
{
	WINDOW *win = JamesCurses::newwin(9, 50, 16, 20);
		JamesCurses::wbox(win, 0, 0);
		JamesCurses::wbkgd(win, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));

	return win;
}


WINDOW* JamesConsoleUI::largeMessageFrame()
{
	WINDOW *win = JamesCurses::newwin(20, 74, 10, 8);
		JamesCurses::wbox(win, 0, 0);
		JamesCurses::wbkgd(win, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));

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

