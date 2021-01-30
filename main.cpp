#include <iostream>
#include "Lexer.h"
#include <fstream>

#include <cctype>

int main(int argc, char* argv[]) {
    std::string filename = argv[1];
    std::string fileContents;

    std::ifstream inFile (filename, std::ifstream::in);
    while(inFile.peek() != EOF)
    {
        fileContents.push_back(inFile.get());
    }

    Lexer mainLex = Lexer();
    mainLex.Run(fileContents);
    std::vector<Token*> tokenData = mainLex.SendTokens();

    for(unsigned i = 0; i < tokenData.size(); i++)
    {
        std::cout << tokenData.at(i)->ToString() << std::endl;
    }



// Token testing
//    Token newTok = Token(UNDEFINED, "Whoah", 21);
//    std ::cout << newTok.ToString() << std::endl;

    return 0;
}
