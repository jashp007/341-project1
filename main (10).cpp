// see for background
// https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html

#include "chessboard.h"
#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!\n";
  Chessboard chessboard;

  // Initialize white pieces
  for (int i = 0; i < 8; i++) {
    chessboard.place(1, i, White, Pawn);
  }
  chessboard.place(0, 0, White, Rook);
  chessboard.place(0, 1, White, Knight);
  chessboard.place(0, 2, White, Bishop);
  chessboard.place(0, 3, White, Queen);
  chessboard.place(0, 4, White, King);
  chessboard.place(0, 5, White, Bishop);
  chessboard.place(0, 6, White, Knight);
  chessboard.place(0, 7, White, Rook);

  // Initialize black pieces
  for (int i = 0; i < 8; i++) {
    chessboard.place(6, i, Black, Pawn);
  }
  chessboard.place(7, 0, Black, Rook);
  chessboard.place(7, 1, Black, Knight);
  chessboard.place(7, 2, Black, Bishop);
  chessboard.place(7, 3, Black, Queen);
  chessboard.place(7, 4, Black, King);
  chessboard.place(7, 5, Black, Bishop);
  chessboard.place(7, 6, Black, Knight);
  chessboard.place(7, 7, Black, Rook);

  chessboard.print();

  cout << "***********Testing get************" << endl;
  Color co;
  Piece p;
  cout << "Testing get illegal x cood: " << chessboard.get(8, 0, co, p) << endl;
  cout << "Testing get illegal y cood: " << chessboard.get(0, 8, co, p) << endl;
  cout << "Testing get occupied square: " << chessboard.get(3, 0, co, p)
       << endl;
  cout << "Testing get unoccupied square: " << chessboard.get(0, 2, co, p)
       << endl;
  cout << "***********Testing place************" << endl;
  Color coPlace = (Color)3;
  Piece piPlace = (Piece)6;
  cout << "Testing place illegal x cood: "
       << chessboard.place(87, 8, coPlace, piPlace) << endl;
  cout << "Testing place illegal y cood: "
       << chessboard.place(0, 8, coPlace, piPlace) << endl;
  cout << "Testing place square occupied: "
       << chessboard.place(0, 0, coPlace, piPlace) << endl;
  cout << "Testing place illegal color: "
       << chessboard.place(0, 2, coPlace, piPlace) << endl;
  coPlace = (Color)0;
  cout << "Testing place illegal piece: "
       << chessboard.place(0, 2, coPlace, piPlace) << endl;
  piPlace = (Piece)3;
  cout << "Testing place everything ok: "
       << chessboard.place(0, 2, coPlace, piPlace) << endl;
  chessboard.print();
}
