#ifndef __MINIMAX_H__
#define __MINIMAX_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include "../state/state.hpp"
#include <unordered_map>

#include "../config.hpp"

class Minimax{
    public:
        static int minimax(State* node,int depth, int me,std::unordered_map<State*, int>& cache);
        static Move get_move(State *state, int depth);
};

#endif