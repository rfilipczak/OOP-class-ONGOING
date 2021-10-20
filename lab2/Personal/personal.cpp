#include <iostream>
#include <string_view>
#include <fstream>

#include "./personal.hpp"



void print_usage(std::string_view prog)
{
    std::cout << "usage: " << prog << " filename\n" 
              << "filename -- file where personal data is stored\n";
}

int main(int argc, char *argv[])
{
    std::string_view prog{ argv[0] };
    if (argc != 2)
    {
        std::cerr << prog << ": error: Invalid number of arguments\n";
        print_usage(prog);
        return 1;
    }

    std::string_view filename{ argv[1] };
    std::ifstream ifile{ filename.data() };
    if (ifile)
    {
        PersonalDataBank bank{ ifile };
        ifile.close();

        std::cout << bank << '\n';

        std::string s;
        std::cout << "Would you like to edit the databank [y/n]?: ";
        std::getline(std::cin, s);

        if (s == "y")
        {
            auto print_menu = []() {
                std::cout << "[q] Quit\n" <<
                 "[h] Print this menu\n" <<
                 "[p] Print databank\n" <<
                 "[a] Add entry\n" <<
                 "[r] Remove entry\n" <<
                 "[s] Save changes to file\n";
            };

            print_menu();

            bool quit{ false };
            do {
                std::cout << "Enter the option: ";
                std::getline(std::cin, s);
                if (s == "q")
                {
                    quit = true;
                }
                else if (s == "h")
                {
                    print_menu();
                }
                else if (s == "p")
                {
                    std::cout << bank << '\n';
                }
                else if (s == "a")
                {
                    std::cout << "Enter a new entry (name, lastname, address, pesel): ";
                    std::getline(std::cin, s);
                    using Result = PersonalDataBank::AddResultType;
                    auto result = bank.add(s);
                    if (result == Result::Success)
                    {
                        std::cout << "Successfully added new entry\n";
                    }
                    else
                    {
                        std::cerr << "Failed to add new entry: " << s << ": ";
                        if (result == Result::InvalidFormat)
                            std::cerr << "Invalid format\n";
                        else if (result == Result::AlreadyInBank)
                            std::cerr << "Pesel already in the bank\n";
                        else
                            std::cerr << "Unexpected error\n";
                    }
                }
                else if (s == "r")
                {
                    std::cout << "Enter pesel to remove: ";
                    std::getline(std::cin, s);
                    using Result = PersonalDataBank::RemoveResultType;
                    auto result = bank.remove(s);
                    if (result == Result::Success)
                    {
                        std::cout << "Succsessfully removed entry\n";
                    }
                    else
                    {
                        std::cerr << "Failed to remove entry: " << s << ": ";
                        if (result == Result::PeselNotFound)
                            std::cerr << "Pesel not found in the bank\n";
                        else
                            std::cerr << "Unexpected error\n";
                    }
                }
                else if (s == "s")
                {
                    std::cout << "Saving to file " << filename << "...\n";
                    std::ofstream ofile{ filename.data() };
                    bank.saveToFile(ofile);
                    std::cout << "done.\n";
                }
                else
                {
                    std::cout << "Unrecognized option\n";
                }
            } while (!quit);
        }
    }
    else
    {
        std::cerr << prog << ": error: Invalid filename: " << filename << '\n';
        print_usage(prog);
        return 1;
    }

    return 0;
}
