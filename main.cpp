#include <iostream>
#include "game.h"

using namespace std;

int main() {
	char ans;
	do {
		game bs;
		//place ships
		bs.placeP1Ships();
		bs.placeP2Ships();
		bs.loop();
		do {
			cout<<"Do you want to play again?(y/n) ";
			cin>>ans;
		} while (ans!='y'&&ans!='n');
	} while (ans=='y');
	return 0;
}
