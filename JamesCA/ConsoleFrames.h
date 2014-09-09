#ifndef CONSOLEFRAMES_H
#define CONSOLEFRAMES_H

#include <windows.h>
#include <string>


class ConsoleFrames
{
public:
	COORD CursorPosition;

	void gotoXY(int col, int row);
	void gotoXY(int col, int row, int color, string text);
	void Draw(int col, int row, int length, int height, int color, int style, bool filled, int shadow);

private:
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
};

#endif /* CONSOLEFRAMES_H */

