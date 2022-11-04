#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <pugixml.hpp>
using namespace std;

struct ZombieData {
    int playerAlive =true ;
    int playerskill = 9;
    int playerScore = 1;
    string playerName = "";
    int zombieCount = 0;
    int zombiesKilled = 0;
    string userInput;
};

ZombieData zombieData;

  struct LanguageData {
    std::string Welcome = "";
    std::string SaveGame = "";
    std::string StartGame = "";
    std::string PlayerName = "";
    std::string ZombieCount = "";
    std::string ReadyFight = "";
    std::string BigZombieAttack = "";
    std::string NormalZombieAttack = "";
    std::string Fighting = "";
    std::string Death = "";
    std::string ZombieHurt = "";
    std::string ZombieHurtBad = "";
    std::string ZombieKilled = "";
    std::string PlayerInjured="";
    std::string PlayerSurvived="";
    std::string PlayerDead="";
    std::string ZombiesKilled="";
    std::string FinalScore = "";
    
};

LanguageData languageData;

void ReadLanguage(std::string lang)
{
    pugi::xml_document language;
    pugi::xml_parse_result result = language.load_file("language.xml");
    if (!result) {
        return;
    }

    pugi::xml_object_range<pugi::xml_node_iterator> states = language.child("language").children();
    if (!result) {
        return;
    }

    pugi::xml_node_iterator languageIt;
    for (languageIt = states.begin(); languageIt != states.end(); languageIt++) {
        pugi::xml_node languageNode = *languageIt;

        pugi::xml_attribute category = languageNode.attribute("lang");
        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "Welcome")
            languageData.Welcome = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "SaveGame")
            languageData.SaveGame = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "StartGame")
            languageData.StartGame = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "PlayerName")
            languageData.PlayerName = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "ZombieCount")
            languageData.ZombieCount = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "ReadyFight")
            languageData.ReadyFight = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "BigZombieAttack")
            languageData.BigZombieAttack = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "NormalZombieAttack")
            languageData.NormalZombieAttack = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "Fighting")
            languageData.Fighting = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "Death")
            languageData.Death = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "ZombieHurt")
            languageData.ZombieHurt = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "ZombieHurtBad")
            languageData.ZombieHurtBad = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "ZombieKilled")
            languageData.ZombieKilled = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "PlayerInjured")
            languageData.PlayerInjured = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "PlayerSurvived")
            languageData.PlayerSurvived = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "PlayerDead")
            languageData.PlayerDead = languageNode.child_value();

        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "ZombiesKilled")
            languageData.ZombiesKilled = languageNode.child_value();


        if (std::string(lang.c_str()) == std::string(category.value()) && std::string(languageNode.name()) == "FinalScore")
            languageData.FinalScore = languageNode.child_value();

     
    }
}

int createZombie() {
    if (rand() % 67 < 10)
        return 11;

    else
        return rand() % 10 + 1;
}

void LoadXMLFromFile() {

    pugi::xml_document zombies;
    pugi::xml_parse_result result = zombies.load_file("zombies.xml");

    if (!result) {
        return;
    }

    pugi::xml_object_range<pugi::xml_node_iterator> states = zombies.child("zombies").children();
    if (states.empty()) {
        return;
    }

    pugi::xml_node_iterator zombiesIt;
    for (zombiesIt = states.begin(); zombiesIt != states.end(); zombiesIt++) {
        pugi::xml_node zombiesNode = *zombiesIt;

        if (std::string(zombiesNode.name()) == "playerAlive")
            zombieData.playerAlive = atoi(zombiesNode.child_value());

        if (std::string(zombiesNode.name()) == "playerskill")
            zombieData.playerskill = atoi(zombiesNode.child_value());

        if (std::string(zombiesNode.name()) == "playerScore")
            zombieData.playerScore = atoi(zombiesNode.child_value());

        if (std::string(zombiesNode.name()) == "playerName")
            zombieData.playerName = atoi(zombiesNode.child_value());

        if (std::string(zombiesNode.name()) == "zombieCount")
            zombieData.zombieCount = atoi(zombiesNode.child_value());

        if (std::string(zombiesNode.name()) == "zombiesKilled")
            zombieData.zombiesKilled = atoi(zombiesNode.child_value());

        if (std::string(zombiesNode.name()) == "userInput")
            zombieData.userInput = atoi(zombiesNode.child_value());
    }

}

