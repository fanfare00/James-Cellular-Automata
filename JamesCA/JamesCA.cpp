using namespace std;

#include "jamesCA.h"
#include <string>
#include <bitset>





JamesCA::~JamesCA()
{
	JamesCurses::endwin();
}

JamesCA& JamesCA::getInstance()
{
	static JamesCA instance;
	return instance;
}

void JamesCA::setUp()
{
	JamesCurses::initscr();
	JamesCurses::noecho();
	JamesCurses::cbreak();
	JamesCurses::curs_set(0);
	JamesCurses::resize_term(40, 90);

	JamesConsoleUI::loadColors();
}



void JamesCA::refreshBackground()
{


	JamesCurses::resize_term(40, 90);
	JamesCurses::delwin(mainWindow);
	

	mainWindow = JamesCurses::newwin(LINES, COLS, 0, 0);
	JamesCurses::wbkgd(mainWindow, COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Blue_Cyan)));

	//JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Cyan)));
	//JamesCurses::mvwprintw(mainWindow, LINES - 2, 0, "Welcome to James' Cellular Automata Program");
	//JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Cyan)));

	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Green_Cyan)));
	JamesCurses::mvwprintw(mainWindow, LINES - 1, 0, "%s %s", defaultStatus, userName);
	JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Green_Cyan)));

	

	JamesCurses::wrefresh(mainWindow);
}

void JamesCA::start()
{
	setUp();
	refreshBackground();
	welcomeScreen();


}




void JamesCA::welcomeScreen()
{
	WINDOW *win = JamesCurses::newwin(15, 65, 2, 12);
	
	
	while (win != NULL)
	{
		
		JamesCurses::wbox(win, 0, 0);
		JamesCurses::wbkgd(win, COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Blue_Green)));
		
		
		JamesCurses::mvwprintw(win, 1, 16, "  _____     _ _       _			");
		JamesCurses::mvwprintw(win, 2, 16, " / ____|   | | |     | |		");
		JamesCurses::mvwprintw(win, 3, 16, "| |     ___| | |_   _| | __ _ _ __");
		JamesCurses::mvwprintw(win, 4, 16, "| |    / _ \\ | | | | | |/ _` | '__|");
		JamesCurses::mvwprintw(win, 5, 16, "| |___|  __/ | | |_| | | (_| | |	");
		JamesCurses::mvwprintw(win, 6, 16, " \\_____\\___|_|_|\\__,_|_|\\__,_|_|");
		JamesCurses::mvwprintw(win, 7, 4, "         _    _ _______ ____  __  __       _______	");
		JamesCurses::mvwprintw(win, 8, 4, "    /\\  | |  | |__   __/ __ \\|  \\/  |   /\\|__   __|/\\ ");
		JamesCurses::mvwprintw(win, 9, 4, "   /  \\ | |  | |  | | | |  | | \\  / |  /  \\  | |  /  \\ ");
		JamesCurses::mvwprintw(win, 10, 4, "  / /\\ \\| |  | |  | | | |  | | |\\/| | / /\\ \\ | | / /\\ \\ ");
		JamesCurses::mvwprintw(win, 11, 4, " / ____ \\ |__| |  | | | |__| | |  | |/ ____ \\| |/ ____ \\ ");
		JamesCurses::mvwprintw(win, 12, 4, "/_/    \\_\\____/   |_|  \\____/|_|  |_/_/    \\_\\_/_/    \\_\\ ");
		JamesCurses::wattroff(win, COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Blue_Green)));

		JamesCurses::wrefresh(win);


		JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Cyan)));
		JamesCurses::mvwprintw(mainWindow, 1, 13, "Welcome to James'");
		JamesCurses::mvwprintw(mainWindow, 17, 16, "--An experimental program examining digital life-forms--");
		JamesCurses::mvwprintwCentered(mainWindow, LINES/2+5, "Press <ENTER> To Begin");
		JamesCurses::wattroff(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Cyan)));
		
		
		JamesCurses::wrefresh(mainWindow);

		JamesConsoleUI::hitEnter(mainWindow);
	

			JamesCurses::werase(win);
			JamesCurses::wrefresh(win);
			refreshBackground();
			mainMenu();
			JamesCurses::flash();
			return;
		
	}
}


