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

"JamesCurses.h" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/

#ifndef JAMESCURSES_H
#define JAMESCURSES_H

#include "curses.h"

class JamesCurses
{

public:

	// Starts curses mode
	static WINDOW* initscr();

	// Creates a new window
	static WINDOW* newwin(int nlines, int ncols, int begin_y, int begin_x);

	// Deletes a given window
	static int delwin(WINDOW *win);

	// Surround a window with a frame
	static int wbox(WINDOW *win, chtype verch, chtype horch);

	// No echoing
	static int noecho();

	// Enable echoing
	static int echo();

	// No buffering
	static int cbreak();

	// Whether cursor displays (1) or not (0)
	static int curs_set(int visibility);

	// Resize the terminal
	static int resize_term(int lines, int columns);

	// Output a formatted str in win in (x, y)
	static int mvwprintw(WINDOW *win, int y, int x, char *fmt, ...);

	// Output a formatted str centered inside of window
	static int mvwprintwCentered(WINDOW *win, int y, char *fmt, ...);

	// Output a formatted str outside of window
	static int mvprintw(int y, int x, char *fmt, ...);

	// Wait for key input
	static int wgetch(WINDOW *win);

	// Enables attributes to a window
	static int wattron(WINDOW *win, int attrs);

	// Disable attributes to a window
	static int wattroff(WINDOW *win, int attrs);

	//Enable attributes outside window
	static int attron(int attrs);

	//Disable attributes outside window
	static int attroff(int attrs);

	// Creates a new pair (1..COLOR_PAIRS-1) with the given f(oreground) 
	// and b(ackground) color
	static int init_pair(short pair, short f, short b);

	// Starts color mode
	static int start_color();

	// Refresh the given window
	static int wrefresh(WINDOW *win);

	//Refresh all
	static int refresh();

	// Flash the window
	static int flash();

	// Ends curses mode
	static void endwin();

	// Clear the given window
	static int werase(WINDOW *win);


	// Change the attributes of a window
	static int wbkgd(WINDOW *win, chtype ch);

};





#endif /* JAMESCURSES_H */



