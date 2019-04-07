/*
Description: A header for the current game state of the class.
Last Modified: 07 Apr 2019
Author: Isaac Draper
*/

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <unordered_map>

#include "json11/json11.hpp"
#include "GameLib/src/structs.h"
#include "GameLib/src/enums.h"
#include "GameLib/src/util.h"

namespace terminal {

    using json11::Json;
    using std::string;

    /// This represents everything about a current state of the game.
    /// It provides a convienent way to add/remove units and
    /// get information about the opponent.
    class GameState {
    public:
        GameState(Json configuration, Json jsonState);
        double getResource(RESOURCE rType, Player& player);
        double projectFutureBits(int turnsInFuture, double currentBits, Player& player);
        int numberAffordable(UNIT_TYPE uType, Player& player);
        void submitTurn();

    private:
        void parseState(Json jsonState);
        void parsePlayerStats(Player& player, int id, Json::array stats);
        void parseUnits(Player& player, Json::array jsonUnits);
        Unit createUnit(Player& player, int uType, Json::array unitRaw);

        void setResource(RESOURCE rType, double amount, Player& player);
        RESOURCE resourceRequired(UNIT_TYPE uType);
        double typeCost(UNIT_TYPE uType);


        Json config;
        Player player1;
        Player player2;
        Json::array buildStack;
        Json::array deployStack;
        int turnNumber;
        // TODO: Add GameMap
        // TODO: Add pathfinding

        std::unordered_map<UNIT_TYPE, string> unitStr;

    };

}

#endif