//DESCRIPTION: 

void JamesCA::mainMenu()
{
	char *menuItems[] = { "SIGN IN", "DISPLAY LOGO", "CELLULAR AUTOMATA", "ID INFORMATION", "CREDITS", "STARS", "EXIT" };

	int choice = 0;

	refreshBackground();

	WINDOW* titleBox = JamesConsoleUI::titleBox();
		JamesCurses::mvwprintw(titleBox, 2, 5, "James Cellular Automata Program");
		JamesCurses::wrefresh(titleBox);
	
		WINDOW *win = JamesCurses::newwin(15, 40, 14, (COLS / 2) - 20);
		WINDOW *shadowWin = JamesCurses::newwin(15, 40, 15, (COLS / 2) - 19);
			JamesCurses::wbkgd(win, COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::White_Yellow)));
			JamesCurses::mvwprintw(win, 2, 15, "-MAIN MENU-");
			JamesCurses::wrefresh(shadowWin);
			JamesCurses::wrefresh(win);


		JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Cyan)));
	JamesCurses::mvwprintwCentered(mainWindow, 30, "Use the arrow keys to move up and down");
	JamesCurses::mvwprintwCentered(mainWindow, 31, "Press <ENTER> to make a selection");
	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Cyan)));
	JamesCurses::wrefresh(mainWindow);

	choice = JamesConsoleUI::navigationMenu(win, menuItems, 7);

		
	if (JamesConsoleUI::popUpConfirm(menuItems[choice - 1]))
	{
		switch (choice)
		{
			case 1:
				signIn();
				break;

			case 2:
				displayLogo();
				break;

			case 3:
				patternMenu();

				break;
			case 4:
				idInfo();
				break;
			case 5:
				credits();
				break;

			case 6:
				displayStars();
				break;

			case 7:
				farewell();
				break;
		}
	}
	else
	{	
		refreshBackground();
		mainMenu();
	}
	

	
}

void JamesCA::displayStars()
{
	WINDOW* starWindow = JamesConsoleUI::largePopUpWindow();
	JamesCurses::mvwprintwCentered(starWindow, 2, "STARS");
	JamesCurses::mvwprintwCentered(starWindow, 5, "1 - did some stuff");
	JamesCurses::mvwprintwCentered(starWindow, 6, "Assignment #            :      TA #1.2CA         ");
	JamesCurses::mvwprintwCentered(starWindow, 7, "Assignment Name         :      Cellular Automata ");
	JamesCurses::mvwprintwCentered(starWindow, 8, "Course # and Title      :      CISC 205 - OOPS   ");
	JamesCurses::mvwprintwCentered(starWindow, 9, "Class Meeting Time      :      TTh 9:35 - 12:40  ");
	JamesCurses::mvwprintwCentered(starWindow, 10, "Instructor              :      Professor Forman  ");
	JamesCurses::mvwprintwCentered(starWindow, 11, "Hours                   :      15                ");
	JamesCurses::mvwprintwCentered(starWindow, 12, "Difficulty              :      5                 ");
	JamesCurses::mvwprintwCentered(starWindow, 13, "Completion Date         :      9/11/2014         ");
	JamesCurses::mvwprintwCentered(starWindow, 14, "Project Name            :      JamesCA           ");

	JamesCurses::mvwprintwCentered(starWindow, 15, "TOTAL STARS: X");



	JamesCurses::wrefresh(starWindow);


	JamesConsoleUI::hitEnter(starWindow);
	refreshBackground();
	mainMenu();
}

