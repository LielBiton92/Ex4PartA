#include "Game.hpp"
#include <string>
#pragma once

namespace coup{
   // class Game;
    class Player{
        private:
        std::string name;
        int cash;

        public:
       // Player(Game &game , const std::string &name);
        void income();
        void foreign_aid();
        void coup(Player &p);
        std::string role();
        int coins();
    };
}