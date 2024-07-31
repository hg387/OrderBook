#pragma once
#include "order.h"
#include <unordered_map>
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <queue>


class TopOfBook{
    private:
        size_t timestamp;
        struct CompareBuy {
            bool operator()(const std::shared_ptr<Order>& a, const std::shared_ptr<Order>& b) {
                return a->price < b->price || (a->price == b->price && a->timestamp > b->timestamp);
            }
        };

        struct CompareSell {
            bool operator()(const std::shared_ptr<Order>& a, const std::shared_ptr<Order>& b) {
                return a->price > b->price || (a->price == b->price && a->timestamp > b->timestamp);
            }
        };

    public:
        std::priority_queue<std::shared_ptr<Order>, std::vector<std::shared_ptr<Order>>, CompareBuy> buyOrders;
        std::priority_queue<std::shared_ptr<Order>, std::vector<std::shared_ptr<Order>>, CompareSell> sellOrders;
        std::map<size_t, std::shared_ptr<Order>, std::greater<size_t>> buyQuantities;
        std::map<size_t, std::shared_ptr<Order>> sellQuantities;
        std::string symbol;

        TopOfBook(std::string S): symbol(S), timestamp(0) {}

        friend std::ostream& operator<<(std::ostream&, const TopOfBook&);

        template <Order::Action action>
        void addOrder(size_t quantity, size_t price);
};