void JamesCA::patternMenu()
{
	char nLines[3];
	char patternCode[3];

	JamesCurses::curs_set(1);
	echo();

	WINDOW *entryPopUp = JamesConsoleUI::popUpWindow();
		JamesCurses::wattron(entryPopUp, A_BOLD | WA_BLINK);
		JamesCurses::mvwprintwCentered(entryPopUp, 6, "CONTINUE");
		JamesCurses::wattroff(entryPopUp, A_BOLD | WA_BLINK);

		JamesCurses::mvwprintwCentered(entryPopUp, 1, "  Please enter number of lines: ");
		JamesCurses::mvwprintw(entryPopUp, 3, 11, " ");
		JamesCurses::wrefresh(entryPopUp);

	WINDOW *lineBox = JamesCurses::newwin(3, 30, 18, 30);
		JamesCurses::wbox(lineBox, 0, 0);
		JamesCurses::wrefresh(lineBox);

	wgetstr(entryPopUp, nLines);

		JamesCurses::werase(entryPopUp);
		JamesCurses::wbox(entryPopUp, 0, 0);
		JamesCurses::wattron(entryPopUp, A_BOLD | WA_BLINK);
		JamesCurses::mvwprintwCentered(entryPopUp, 6, "CONTINUE");
		JamesCurses::wattroff(entryPopUp, A_BOLD | WA_BLINK);

		JamesCurses::mvwprintwCentered(entryPopUp, 1, "  Please enter pattern number (0-256): ");
		JamesCurses::mvwprintw(entryPopUp, 3, 11, " ");
		JamesCurses::wrefresh(entryPopUp);


		JamesCurses::werase(lineBox);
		lineBox = JamesCurses::newwin(3, 30, 18, 30);
		JamesCurses::wbox(lineBox, 0, 0);
		JamesCurses::wrefresh(lineBox);

	wgetstr(entryPopUp, patternCode);


	JamesCurses::curs_set(0);
	JamesCurses::noecho();
	
	string binary = std::bitset<8>(atoi(patternCode)).to_string();
	char *ruleSet = (char*)binary.c_str();

	JamesCurses::werase(entryPopUp);
	JamesCurses::werase(lineBox);

	displayPattern(atoi(nLines), ruleSet, patternCode);
}


void JamesCA::signIn()
{

	JamesCurses::curs_set(1);
	echo();

	WINDOW *entryPopUp = JamesConsoleUI::popUpWindow();

		JamesCurses::wattron(entryPopUp, A_BOLD | WA_BLINK);
		JamesCurses::mvwprintwCentered(entryPopUp, 6, "CONTINUE");
		JamesCurses::wattroff(entryPopUp, A_BOLD | WA_BLINK);

		JamesCurses::mvwprintw(entryPopUp, 1, 11, "  Please enter your name: ");
		JamesCurses::mvwprintw(entryPopUp, 3, 11, " ");
		JamesCurses::wrefresh(entryPopUp);

	WINDOW *nameBox = JamesCurses::newwin(3, 30, 18, 30);
		JamesCurses::wbox(nameBox, 0, 0);
		JamesCurses::wrefresh(nameBox);
	
	wgetstr(entryPopUp, userName);
	defaultStatus = ("You are currently signed in as:");

	JamesCurses::curs_set(0);
	JamesCurses::noecho();
	
	WINDOW *echoPopUp = JamesConsoleUI::popUpWindow();
		JamesCurses::mvwprintw(echoPopUp, 3, 9, "Thank you for joining us %s.", userName);
		JamesCurses::wattron(echoPopUp, A_BOLD | WA_BLINK);
		JamesCurses::mvwprintwCentered(echoPopUp, 6, "CONTINUE");
		JamesCurses::wattroff(echoPopUp, A_BOLD | WA_BLINK);
		JamesCurses::wrefresh(echoPopUp);
		JamesCurses::wgetch(echoPopUp);


	//JamesCurses::werase(entryPopUp);
	JamesCurses::werase(echoPopUp);
	//JamesCurses::werase(nameBox);
	refreshBackground();
	mainMenu();

}



