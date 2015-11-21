#include <iostream>

using namespace std;

/*
For given "N", print:
   A
  AA
 AAA
AAAA
AAA
AA
A
*/
void printFigure1() {
  int n;
  cin >> n;

  // print first N rows
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < (n - i); j++) {
      cout << " ";
    }
    for (int j = 0; j < i; j++) {
      cout << "A";
    }
    cout << endl;
  }
  // print following N-1 rows
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      cout << "A";
    }
    cout << endl;
  }
}

// Compare two dates after checking that they are valid
void compare2dates() {
  int year1, month1, day1;
  int year2, month2, day2;

  bool isValidDate;
  do {
    isValidDate = true;
    cout << "Enter date 1: ";
    cin >> year1 >> month1 >> day1;

    int maxDays = 0;
    int isLeapYear =
      (year1 % 400 == 0) ||
      (year1 % 100 != 0 && year1 % 4 == 0);
    switch (month1) {
      case 1: case 3: case 5: case 7:
      case 8: case 10: case 12:
        maxDays = 31;
        break;
      case 4: case 6: case 9: case 11:
        maxDays = 30;
        break;
      case 2:
        maxDays = 28 + isLeapYear;
        break;
      default:
        isValidDate = false;
    }
    if (!(1 <= day1 && day1 <= maxDays)) {
      isValidDate = false;
    }

  } while ( !isValidDate );

  cin >> year2 >> month2 >> day2;

  // skip the check if date is valid

  // OPTION 1
  if (year1 > year2) {
    cout << "date 1 is later";
  } else if (year1 < year2) {
    cout << "date 2 is later";
  } else { // both years are equal
    if (month1 > month2) {
      cout << "date 1 is later";
    } else if (month1 < month2) {
      cout << "date 2 is later";
    } else {
      if (day1 > day2) {
        cout << "date 1 is later";
      } else if (day1 < day2) {
        cout << "date 2 is later";
      } else {
        cout << "dates are equal";
      }
    }
  }
  cout << endl;

  // OPTION 2
  int date1, date2;
  date1 = year1 * 10000 + month1 * 100 + day1;
  date2 = year2 * 10000 + month2 * 100 + day2;

  if (date1 > date2) {
    cout << "date 1 is later";
  } else if (date1 < date2) {
    cout << "date 2 is later";
  } else {
    cout << "dates are equal";
  }
  cout << endl;
}

/* Read a numnber and check if a bit is set or not.
   n=5, b = 2 -> true
   & 0100
     0101 = 1
   n=5, b = 1 -> false
   & 0010
     0101 = 0
   n=5, b = 0 -> true
   & 0001
     0101 = 1
   n=5, b = 3+ -> false
   & 1000
   0101 = 0
*/
void checkBit() {
  int n, b;
  cout << "Enter a number: "; cin >> n;
  cout << "Enter a bit to check: "; cin >> b;

  cout << ((n & (1 << b)) != 0) << endl;
}

// Find the n-th prime number
void nthPrimeNumber() {
  int n;
  cin >> n;
  int i = 2;
  int lastPrimeNumber = i;
  while (n > 0) {
    bool isPrime = true;
    for (int k = 2; k < i; k++) {
      if (i % k == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) {
      lastPrimeNumber = i;
      n--;
    }
    i++;
  }
  cout << "Nth prime number is: " << lastPrimeNumber << endl;
}

// number transformation
void numberTransformation() {
  int n, r;
  cin >> n;

  while (true) {
    char c;
    cin >> c;
    switch (c) {
      case 'e':
        cout << n << endl;
        return;
      case 'r':
        // On r - reverse the number
        r = 0;
        while (n > 0) {
          r = r * 10 + n % 10;
          n /= 10;
        }
        n = r;
        break;
      case 'd':
        // On d - divide the number by 5
        n /= 5;
        break;
      case 'm':
        // On m - reminder by 231
        n %= 231;
        break;
      case '0':case '1':case '2':case '3':case '4':
      case '5':case '6':case '7':case '8':case '9':
        // On digit - n+=digit
        n += c - '0';
        break;
      default:
        // On * - n++
        n++;
        break;
    }
  }
}
/* Check if a number has duplicate digits
   767
       ?
   0 0 1 1 0 0 0 0 0 0 digits
   9 8 7 6 5 4 3 2 1 0 | positions
   0 0 1 0 0 0 0 0 0 0
*/
void hasDuplicateDigits() {
  int n;
  cin >> n;

  int digits = 0;
  bool hasDuplicates = false;
  while (n > 0) {
    int lastDigit = n % 10;
    if ((digits & (1 << lastDigit)) > 0) {
      hasDuplicates = true;
      break;
    } else {
      digits = digits | (1 << lastDigit);
    }
    n /= 10;
  }

  if (hasDuplicates) {
    cout << "hasDuplicates" << endl;
  }
}

void changeCase() {
  char c;
  cin >> c;
  if ('a' <= c && c <= 'z') {
    cout << (char)(c + ('A' - 'a')) << endl;
  }
  if ('A' <= c && c <= 'Z') {
    cout << (char)(c + ('a' - 'A')) << endl;
  }
}

void matchBrackets() {
  char c;
  int smallBrackets = 0; // ()
  int mediumBrackets = 0; // []
  int bigBrackets = 0; // {}

  bool isValid = true;

  while (true) {
    cin >> c;
    if (c == ';') break;

    // {}
    if (c == '{') {
      if (smallBrackets > 0 || mediumBrackets > 0) {
        isValid = false;
        break;
      }
      bigBrackets++;
    }
    if (c == '}') {
      if (bigBrackets <= 0) {
        isValid = false;
        break;
      }
      if (smallBrackets > 0 || mediumBrackets > 0) {
        isValid = false;
        break;
      }
      bigBrackets--;
    }

    // []
    if (c == '[') {
      if (smallBrackets > 0) {
        isValid = false;
        break;
      }
      mediumBrackets++;
    }
    if (c == ']') {
      if (mediumBrackets <= 0) {
        isValid = false;
        break;
      }
      if (smallBrackets > 0) {
        isValid = false;
        break;
      }
      mediumBrackets--;
    }

    // ()
    if (c == '(') {
      smallBrackets++;
    }
    if (c == ')') {
      if (smallBrackets <= 0) {
        isValid = false;
        break;
      }
      smallBrackets--;
    }
  }

  if (smallBrackets != 0 || mediumBrackets != 0 || bigBrackets != 0 || isValid == false) {
    cout << "Error" << endl;
  } else {
    cout << "OK" << endl;
  }
}


int main() {
  // printFigure1();
  // compare2dates();
  // checkBit();
  // nthPrimeNumber();
  // numberTransformation();
  // changeCase();
  // matchBrackets();

  return 0;
}








