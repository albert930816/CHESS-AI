#include <iostream>
#include <fstream>

#include "../state/state.hpp"
#include "./minimax.hpp"


int Minimax::minimax(State* node,int depth, bool maximizingPlayer){
    if(depth==0){
        return node->evaluate();
    }
    if(maximizingPlayer){
        int value = -(2e5);
        for(auto it:node->legal_actions){
            State* next_move = node->next_state(it);
            value = std::max(value,minimax(next_move,depth-1,false));
        }
        return value;
    }
    else{
        int value = 2e5;
        for(auto it:node->legal_actions){
            State* next_move = node->next_state(it);
            value = std::min(value,minimax(next_move,depth-1,true));
        }
        return value;
    }
}

Move Minimax::get_move(State *state, int depth){
  Move bestMove;
  int Max=-2e5;
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  for(auto it:state->legal_actions){
    State* next_move = state->next_state(it);
    if(Max<minimax(next_move,depth,next_move->player)){
        Max=minimax(next_move,depth,next_move->player);
        bestMove=it;
    }
  }
  return bestMove;
}