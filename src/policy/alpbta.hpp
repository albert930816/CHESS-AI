#ifndef __ALPBTA_H__
#define __ALPBTA_H__

#include <string>
#include <cstdlib>
#include <vector>
#include <utility>
#include<unordered_map>
#include "../state/state.hpp"

#include "../config.hpp"

class Alpbta{
    public:
        static int alpbta(State* node,int depth, int me,int alpha,int beta,std::unordered_map<State*, int>& cache);
        static Move get_move(State *state, int depth);
};

#endif