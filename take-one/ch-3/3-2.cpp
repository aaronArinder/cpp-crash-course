#include <cstdio>

enum class Case {
    Upper,
    Lower
};

struct AtoE {
    void read_from(Case casing){
        switch (casing){
            case Case::Upper: {
                printf("Upper: %s\n", upper);
                break;
            }
            case Case::Lower: {
                printf("Lower: %s\n", lower);
                break;
            }
        }
    }

    void write_to(Case casing, int index, char character) {
        if (index > 6) {
            printf("Index must be below 6\n");
        } else {
            switch (casing){
                case Case::Upper: {
                    upper[index] = character;
                    break;
                }
                case Case::Lower: {
                    lower[index] = character;
                    break;
                }
            }
        }
    }

    private:
        char lower[6] = "abc?e";
        char upper[6] = "ABC?E";
};

int main() {
    AtoE string;
    string.read_from(Case::Upper);
    string.write_to(Case::Upper, 3, 'D');
    string.read_from(Case::Upper);

    string.read_from(Case::Lower);
    string.write_to(Case::Lower, 3, 'd');
    string.read_from(Case::Lower);

    string.write_to(Case::Lower, 7, 'g');
}

