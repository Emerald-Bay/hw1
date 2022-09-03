#include "split.h"
#include <iostream>

int main() {
    Node *ten = new Node {10, nullptr};
    Node *nine = new Node{9, ten};
    Node *eight = new Node{8, nine};
    Node *seven = new Node{7, eight};
    Node *six = new Node{6, seven};
    Node *five = new Node{5, six};
    Node *four = new Node {4, five};
    Node *three = new Node{3, four};
    Node *two = new Node{2, three};
    Node *one = new Node{1, two};

    Node *oddsStart;
    Node *evensStart;

    Node *temp;
    
    std::cout << "Test 1" << std::endl;
    split(one, oddsStart, evensStart);
    std::cout << "Test 2" << std::endl;

    std::cout << "Odds" << std::endl;
    while (oddsStart->next != nullptr) {
        std::cout << oddsStart->value << std::endl;
        temp = oddsStart;
        oddsStart = oddsStart->next;
        delete temp;
    }

    std::cout << std::endl;
    std::cout << "Evens" << std::endl;
    while (evensStart->next != nullptr) {
        std::cout << evensStart->value << std::endl;
        temp = evensStart;
        evensStart = evensStart->next;
        delete temp;
    }
}