#include <iostream>
#include "JamesCAUI.h"
#include "ConsoleFrames.h"


void JamesCAUI::hitEnter()
{
	////////////////////////////////////////////////////////////////////////////
	//		LOCAL VARIABLE DECLARATIONS 
	////////////////////////////////////////////////////////////////////////////

	static unsigned int counter = 1;

	ConsoleFrames CFrame;

	////////////////////////////////////////////////////////////////////////////

	CFrame.gotoXY(29, 21, 15, "<Hit ENTER to continue>");
	CFrame.Draw(26, 20, 29, 3, 10, 2, 0, 0);

	cin.ignore();
	counter++;
	system("cls");
	return;
}


void JamesCAUI::invalidEntry(char entry)
{
	system("cls");
	cout << "Sorry but, \"" << entry << "\" is not a valid entry.\n";
	cout << "Let's try that again . . .";
	cin.ignore();
	hitEnter();
	mainMenu();

}


void JamesCAUI::mainMenu()
{
	char menuChoice;
	ConsoleFrames CFrame;

	CFrame.Draw(7, 2, 66, 20, 2, 2, 1, 4);  // Box, 2 lines, around screen
	CFrame.Draw(28, 4, 25, 3, 2, 1, 0, 0);  //title box
	CFrame.gotoXY(39, 5, 15, "MENU");		//title

	//menu items
	CFrame.gotoXY(26, 8, 15, "S  -  Sign In");	
	CFrame.gotoXY(26, 9, 15, "L  -  Display Logo");
	CFrame.gotoXY(26, 10, 15, "C  -  Display the 'Odd Tie' Pattern");
	CFrame.gotoXY(26, 11, 15, "X  -  Exit Program");

	//box description above
	CFrame.gotoXY(20, 14, 15, "Please type your selection and hit RETURN:"); 

	CFrame.Draw(18, 16, 46, 3, 10, 2, 0, 0); //enter box

	CFrame.gotoXY(19, 17, 15, " "); //space before input

}


void JamesCAUI::signIn(char userEntry)
{
	//string userName;
	system("cls");


	cout << "Thank you for selecting \"" << userEntry << "\" . . .\n";
	cout << "Time to sign in!\n";
	cout << "Please enter your first name: ";

	cin.ignore();
	hitEnter();

	//return userName;
}


void JamesCAUI::displayLogo(string programmerName)
{
	////////////////////////////////////////////////////////////////////////////
	//		LOCAL VARIABLE DECLARATIONS 
	////////////////////////////////////////////////////////////////////////////

	ConsoleFrames CFrame;

	////////////////////////////////////////////////////////////////////////////

	system("cls");
	CFrame.Draw(13, 2, 54, 6, 155, 3, 0, 0);
	CFrame.gotoXY(19, 4, 14, "The logo you are about to see was created ");
	CFrame.gotoXY(19, 5, 14, "by " + programmerName + " for your viewing "
		"pleasure...");

	cin.ignore();
	hitEnter();

	CFrame.Draw(20, 1, 40, 5, 12, 1, 0, 0);
	CFrame.gotoXY(25, 3, 10, "Thanks for viewing " + programmerName +
		"' Logo!");

	//////GREY BLADE///////

	//line 1
	CFrame.gotoXY(21, 10, 120, "\333\333\333");

	//line 2
	CFrame.gotoXY(22, 11, 120, "\333\333\333\333\333\333\333\333\333\333\333"
		"\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333"
		"\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333"
		"\333\333\333\333\333\333\333\333");

	//line 3
	CFrame.gotoXY(22, 12, 120, "\333\333                                    "
		"          \333\333\333");

	//line 4
	CFrame.gotoXY(22, 13, 120, "\333\333                                    "
		"       \333\333\333");

	//line 5
	CFrame.gotoXY(22, 14, 120, "\333\333\304\304\304\304\304\304\304\304\304"
		"\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304"
		"\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\333"
		"\333\333");

	//line 6
	CFrame.gotoXY(22, 15, 120, "\333\333\333\333\333\333\333\333\333\333\333"
		"\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333"
		"\333\333\333\333\333\333\333\333\333\333\333\333\333\333\333");

	//line 7
	CFrame.gotoXY(21, 16, 120, "\333\333\333");

	//////GOLD/RED HILT/////
	CFrame.gotoXY(6, 12, 70, " \333\333\333\333\333 \333 \333\333\333\333"
		"\333 \333\n      \333 \333\333\333 \333\333\333 \333\333\333 \333"
		"\333\n      \333\333 \333 \333\333\333\333\333 \333 \333\333\333"
		"\n");

	//////YELLOW POMMEL/////
	CFrame.gotoXY(4, 10, 14, "\333\n    \333\333\n    \333\333\n    \333\333\n"
		"    \333\333\n    \333\333\n    \333");

	CFrame.gotoXY(42, 13, 124, "J D M");

	hitEnter();
	
}


void JamesCAUI::oddTie()
{
	system("cls");
	cout << "odd tie";
	cin.ignore();
	hitEnter();
	mainMenu();
}


void JamesCAUI::farewell(char userEntry)
{
	
	string programmerName = "James";

	system("cls");
	cout << "Thank you for selecting \"" << userEntry << "\". . .\n";
	cout << "Time to X-cape!";
	cin.ignore();
	hitEnter();
	system("cls");
	cout << "Farewell, " + userName + ", and thank you for visiting "
		+ programmerName + "'s Cellular Automaton Program";
	hitEnter();

}