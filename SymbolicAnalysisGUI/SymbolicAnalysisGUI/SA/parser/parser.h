// parser.h
// ???? ???? ???????? ???????? ?????? TParser,
// ??????????????? ?????? ????????? ??????????????? ?????????.
// Written by Chaos Master, 11th of Febrary, 2000.
#pragma once

#if !defined(__SOLVER_H)
#define __SOLVER_H

// Includes
#include <string.h>
#include <vector>
using namespace std;

// Defines
#define MAX_EXPR_LEN   255
#define MAX_TOKEN_LEN  80

struct TParserNode
{
   float value;
   TParserNode *left;
   TParserNode *right;

   TParserNode(float _value=0.0, TParserNode *_left=NULL, TParserNode *_right=NULL)
      { value = _value; left = _left; right = _right; }
};

struct TError
{
   char *error;
   int pos;

   TError() {};
   TError(char *_error, int _pos) { error=_error; pos=_pos; }
};

class TParser
{
private:
   TParserNode *root;
   char *expr;
   char curToken[MAX_TOKEN_LEN];
   enum { PARSER_PLUS, PARSER_MINUS, PARSER_MULTIPLY, PARSER_DIVIDE, PARSER_PERCENT, PARSER_POWER,
          PARSER_SIN, PARSER_COS, PARSER_TG, PARSER_CTG, PARSER_ARCSIN, PARSER_ARCCOS, PARSER_ARCTG, PARSER_ARCCTG, PARSER_SH, PARSER_CH, PARSER_TH, PARSER_CTH,
          PARSER_EXP, PARSER_LG, PARSER_LN, PARSER_SQRT, PARSER_X, PARSER_L_BRACKET, PARSER_R_BRACKET, PARSER_E, PARSER_PI, PARSER_NUMBER, PARSER_END } typToken;
   int pos;

   const float*x;
   float result;

   vector<TParserNode *> history;

private:
   TParserNode *CreateNode(float _value=0.0, TParserNode *_left=NULL, TParserNode *_right=NULL);

   TParserNode *Expr(void);
   TParserNode *Expr1(void);
   TParserNode *Expr2(void);
   TParserNode *Expr3(void);
   TParserNode *Expr4(void);
   TParserNode *Expr5(void);

   bool GetToken(void);
   bool IsDelim(void) { return (strchr("+-*/%^()[]", expr[pos])!=NULL); }
   bool IsLetter(void) { return ((expr[pos]>='a' && expr[pos]<='z') ||
                                 (expr[pos]>='A' && expr[pos]<='Z')); }
   bool IsDigit(void) { return (expr[pos]>='0' && expr[pos]<='9'); }
   bool IsPoint(void) { return (expr[pos]=='.'); }

   float CalcTree(TParserNode *tree);
   void  DelTree(TParserNode *tree);

   void SendError(int errNum);

public:
   TParser() { result = 0.0; x = NULL; root = NULL; }
   ~TParser() { DelTree(root); root=NULL; }
   void SetX(const float*_x) { x=_x; }
   //void SetY(float _y) { y=_y; }

   bool Compile(char *expr);
   void Decompile() { DelTree(root); root=NULL; }

   float Evaluate();
   float Evaluate(float*_x) { SetX(_x); return Evaluate(); }
   float Evaluate(float x, ...) { SetX(&x); return Evaluate(); }

   float GetResult(void) { return result; }
};

#endif