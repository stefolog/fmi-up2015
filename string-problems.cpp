#include <iostream>
#include <string.h>

using namespace std;

/*
0. Print string in reverse order
1. Number of occurences of a char in a string
2. Number of occurences of string as substring in another string (without using strstr)
3. Convert string to Camel Case. E.g. ala bala Nitsa -> Ala Bala Nitsa
4. Replace a word with another word with the same length in a string
4* Replace a word with another word with the any length in a string
5. Delete all occurences of a word from a string
6. As input you have string which presents expression:
  (a op b), where op is Operation and can be +,*,/ or -
  Calculate the expression.

E.g.
  input: (((10 - 1)*(3*2))*4)
  output: 216
*/

void problem_0() {
  char str[100];
  cin.getline(str, 100);
  int n = strlen(str);

  for (int i = n - 1; i >=0; i--) {
    cout << str[i];
  }
  cout << endl;
}

void problem_1() {
  char str[100];
  char x;
  int count = 0;

  cin.getline(str, 100);
  cin >> x;

  int n = strlen(str);
  for (int i = 0; i < n; i++) {
    if (str[i] == x) {
      count++;
    }
  }

  cout << count << endl;
}

void problem_2() {
  char s1[100];
  char s2[100];

  int count = 0;

  cin.getline(s1, 100);
  cin.getline(s2, 100);

  int n1 = strlen(s1);
  int n2 = strlen(s2);

  for (int i = 0; i < n1 - n2 + 1; i++) {
    bool isMatch = true;
    for (int j = 0; j < n2; j++) {
      if (s1[i + j] != s2[j]) {
        isMatch = false;
        break;
      }
    }
    if (isMatch) {
      count++;
    }
  }

  cout << count << endl;
}

void problem_3() {
  char separators[] = " ,.!?;";
  char str[100];
  cin.getline(str, 100);

  bool isNewWord = true;

  int n = strlen(str);
  for (int i = 0; i < n; i++) {
    if (strchr(separators, str[i])) {
      isNewWord = true;
    } else if (isNewWord && 'a' <= str[i] && str[i] <= 'z') {
      str[i] += 'A' - 'a';
      isNewWord = false;
    } else {
      isNewWord = false;
    }

  }

  cout << str << endl;
}

int main() {
  // problem_0();
  // problem_1();
  // problem_2();
  problem_3();

  return 0;
}
