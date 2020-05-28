#include <cstdio>

struct Element {
    Element* next{};
    Element* previous{};

    void insert_after(Element* new_element) {
        new_element->next = next;
        next = new_element;
    }

    void insert_before(Element* new_element) {
        new_element->previous = previous;
        previous = new_element;
    }

    char prefix[2];
    short operating_number;
};

int main() {
    Element trooper1, trooper2, trooper3;

    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;

    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;

    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 115;


    trooper1.insert_after(&trooper2);
    trooper2.insert_after(&trooper3);

    /*
     * order matters: if you have this,
     *
     *  trooper2.insert_before(&trooper1);
     *  trooper3.insert_before(&trooper2);
     *
     * then the correct ordering won't be printed
     *
     * why? because when we take trooper3's `previous` and use it
     * for trooper2's, trooper3->previous points to null; so, we then
     * point trooper2's `previous` to null, despite having already set
     * it to trooper1 (i.e., it overwrites trooper1 to point to null)
     *
     * t2 insert_before t1
     * t1->previous = null*
     * t2->previous = t1
     *
     * t3 insert_before t2
     * t2->previous = null*
     * t3->previous = t2
     * */

    trooper2.insert_before(&trooper1);
    trooper3.insert_before(&trooper2);

    printf("Linked list moving 'foward': \n\n");
    for (Element *cursor = &trooper1; cursor; cursor = cursor->next){
        printf("stormtrooper %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number
        );
    }

    printf("\n\nAnd now the other way:\n\n");
    for (Element *cursor = &trooper3; cursor; cursor = cursor->previous){
        printf("stormtrooper %c%c-%d\n",
            cursor->prefix[0],
            cursor->prefix[1],
            cursor->operating_number
        );
    }
}
