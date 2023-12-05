#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> read_file() {
  ifstream input_file("../input");
  string str;
  vector<string> str2;

  while (getline(input_file, str)) {
    str2.push_back(str);
  }
  input_file.close();
  return str2;
}

int get_calib_value(string line) {
  char first_digit, last_digit;

  for (int i = 0; i < line.length(); i++) {
    if (isdigit(line[i])) {
      first_digit = line[i];
      break;
    }
  }

  for (int i = line.length() - 1; i >= 0; i--) {
    if (isdigit(line[i])) {
      last_digit = line[i];
      break;
    }
  }

  string calib_value;
  calib_value.push_back(first_digit);
  calib_value.push_back(last_digit);
  return stoi(calib_value);
}

int calib_value_sum(vector<string> calib_list) {
  int sum = 0;
  for (auto calib_value : calib_list) {
    sum += get_calib_value(calib_value);
  }
  return sum;
}

int main() {
  vector<string> input = read_file();
  cout << calib_value_sum(input);
  return 0;
}