void JamesCA::displayLogo()
{
		WINDOW* logoWindow = JamesConsoleUI::largePopUpWindow();
			JamesCurses::mvwprintwCentered(logoWindow, 2, "THANK YOU FOR VIEWING JAMES' LOGO");
			
		int c = 1;

		char* logoLines[] = {
			 "     JJJJJJJJJJJJJJJ DDDDDDDDDDDDD    MMMMMM        MMMMMM",
			 "     J.............J D............D   M.....M      M.....M",
			 "     JJJJJJJ...JJJJJ D....DDDDD....D  M......M    M......M",
			 "           J...J      D...D    D....D M.......M  M.......M",
			 "           J...J      D...D    D....D M........MM........M",
			 "           J...J      D...D    D....D M....MM......MM....M",
			 "JJJJJJ     J...J      D...D    D....D M....M MM..MM M....M",
			 "J....J     J...J      D...D    D....D M....M   MM   M....M",
			 "J.....JJJJJ....J     DD...DDDDDD...D  M....M        M....M",
			 " J............J      D............D   M....M        M....M",
			 "  JJJJJJJJJJJJ       DDDDDDDDDDDDD    MMMMMM        MMMMMM"
		};

		nodelay(logoWindow, TRUE);
		
		while ((JamesCurses::wgetch(logoWindow) == ERR))
		{
			c++;
			if (c == 18)
			{
				c = 1;
			}
			
			//for ever line in the logo
			for (int i = 0; i < 11; i++)
			{
				//for every character in the line
				for (int j = 0; j < 58; j++)
				{
					if ((JamesCurses::wgetch(logoWindow) != ERR))
					{
						goto endLoops;
					}

					switch (logoLines[i][j])
					{	
						case 'J':
							JamesCurses::wattron(logoWindow, COLOR_PAIR(1));
							JamesCurses::mvwprintw(logoWindow, 5 + i, 7 + j, "J");
							JamesCurses::wattroff(logoWindow, COLOR_PAIR(1));
						
							break;

						case 'D':
							JamesCurses::wattron(logoWindow, COLOR_PAIR(1));
							JamesCurses::mvwprintw(logoWindow, 5 + i, 7 + j, "D");
							JamesCurses::wattroff(logoWindow, COLOR_PAIR(1));
							break;

						case 'M':
							JamesCurses::wattron(logoWindow, COLOR_PAIR(1));
							JamesCurses::mvwprintw(logoWindow, 5 + i, 7 + j, "M");
							JamesCurses::wattroff(logoWindow, COLOR_PAIR(1));

							break;

						case '.':
							JamesCurses::wattron(logoWindow, COLOR_PAIR(c));
							JamesCurses::mvwprintw(logoWindow, 5 + i, 7 + j, "#");
							JamesCurses::wattroff(logoWindow, COLOR_PAIR(c));
							JamesCurses::wrefresh(logoWindow);
							
							napms(40);
							break;

					default:
						break;

					}
				}
			}
		}
		endLoops:

		JamesCurses::wrefresh(logoWindow);

		refreshBackground();
		mainMenu();
}

