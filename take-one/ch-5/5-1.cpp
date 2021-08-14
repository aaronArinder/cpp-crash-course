/*
 * You didn't implement an accounting system in your Bank. Design an interface
 * called AccountDatabase that can retrieve and set amounts in bank accounts
 * (identified by a long id).
 * */

#include <cstdio>

struct AccountDatabase {
    virtual void set_amount (long id) = 0;
    virtual void retrieve_amount (long id) = 0;
};

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount);
    }
};

