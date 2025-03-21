#ifndef RISK_CHECKS_HPP
#define RISK_CHECKS_HPP

#include <vector>
#include <string>

// contains functions for evaluating trade risks

class RiskChecks {
public:
    // evaluates if trade order exceeds risk limits
    static bool check_order_size(double order_size, double max_size);

    // evaluates if trade violates price constraints
    static bool check_price_limits(double order_price, double min_price, double max_price);

    // evaluates if trade passes all risk criteria
    static bool validate_trade(double order_size, double max_size, 
                               double order_price, double min_price, double max_price);
};

#endif // RISK_CHECKS_HPP
