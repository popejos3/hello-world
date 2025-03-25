#include <vector>
#include <iostream>
#include <string>
#include <sstream>

std::string Two_D_Vector_To_String(std::vector<std::vector<char>> vec){
  std::stringstream os;
  for(int i = 0; i < static_cast<int>(vec.size()); i++){
    for(int j = 0; j < static_cast<int>(vec.at(i).size()); j++){
      os << vec.at(i).at(j) << " ";
    }
    os << "\n";
  }
  return os.str();
}

std::vector<std::vector<char>> Counting_Spiral(int size) {
  int i = size/2;
  int k = i;
  int num = 0;
  bool right = false;
  bool up = false;
  int change = 1;
  int changeVar = 1;
  int changeCount = 2;
  char counter;
  std::vector<std::vector<char>> vec(size, std::vector<char>(size, 0));
  for (int count = 0; count < size*size; count++) {
    counter = count%10;
    vec[i][k] = counter + 48;
    if (right == false && up == false) {
      k++;
      change -= 1;
      if (change == 0) {
        right = true;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
    else if (right == true && up == false) {
      i--;
      change -= 1;
      if (change == 0) {
        up = true;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
    else if (right == true && up == true) {
      k--;
      change -= 1;
      if (change == 0) {
        right = false;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
    else if (right == false && up == true) {
      i++;
      change -= 1;
      if (change == 0) {
        up = false;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
  }
  return vec;
}

std::vector<std::vector<char>> Prime_Spiral(int size) {
  int i = size/2;
  int k = i;
  int num = 0;
  bool right = false;
  bool up = false;
  int change = 1;
  int changeVar = 1;
  int changeCount = 2;
  char counter;
  std::vector<std::vector<char>> vec(size, std::vector<char>(size, 0));
  for (int count = 0; count < size*size; count++) {
    counter = count%10 + 48;
    if (counter == '5' || counter == '3' || counter == '2' || counter == '7') {
      vec[i][k] = 'O';
    }
    if (right == false && up == false) {
      k++;
      change -= 1;
      if (change == 0) {
        right = true;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
    else if (right == true && up == false) {
      i--;
      change -= 1;
      if (change == 0) {
        up = true;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
    else if (right == true && up == true) {
      k--;
      change -= 1;
      if (change == 0) {
        right = false;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
    else if (right == false && up == true) {
      i++;
      change -= 1;
      if (change == 0) {
        up = false;
        changeCount -= 1;
        if (changeCount == 0) {
          changeCount = 2;
          changeVar+=1;
        }
        change += changeVar;
      }
    }
  }
  return vec;
}

int main() {

  std::vector<std::vector<char>> vec = Prime_Spiral(10);
  std::cout << Two_D_Vector_To_String(vec);
}