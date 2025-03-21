#include "order_book.hpp"
#include <iostream>

void OrderBook::add_order(double price, int quantity, bool is_buy)
{
    // add order to order book
    if (is_buy)
    {
        buy_orders[price] += quantity;
    }
    else
    {
        sell_orders[price] += quantity;
    }
}

void OrderBook::remove_order(double price, int quantity, bool is_buy)
{
    // remove order from order book
    if (is_buy)
    {
        if (buy_orders.count(price))
        {
            buy_orders[price] -= quantity;
            if (buy_orders[price] <= 0)
            {
                buy_orders.erase(price);
            }
        }
    }
    else
    {
        if (sell_orders.count(price))
        {
            sell_orders[price] -= quantity;
            if (sell_orders[price] <= 0)
            {
                sell_orders.erase(price);
            }
        }
    }
}

double OrderBook::get_best_bid()
{
    // return highest buy order price
    if (buy_orders.empty())
        return 0.0;
    return buy_orders.rbegin()->first;
}

double OrderBook::get_best_ask()
{
    // return lowest sell order price
    if (sell_orders.empty())
        return 0.0;
    return sell_orders.begin()->first;
}
