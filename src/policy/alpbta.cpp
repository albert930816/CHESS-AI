#include <iostream>
#include <fstream>

#include "../state/state.hpp"
#include "./alpbta.hpp"


int Alpbta::alpbta(State* node, int depth, int me, int alpha, int beta) {
    if (depth == 0) {
        return node->evaluate(me);
    }
    
    if (node->player==me) {
        int value = -2e8; 
        for (auto it : node->legal_actions) {
            State* next_move = node->next_state(it);
            value = std::max(value, alpbta(next_move, depth - 1, me, alpha, beta));
            alpha = std::max(alpha, value);
            if (alpha >= beta) {
                break;
            }
        }
        return value;
    } else {
        int value = 2e8;
        for (auto it : node->legal_actions) {
            State* next_move = node->next_state(it);
            value = std::min(value, alpbta(next_move, depth - 1, me, alpha, beta));
            beta = std::min(beta, value);
            if (alpha >= beta) {
                break;
            }
        }
        return value;
    }
}


Move Alpbta::get_move(State *state, int depth){
  Move bestMove;
  int Max=-2e8;
  int tmp;
  if(!state->legal_actions.size())
    state->get_legal_actions();
  
  for(auto it:state->legal_actions){
    State* next_move = state->next_state(it);
    tmp=alpbta(next_move,depth-1,state->player,Max,2e8);
    if(tmp>Max){
        Max=tmp;
        bestMove = it;
    }
  }
  return bestMove;
}