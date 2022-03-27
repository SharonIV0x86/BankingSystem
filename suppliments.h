#include <iostream>
#include <fstream>
#include <cstdio>
bool access = false;
void clear_screen();
void check_counter()
{
    static int cntr = -1;
    cntr++;
    std::cout << "counter is: " << cntr;
    if (cntr > 3)
    {
        std::cout << "\n\n\tToo many wrong attempts! " << std::endl;
        exit(EXIT_FAILURE);
    }
}
class BankingCalculations;

std::ofstream write_out_to_file(".dont_delete.txt", std::ios::app); // FILE I/O basically making object for reading from the file
std::ifstream read_from_the_file(".dont_delete.txt");

std::ifstream account_read_from_file(".account.txt");
std::ofstream account_write_to_file(".account.txt", std::ios::app);

class Login
{
protected:
    void create_a_account();
    void human_verification(std::string);
    std::string *string_array = new std::string[20];
    int *int_array = new int[200];
    std::string *dump_array = new std::string[100]; // index above 50 is for way too useless data hehe partition moment (gandhi moment)
    std::string *login_check_array = new std::string[10];
    void login_to_your_account(void);
    void check_login_credentials(void);
    void check_for_empty_fields(std::string);
public:
    void exec_human_verification(std::string directioner) { human_verification(directioner); } // have to keep human vec function protected so using this function to execute that function ironically
    void exec_creat_a_account() { create_a_account(); }                                        // will run create_a_account function as that is protected
    void exec_check_login_credentials(void) { check_login_credentials(); }
};
class working_class : public virtual Login // Deriving working class virtually from the Login class to avoid ambguity
{
protected:
    void Making_Choices();

public:
    void exec_making_choices() { Making_Choices(); }
};

class BankingCalculations : public virtual working_class // Deriving Banking calculation from working class that is virtual so working class will have the public members of login class and so baking calculations will have
{
public:
    int *depositing_array = new int[15], *withdrawing_array = new int[15], *IO_array = new int[15];
    void Account(void);
    void Deposit_or_Withdraw_Money(void);
    void delete_accounts();
    void get_to_know_something_cool();
    ~BankingCalculations()
    {
        std::cout << "\n\n\tObject destructor altered. " << std::endl;
        account_write_to_file << IO_array[10];
        account_write_to_file.close();
    }
};
void BankingCalculations ::get_to_know_something_cool()
{
    clear_screen();
    std::cout << "\n\n\tThis program was created by SharonIV0x86" << std::endl
              << "\n\n\tA lot of efforts have been put into " << std::endl
              << "\n\n\tStill there are some weak points in the code and it looks very complex" << std::endl
              << "\n\n\tand its also very unoptimized, yes i suck at coding swy :( lol" << std::endl
              << "\n\n\thttps://GitHub.com/SharonIV0X86";
}