void JamesCA::displayPattern(int nSteps, char* ruleSet, char* patternCode)
{
	int i; //iterate for
	int j;
	int nCells = 90;

	char *x = new char[nCells + 2];;
	char *x_old = new char[nCells + 2];;

	bool rules[7]; //array of possible neighbor configurations

	
	//resize the console window based on number of lines user asked to see
	JamesCurses::resize_term(nSteps + 15, nCells + 6);

	//title box that displays the code# and ruleset of the current pattern
	WINDOW* patternTitle = JamesConsoleUI::titleBox();
		JamesCurses::mvwprintw(patternTitle, 1, 16, "%s", ruleSet);
		JamesCurses::mvwprintwCentered(patternTitle, 3, "PATTERN # %s", patternCode);
		JamesCurses::wrefresh(patternTitle);

	//window the pattern is displayed inside
	WINDOW* patternWindow = JamesCurses::newwin(LINES - 12, COLS - 4,  8, (COLS / 2) - ((COLS - 4) / 2));
		JamesCurses::wbkgd(patternWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));
		JamesCurses::wbox(patternWindow, 0, 0);
		JamesCurses::wrefresh(patternWindow);

	//dont pause for input
	nodelay(patternWindow, TRUE);

	//allow window to scroll down and replace lines at the top
	scrollok(patternWindow, TRUE);

	//fill array with "dead" cells
	for (i = 0; i <= nCells + 1; i++)
	{
		x[i] = ' ';
	}

	//seed cell in the middle in "alive" state
	x[nCells/2] = '#';

	//print "generation 1"
	for (i = 1; i <= nCells; i++)
	{
		JamesCurses::mvwprintw(patternWindow, 1, i,"%c", x[i]);
	}

	//repeat for each row user asked for
	for (j = 1; j <= nSteps; j++)
	{
		//put generation 1 into a seperate array for checking
		for (i = 0; i < nCells + 2; i++)
		{
			x_old[i] = x[i];
		}

		for (i = 1; i <= nCells; i++)
		{
			//define each possible rule in the neighborhood
			rules[7] = (x_old[i - 1] == ' ' && x_old[i] == ' ' && x_old[i + 1] == ' ');
			rules[6] = (x_old[i - 1] == ' ' && x_old[i] == ' ' && x_old[i + 1] == '#');
			rules[5] = (x_old[i - 1] == ' ' && x_old[i] == '#' && x_old[i + 1] == ' ');
			rules[4] = (x_old[i - 1] == ' ' && x_old[i] == '#' && x_old[i + 1] == '#');
			rules[3] = (x_old[i - 1] == '#' && x_old[i] == ' ' && x_old[i + 1] == ' ');
			rules[2] = (x_old[i - 1] == '#' && x_old[i] == ' ' && x_old[i + 1] == '#');
			rules[1] = (x_old[i - 1] == '#' && x_old[i] == '#' && x_old[i + 1] == ' ');
			rules[0] = (x_old[i - 1] == '#' && x_old[i] == '#' && x_old[i + 1] == '#');

			//loop through each binary digit int he user defined ruleset
			for (int a = 0; a < 8; a++)
			{
					//if binary digit is a 0, dont use rule
				if (ruleSet[a] == '0')
				{
					rules[a] = false;
				}

			}

			//check if character in old generate satisfies rule and set character in new array to "alive"
			if (rules[0] || rules[1] || rules[2] || rules[3] || rules[4] || rules[5] || rules[6] || rules[7])
			{
				x[i] = '#';
			}
			//otherwise, if rules are not satisfied, set new character to "dead"
			else
			{
				x[i] = ' ';
			}
	
		}
		x[0] = x[nCells];
		x[nCells + 1] = x[1];

		for (i = 1; i <= nCells; i++)
		{
			JamesCurses::mvwprintw(patternWindow, j+1, i, "%c", x[i]);

		}
		
		//if key is pressed, end pattern loop
		if ((JamesCurses::wgetch(patternWindow) != ERR))
		{
			break;
		}

		//refresh after printing line
		JamesCurses::wrefresh(patternWindow);

		//pause thread for .25 seconds before printing next line
		napms(250);
	}

	//free memory
	delete[] x;
	delete[] x_old;

	JamesCurses::attron(A_BOLD | WA_BLINK | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));
	JamesCurses::mvprintw( LINES-3, (COLS/2) - 2, "BACK");
	JamesCurses::attroff(A_BOLD | WA_BLINK | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Yellow_Black)));
	JamesCurses::refresh();

	JamesConsoleUI::hitEnter(patternWindow);
	refreshBackground();
	mainMenu();

}

