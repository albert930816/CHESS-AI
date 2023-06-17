#ifndef __MINIMAX_H__
#define __MINIMAX_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include "../state/state.hpp"

#include "../config.hpp"

class Minimax{
    public:
        static int minimax(State* node,int depth, bool maximizingPlayer,int alpha,int beta);
        static Move get_move(State *state, int depth);
};

#endif