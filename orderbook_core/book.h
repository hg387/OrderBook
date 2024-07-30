#include <mutex>
#include <unordered_map>
#include <string>

struct Order{
    enum Action {BUY, SELL};

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


class TopOfBook{

};

class Book{
    private:
        static std::once_flag initInstanceFlag;
        static Book* instance;
        static std::unordered_map<std::string, TopOfBook*> snapshots; 

        Book() = default;
        ~Book() = default;

        static void initBook();

    public:
        Book(const Book&) = delete;
        Book& operator=(const Book&) = delete;

        static Book* getInstance();
};
