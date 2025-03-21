#include "market_data_interface.hpp"
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <stdio.h>
#include <io.h>

double get_stock_price(std::string symbol)
{
    // execute python script to fetch stock price
    FILE *pipe = _popen("python3 market_data/yahoo_data.py ", "r");
    if (!pipe)
    {
        std::cerr << "error opening pipe\n";
        return -1;
    }

    // read output from python script
    char buffer[128];
    std::string result = "";
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr)
    {
        result += buffer;
    }
    _pclose(pipe);

    // convert output to double
    std::stringstream ss(result);
    double price;
    ss >> price;

    return price;
}
