#include "matching_engine.hpp"
#include <iostream>

void MatchingEngine::process_order(double price, int quantity, bool is_buy)
{
    // check if order can be matched
    if (is_buy)
    {
        double best_ask = order_book.get_best_ask();
        if (best_ask > 0.0 && price >= best_ask)
        {
            std::cout << "order matched at price: " << best_ask << "\n";
            order_book.remove_order(best_ask, quantity, false);
        }
        else
        {
            order_book.add_order(price, quantity, true);
        }
    }
    else
    {
        double best_bid = order_book.get_best_bid();
        if (best_bid > 0.0 && price <= best_bid)
        {
            std::cout << "order matched at price: " << best_bid << "\n";
            order_book.remove_order(best_bid, quantity, true);
        }
        else
        {
            order_book.add_order(price, quantity, false);
        }
    }
}
