
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     LETRA = 258,
     DIGITO = 259,
     FNMAX = 260,
     ID = 261,
     COMA = 262,
     PYC = 263,
     ASIG = 264,
     DECVAR = 265,
     DEFTIPO = 266,
     IMPR = 267,
     LEER = 268,
     INTEGER = 269,
     FLOAT = 270,
     CONSCAD = 271,
     CONSENT = 272,
     CONSREAL = 273,
     CONSHEXA = 274,
     CONSBIN = 275,
     SUMA = 276,
     MENOS = 277,
     DIV = 278,
     MULT = 279,
     WHILE = 280,
     SI = 281,
     SINO = 282,
     PARA = 283,
     PARC = 284,
     LLAVA = 285,
     LLAVC = 286,
     CORCA = 287,
     CORCC = 288,
     DIST = 289,
     MENIG = 290,
     MAYIG = 291,
     IG = 292,
     Y = 293,
     O = 294,
     NOT = 295
   };
#endif
/* Tokens.  */
#define LETRA 258
#define DIGITO 259
#define FNMAX 260
#define ID 261
#define COMA 262
#define PYC 263
#define ASIG 264
#define DECVAR 265
#define DEFTIPO 266
#define IMPR 267
#define LEER 268
#define INTEGER 269
#define FLOAT 270
#define CONSCAD 271
#define CONSENT 272
#define CONSREAL 273
#define CONSHEXA 274
#define CONSBIN 275
#define SUMA 276
#define MENOS 277
#define DIV 278
#define MULT 279
#define WHILE 280
#define SI 281
#define SINO 282
#define PARA 283
#define PARC 284
#define LLAVA 285
#define LLAVC 286
#define CORCA 287
#define CORCC 288
#define DIST 289
#define MENIG 290
#define MAYIG 291
#define IG 292
#define Y 293
#define O 294
#define NOT 295




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 109 "./sintactico/Sintactico.y"

  char* value;
  SExpression *expression;



/* Line 1676 of yacc.c  */
#line 139 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


