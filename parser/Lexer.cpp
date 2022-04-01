/*
 * Lexer.cpp
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年4月1日 Author: menmen
 */
#include "Lexer.h"

std::string Lexer::getTokName(int Tok) {
  switch (Tok) {
    case tok_eof:
      return "eof";
    case tok_def:
      return "def";
    case tok_extern:
      return "extern";
    case tok_identifier:
      return "identifier";
    case tok_number:
      return "number";
    case tok_if:
      return "if";
    case tok_then:
      return "then";
    case tok_else:
      return "else";
    case tok_for:
      return "for";
    case tok_in:
      return "in";
    case tok_binary:
      return "binary";
    case tok_unary:
      return "unary";
    case tok_var:
      return "var";
  }
  return std::string(1, (char)Tok);
}

int Lexer::advance() {
  int LastChar = getchar();

  if (LastChar == '\n' || LastChar == '\r') {
    lex_loc_.Line++;
    lex_loc_.Col = 0;
  } else {
    lex_loc_.Col++;
  }
  return LastChar;
}

int Lexer::gettok() {
  static int LastChar = ' ';

  // Skip any whitespace.
  while (isspace(LastChar)) LastChar = advance();

  cur_loc_ = lex_loc_;

  if (isalpha(LastChar)) {  // identifier: [a-zA-Z][a-zA-Z0-9]*
    identifier_str_ = LastChar;
    while (isalnum((LastChar = advance()))) identifier_str_ += LastChar;

    if (identifier_str_ == "def") return tok_def;
    if (identifier_str_ == "extern") return tok_extern;
    if (identifier_str_ == "if") return tok_if;
    if (identifier_str_ == "then") return tok_then;
    if (identifier_str_ == "else") return tok_else;
    if (identifier_str_ == "for") return tok_for;
    if (identifier_str_ == "in") return tok_in;
    if (identifier_str_ == "binary") return tok_binary;
    if (identifier_str_ == "unary") return tok_unary;
    if (identifier_str_ == "var") return tok_var;
    return tok_identifier;
  }

  if (isdigit(LastChar) || LastChar == '.') {  // Number: [0-9.]+
    std::string NumStr;
    do {
      NumStr += LastChar;
      LastChar = advance();
    } while (isdigit(LastChar) || LastChar == '.');

    number_value_ = strtod(NumStr.c_str(), nullptr);
    return tok_number;
  }

  if (LastChar == '#') {
    // Comment until end of line.
    do {
      LastChar = advance();
    } while (LastChar != EOF && LastChar != '\n' && LastChar != '\r');

    if (LastChar != EOF) return gettok();
  }

  // Check for end of file.  Don't eat the EOF.
  if (LastChar == EOF) return tok_eof;

  // Otherwise, just return the character as its ascii value.
  int ThisChar = LastChar;
  LastChar = advance();
  return ThisChar;
}
