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

"ConsoleWordWrapper.cpp" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/

#include "ConsoleWordWrapper.h"
using namespace std;

void ConsoleWordWrapper::formatString(string *text, int lineNumber)
{
	//loop through each character in the quirk string
	for (unsigned int i = 1; i <= (*text).length(); i++)
	{
		if ((*text)[(i - 1)] == '\n')
		{
			break;
		}

		//check to see if at end of line
		if ((i % lineNumber) == 0)
		{
			//check how many characters backtracked through to find a space
			int spaceCount = 0;



			//check if character at end of line is already a space or not
			if ((*text)[(i - 1)] != ' ')
			{
				//loop backwards at this position in the quirk until a space is found
				for (int j = (i - 1); j > -1; j--)
				{
					//if a space is found, its the last word and a number of blank spaces
					//get added to the end in order to push the next word to the next line
					if ((*text)[j] == ' ')
					{
						//add X number of blank spaces where X is the # of times back tracked
						(*text).insert(j, spaceCount, ' ');

						break;
					}
					//if no space found, add 1 to the # of spaces needed to push the word over
					else spaceCount++;
				}
			}
		}
	}

	return;
}

