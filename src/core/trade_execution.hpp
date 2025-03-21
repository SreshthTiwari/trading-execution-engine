#ifndef TRADE_EXECUTION_HPP
#define TRADE_EXECUTION_HPP

#include <string>
#include "risk_checks.hpp"

// represents trade execution module
class TradeExecution {
public:
    // processes trade order and executes if risk criteria met
    static bool execute_trade(double order_size, double order_price, 
                              double max_size, double min_price, double max_price);
};

#endif // TRADE_EXECUTION_HPP
