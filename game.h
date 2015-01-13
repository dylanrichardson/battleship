#ifndef GAME_H
#define GAME_H

class grid
{
	public:
		grid();
		void display (void);
		int shoot (char, char);
		bool place (char, char);
		void update(char,char,char);
		char GRID[9][10] = {"8........",
							"7........",
							"6........",
							"5........",
							"4........",
							"3........",
							"2........",
							"1........",
							" ABCDEFGH"};
	protected:
};

class game
{
	public:
		game();
		void p1display (void);
		void p2display (void);
		bool p1Turn (void);
		bool p2Turn (void);
		void input (char [3]);
		void placeP1Ships (void);
		void placeP2Ships (void);
		void wait (int);
		void loop (void);
		grid p1bombs,p2bombs,p1navy,p2navy;
		int p1Ships = 6, p2Ships = 6;
	protected:
};

#endif
