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

"JamesCurses.cpp" DESCRIPTION



********************************************************************************
********************************************************************************

CUSTOM-DEFINED FUNCTION LIST




********************************************************************************
********************************************************************************

CREDITS




********************************************************************************
********************************************************************************
********************************************************************************/

#include "JamesCurses.h"
#include <string>

WINDOW* JamesCurses::initscr()
{
	return ::initscr();
}

WINDOW* JamesCurses::newwin(int nlines, int ncols, int begin_y, int begin_x)
{
	return ::newwin(nlines, ncols, begin_y, begin_x);
}

int JamesCurses::delwin(WINDOW *win)
{
	return ::delwin(win);
}

int JamesCurses::resize_term(int lines, int columns)
{
	return ::resize_term(lines, columns);
}

int JamesCurses::wgetch(WINDOW *win)
{
	return ::wgetch(win);
}

int JamesCurses::curs_set(int visibility)
{
	return ::curs_set(visibility);
}

int JamesCurses::noecho()
{
	return ::noecho();
}

int JamesCurses::echo()
{
	return ::echo();
}

int JamesCurses::cbreak()
{
	return ::cbreak();
}

int JamesCurses::mvwprintw(WINDOW *win, int y, int x, char *fmt, ...)
{
	int ret = ERR;

	va_list args;
	va_start(args, fmt);
	::wmove(win, y, x);
	ret = ::vwprintw(win, fmt, args);
	va_end(args);

	return ret;
}

int JamesCurses::mvwprintwCentered(WINDOW *win, int y, char *fmt, ...)
{
	int ret = ERR;
	int x = (getmaxx(win) / 2) - (strlen(fmt) / 2);


	va_list args;
	va_start(args, fmt);
	::wmove(win, y, x);
	ret = ::vwprintw(win, fmt, args);
	va_end(args);

	return ret;

}

int JamesCurses::mvprintw(int y, int x, char *fmt, ...)
{
	int ret = ERR;
	
	va_list args;
	va_start(args, fmt);
	::move(y, x);
	ret = ::mvprintw(y, x, fmt);
	va_end(args);


	return ret;

}


int JamesCurses::wbox(WINDOW *win, chtype verch, chtype horch)
{
	return ::box(win, verch, horch);
}

int JamesCurses::wattron(WINDOW *win, int attrs)
{
	return ::wattron(win, attrs);
}

int JamesCurses::wattroff(WINDOW *win, int attrs)
{
	return ::wattroff(win, attrs);
}

int JamesCurses::attron(int attrs)
{
	return ::attron(attrs);
}

int JamesCurses::attroff(int attrs)
{
	return ::attroff(attrs);
}

int JamesCurses::init_pair(short pair, short f, short b)
{
	return ::init_pair(pair, f, b);
}

int JamesCurses::start_color()
{
	return ::start_color();
}

int JamesCurses::wrefresh(WINDOW *win)
{
	return ::wrefresh(win);
}

int JamesCurses::refresh()
{
	return ::refresh();
}

int JamesCurses::flash()
{
	return ::flash();
}

void JamesCurses::endwin()
{
	::endwin();
}

int JamesCurses::werase(WINDOW *win)
{
	return ::werase(win);
}

int JamesCurses::wbkgd(WINDOW *win, chtype ch)
{
	return ::wbkgd(win, ch);
}