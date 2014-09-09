#ifndef JAMESCA_H
#define JAMESCA_H

#include "curses.h"
#include "JamesCurses.h"
#include "JamesConsoleUI.h"
#include <string>
#include <vector>


class JamesCA
{
public: 

	char userName[80];
	char* defaultStatus = "You are currently not signed in.";

	WINDOW *mainWindow;
//	WINDOW *terminal;

	static JamesCA& getInstance();
	~JamesCA();

	void setUp();
	void start();
	void welcomeScreen();
	void refreshBackground();
	void mainMenu();
	void signIn();
	void displayLogo();
	void displayStars();
	void displayPattern(int nSteps, char* ruleSet, char* patternCode);
	void patternMenu();

	void credits();
	void idInfo();
	void farewell();



private:
	std::vector<WINDOW *> windows_;
	

	


};

#endif /* JAMESCA_H */
