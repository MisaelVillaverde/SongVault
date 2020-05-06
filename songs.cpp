#include <iostream>
#include <string>
#include <vector>
#include "songs.hpp"

// default
Songs new_human;
bool user_created = false;

void menu()
{
    int option;
    std::cout << "Menu: \n";

    if (!user_created)
    {
        std::cout << "> To create user press 1: \n> ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            create_user();
            break;
        default:
            std::cout << "Choose a valid option\n";
            menu();
            break;
        }
    }
    else
    {
        std::cout << "> To add songs press 1\n";
        std::cout << "> To show songs press 2\n";
        std::cout << "> To remove a song press 3\n> ";
        std::cin >> option;
        switch (option)
        {
        case 1:
            new_human.add_songs();
            break;
        case 2:
            new_human.show_songs();
            break;
        case 3:
            new_human.remove_songs();
            break;
        default:
            std::cout << "Choose a valid option\n";
            menu();
            break;
        }
    }
}

void create_user()
{
    std::string name;
    int pass, pconf;
    std::cout << "Insert your username: ";
    std::cin >> name;
    std::cout << "Insert your Password: ";
    std::cin >> pass;
    std::cout << "Confirm your Password: ";
    std::cin >> pconf;
    if (pconf == pass)
    {
        user_created = true;
        new_human = Songs(name, pass);
        std::cout << "\n----------------------------------\n"
                  << std::endl;
        std::cout << "User " << new_human.show_user() << " Created!";
        std::cout << "\n\n----------------------------------\n"
                  << std::endl;
    }
    while (pconf != pass)
    {
        std::cout << "Wrong Digits!, Try again: ";
        std::cin >> pconf;
        if (pconf == pass)
        {
            user_created = true;
            new_human = Songs(name, pass);
            std::cout << "\n----------------------------------\n"
                      << std::endl;
            std::cout << "User " << new_human.show_user() << " Created!";
            std::cout << "\n\n----------------------------------\n"
                      << std::endl;
        }
    }
    std::cin;
    std::cout << "\n";
    menu();
}

std::string Songs::show_user()
{
    return user;
}

Songs::Songs(std::string new_user, int new_password)
    : user(new_user), password(new_password) {}

Songs::Songs()
{
    return;
}

void Songs::add_songs()
{
    std::string text;
    std::cout << "\nInsert songs, to break: x" << std::endl;
    std::cin.ignore(); // Para ignorar la linea en blanco q deja el std::endl
    while (text != "x")
    {
        std::getline(std::cin, text);
        if (text != "x")
        {
            songs.push_back(text);
        }
    }
    menu();
}

void Songs::show_songs()
{

    std::cout << "\nThese are your " << songs.size() << " songs" << std::endl;
    for (int i = 0; i < songs.size(); i++)
    {
        std::cout << i + 1 << ". " << songs[i] << std::endl;
    }

    std::cout << "\n\n";
    menu();
}

bool Songs::pass_code()
{
    bool pass_code = false;
    int tries = 3;
    int pass;
    std::cout << "\nInsert your password: ";
    std::cin >> pass;
    if (pass == password)
    {
        pass_code = true;
    }
    while (pass != password && tries != 0)
    {
        std::cout << "\nPls, Try again: ";
        std::cin >> pass;
        if (pass == password)
        {
            pass_code = true;
        }
        tries--;
    }
    if (tries == 0)
    {
        std::cout << "Access denied.\n";
    }

    std::cout << std::endl;

    return pass_code;
}

void Songs::remove_songs()
{
    if (pass_code() == true)
    {
        int delsong;
        std::cout << "Select the song you want to delete:\n";
        for (int i = 0; i < songs.size(); i++)
        {
            std::cout << i + 1 << ". " << songs[i] << std::endl;
        }
        std::cout << "\n>> ";
        std::cin >> delsong;

        if (delsong - 1 < songs.size())
        {
            songs.erase(songs.begin() + delsong - 1);
        }
        else
        {
            std::cout << "Invalid number\n";
        };
    }

    std::cout << std::endl;

    menu();
}

Songs::~Songs()
{
    std::cout << "\nbye " << user << std::endl;
}
