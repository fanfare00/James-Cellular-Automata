#ifndef JAMESCAUI_H
#define JAMESCAUI_H

using namespace std;


#include <string>

class JamesCAUI
{
public: string userName = "Unknown";
		string programmerName;

		void hitEnter();
		void invalidEntry(char entry);
		void mainMenu();
		void signIn(char entry);
		void displayLogo(string programmerName);
		void oddTie();
		void farewell(char entry);
};

#endif /* JAMESCAUI_H */