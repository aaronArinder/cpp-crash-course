/*
 * Generate an InMemoryAccountDatabase that implements AccountDatabase.
 * */

#include <cstdio>

struct Logger {
    virtual ~Logger() = default;
    virtual void log_transfer(long from, long to, double amount) = 0;
    virtual void log_setting_amount(long to, double amount) = 0;
};

struct ConsoleLogger : Logger {
    void log_setting_amount(long to_account, double amount) override {
        printf("adding %f to %ld", amount, to_account);
    }

    void log_transfer(long from, long to, double amount) override {
        printf("[cons] %ld -> %ld: %f\n", from, to, amount);
    }
};

struct AccountDatabase {
    virtual ~AccountDatabase() = default;
    virtual void set_amount (long id, double amount) = 0;
    virtual double retrieve_amount (long id) = 0;
};

struct InMemoryAccountDatabase : AccountDatabase {
    InMemoryAccountDatabase(Logger& logger) : logger{ logger } {}
    void set_amount (long id, double amount) override {
        database[current_index++] = amount;
        logger.log_setting_amount(amount, id);
    };

    double retrieve_amount (long id) override {
        double total = 0;
        for (int i = 0; i < 100; i++) {
            total += database[i];
        }
        return total;
    };

    private:
        Logger& logger;
        double database[100] = {0};
        int current_index = 1;
};

struct Bank {
    Bank() : database{} {}
    InMemoryAccountDatabase* database;
};

int main() {
    Bank a {};
    a.database->set_amount(1234, 234.00);
    Bank b {};

}
