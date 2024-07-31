#include "top_of_book.h"

std::ostream& operator<<(std::ostream& os, const TopOfBook& tp){
    os << tp.symbol;
    return os;
}

template<>
void TopOfBook::addOrder<Order::BUY>(size_t quantity, size_t price){
    if (buyQuantities.find(price) == buyQuantities.end()){
        std::shared_ptr<Order> order = std::make_shared<Order>(Order::BUY, price, quantity, timestamp);
        buyQuantities[price] = order;
        buyOrders.push(order);
    }
    else{
        buyQuantities[price]->quantity += quantity;
    }
    ++timestamp;
};

template<>
void TopOfBook::addOrder<Order::SELL>(size_t quantity, size_t price){
    if (sellQuantities.find(price) == sellQuantities.end()){
        std::shared_ptr<Order> order = std::make_shared<Order>(Order::SELL, price, quantity, timestamp);
        sellQuantities[price] = order;
        sellOrders.push(order);
    }
    else{
        sellQuantities[price]->quantity += quantity;
    }
    ++timestamp;
};