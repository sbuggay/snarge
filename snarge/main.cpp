#include <iostream>

#include "Game.h"

#include "ResourcePath.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	cout << "Desolate " << version << endl;
	cout << "argc : " << argc << endl;
	cout << "argv : ";
	for(int i = 0; i < argc; i++) {
	    cout << argv[i] << " ";
	}
    cout << endl;
    
	Game g;
    g.init();
	g.run();    
    return 0;
}
