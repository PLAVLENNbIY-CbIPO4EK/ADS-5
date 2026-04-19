// Copyright 2025 NNTU-CS
#include "alg.h"

#include <cctype>
#include <string>

#include "tstack.h"

int priority(char s) {
  if (s == '+' || s == '-') return 1;
  if (s == '*' || s == '/') return 2;
  return 0;
}

std::string infx2pstfx(const std::string& inf) {
  TStack<char, 100> s;
  std::string str = "";

  for (int i = 0; i < static_cast<int>(inf.size()); i++) {
    if (isspace(inf[i])) continue;

    if (isdigit(inf[i])) {
      while (i < static_cast<int>(inf.size()) && isdigit(inf[i])) {
        str += inf[i];
        i++;
      }
      str += ' ';
      i--;
    } else if (inf[i] == '(') {
      s.push(inf[i]);
    } else if (inf[i] == ')') {
      while (!s.isEmpty() && s.top() != '(') {
        str += s.top();
        str += ' ';
        s.pop();
      }
      if (!s.isEmpty()) s.pop();
    } else {
      while (!s.isEmpty() && priority(s.top()) >= priority(inf[i])) {
        str += s.top();
        str += ' ';
        s.pop();
      }
      s.push(inf[i]);
    }
  }

  while (!s.isEmpty()) {
    str += s.top();
    str += ' ';
    s.pop();
  }

  return str;
}

int eval(const std::string& pref) {
  TStack<int, 100> str;
  const std::string& n = pref;

  for (int i = 0; i < static_cast<int>(n.size()); i++) {
    if (isspace(n[i])) continue;

    if (isdigit(n[i])) {
      int num = 0;
      while (i < static_cast<int>(n.size()) && isdigit(n[i])) {
        num = num * 10 + (n[i] - '0');
        i++;
      }
      str.push(num);
      i--;
    } else if (n[i] == '+' || n[i] == '-' ||
               n[i] == '*' || n[i] == '/') {
      int b = str.top();
      str.pop();
      int a = str.top();
      str.pop();

      int res = 0;
      if (n[i] == '+') res = a + b;
      else if (n[i] == '-') res = a - b;
      else if (n[i] == '*') res = a * b;
      else if (n[i] == '/') res = a / b;

      str.push(res);
    }
  }

  return str.top();
}
