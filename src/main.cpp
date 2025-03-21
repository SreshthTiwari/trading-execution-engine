#include "matching_engine.hpp"
#include "market_data_interface.hpp"
#include <iostream>

int main()
{
    // fetch live stock price
    std::string symbol = "AAPL";
    double live_price = get_stock_price(symbol);
    std::cout << "live stock price for " << symbol << ": " << live_price << "\n";

    // create matching engine
    MatchingEngine engine;

    // process buy order
    std::cout << "placing buy order at: " << live_price << "\n";
    engine.process_order(live_price, 10, true);

    return 0;
}
