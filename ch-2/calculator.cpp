#include <cstdio>

enum class Operation {
    Add,
    Subtract,
    Multiply,
    Divide
};

struct Calculator {
    Calculator(Operation op) {
        operation = op;
    }

    int calculate(int a, int b) {
        switch(operation) {
            case Operation::Add:
                return a + b;
            case Operation::Subtract:
                return a - b;
            case Operation::Multiply:
                return a * b;
            case Operation::Divide:
                return a / b;
        }
    }

    private:
        Operation operation;
};

int main(){
    Calculator calc_add(Operation::Add);
    int result_add = calc_add.calculate(1, 4);
    printf("%d\n", result_add);

    Calculator calc_sub(Operation::Subtract);
    int result_sub = calc_sub.calculate(1, 4);
    printf("%d\n", result_sub);

    Calculator calc_mult(Operation::Multiply);
    int result_mult = calc_mult.calculate(1, 4);
    printf("%d\n", result_mult);

    Calculator calc_div(Operation::Divide);
    int result_div = calc_div.calculate(1, 4);
    printf("%d\n", result_div);
    return 0;
}
