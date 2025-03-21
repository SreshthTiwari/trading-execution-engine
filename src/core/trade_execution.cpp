#include "trade_execution.hpp"
#include <iostream>

// processes trade order and executes if risk criteria met
bool TradeExecution::execute_trade(double order_size, double order_price, 
                                   double max_size, double min_price, double max_price) {
    if (!RiskChecks::validate_trade(order_size, max_size, order_price, min_price, max_price)) {
        std::cout << "trade execution failed: risk checks not passed" << std::endl;
        return false;
    }

    // logic for sending order to market (mocked)
    std::cout << "trade executed: size=" << order_size << " price=" << order_price << std::endl;
    return true;
}
