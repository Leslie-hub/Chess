#include "Piece.h"

bool Piece::validCoordinate(std::pair<int,int> move) {
    if (move.first < 0 || move.first > 7) {
        return false;
    }
    else if (move.second < 0 || move.second > 7) {
        return false;
    }
    return true;
}

std::vector<std::pair<int,int>> Piece::getStraightMoves() {
    std::vector<std::pair<int,int>> moves;
    std::pair<int,int> move;

    int x = this->coordinates.first;
    int y = this->coordinates.second;

    //up straight
    move = std::make_pair(x, y-1);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;
            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first, move.second-1);
        }
    }

    //down straight
    move = std::make_pair(x, y+1);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;
            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first, move.second+1);
        }
    }

    //right straight
    move = std::make_pair(x+1, y);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;

            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first+1, move.second);
        }
    }

    //left straight
    move = std::make_pair(x-1, y);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;

            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first-1, move.second);
        }
    }

    return moves;
}

std::vector<std::pair<int,int>> Piece::getDiagonalMoves() {
    std::vector<std::pair<int,int>> moves;
    std::pair<int,int> move;

    int x = this->coordinates.first;
    int y = this->coordinates.second;

    //up right
    move = std::make_pair(x+1, y-1);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;

            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first+1, move.second-1);
        }
    }

    //up left
    move = std::make_pair(x-1, y-1);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;

            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first-1, move.second-1);
        }
    }

    //down right
    move = std::make_pair(x+1, y+1);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;

            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first-1, move.second-1);
        }
    }

    //down left
    move = std::make_pair(x-1, y+1);
    while(true) {
        if (validCoordinate(move)) {
            //if space is other colour
            moves.emplace_back(move);
            break;
        
            //if space is empty
            moves.emplace_back(move);
            move = std::make_pair(move.first-1, move.second+1);
        }
    }

    return moves;
}

std::string Piece::toString() {
    Piecetype p = this->getType();
    if (this->side == Side::White) {
        if (p == Piecetype::Pawn) {
            return "P";
        }
        else if (p == Piecetype::Bishop) {
            return "B";
        }
        else if (p == Piecetype::Knight) {
            return "N";
        }
        else if (p == Piecetype::Rook) {
            return "R";
        }
        else if (p == Piecetype::King) {
            return "K";
        }
        else if (p == Piecetype::Queen) {
            return "Q";
        }
    }
    else if (this->side == Side::Black) {
        if (p == Piecetype::Pawn) {
            return "p";
        }
        else if (p == Piecetype::Bishop) {
            return "b";
        }
        else if (p == Piecetype::Knight) {
            return "n";
        }
        else if (p == Piecetype::Rook) {
            return "r";
        }
        else if (p == Piecetype::King) {
            return "k";
        }
        else if (p == Piecetype::Queen) {
            return "q";
        }
    }
    return "";
}
