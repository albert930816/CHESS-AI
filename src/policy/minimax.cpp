#include <iostream>
#include <fstream>

#include "../state/state.hpp"
#include "./minimax.hpp"

int Minimax::minimax(State* node, int depth, bool maximizingPlayer, Move& bestMove) {
    if (depth == 0) {
        return node->evaluate();
    }
    if (maximizingPlayer) {
        int value = -(2e5);
        for (auto it : node->legal_actions) {
            State* next_move = node->next_state(it);
            int eval = minimax(next_move, depth - 1, false, bestMove);
            if (eval > value) {
                value = eval;
                bestMove = it;
            }
        }
        return value;
    }
    else {
        int value = 2e5;
        for (auto it : node->legal_actions) {
            State* next_move = node->next_state(it);
            int eval = minimax(next_move, depth - 1, true, bestMove);
            if (eval < value) {
                value = eval;
                bestMove = it;
            }
        }
        return value;
    }
}

Move Minimax::get_move(State* state, int depth) {
    if (!state->legal_actions.size())
        state->get_legal_actions();

    Move bestMove;
    minimax(state, depth, state->player, bestMove);
    return bestMove;
}
