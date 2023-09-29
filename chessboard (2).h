// see for background
// https://users.cs.northwestern.edu/~riesbeck/programming/c++/stl-iterator-define.html

#include <iostream>
#include <iterator>
using namespace std;

// define separate containers for Color, Piece (enums recommended)
enum Color { White, Black };
enum Piece { Rook, Knight, Bishop, Queen, King, Pawn };

// a chessboard contains squares
class Square {
private:
  Color color;
  Piece piece;
  bool occupied;

public:
  Square() { // default, square unoccupied
    occupied = false;
  }
  Square(Color c, Piece p) { // an occupied square
    piece = p;
    occupied = true;
    color = c;
  }
  int get(bool &o, Color &c, Piece &p) {
    p = piece;
    c = color;
    o = occupied;

    return 0;
  }

  void print();
};

class ChessboardIterator;

class Chessboard {
  // make the container iterator friendly
  typedef ChessboardIterator iterator;

private:
  Square chessboard[8][8];

public:
  friend class ChessboardIterator;

  Chessboard() {} // Square does all the initialization

  // return an x,y square from chessboard
  Square square(int x, int y) { return chessboard[x][y]; }

  ChessboardIterator begin();
  ChessboardIterator end();

  // place a piece on a x,y square in the chessboard
  int place(int x, int y, Color c, Piece p) {
    if (x < 0 || x > 7) {
      return -1;
    }
    if (y < 0 || y > 7) {
      return -2;
    }
    int occupied;
    Color col;
    Piece piec;
    occupied = get(x, y, col, piec);
    if (occupied == 1) {
      return -3;
    }
    if (c != White && c != Black) {
      return -4;
    }
    // cout << p << endl;
    bool isValidPiece = false;
    for (int pi = 0; pi <= Pawn; pi++) {
      // cout << p << " " << pi << endl;
      if (p == pi) {
        isValidPiece = true;
        break;
      }
    }
    if (!isValidPiece) {
      return -5;
    }
    chessboard[x][y] = Square(c, p);
    return 1;
  }
  int get(int x, int y, Color &c, Piece &p) {
    if (x < 0 || x > 7) {
      return -1;
    }
    if (y < 0 || y > 7) {
      return -2;
    }
    bool occupied;
    chessboard[x][y].get(occupied, c, p);
    if (occupied == false) {
      return -3;
    }
    return 1;
  }
  int move(int fromX, int fromY, int toX, int toY) {
    if (fromX < 0 || fromX > 7) {
      return -1;
    }
    if (fromY < 0 || fromY > 7) {
      return -2;
    }
    if (toX < 0 || toX > 7) {
      return -3;
    }
    if (toY < 0 || toY > 7) {
      return -4;
    }
    Color fromCo, toCo;
    Piece fromPi, toPi;
    int occupyFrom = get(fromX, fromY, fromCo, fromPi);
    bool occupyTo;
    chessboard[toX][toY].get(occupyTo, toCo, toPi);
    if (occupyFrom != 1) {
      return -5;
    }
    if (occupyTo == true && (toCo == fromCo)) {
      return -6;
    }
    int dx = abs(toX - fromX);
    int dy = abs(toY - fromY);
    if (fromPi == Rook) {
      // Rooks can move any number of squares vertically or horizontally
      if (!(dx == 0 || dy == 0))
        return -7;
    } else if (fromPi == Knight) {
      // Knights move in an L-shape: 2 squares in one direction and 1 square
      // perpendicular to it
      if (!((dx == 1 && dy == 2) || (dx == 2 && dy == 1)))
        return -7;
    } else if (fromPi == Bishop) {
      // Bishops can move any number of squares diagonally
      if (dx != dy)
        return -7;
    } else if (fromPi == Queen) {
      // Queens can move any number of squares vertically, horizontally, or
      // diagonally
      if (!(dx == 0 || dy == 0 || dx == dy))
        return -7;
    } else if (fromPi == King) {
      // Kings can move one square in any direction
      if (dx > 1 || dy > 1)
        return -7;
    } else if (fromPi == Pawn) {
      // Pawns can move forward one square, or two squares from their starting
      // position Pawns can also move diagonally forward one square to capture
      // an opponent's piece
      int direction = (fromCo == White) ? 1 : -1;
      bool isForwardMove = dx == 0 && dy == direction;
      bool isDoubleForwardMove =
          fromY == (fromCo == White ? 1 : 6) && dx == 0 && dy == 2 * direction;
      bool isDiagonalMove = dx == 1 && dy == direction;

      // Forward move
      if (isForwardMove && occupyTo == 0) {
        // Do nothing and break out of the if statement
      } else if (isDoubleForwardMove && occupyTo == 0) {
        // Additionally, check if the square in-between is unoccupied
        bool inBetweenOccupied;
        Color inBetweenColor;
        Piece inBetweenPiece;
        get(fromX, fromY + direction, inBetweenColor, inBetweenPiece);
        if (inBetweenOccupied)
          return -7;
      } else if (isDiagonalMove && occupyTo == 1 && fromCo != toCo) {
        // Do nothing and break out of the if statement
      } else {
        // If none of the above conditions are met, the move is illegal
        return -7;
      }
    }
    chessboard[toX][toY] = Square(fromCo, fromPi);
    chessboard[fromX][fromY] = Square();
    return 1;
  }

  void print();
};

class ChessboardIterator {
private:
  int position; // a number in [0..64]
  Chessboard chessboard;

public:
  ChessboardIterator(Chessboard &board,
                     int pos) { // start out with an empty board
    this->chessboard = board;
    this->position = pos;
  }

  void xy(int &x, int &y) { // break position down into x and y
    x = position / 8;
    y = position % 8;
  }

  // return the square
  Square operator*() {
    int x, y;
    xy(x, y);
    return chessboard.square(x, y);
  }

  // pre-increment
  ChessboardIterator &operator++() {
    ++position;
    return *this;
  }

  // needed to support foreach
  int operator!=(const ChessboardIterator &a) { return position != a.position; }
};
