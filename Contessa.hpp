#include "Player.hpp"

namespace coup{
    class Contessa : public Player{
        public:
        Contessa(Game &game , const std::string &name);
        ~Contessa();
        void block(Player &p);
    };
}