#include <iostream>
#include "suppliments.h"

// working_class universal_object;
void working_class::Making_Choices()
{

    std::cout << "\n\n\tPress 1 to Create An Account: "
              << "\n\n\tPress 2 to Login in to current account: "
              << "\n\n\tPress 3 to exit happily :) and get to know something cool! "
              << "\n~~~~~>";
    std::getline(std::cin, dump_array[1]);
    check_for_empty_fields(dump_array[1]);

    int_array[1] = std::stoi(dump_array[1]);

    switch (int_array[1])
    {
    case 1:
    {
        clear_screen();
        std::cout << "\n\n\tIn order to create a new account you must complete human verification! " << std::endl;
        std::cin.ignore();
        human_verification("register");
    }
    case 2:
    {
        clear_screen();
        std::cout << "\n\n\tIn order to Login to the account you must complete human verification! " << std::endl;
        human_verification("login");
    }
    case 3:
    {
        clear_screen();
        universal_object.get_to_know_something_cool();
        exit(EXIT_SUCCESS);
    }
    break;

    default:
        std::cerr << "\n\n\tWrong Choice :( " << std::endl;
        break;
    }
}

int main()
{

    universal_object.exec_making_choices();
}
