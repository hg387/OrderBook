#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "orderbook_core/parser.h"

void readMarketData(std::string filename){
    std::string line;
    std::ifstream file(filename);
    while(std::getline(file, line)){
        std::stringstream ss(line);
        Parser::on_market_data(ss.str().c_str());
    }
}

int main(){
    std::cout << "----------------------- Welcome to OrderBook -----------------------" << std:: endl;
    std::cout << "Reading market data from input.txt...." << std::endl;
    readMarketData("./input.txt");
    std::cout << "------- Printing Order Book -------";
    Parser::printCompleteBook();
    return 0;
}