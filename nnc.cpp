#include <iostream>
using namespace std;

void buildGrid(string grid[3][3]){
  cout << "-------------";
  cout << "\n| " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << " | 3";
  cout << "\n-------------";
  cout << "\n| " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << " | 2";
  cout << "\n-------------";
  cout << "\n| " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << " | 1";
  cout << "\n-------------";
  cout << "\n  1   2   3";
}

void game(string counter, string grid[3][3]){

    int x = 0;
    int y = 0;

    do{
      cout << "\n\n" << counter << "'s turn";
      cout << "\n\nEnter the x-coordinate: ";
      do{
        cin >> x;
      }while (x < 1 || x > 3);

      cout << "\nEnter the y-coordinate: ";
      do{
        cin >> y;
      }while (y < 1 || y > 3);
    } while (grid[y-1][x-1]!="-");

    grid[y - 1][x - 1] = counter;
    buildGrid(grid);
}

bool checkWin(string grid[3][3]){

    for (int i = 0; i < 3; i++) {
      if (grid[0][i] != "-" && (grid[0][i] == grid[1][i]) && (grid[0][i] == grid[2][i])){return true;}
      if (grid[i][0] != "-" && (grid[i][0] == grid[i][1]) && (grid[i][0] == grid[i][2])){return true;}
    }
    if (grid[0][0] != "-" && (grid[0][0] == grid[1][1]) && (grid[0][0] == grid[2][2])){return true;}
    if (grid[2][0] != "-" && (grid[2][0] == grid[1][1]) && (grid[2][0] == grid[0][2])){return true;}

    return false;
}

int main() {

  string counter;
  string grid[3][3];

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      grid[i][j] = "-";
    }
  }
  buildGrid(grid);

  for (int i = 0; i < 5; i++) {
    counter = "X";
    game(counter, grid);
    if (checkWin(grid) == true){break;}
    if (i < 4){
      counter = "O";
      game(counter, grid);
      if (checkWin(grid) == true){break;}
    }
  }

  if (checkWin(grid) == false) {
    counter = "No-one";
  }

  cout << "\n\n" << counter << " wins!";

  return 0;
}



