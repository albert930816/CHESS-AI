#include <iostream>
#include <fstream>

#include "../state/state.hpp"
#include "./alpbta.hpp"


int Alpbta::alpbta(State* node, int depth, int me, int alpha, int beta,std::unordered_map<State*, int>& cache) {
    if (depth == 0) {
        return node->evaluate(me);
    }

    if (cache.count(node)) {
        return cache[node];
    }
    
    if (node->player==me) {
        int value = -2e8; 
        if(node->game_state==WIN){
            return 2e8;
        }
        for (auto it : node->legal_actions) {
            State* next_move = node->next_state(it);
            value = std::max(value, alpbta(next_move, depth - 1, me, alpha, beta,cache));
            alpha = std::max(alpha, value);
            if (alpha >= beta) {
                break;
            }
        }
        cache[node] = value;
        return value;
    } else {
        int value = 2e8;
        if(node->game_state==WIN){
            return -2e8;
        }
        for (auto it : node->legal_actions) {
            State* next_move = node->next_state(it);
            value = std::min(value, alpbta(next_move, depth - 1, me, alpha, beta,cache));
            beta = std::min(beta, value);
            if (alpha >= beta) {
                break;
            }
        }
        cache[node] = value;
        return value;
    }
}


Move Alpbta::get_move(State *state, int depth){
  Move bestMove;
  int Max=-2e8;
  int tmp;
  std::unordered_map<State*, int> cache;
  if(state->legal_actions.size())
    bestMove=state->legal_actions[0];
  
  for(auto it:state->legal_actions){
    State* next_move = state->next_state(it);
    tmp=alpbta(next_move,depth-1,state->player,Max,2e8,cache);
    if(tmp>Max){
        Max=tmp;
        bestMove = it;
    }
  }
  return bestMove;
}