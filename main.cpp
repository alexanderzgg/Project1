#include <iostream>
#include "Lexer.h"
#include <fstream>
#include "Parser.h"
int main(int argc, char* argv[]) {
    //Check number of arguments
    if(argc != 2)
    {
        std::cout << "Error, please provide only command line argument after the executable" << std::endl;
        return 0;
    }

    //Extract contents of file as a string
    std::string filename = argv[1];
    std::string fileContents;
    std::ifstream inFile (filename, std::ifstream::in);
    while(inFile.peek() != EOF)
    {
        fileContents.push_back(inFile.get());
    }
    fileContents.push_back(inFile.get());

    //Create Lexer and feed it the file contents. Get back a vector of tokens
    Lexer mainLex = Lexer();
    mainLex.Run(fileContents);
    std::vector<Token*> tokenData = mainLex.SendTokens();

    //Print out all tokens
//    for(unsigned i = 0; i < tokenData.size(); i++)
//    {
//        std::cout << tokenData.at(i)->ToString() << std::endl;
//    }
//    std::cout << "Total Tokens = " << tokenData.size() << std::endl;

    //Create Parser and parse the token vector
    Parser mainParse = Parser(tokenData);
    mainParse.RunDatalogProgram();
    return 0;
}
