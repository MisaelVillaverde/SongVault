#include <string>
#include <map>

void menu();
void create_user();

class Songs
{
    std::string user;
    int password;
    std::map<std::string, std::string> songs;

public:
    Songs(std::string new_user, int new_password);
    Songs();
    /* ~Songs(); */

    std::string show_user();
    void add_songs();
    void show_songs();
    void remove_songs();
    bool pass_code();
};