void JamesCA::idInfo()
{
	WINDOW* idWindow = JamesConsoleUI::largePopUpWindow();
		JamesCurses::mvwprintwCentered(idWindow, 2,  "ID INFORMATION");
		JamesCurses::mvwprintwCentered(idWindow, 5,  "Programmer              :      James McCarthy    ");
		JamesCurses::mvwprintwCentered(idWindow, 6,  "Assignment #            :      TA #1.2CA         ");
		JamesCurses::mvwprintwCentered(idWindow, 7,  "Assignment Name         :      Cellular Automata ");
		JamesCurses::mvwprintwCentered(idWindow, 8,  "Course # and Title      :      CISC 205 - OOPS   ");
		JamesCurses::mvwprintwCentered(idWindow, 9,  "Class Meeting Time      :      TTh 9:35 - 12:40  ");
		JamesCurses::mvwprintwCentered(idWindow, 10, "Instructor              :      Professor Forman  ");
		JamesCurses::mvwprintwCentered(idWindow, 11, "Hours                   :      15                ");
		JamesCurses::mvwprintwCentered(idWindow, 12, "Difficulty              :      5                 ");
		JamesCurses::mvwprintwCentered(idWindow, 13, "Completion Date         :      9/11/2014         ");
		JamesCurses::mvwprintwCentered(idWindow, 14, "Project Name            :      JamesCA           ");
	

	
	JamesCurses::wrefresh(idWindow);


	JamesConsoleUI::hitEnter(idWindow);
	refreshBackground();
	mainMenu();

}

void JamesCA::credits()
{
	WINDOW* creditsWindow = JamesConsoleUI::largePopUpWindow();
		JamesCurses::mvwprintwCentered(creditsWindow, 2,  "CREDITS");
		JamesCurses::mvwprintwCentered(creditsWindow, 5,  "James' Cellular Automata Program was created by James McCarthy for");
		JamesCurses::mvwprintwCentered(creditsWindow, 6,  "Larry Forman's Fall 2014 CISC 205 Object Oriented C++ class at San");
		JamesCurses::mvwprintwCentered(creditsWindow, 7,  "Diego City College. Thank you to Nils Olsson for introducing me to");
		JamesCurses::mvwprintwCentered(creditsWindow, 8,  "PDCurses and helping me set it up in Visual Studio. Thank you to  ");
		JamesCurses::mvwprintwCentered(creditsWindow, 9,  "the creators of PDCurses and ncurses for providing documentation  ");
		JamesCurses::mvwprintwCentered(creditsWindow, 10, "that helped me learn the ins and outs of ncurses/PDCurses.        ");

		JamesCurses::mvwprintwCentered(creditsWindow, 12, "PDCurses Website  :   www.pdcurses.sourceforge.net      ");
		JamesCurses::mvwprintwCentered(creditsWindow, 13, "My Personal Blog  :   www.jdonaldmccarthy.wordpress.com ");
		JamesCurses::mvwprintwCentered(creditsWindow, 14, "My Github Profile :   www.github.com/fanfare00          ");


	JamesCurses::wrefresh(creditsWindow);


	JamesConsoleUI::hitEnter(creditsWindow);
	refreshBackground();
	mainMenu();
}


void JamesCA::farewell()
{
	WINDOW* win = JamesConsoleUI::popUpWindow();

	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Green_Cyan)));
	JamesConsoleUI::showDateTime(mainWindow, 10, 37);
	JamesCurses::wattron(mainWindow, A_BOLD | COLOR_PAIR(static_cast<int>(JamesConsoleUI::Color::Green_Cyan)));
	JamesCurses::wrefresh(mainWindow);


	JamesCurses::mvwprintw(win, 1, 2, "Farewell, %s", userName);
	JamesCurses::mvwprintw(win, 3, 2, "Thank you for using James' Cellular Automata.");
	JamesCurses::mvwprintwCentered(win, 6, "Hit <ESC> to Close");
	JamesCurses::wrefresh(win);

	nodelay(win, TRUE);

	if (JamesCurses::wgetch(win) == 27)
	{
		exit(1);
	}
	else
	{
		napms(1000);
		farewell();
		
	}

}

int main(int argc, char *argv[])
{
	JamesCA::getInstance().start();


	return 0;

	return 0;
	
}
