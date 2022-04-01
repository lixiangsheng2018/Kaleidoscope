/*
 * Lexer.h
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年4月1日 Author: menmen
 */

#ifndef PARSER_LEXER_H_
#define PARSER_LEXER_H_
#include <string>

// The lexer returns tokens [0-255] if it is an unknown character, otherwise one
// of these for known things.
enum Token : int {
  tok_eof = -1,

  // commands
  tok_def = -2,
  tok_extern = -3,

  // primary
  tok_identifier = -4,
  tok_number = -5,

  // control
  tok_if = -6,
  tok_then = -7,
  tok_else = -8,
  tok_for = -9,
  tok_in = -10,

  // operators
  tok_binary = -11,
  tok_unary = -12,

  // var definition
  tok_var = -13
};

struct SourceLocation {
  int Line;
  int Col;
};

class Lexer {
 public:
  Lexer() {
    lex_loc_.Line = 1;
    lex_loc_.Col = 0;
  }
  std::string getTokName(int Tok);

 private:
  int gettok();
  int advance();

 private:
  SourceLocation cur_loc_;
  SourceLocation lex_loc_;
  std::string identifier_str_;
  double number_value_;
};

#endif /* PARSER_LEXER_H_ */
