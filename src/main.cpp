#include <iostream>
#include "trade_execution.hpp"

int main() {
    // define risk parameters
    double max_order_size = 1000.0;
    double min_price = 10.0;
    double max_price = 500.0;

    // example trade orders
    double order_size1 = 500.0;
    double order_price1 = 50.0;

    double order_size2 = 1500.0; // exceeds max_order_size
    double order_price2 = 50.0;

    // process first trade
    std::cout << "processing first trade:" << std::endl;
    TradeExecution::execute_trade(order_size1, order_price1, max_order_size, min_price, max_price);

    // process second trade
    std::cout << "processing second trade:" << std::endl;
    TradeExecution::execute_trade(order_size2, order_price2, max_order_size, min_price, max_price);

    return 0;
}
