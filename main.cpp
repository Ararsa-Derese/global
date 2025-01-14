#include <stdio.h>
#include <iostream>
#include <fstream>
#include "headers/globals.h"
#include "headers/lexer.h"
#include "headers/parser.h"

using namespace std;

// main function

int main( int argc, char* argv[] ) { // take file name as parameter
    if (argc != 2) {
        // cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    ifstream file(argv[1]);
    if (!file.is_open()) {
        // cerr << "Error: Unable to open file '" << argv[1] << "'" << endl;
        return 1;
    }

    string source;
    string line;
    while (getline(file, line)) {
        Lexer lexer(line);
        Parser parser(lexer);
        int result = parser.parse();
    }

    return 0;
}
