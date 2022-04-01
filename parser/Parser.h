/*
 * Parser.h
 * Copyright(C),2022,闷闷交流
 * Created on: 2022年4月1日 Author: menmen
 */
#ifndef PARSER_H_
#define PARSER_H_
#include "Lexer.h"


class ExprAST {
private:
  SourceLocation Loc;

public:
  ExprAST(SourceLocation Loc = CurLoc) : Loc(Loc) {}
  virtual ~ExprAST() {}
  virtual Value *codegen() = 0;
  int getLine() const { return Loc.Line; }
  int getCol() const { return Loc.Col; }
  virtual raw_ostream &dump(raw_ostream &out, int ind) {
    return out << ':' << getLine() << ':' << getCol() << '\n';
  }
};

class Parser {

};




#endif /* PARSER_H_ */
