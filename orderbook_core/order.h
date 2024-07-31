struct Order{
    enum Action {BUY = 0, SELL = 1};

    Action action;
    size_t price;
    size_t quantity;
    bool valid;
    size_t timestamp;

    Order(Action a, int p, int q, int ts)
        : action(a), price(p), quantity(q), timestamp(ts), valid(true) {}

    // Disable copy and move constructors and assignment operators
    Order(const Order&) = delete;
    Order(Order&&) = delete;
    Order& operator=(const Order&) = delete;
    Order& operator=(Order&&) = delete;
};