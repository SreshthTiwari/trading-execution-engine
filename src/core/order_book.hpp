#ifndef ORDER_BOOK_HPP
#define ORDER_BOOK_HPP

#include <map>
#include <vector>

struct Order
{
    double price;
    int quantity;
    bool is_buy;
};

class OrderBook
{
public:
    void add_order(double price, int quantity, bool is_buy);
    void remove_order(double price, int quantity, bool is_buy);
    double get_best_bid();
    double get_best_ask();

private:
    std::map<double, int> buy_orders;  // stores buy orders sorted by price descending
    std::map<double, int> sell_orders; // stores sell orders sorted by price ascending
};

#endif // ORDER_BOOK_HPP
