#include <iostream>
#include <fstream>

#include "../state/state.hpp"
#include "./minimax.hpp"


int Minimax::minimax(State* node,int depth, bool maximizingPlayer,int alpha,int beta){
    int value;
    if(depth==0){
        return node->evaluate();
    }
    if(maximizingPlayer){
        value = -(2e5);
        for(auto it:node->legal_actions){
            State* next_move = node->next_state(it);
            alpha=value = std::max(value,minimax(next_move,depth-1,false,value,2e5));
            if(alpha>=beta){
                break;
            }
        }
    }
    else{
        value = 2e5;
        for(auto it:node->legal_actions){
            State* next_move = node->next_state(it);
            beta=value = std::min(value,minimax(next_move,depth-1,true,-2e5,value));
            if(alpha>=beta){
                break;
            }
        }
    }
    return value;
}

Move Minimax::get_move(State *state, int depth){
  Move bestMove;
  int Max=-2e5;
  int tmp;
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  for(auto it:state->legal_actions){
    State* next_move = state->next_state(it);
    tmp=minimax(next_move,depth-1,state->player,Max,2e5);
    if(tmp>Max){
        Max=tmp;
        bestMove = it;
    }
  }
  return bestMove;
}