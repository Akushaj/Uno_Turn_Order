#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----
    std::cout << std::endl << "== Uno scnene ==" << std::endl;
    std::unique_ptr<List<Player>> table1 = makeList<Player>();

    std::cout << "The table forms. Players take their seats:" << std::endl;
    table1->addFront(new Player(20 , "Kratos"));
    table1->addFront(new Player(30 ,"Ashura"));
    table1->addFront(new Player(40, "TungTungSahur"));
    table1->print();

    // using Add anywhere method
    std::cout << "Sonion pulls up a chair between Ashura and Kratos." << std::endl;
    table1->addAnywhere(2, new Player(67 , "Sonion"));
    table1->print();


    // player uses the reverse card
    std::cout << std::endl << "Ashura plays a Reverse card!" << std::endl;
    table1->reverse();
    table1->print();

    std::cout << std::endl << "Sonion runs out of cards and leaves the table." << std::endl;    //player runs out of card
    table1->deleteAnywhere(1);
    table1->print();

    //making a new table and values to it
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addFront(new Player(7 , "Superman"));
    table2->addFront(new Player(8, "Spiderman"));
    table2->addFront(new Player(9, "Plastic-man"));

    std::cout << std::endl << "A second table finishes early and wants to join the first." << std::endl;
    std::cout << "-- table1 before merge --" << std::endl;
    table1->print();
    std::cout << "-- table2 before merge --" << std::endl;
    table2->print();

    table1->concat(table2.get());
    std::cout << std::endl << "The tables merge!" << std::endl;
    std::cout << "-- table1 after merge --" << std::endl;
    table1->print();
    std::cout << "-- table2 after merge (empty) --" << std::endl;
    table2->print();

    return 0;
}
