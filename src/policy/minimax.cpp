#include <iostream>
#include <fstream>

#include "../state/state.hpp"
#include "./minimax.hpp"


int Minimax::minimax(State* node,int depth, int me,std::unordered_map<State*, int>& cache){
    int value;
    if(depth==0){
        return node->evaluate(me);
    }
    if (cache.count(node)) {
        return cache[node];
    }
    if(!node->legal_actions.size())
        node->get_legal_actions();
    if(node->player==me){
        value = -(2e8);
        if(node->game_state==WIN){
            return 2e8;
        }
        for(auto it:node->legal_actions){
            State* next_move = node->next_state(it);
            value = std::max(value,minimax(next_move,depth-1,me,cache));
        }
    }
    else{
        value = 2e8;
        if(node->game_state==WIN){
            return -2e8;
        }
        for(auto it:node->legal_actions){
            State* next_move = node->next_state(it);
            value = std::min(value,minimax(next_move,depth-1,me,cache));
        }
    }
    cache[node]=value;
    return value;
}

Move Minimax::get_move(State *state, int depth){
  Move bestMove;
  int Max=-2e8;
  int tmp;
  std::unordered_map<State*, int> cache;
  if(state->legal_actions.size())
    bestMove=state->legal_actions[0];
  for(auto it:state->legal_actions){
    State* next_move = state->next_state(it);
    tmp=minimax(next_move,depth-1,state->player,cache);
    if(tmp>Max){
        Max=tmp;
        bestMove = it;
    }
  }
  return bestMove;
}