#include "doctest.h"
#include "Game.hpp"
#include "Player.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include <string>
#include "vector"
using namespace coup;

TEST_CASE("Good")
{
    Game game_1{};
    Duke duke{game_1, "Druid"};
    Assassin assassin{game_1, "Priest"};
    Ambassador ambassador{game_1, "Mage"};
    Captain captain{game_1, "Shamen"};
    Contessa contessa{game_1, "Hunter"};
    CHECK(duke.role() == "Druid");
    CHECK(assassin.role() == "Priest");
    CHECK(ambassador.role() == "Shamen");
    CHECK(captain.role() == "Shamen");
    CHECK(contessa.role() == "Hunter");
    CHECK(game_1.players().size() == 5);
    CHECK_NOTHROW(duke.income());
    CHECK_NOTHROW(assassin.income());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    CHECK(duke.coins() == 1);
    CHECK(assassin.coins() == 1);
    CHECK(ambassador.coins() == 1);
    CHECK(captain.coins() == 1);
    CHECK(contessa.coins() == 1);
    // CHECK_NOTHROW(game_1.winner());
    // CHECK_THROWS(assassin.foreign_aid());
    CHECK_NOTHROW(duke.foreign_aid());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK(duke.coins() == 3);
    CHECK(assassin.coins() == 3);
    CHECK(ambassador.coins() == 3);
    CHECK(captain.coins() == 3);
    CHECK(contessa.coins() == 3);
}
TEST_CASE("Duke functions")
{
    Game game_1{};
    Duke duke{game_1, "Druid"};
    Assassin assassin{game_1, "Priest"};
    Ambassador ambassador{game_1, "Mage"};
    Captain captain{game_1, "Shamen"};
    Contessa contessa{game_1, "Hunter"};
    
    duke.tax();
    CHECK(duke.coins()==3);
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.income());
    CHECK_NOTHROW(captain.income());
    CHECK_NOTHROW(contessa.income());
    duke.block(assassin);
    CHECK_THROWS(duke.block(contessa));
    CHECK(duke.coins()==0);
}
    
TEST_CASE("Assassin functions"){
    Game game_1{};
    Duke duke{game_1, "Druid"};
    Assassin assassin{game_1, "Priest"};
    Ambassador ambassador{game_1, "Mage"};
    Captain captain{game_1, "Shamen"};
    Contessa contessa{game_1, "Hunter"};
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    assassin.coup(duke);
    CHECK(game_1.players().size()==4);
    duke.income();
    assassin.income();
    ambassador.income();
    captain.income();
    contessa.income();
    duke.income();
    CHECK_THROWS(assassin.coup(contessa));
        
}

TEST_CASE("Ambassador and captain functions"){
    Game game_1{};
    Duke duke{game_1, "Druid"};
    Assassin assassin{game_1, "Priest"};
    Ambassador ambassador{game_1, "Mage"};
    Captain captain{game_1, "Shamen"};
    Contessa contessa{game_1, "Hunter"};
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.foreign_aid();
    captain.foreign_aid();
    contessa.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    ambassador.transfer(duke , assassin);
    CHECK(duke.coins()==1);
    captain.steal(assassin);
    contessa.foreign_aid();
    duke.foreign_aid();
    assassin.foreign_aid();
    CHECK_NOTHROW(ambassador.block(captain));
    
    
}




