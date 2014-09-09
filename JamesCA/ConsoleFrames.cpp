using namespace std;

#include "ConsoleFrames.h"
#include <iostream>

//NAME: gotoXY
//DESCRIPTION: takes desired column and row as input, sets the cursor position

void ConsoleFrames::gotoXY(int col, int row)
{
	CursorPosition.X = col;
	CursorPosition.Y = row;
	SetConsoleCursorPosition(console, CursorPosition);
}

//NAME: gotoXY
//DESCRIPTION: sets the cursor position with the option to change color and include text

void ConsoleFrames::gotoXY(int col, int row, int color, string text)
{
	CursorPosition.X = col;
	CursorPosition.Y = row;
	SetConsoleCursorPosition(console, CursorPosition);

	SetConsoleTextAttribute(console, color);

	cout << text;

	SetConsoleTextAttribute(console, 15);
}

//NAME: Draw
//DESCRIPTION: draws a box with top left corner at a given point of given length/height with options
	//to include color, different styles, shadows, and fill

void ConsoleFrames::Draw(int col, int row, int length, int height, int color, int style, bool fill, int sw)
{
	// Draws a 1 or 2 line box 
	int a;
	if (sw >4)
		sw = 4;
	style = (style - 1) * 6;
	char box[12];
	char shdw[5];

	//various styles of border/shadow
	box[0] = '\332';//  ┌
	box[1] = '\277';//  ┐
	box[2] = '\300';//  └
	box[3] = '\331';//  ┘
	box[4] = '\263';//  │ 
	box[5] = '\304';//  ─
	box[6] = '\311';//  ╔ 
	box[7] = '\273';//  ╗
	box[8] = '\310';//  ╚
	box[9] = '\274';//  ╝
	box[10] = '\272';// ║
	box[11] = '\315';// ═
	shdw[1] = '\260';// ░
	shdw[2] = '\261';// ▒
	shdw[3] = '\262';// ▓
	shdw[4] = '\333';// █

	//top left corner character, top right, etc...
	char tl, tr, bl, br, side, edge, shadow;
	tl = box[style];
	tr = box[style + 1];
	bl = box[style + 2];
	br = box[style + 3];
	side = box[style + 4];
	edge = box[style + 5];
	shadow = shdw[sw];

	//lines, shadow, fill
	string Line(length - 2, edge);
	string Shadow(length, shadow);
	string Fill(length - 2, ' ');
	gotoXY(col, row);

	//set color to desired color before screen output
	SetConsoleTextAttribute(console, color);

	//output to console
	cout << tl << Line << tr;
	for (a = 1; a <height - 1; a++)
	{
		gotoXY(col, row + a);
		cout << side;
		if (fill)
			cout << Fill;
		else
			gotoXY(col + length - 1, row + a);
		cout << side;
		if (sw)
			cout << shadow;
	}
	gotoXY(col, (height + row) - 1);
	cout << bl << Line << br;
	if (sw)
	{
		cout << shadow;
		gotoXY(col + 1, row + height, color, Shadow);
	}

	//set color back to standard after screen output
	SetConsoleTextAttribute(console, 15);

}