BankingCalculations universal_object; // it is better for this main object to be here because this header file will be first provided to compiler and compiler will be known of this ojbect and i can use it all across
// Login functions defined from suppliments.h line 45-137
void Login ::check_login_credentials()
{
    check_counter();
    // clear_screen();
    std::cout << "\n\n\tEnter your name: " << std::endl;
    std::cout << "\n\n\t~~~~~> ";
    std::getline(std::cin, login_check_array[1]);
    check_for_empty_fields(login_check_array[1]);

    std::cout << "\n\n\tEnter your PIN number: " << std::endl;
    std::cout << "\n\n\t~~~~~> ";
    std::getline(std::cin, login_check_array[2]);
    check_for_empty_fields(login_check_array[2]);

    if (login_check_array[2].length() < 4 || login_check_array[2].length() > 4) // finding lenght of the user input pin.
    {
        clear_screen();
        std::cout << "\n\n\tPIN lenght must be strictly of 4 numbers only! " << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string check_creds_array[20];
    bool matched_password = 0;
    bool matched_PIN = 0;

    for (int i = 0; i < 20; i++)
    {
        read_from_the_file >> check_creds_array[i];
        if (login_check_array[1] == check_creds_array[i])
        {
            std::cout << "\n\n\tPassword matched. " << std::endl;
            matched_password = 1;
        }
        if (login_check_array[2] == check_creds_array[i])
        {
            std::cout << "\n\n\tPIN matched. " << std::endl;
            matched_PIN = 1;
        }
    }
    if (matched_password == 1 && matched_PIN == 1)
    {
        clear_screen();
        std::cout << "\n\n\tCREDENTIALS MATCHED SUCCESSFULLY! " << std::endl;
        std::cout << "\n\n\tPress any key to move to your account :)" << std::endl;
        std::cin.get();
        access = true;
        universal_object.Account();
    }
    if (matched_password == 0 && matched_PIN == 0)
    {
        std::cout << "\n\n\tcredentials do not match! " << std::endl;
        std::cout << "\n\n\tpress any key to login again" << std::endl;
        std::cin.get();

        universal_object.exec_making_choices();
    }
}
void Login ::create_a_account()
{
    std::cout << "\n\n\tEnter your Name: " << std::endl;
    std::cout << "\n\n\t~~~~~~> ";
    std::getline(std::cin, string_array[1]);
    check_for_empty_fields(string_array[1]);

re_enter_pin: // this goto right here if the pin lenght is above or below 4 characters the compiler will return user back here to enter pin again!

    std::cout << "\n\n\tEnter a PIN number of 4 characters: " << std::endl;
    std::cout << "\n\n\t~~~~~~> ";
    std::getline(std::cin, string_array[2]);
    check_for_empty_fields(string_array[2]);

    if (string_array[2].length() < 4 || string_array[2].length() > 4) // finding lenght of the user input pin.
    {
        clear_screen();
        std::cout << "\n\n\tPIN lenght must be strictly of 4 numbers only! " << std::endl;
        goto re_enter_pin;
    }
    int_array[3] = std::stoi(string_array[2]); // storing the string user entered pin in the int array after converting it

    if (!write_out_to_file) // if the file does not exist or cannot be opened simply show this array and gtfo
    {
        clear_screen();
        std::cerr << "\n\n\tOh no something went wrong! " << std::endl;
        exit(EXIT_FAILURE);
    }
    write_out_to_file << string_array[1] << "\n";
    write_out_to_file << int_array[3] << "\n\n";
    int_array[1] = 0; // declaring this becasue something is wrog and i can feel it.
    std::cout << "\n\n\tAccount Registration success! you may now log in back to the account." << std::endl;

    write_out_to_file.close();

    universal_object.exec_making_choices();
}
void Login ::human_verification(std::string secret = "none") // declaring the human_verification function of login class
{
    check_counter();
    std::string alphabets_uppercase = "ABCDEFGHIJKLMNOPQRS12345678abcdefghijklmnopqrstuvwxyz910TUVWXYZ";
    int random_number_for_string = (rand() % 58);
    int random_number = rand() % 9999;
    std::string verify = std::to_string(random_number) + alphabets_uppercase[random_number_for_string] + alphabets_uppercase[random_number_for_string] + alphabets_uppercase[random_number_for_string] + std::to_string(random_number);
    std::string input;
    std::cout << "\n\t\t|--------------------------------------------|"
              << "\n\t\t|                                            |"
              << "\n\t\t|VERIFICATION NUMBER----->" << verify << "\t     |"
              << "\n\t\t|Enter the number on screen for verification:|"
              << "\n\t\t|--------------------------------------------|" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~>";
    std::getline(std::cin, input);

    if (input.empty() || input != verify)
    {
        std::cout << "\n\n\tBAD_INPUT_ retry! the verification field cannot be empty!!" << std::endl;
        universal_object.exec_human_verification("none");
    }

    clear_screen();
    std::cout << "\n\n\tVERIFICATION SUCCESS!" << std::endl;
    std::cout << "\n\n\tRemember Your Credentials :) " << std::endl;
    if (secret == "register")
    {
        std::cout << "\n\n\tYou must enter your credentials now:  " << std::endl
                  << "\tPress any key. ";
        std::cin.get();
        create_a_account();
    }
    if (secret == "login")
    {
        exec_check_login_credentials();
    }
}

void clear_screen()
{
#ifdef _WIN32
    {
        std::system("cls");
    }
#else
    {
        std::system("clear");
    }
#endif
}
void Login::check_for_empty_fields(std::string field)
{
    if (field.empty())
    {
        std::cout << "this field cannot be empty father." << std::endl;
        exit(EXIT_FAILURE);
    }
}
std::ifstream extra_read_again(".account.txt", std::ios::app); // an extra ojb is created to resolve this problem

void BankingCalculations ::Account()
{
    // bank info containing data types declared publicly in class banking calculation.
    if (access == true)
    {
        clear_screen();
        std::cout << "\n\n\tWELCOME " << login_check_array[1] << std::endl;
    }
    else if (access != true)
    {
        std::cout << "\n\n\tAccount access denied! try again" << std::endl;
        exit(EXIT_SUCCESS);
    }
    int choice;
    extra_read_again >> int_array[10];
    account_write_to_file << int_array[10];
    account_write_to_file.close();
    if (int_array[10] >= 100000)
    {
        std::cout << "\n\n\tSUS activity detected, performing a full wipe on bank account! " << std::endl;
        int delete_cos_sus = remove(".account.txt");
        exit(EXIT_SUCCESS);
    }
    std::cout << "\n\n\tYour account holds the balance of: " << int_array[10] << " $";
    std::cout << "\n\n\tPress any key to move to main screen.";
    std::cin.get();
    std::cout << "\n\n\tPress 1 to deposit money" << std::endl
              << "\n\n\tPress 2 to withdraw money" << std::endl
              << "\n\n\tPress 3 to delete your bank account" << std::endl
              << "\n\n\tPress 4 to happily exit :) " << std::endl
              << "\n~~~~~>";
    std::cin >> choice;

    switch (choice)
    {

    case 1:
    {
        clear_screen();
        std::cout << "\n\n\tEnter the ammount of money you want to deposit: " << std::endl
                  << "\t~~~~>";
        std::cin >> depositing_array[2];
        if (depositing_array[2] >= 100000)
        {
            std::cout << "\n\n\tPlease enter a valid ammount under 100000 (hundered thousand)" << std::endl;
            exit(EXIT_FAILURE);
        }
        int_array[10] += depositing_array[2];
        account_write_to_file << int_array[10];

        std::cout << "\n\n\tYou deposited---> " << depositing_array[2] << " $";
        std::cout << "\n\n\tPress any key to move to main screen. " << std::endl;
        account_write_to_file.close();
        std::cin.get();
        std::cin.get();
        Account();
        break;
    }
    case 2:
    {
        clear_screen();
        std::cout << "\n\n\tEnter the ammount of money you want to withdraw: " << std::endl
                  << "\t~~~~~>";
        std::cin >> depositing_array[3];
        if (depositing_array[3] >= 10000)
        {
            std::cout << "\n\n\tPlease enter a valid ammount under 100000 (hundered thousand)" << std::endl;
            exit(EXIT_FAILURE);
        }
        int_array[10] -= depositing_array[3];
        account_write_to_file << IO_array[2];

        std::cout << "\n\n\tThe ammount to be withdrawn: " << depositing_array[3] << " $";
        std::cout << "\n\n\tPress any key to move to main screen." << std::endl;
        account_write_to_file.close();
        std::cin.get();
        std::cin.get();
        Account();
    }
    case 3:
    {
        clear_screen();
        std::cout << "\n\n\tWARNING! " << std::endl;
        std::cout << "\n\n\tAll your accounts will be deleted and will be unable to recover! " << std::endl;
        std::cout << "\n\n\tPress any key to continue. ";
        std::cin.get();
        int delete_files = remove(".dont_delete.txt");
        int delete_file2 = remove(".account.txt");
        std::cout << "\n\n\tThanks for using this program." << std::endl;
        exit(EXIT_SUCCESS);
    }
    case 4:
    {
        clear_screen();
        std::cout << "\n\n\tif you are reading this you are a great guy. im crying rn ;)" << std::endl;
        get_to_know_something_cool();
        exit(EXIT_SUCCESS);
    }
    default:
    {
        clear_screen();
        std::cerr << "\n\n\tOh no :( something went wrong! " << std::endl;
        exit(EXIT_FAILURE);
    }
    }
}
