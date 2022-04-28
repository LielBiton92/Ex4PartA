#pragma once
#include "vector"
#include <string>

namespace coup{
    class Game{
        private:
       // std::vector<Player> playersgame;
        public:
        Game();
        std::vector<std::string> players(); 
        std::string turn();
        std::string winner();





    };

}