#ifndef MATCHING_ENGINE_HPP
#define MATCHING_ENGINE_HPP

#include "order_book.hpp"

class MatchingEngine
{
public:
    void process_order(double price, int quantity, bool is_buy);

private:
    OrderBook order_book;
};

#endif // MATCHING_ENGINE_HPP
