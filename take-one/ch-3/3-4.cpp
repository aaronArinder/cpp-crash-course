#include <cstdio>

// main point: references can't be reseated

int main() {
    auto original = 100;
    auto& original_ref = original;

    printf("Original: %d\n", original);
    printf("Reference: %d\n", original_ref);

    auto new_value = 200;
    original_ref = new_value;

    printf("Original: %d\n", original);
    printf("New value: %d\n", new_value);
    printf("Reference: %d\n", original_ref);
}
