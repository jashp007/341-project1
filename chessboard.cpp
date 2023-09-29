#include "chessboard.h"
#include <iostream>
using namespace std;

ChessboardIterator Chessboard::begin() { return ChessboardIterator(*this, 0); }

ChessboardIterator Chessboard::end() { return ChessboardIterator(*this, 64); }

void Chessboard::print() {

  for (int y = 7; y >= 0; --y) { // Start from the top row
    ChessboardIterator it = begin();
    int i = 0;
    while (i < y * 8) {
      ++it;
      ++i;
    }
    for (int x = 0; x < 8; ++x) {
      Square square = *it;
      bool occupied;
      Color color;
      Piece piece;
      square.get(occupied, color, piece);
      if (!occupied) {
        cout << " . "; // Use add a space after the dot to align
      } else {
        char colorChar = (color == White ? 'w' : 'b');
        char pieceChar;
        switch (piece) {
        case Rook:
          pieceChar = 'R';
          break;
        case Knight:
          pieceChar = 'N';
          break;
        case Bishop:
          pieceChar = 'B';
          break;
        case Queen:
          pieceChar = 'Q';
          break;
        case King:
          pieceChar = 'K';
          break;
        case Pawn:
          pieceChar = 'P';
          break;
        default:
          break;
        }
        cout << colorChar << pieceChar << ' ';
      }
      ++it;
    }
    cout << '\n'; // Move to the next line at the end of each row
  }
}