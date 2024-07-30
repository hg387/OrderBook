#include <mutex>

class TopOfBook{
    private:
        static std::once_flag initInstanceFlag;
        static TopOfBook* instance;

        TopOfBook() = default;
        ~TopOfBook() = default;

        static void initTopOfBook();

    public:
        TopOfBook(const TopOfBook&) = delete;
        TopOfBook& operator=(const TopOfBook&) = delete;

        static TopOfBook* getInstance();
};