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

"JamesCA.h" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/

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

	//char userName[80];
	string userName;
	const string MY_NAME = "James";
	char* defaultStatus = "You are currently not signed in.";

	WINDOW *mainWindow;

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

	

};

#endif /* JAMESCA_H */