int main() {
    srand(time(NULL));
    char enter;

    // game stats
    int playerAlive = true;
    int playerskill = 9;
    int playerScore = 1;
    string playerName = "";
    int zombieCount = 0;
    int zombiesKilled = 0;
    string userInput;
    int languageInput;

    string Welcome;
    string SaveGame;
    string StartGame;
    string PlayerName;
    string ZombieCount;
    string ReadyFight;
    string BigZombieAttack;
    string NormalZombieAttack;
    string Fighting;
    string Death;
    string ZombieHurt;
    string ZombieHurtBad;
    string ZombieKilled;
    string PlayerInjured;
    string PlayerSurvived;
    string PlayerDead;
    string ZombiesKilled;
    string FinalScore;


    //Selecting aLanguage

    std::cout << "Select a Language \n 1)Press 1 for English \n 2)Press 2 for French(français') \n 3)Press 3 for Spanish(Español) \n 4)Press 4 for Japanese(日本語) \n 5)Press 5 for Telugu(తెలుగు) " << endl; //language change
    cin >> languageInput;

    switch (languageInput)
    {
    case 1:
        ReadLanguage("en");
        break;
    case 2:
        ReadLanguage("fr");
        break;
    case 3:
        ReadLanguage("es");
        break;
    case 4:
        ReadLanguage("jp");
        break;
    case 5:
        ReadLanguage("tl");
        break;
    default:
        ReadLanguage("en");
        break;
    }

    // title
    std::cout << languageData.Welcome << endl; //language change  //Welcome
    std::cout << languageData.SaveGame; //language change //SaveGame
    //New and load game
    cin >> userInput;
    if (userInput == "N" || userInput == "n") {
        // we do nothing
    }
    else if (userInput == "L" || userInput == "l") {
        LoadXMLFromFile();
        playerAlive = zombieData.playerAlive;
        playerskill = zombieData.playerskill;
        playerScore = zombieData.playerScore;
        playerName =  zombieData.playerName;
        zombieCount = zombieData.zombieCount;
        zombiesKilled = zombieData.zombiesKilled;
        userInput= zombieData.userInput;
    }
    
    std::cout<<languageData.StartGame<<endl; //language change //StartGame
    cin.get();

    // player name
    std::cout << languageData.PlayerName; //language change //PlayerName
    cin >> playerName;

    // ask how many zombies
    cout << languageData.ZombieCount; //ZombieCount //language change
    cin >> zombieCount;

    cout << languageData.ReadyFight << playerName << "!" << endl; //language change // ReadyFight

    // main game loop
    while (playerAlive && zombiesKilled < zombieCount) {
        // create a random zombie
        int zombieSkill = createZombie();

        // battle sequence
        if (zombieSkill > 10) {
            cout << endl << languageData.BigZombieAttack << endl;  //language change //BigZombieAttack
        } 
        else {
            cout << endl << languageData.NormalZombieAttack << zombiesKilled + 1 << endl; //NormalZombieAttack
        }

        cout << languageData.Fighting << endl;  //language change //Fighting
        

        // zombie killed the player
        if (playerskill < zombieSkill) {
            playerAlive = false;
            cout << languageData.Death << endl; //language change  //Death
        }

        // player killed the zombie
        else {
            if (playerskill - zombieSkill > 7) {
                cout << languageData.ZombieHurt << endl;  //language change  //ZombieHurt
                playerScore = playerScore * 2;
            }

            else if (playerskill - zombieSkill > 5) {
                cout << languageData.ZombieHurtBad << endl; //language change // ZombieHurtBad
                playerScore = playerScore * 2;
            }

            else if (playerskill - zombieSkill > 0) {
                cout << languageData.ZombieKilled << endl; //language change //ZombieKilled
                playerScore = playerScore * 2;
            }

            else {
                cout << languageData.PlayerInjured << endl; //language change //PlayerInjured
            }

            zombiesKilled++;
        }

        cout << endl;
        
    }

    // end game
    if (zombiesKilled == zombieCount) {
        // victory
        cout << languageData.PlayerSurvived << endl;  //language change //PlayerSurvived
    }
    else {
        // lost
        cout << languageData.PlayerDead << endl;  //language change //PlayerDead
    }

    cout << languageData.ZombiesKilled << zombiesKilled << endl;  //language change  //ZombiesKilled
    cout << languageData.FinalScore << playerScore << endl << endl;  //language change //FinalScore
}