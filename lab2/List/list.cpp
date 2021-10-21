#include <iostream>
#include <string_view>
#include <fstream>

#include "./list.hpp"


void print_usage(std::string_view prog)
{
    std::cout << "usage: " << prog << " filename\n" 
              << "filename -- file to read values from\n";
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
        List<int> list{ ifile };
        ifile.close();

        std::cout << list << '\n';

        std::string choice;
        std::cout << "Would you like to edit the list [y/n]?: ";
        std::getline(std::cin, choice);

        if (choice == "y")
        {
            auto print_menu = []() {
                std::cout << "[q] Quit\n" <<
                 "[h] Print this menu\n" <<
                 "[p] Print list\n" <<
                 "[i] Insert value\n" <<
                 "[r] Remove value\n" <<
                 "[s] Sort\n" <<
                 "[save] Save to file\n";
            };

            print_menu();

            bool quit{ false };
            do {
                std::cout << "Enter the option: ";
                std::getline(std::cin, choice);

                if (choice == "q")
                {
                    quit = true;
                }
                else if (choice == "h")
                {
                    print_menu();
                }
                else if (choice == "p")
                {
                    std::cout << list << '\n';
                }
                else if (choice == "i")
                {
                    decltype(list)::NodeIDType value;
                    decltype(list)::NodeIDType after;
                    
                    std::cout << "Enter value to insert: ";
                    std::getline(std::cin, choice);
                    if (std::istringstream{choice} >> value)
                    {
                        std::cout << "Enter value to insert AFTER: ";
                        std::getline(std::cin, choice);
                        if (std::istringstream{choice} >> after)
                        {
                            auto node = list.insert_after(after, value);
                            std::cout << "Successfully inserted new node: " << node << '\n';
                        }
                        else
                        {
                            std::cerr << "Invalid format: " << choice << '\n';
                        }
                    }
                    else
                    {
                        std::cerr << "Invalid format: " << choice << '\n';
                    }
                }
                else if (choice == "r")
                {
                    decltype(list)::NodeIDType value;
                    std::cout << "Enter value to remove: "; 
                    std::getline(std::cin, choice);
                    if (std::istringstream{choice} >> value)
                    {
                        using Result = decltype(list)::RemoveResultType;
                        Result result = list.remove(value);
                        if (result == Result::Success)
                        {
                            std::cout << "Successfully removed node with value " << value << '\n';
                        }
                        else
                        {
                            std::cout << "Node with value " << value << " not found in the list\n";
                        }
                    }
                    else
                    {
                        std::cerr << "Invalid format for value: " << choice << '\n';
                    }
                }
                else if (choice == "s")
                {
                    if (list.length() > List<int>::SortThreshold)
                    {
                        std::cout << "\tWarning: List has " << list.length() << " nodes. Sorting list with over " << List<int>::SortThreshold << " nodes may be slow.\n";
                        std::cout << "\tDo you wish to proceed (y/n)? ";
                        std::string answer;
                        std::getline(std::cin, answer);
                        if (answer != "y")
                        {
                            std::cout << "Aborting sort...\n";
                        }
                        else
                        {
                            // TODO: duplicate code
                            std::cout << "Sorting...\n";
                            list.sort();
                        }
                    }
                    else
                    {
                        // TODO: duplicate code
                        std::cout << "Sorting...\n";
                        list.sort();
                    }
                    std::cout << "done.\n";
                }
                else if (choice == "save")
                {
                    std::cout << "Saving to file " << filename << "...\n";
                    std::ofstream ofile{ filename.data() };
                    list.saveToFile(ofile);
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
