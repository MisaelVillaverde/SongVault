#include <string>
#include <vector>

void menu();
void create_user();

class Songs
{
    std::string user;
    int password;
    std::vector<std::string> songs; // Para mañana crear vector multidimensional para almacenar a los artistas

public:
    Songs(std::string new_user, int new_password);
    Songs();
    ~Songs();

    std::string show_user();
    void add_songs();
    void show_songs();
    void remove_songs();
    bool pass_code();
};
