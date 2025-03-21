#include "risk_checks.hpp"

// evaluates if trade order exceeds risk limits
bool RiskChecks::check_order_size(double order_size, double max_size) {
    return order_size <= max_size;
}

// evaluates if trade violates price constraints
bool RiskChecks::check_price_limits(double order_price, double min_price, double max_price) {
    return order_price >= min_price && order_price <= max_price;
}

// evaluates if trade passes all risk criteria
bool RiskChecks::validate_trade(double order_size, double max_size, 
                                double order_price, double min_price, double max_price) {
    return check_order_size(order_size, max_size) && check_price_limits(order_price, min_price, max_price);
}
