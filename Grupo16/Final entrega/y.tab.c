
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "./sintactico/Sintactico.y"

  #include "expression.h"
  #include "Primitivas.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"
  

  int yystopparser = 0;
  FILE *yyin;

  char *yytext;

  int yyerror();
  int yylex();

  SExpression* pMaximo;
  SExpression* pFactor;
  SExpression* pExpresion;
  SExpression* pTermino;
  SExpression* pTipos;
  SExpression* pImpresion;
  SExpression* pDeclaracion;
  SExpression* pLectura;
  SExpression* pAsignacion;
  SExpression* pCondicion;
  SExpression* pCondiciones;
  SExpression* pMientras;
  SExpression* pDecision;
  SExpression* pVariables;
  SExpression* pSentencia;
  SExpression* pPrograma;
  SExpression* pAux;

  EOperationType condicional;

  char nameID[30];
  char distinctVariableName[30];
  char stringFormateado[33];

  t_pila pilaTipos;
  t_pila pilaVariables;
  t_pila pilaParametros[10];

  t_cola colaSimbolos;
  QueueItem itemSimbolo;

  int indicePilaParametros = -1;
  int cantCadenas = 0;

  StackItem itemTipo;
  StackItem itemVar;
  StackItem itemParametro;

  void write_graphviz(SExpression*);


/* Line 189 of yacc.c  */
#line 132 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
#line 109 "./sintactico/Sintactico.y"

  char* value;
  SExpression *expression;



/* Line 214 of yacc.c  */
#line 255 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 267 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   124

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  60
/* YYNRULES -- Number of states.  */
#define YYNSTATES  108

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    22,    31,    35,    37,    39,    43,    45,    47,    49,
      50,    55,    56,    61,    62,    67,    68,    74,    78,    82,
      84,    88,    92,    94,    98,   100,   102,   104,   106,   108,
     110,   118,   122,   126,   129,   131,   132,   133,   139,   141,
     143,   145,   147,   149,   151,   153,   158,   162,   164,   170,
     178
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      42,     0,    -1,    43,    -1,    44,    -1,    43,    44,    -1,
      50,    -1,    45,    -1,    53,    -1,    55,    -1,    60,    -1,
      68,    -1,    10,    32,    46,    33,    11,    32,    48,    33,
      -1,    46,     7,    47,    -1,    47,    -1,     6,    -1,    48,
       7,    49,    -1,    49,    -1,    14,    -1,    15,    -1,    -1,
      12,    16,    51,     8,    -1,    -1,    12,     6,    52,     8,
      -1,    -1,    13,     6,    54,     8,    -1,    -1,     6,    56,
       9,    57,     8,    -1,    57,    21,    58,    -1,    57,    22,
      58,    -1,    58,    -1,    58,    24,    59,    -1,    58,    23,
      59,    -1,    59,    -1,    28,    57,    29,    -1,     6,    -1,
      17,    -1,    18,    -1,    19,    -1,    20,    -1,    66,    -1,
      25,    28,    61,    29,    30,    43,    31,    -1,    61,    38,
      62,    -1,    61,    39,    62,    -1,    40,    62,    -1,    62,
      -1,    -1,    -1,    57,    63,    65,    64,    57,    -1,    57,
      -1,    32,    -1,    33,    -1,    34,    -1,    35,    -1,    36,
      -1,    37,    -1,     5,    28,    67,    29,    -1,    67,     7,
      57,    -1,    57,    -1,    26,    28,    61,    29,    44,    -1,
      26,    28,    61,    29,    30,    43,    31,    -1,    26,    28,
      61,    29,    30,    43,    31,    27,    30,    43,    31,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   135,   135,   143,   144,   147,   148,   149,   150,   151,
     152,   155,   183,   184,   187,   193,   194,   197,   198,   201,
     201,   211,   211,   214,   214,   217,   217,   220,   221,   222,
     225,   226,   227,   230,   231,   232,   240,   249,   257,   265,
     268,   271,   272,   273,   275,   278,   278,   278,   279,   282,
     283,   284,   285,   286,   287,   290,   316,   317,   320,   321,
     322
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "LETRA", "DIGITO", "FNMAX", "ID", "COMA",
  "PYC", "ASIG", "DECVAR", "DEFTIPO", "IMPR", "LEER", "INTEGER", "FLOAT",
  "CONSCAD", "CONSENT", "CONSREAL", "CONSHEXA", "CONSBIN", "SUMA", "MENOS",
  "DIV", "MULT", "WHILE", "SI", "SINO", "PARA", "PARC", "LLAVA", "LLAVC",
  "CORCA", "CORCC", "DIST", "MENIG", "MAYIG", "IG", "Y", "O", "NOT",
  "$accept", "programaPrima", "programa", "sentencia", "declaracion",
  "variables", "variable", "tipos", "tipo", "impresion", "$@1", "$@2",
  "lectura", "$@3", "asignacion", "$@4", "expresion", "termino", "factor",
  "mientras", "condiciones", "condicion", "$@5", "$@6", "condicional",
  "maximo", "parametros", "decision", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    45,    46,    46,    47,    48,    48,    49,    49,    51,
      50,    52,    50,    54,    53,    56,    55,    57,    57,    57,
      58,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      60,    61,    61,    61,    61,    63,    64,    62,    62,    65,
      65,    65,    65,    65,    65,    66,    67,    67,    68,    68,
      68
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       1,     8,     3,     1,     1,     3,     1,     1,     1,     0,
       4,     0,     4,     0,     4,     0,     5,     3,     3,     1,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       7,     3,     3,     2,     1,     0,     0,     5,     1,     1,
       1,     1,     1,     1,     1,     4,     3,     1,     5,     7,
      11
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    25,     0,     0,     0,     0,     0,     0,     2,     3,
       6,     5,     7,     8,     9,    10,     0,     0,    21,    19,
      23,     0,     0,     1,     4,     0,    14,     0,    13,     0,
       0,     0,     0,    34,    35,    36,    37,    38,     0,     0,
      45,    29,    32,     0,    44,    39,     0,     0,     0,     0,
      22,    20,    24,     0,     0,    43,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    26,    12,     0,    57,     0,
      33,    27,    28,    49,    50,    51,    52,    53,    54,    46,
      31,    30,     0,    41,    42,     0,    58,     0,     0,    55,
       0,     0,     0,    17,    18,     0,    16,    56,    47,    40,
      59,     0,    11,     0,    15,     0,     0,    60
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,     8,     9,    10,    27,    28,    95,    96,    11,
      30,    29,    12,    31,    13,    16,    40,    41,    42,    14,
      43,    44,    58,    90,    79,    45,    69,    15
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -43
static const yytype_int8 yypact[] =
{
      84,   -43,   -27,    43,     6,    25,    42,    44,    84,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,    65,    73,   -43,   -43,
     -43,    -2,    -2,   -43,   -43,     2,   -43,    -5,   -43,    74,
      79,    87,    80,   -43,   -43,   -43,   -43,   -43,     2,     2,
      78,   -14,   -43,    19,   -43,   -43,    33,     3,    73,   104,
     -43,   -43,   -43,     2,    56,   -43,     2,     2,    69,     2,
       2,    88,     2,     2,    63,   -43,   -43,    89,    70,    16,
     -43,   -14,   -14,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,   -43,    84,   -43,   -43,    84,   -43,    36,     2,   -43,
       2,    21,    29,   -43,   -43,    -1,   -43,    70,    70,   -43,
      92,    36,   -43,    90,   -43,    84,    55,   -43
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   -42,    -8,   -43,   -43,    75,   -43,    23,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -24,    57,    52,   -43,
     100,   -26,   -43,   -43,   -43,   -43,   -43,   -43
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -49
static const yytype_int8 yytable[] =
{
      24,    47,    48,    32,    33,    17,   101,    32,    33,    59,
      60,    65,    20,    55,    54,    34,    35,    36,    37,    34,
      35,    36,    37,    88,    56,    57,    38,     1,    49,    68,
      38,     2,   102,     3,     4,     1,    83,    84,    39,     2,
      91,     3,     4,    92,    23,    89,     5,     6,    61,    18,
      93,    94,    99,    21,     5,     6,    86,    62,    63,    19,
     100,     1,    64,   106,    97,     2,    98,     3,     4,     1,
      22,    62,    63,     2,    25,     3,     4,    56,    57,    26,
       5,     6,    50,    24,    24,    70,   107,    51,     5,     6,
       1,    56,    57,    85,     2,    52,     3,     4,    24,    56,
      57,    73,    74,    75,    76,    77,    78,   -48,    53,     5,
       6,    80,    81,    71,    72,    67,   -48,   -48,    82,   103,
     105,    87,    46,    66,   104
};

static const yytype_uint8 yycheck[] =
{
       8,    25,     7,     5,     6,    32,     7,     5,     6,    23,
      24,     8,     6,    39,    38,    17,    18,    19,    20,    17,
      18,    19,    20,     7,    21,    22,    28,     6,    33,    53,
      28,    10,    33,    12,    13,     6,    62,    63,    40,    10,
      82,    12,    13,    85,     0,    29,    25,    26,    29,     6,
      14,    15,    31,    28,    25,    26,    64,    38,    39,    16,
      31,     6,    29,   105,    88,    10,    90,    12,    13,     6,
      28,    38,    39,    10,     9,    12,    13,    21,    22,     6,
      25,    26,     8,    91,    92,    29,    31,     8,    25,    26,
       6,    21,    22,    30,    10,     8,    12,    13,   106,    21,
      22,    32,    33,    34,    35,    36,    37,    29,    28,    25,
      26,    59,    60,    56,    57,    11,    38,    39,    30,    27,
      30,    32,    22,    48,   101
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    10,    12,    13,    25,    26,    42,    43,    44,
      45,    50,    53,    55,    60,    68,    56,    32,     6,    16,
       6,    28,    28,     0,    44,     9,     6,    46,    47,    52,
      51,    54,     5,     6,    17,    18,    19,    20,    28,    40,
      57,    58,    59,    61,    62,    66,    61,    57,     7,    33,
       8,     8,     8,    28,    57,    62,    21,    22,    63,    23,
      24,    29,    38,    39,    29,     8,    47,    11,    57,    67,
      29,    58,    58,    32,    33,    34,    35,    36,    37,    65,
      59,    59,    30,    62,    62,    30,    44,    32,     7,    29,
      64,    43,    43,    14,    15,    48,    49,    57,    57,    31,
      31,     7,    33,    27,    49,    30,    43,    31
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (expression, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, expression); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SExpression **expression)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, expression)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    SExpression **expression;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (expression);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, SExpression **expression)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, expression)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    SExpression **expression;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, expression);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, SExpression **expression)
#else
static void
yy_reduce_print (yyvsp, yyrule, expression)
    YYSTYPE *yyvsp;
    int yyrule;
    SExpression **expression;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , expression);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, expression); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, SExpression **expression)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, expression)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    SExpression **expression;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (expression);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (SExpression **expression);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (SExpression **expression)
#else
int
yyparse (expression)
    SExpression **expression;
#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 135 "./sintactico/Sintactico.y"
    {
            printf("COMPILACIÓN EXITOSA!!\n");
             *expression = pPrograma;
             write_graphviz(pPrograma);
             generarASM(pPrograma, &colaSimbolos);
           }
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 143 "./sintactico/Sintactico.y"
    { pPrograma = pSentencia; (yyval.expression) = pPrograma; printf("\t{sentencia} es programa\n"); }
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 144 "./sintactico/Sintactico.y"
    { pPrograma = crearNodo(ePROGRAMA, (yyvsp[(1) - (2)].expression), pSentencia);(yyval.expression) = pPrograma; printf("\t{programa sentencia} es programa\n");}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 147 "./sintactico/Sintactico.y"
    { pSentencia = pImpresion; (yyval.expression) = pSentencia; printf("\t{impresion} es sentencia\n"); }
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 148 "./sintactico/Sintactico.y"
    { pSentencia = pDeclaracion; (yyval.expression) = pSentencia; printf("\t{declaracion} es sentencia\n"); }
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 149 "./sintactico/Sintactico.y"
    { pSentencia = pLectura; (yyval.expression) = pSentencia; printf("\t{lectura} es sentencia\n"); }
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 150 "./sintactico/Sintactico.y"
    { pSentencia = pAsignacion; (yyval.expression) = pSentencia; printf("\t{asignacion} es sentencia\n"); }
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 151 "./sintactico/Sintactico.y"
    { pSentencia = pMientras; (yyval.expression) = pSentencia; printf("\t{mientras} es sentencia\n"); }
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 152 "./sintactico/Sintactico.y"
    {pSentencia = pDecision; (yyval.expression) = pSentencia; printf("\t{decision} es sentencia\n"); }
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 155 "./sintactico/Sintactico.y"
    {
    sacarDePila(&pilaTipos, &itemTipo);
    sacarDePila(&pilaVariables, &itemVar);

    //pDeclaracion = crearNodo(eDECLARACION, crearHoja(itemVar.value), crearHoja(itemTipo.value));
    cargarItemSimboloVariable(&itemSimbolo, itemVar.value, itemTipo.value);
    acolar(&colaSimbolos, &itemSimbolo);

    while(!esPilaVacia(&pilaTipos))
    {

      //pAux = pDeclaracion;

      sacarDePila(&pilaTipos, &itemTipo);
      sacarDePila(&pilaVariables, &itemVar);

      //pDeclaracion = crearNodo(eDECLARACION, crearHoja(itemVar.value), crearHoja(itemTipo.value));
      
      //pDeclaracion = crearNodo(ePROGRAMA, pAux, pDeclaracion);

      cargarItemSimboloVariable(&itemSimbolo, itemVar.value, itemTipo.value);
      acolar(&colaSimbolos, &itemSimbolo);
    }
    
    printf("\t{DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC} es declaracion\n"); 
  }
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 183 "./sintactico/Sintactico.y"
    { strcpy(itemVar.value, yytext); meterEnPila(&pilaVariables, &itemVar); printf("\t{variables COMA variable} es variables\n"); }
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 184 "./sintactico/Sintactico.y"
    { crearPila(&pilaVariables); strcpy(itemVar.value, yytext); meterEnPila(&pilaVariables, &itemVar); printf("\t{variable} es variables\n"); }
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 187 "./sintactico/Sintactico.y"
    { 
    printf("\t{ID} es variable\n");

  }
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 193 "./sintactico/Sintactico.y"
    { strcpy(itemTipo.value, yytext); meterEnPila(&pilaTipos, &itemTipo); printf("\t{tipos COMA tipo} es tipos\n"); }
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 194 "./sintactico/Sintactico.y"
    { crearPila(&pilaTipos); strcpy(itemTipo.value, yytext); meterEnPila(&pilaTipos, &itemTipo); printf("\t{tipo} es tipos\n"); }
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 197 "./sintactico/Sintactico.y"
    { printf("\t{INTEGER} es tipo\n"); }
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 198 "./sintactico/Sintactico.y"
    { printf("\t{FLOAT} es tipo\n"); }
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 201 "./sintactico/Sintactico.y"
    {
    formatearString(yytext, stringFormateado);

    cargarItemSimboloCadena(&itemSimbolo, yytext, &cantCadenas);
    acolar(&colaSimbolos, &itemSimbolo);
  }
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 206 "./sintactico/Sintactico.y"
    { 
    pImpresion = crearNodo(eESCRIBIR, crearHoja(itemSimbolo.nombre), NULL);
    (yyval.expression) = pImpresion;
    printf("\t{IMPR CONSCAD PYC} es impresion\n");
  }
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 211 "./sintactico/Sintactico.y"
    {strcpy(nameID, yytext);}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 211 "./sintactico/Sintactico.y"
    { pImpresion = crearNodo(eESCRIBIR, crearHoja(nameID), NULL); (yyval.expression)=pImpresion; printf("\t{IMPR ID PYC} es impresion\n"); }
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 214 "./sintactico/Sintactico.y"
    {strcpy(nameID, yytext);}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 214 "./sintactico/Sintactico.y"
    { pLectura = crearNodo(eLEER, crearHoja(nameID), NULL); (yyval.expression) = pLectura; printf("\t{IMPR ID PYC} es impresion\n"); }
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 217 "./sintactico/Sintactico.y"
    {strcpy(nameID, yytext);}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 217 "./sintactico/Sintactico.y"
    { pAsignacion = crearNodo(eASIGNACION, crearHoja(nameID), pExpresion);(yyval.expression)=pAsignacion; printf("\t{ID ASIG expresion} es asignacion\n"); }
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 220 "./sintactico/Sintactico.y"
    { pExpresion = crearNodo(eSUMA, (yyvsp[(1) - (3)].expression), pTermino); (yyval.expression) = pExpresion; printf("\t{expresion SUMA termino} es expresion\n"); }
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 221 "./sintactico/Sintactico.y"
    { pExpresion = crearNodo(eMENOS, (yyvsp[(1) - (3)].expression), pTermino); (yyval.expression) = pExpresion; printf("\t{expresion MENOS termino} es expresion\n"); }
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 222 "./sintactico/Sintactico.y"
    { pExpresion = pTermino; (yyval.expression) = pExpresion; printf("\t{termino} es expresion\n"); }
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 225 "./sintactico/Sintactico.y"
    { pTermino = crearNodo(eMULTIPLICACION, (yyvsp[(1) - (3)].expression), pFactor); (yyval.expression)=pTermino; printf("\t{termino MULT factor} es termino\n"); }
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 226 "./sintactico/Sintactico.y"
    { pTermino = crearNodo(eDIVISION, (yyvsp[(1) - (3)].expression), pFactor); (yyval.expression)=pTermino; printf("\t{termino DIV factor} es termino\n"); }
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 227 "./sintactico/Sintactico.y"
    { pTermino = pFactor; (yyval.expression) = (yyvsp[(1) - (1)].expression); printf("\t{factor} es termino\n"); }
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 230 "./sintactico/Sintactico.y"
    { pFactor = pExpresion;(yyval.expression) = (yyvsp[(2) - (3)].expression); printf("\t{PARA expresion PARC} es factor\n"); }
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 231 "./sintactico/Sintactico.y"
    { printf("\t{ID} es factor\n"); pFactor = crearHoja(yytext); (yyval.expression) = pFactor; }
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 232 "./sintactico/Sintactico.y"
    { 
    printf("\t{CONSENT} es factor\n");
    pFactor = crearHoja(yytext);
    (yyval.expression) = pFactor;
    
    cargarItemSimbolo(&itemSimbolo, "entero", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  }
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 240 "./sintactico/Sintactico.y"
    { 
    printf("\t{CONSREAL} es factor\n");

    pFactor = crearHoja(yytext); 
    (yyval.expression) = pFactor;

    cargarItemSimbolo(&itemSimbolo, "real", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  }
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 249 "./sintactico/Sintactico.y"
    { 
    printf("\t{CONSHEXA} es factor\n");
    pFactor = crearHoja(yytext);
    (yyval.expression) = pFactor;
    
    cargarItemSimbolo(&itemSimbolo, "hexadecimal", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  }
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 257 "./sintactico/Sintactico.y"
    {
    printf("\t{CONSBIN} es factor\n");
    pFactor = crearHoja(yytext);
    (yyval.expression) = pFactor;
    
    cargarItemSimbolo(&itemSimbolo, "binario", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  }
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 265 "./sintactico/Sintactico.y"
    {pFactor = pMaximo; (yyval.expression)= pFactor; printf("\t{maximo} es factor\n");}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 268 "./sintactico/Sintactico.y"
    { pMientras = crearNodo(eMIENTRAS, (yyvsp[(3) - (7)].expression), pPrograma);printf("\t{WHILE PARA condicion PARC LLAVA programa LLAVC} es mientras\n"); }
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 271 "./sintactico/Sintactico.y"
    { pCondiciones = crearNodo(eY, pCondiciones, pCondicion); (yyval.expression) = pCondiciones; printf("\t{condiciones Y condicion} es condiciones\n"); }
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 272 "./sintactico/Sintactico.y"
    { pCondiciones = crearNodo(eO, pCondiciones, pCondicion); (yyval.expression) = pCondiciones; printf("\t{condiciones O condicion} es condiciones\n"); }
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 273 "./sintactico/Sintactico.y"
    { pCondiciones = crearNodo(eNOT, (yyvsp[(2) - (2)].expression), NULL); (yyval.expression) = pCondiciones; printf("\t{NOT condicion} es condiciones\n"); }
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 275 "./sintactico/Sintactico.y"
    {pCondiciones = pCondicion; (yyval.expression) = pCondiciones; printf("\t{condicion} es condiciones\n"); }
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 278 "./sintactico/Sintactico.y"
    {pAux =  pExpresion;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 278 "./sintactico/Sintactico.y"
    {condicional = convertirLexemaEnOperacion(yytext);}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 278 "./sintactico/Sintactico.y"
    {pCondicion = crearNodo(condicional, pAux, pExpresion); (yyval.expression)=pCondicion; printf("\t{expresion condicional expresion} es condicion\n"); }
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 279 "./sintactico/Sintactico.y"
    { pCondicion = pExpresion; (yyval.expression)=pCondicion; printf("\t{expresion} es condicion\n"); }
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 282 "./sintactico/Sintactico.y"
    { printf("\t{CORCA} es condicional\n"); }
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 283 "./sintactico/Sintactico.y"
    { printf("\t{CORCC} es condicional\n"); }
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 284 "./sintactico/Sintactico.y"
    { printf("\t{DIST} es condicional\n"); }
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 285 "./sintactico/Sintactico.y"
    { printf("\t{MENIG} es condicional\n"); }
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 286 "./sintactico/Sintactico.y"
    { printf("\t{MAYIG} es condicional\n"); }
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 287 "./sintactico/Sintactico.y"
    { printf("\t{IG} es condicional\n"); }
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 290 "./sintactico/Sintactico.y"
    { 
    sacarDePila(&pilaParametros[indicePilaParametros], &itemParametro);

    strcpy(distinctVariableName, "@max");
    sprintf(stringFormateado, "%d",indicePilaParametros);
    strcat(distinctVariableName, stringFormateado);
    
    cargarItemSimboloVariable(&itemSimbolo, distinctVariableName, "real");
    acolar(&colaSimbolos, &itemSimbolo);

    //pMaximo = crearNodo(eDECLARACION, crearHoja(distinctVariableName), crearHoja("EXPRESION"));
    pAux = crearNodo(ePROGRAMA, pMaximo, crearNodo(eASIGNACION, crearHoja(distinctVariableName), itemParametro.estructura));
    
    while(!esPilaVacia(&pilaParametros[indicePilaParametros]))
    {
      sacarDePila(&pilaParametros[indicePilaParametros], &itemParametro);
      pAux = crearNodo(ePROGRAMA, pAux, crearNodo(eDECISION, crearNodo(eMENOR, crearHoja(distinctVariableName), itemParametro.estructura), crearNodo(eASIGNACION, crearHoja(nameID), itemParametro.estructura)));

    }

    pMaximo=pAux;
    indicePilaParametros--;
    printf("\t{FNMAX PARA parametros PARC} es maximo\n"); 
  }
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 316 "./sintactico/Sintactico.y"
    { itemParametro.estructura = pExpresion; meterEnPila(&pilaParametros[indicePilaParametros], &itemParametro); printf("\t{parametros COMA expresion} es parametros\n"); }
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 317 "./sintactico/Sintactico.y"
    { indicePilaParametros++; crearPila(&pilaParametros[indicePilaParametros]); itemParametro.estructura = pExpresion; meterEnPila(&pilaParametros[indicePilaParametros], &itemParametro); printf("\t{expresion} es parametros\n"); }
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 320 "./sintactico/Sintactico.y"
    {pDecision = crearNodo(eDECISION, (yyvsp[(3) - (5)].expression), pSentencia); (yyval.expression) = pDecision; printf("\t{SI PARA condiciones PARC sentencia} es decision\n"); }
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 321 "./sintactico/Sintactico.y"
    {pDecision = crearNodo(eDECISION, (yyvsp[(3) - (7)].expression), pPrograma); (yyval.expression) = pDecision; printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC} es decision\n"); }
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 322 "./sintactico/Sintactico.y"
    { pDecision = crearNodo(eDECISION, (yyvsp[(3) - (11)].expression), crearNodo(eDECISIONCUERPO, (yyvsp[(6) - (11)].expression), (yyvsp[(10) - (11)].expression))); (yyval.expression) = pDecision; printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC SINO LLAVA programa LLAVC} es decision\n"); }
    break;



/* Line 1455 of yacc.c  */
#line 2073 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (expression, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (expression, yymsg);
	  }
	else
	  {
	    yyerror (expression, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, expression);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, expression);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (expression, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, expression);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, expression);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 324 "./sintactico/Sintactico.y"


////////// funciones GRAPHVIZ
char* node_name(SExpression *e){
  /* return char* description of parse tree node, e.g. '+', '-', '3', etc */
  char* name = (char *)malloc(16);  /* up to 15 char descriptive node name */
  switch (e->type){
  case eVALUE:
    sprintf(name, "%s", e->value);
    return name;
  case eMULTIPLICACION:
    sprintf(name, "*");
    return name;
  case eSUMA:
    sprintf(name, "+");
    return name;
  case eDIVISION:
    sprintf(name, "/");
    return name;
  case eMENOS:
    sprintf(name, "-");
    return name;
  case eASIGNACION:
    sprintf(name, "=");
    return name;
  case eMAYOR:
    sprintf(name, ">");
    return name;
  case eNOT:
    sprintf(name, "NOT");
    return name;
  case eY:
    sprintf(name, "Y");
    return name;
  case eO:
    sprintf(name, "O");
    return name;
  case eMENOR:
    sprintf(name, "<");
    return name;
  case eIGUAL:
    sprintf(name, "==");
    return name;
  case eDISTINTO:
    sprintf(name, "<>");
    return name;
  case eMAYORIGUAL:
    sprintf(name, ">=");
    return name;
  case eMENORIGUAL:
    sprintf(name, "<=");
    return name;
  case eMIENTRAS:
    sprintf(name, "WHILE");
    return name;
  case eDECISION:
    sprintf(name, "IF");
    return name;
  case eDECISIONCUERPO:
    sprintf(name, "CUERPO");
    return name;
  case eESCRIBIR:
    sprintf(name, "PUT");
    return name;
  case eLEER:
    sprintf(name, "GET");
    return name;
  case eDECLARACION:
    sprintf(name, "DECLARACION");
    return name;
  case ePROGRAMA:
    sprintf(name, "PROGRAMA");
    return name;
  default:  // shouldn't get here
    sprintf(name, "???");
    return name;
  }
}

/* We need to declare this before write_node so
   that the recursive mutual calls compile properly. */
void write_tree(SExpression *e, FILE *dotfile, int node);

void write_node(SExpression *e, FILE *dotfile, int node, int parent){
  fprintf(dotfile, " %i -> %i;\n", parent, node);
  write_tree(e, dotfile, node);
}

void write_tree(SExpression *e, FILE *dotfile, int node){
  fprintf(dotfile, " %i [label=\"%s\"];\n", node, node_name(e));
  if (e->left != NULL) write_node(e->left, dotfile, 2*node, node);
  if (e->right != NULL) write_node(e->right, dotfile, 2*node+1, node);
}

void write_graphviz(SExpression *e){
  if(e == NULL)
  {
    printf("ERROR: No se puede imprimir árbol nulo.");
    exit(1);
  }

  FILE *dotfile = fopen("tree.dot", "w");
  fprintf(dotfile, "digraph tree {\n");
  write_tree(e, dotfile, 1);
  fprintf(dotfile, "}\n");
  fclose(dotfile);
}
//////////////////////////////////////////////////////
////////// escribir tablas simbolos
void escribirTablaSimbolos() {
  FILE* arch;
  int i;
  if((arch = fopen("ts.txt","wb")) == NULL) {
    printf("\nNo se puedo crear la tabla de simbolos.\n");
    return;
  }

  fprintf(arch, "%-30s|%-15s|%-30s|%-10s\n\n", "NOMBRE", "TIPO DE DATO", "VALOR", "LONGITUD");

  while (!colaVacia(&colaSimbolos)) {
    desacolar(&colaSimbolos, &itemSimbolo);
    fprintf(arch, "%-30s|%-15s|%-30s|%-10d\n", itemSimbolo.nombre, itemSimbolo.tipo, itemSimbolo.valor, itemSimbolo.longitud);
  }

  fclose(arch);
}
//////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  crearCola(&colaSimbolos);

  if (( yyin = fopen(argv[1], "rt")) == NULL)
  {
    printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
  }
  else
  {
    SExpression *expression;
    yyparse(&expression);

    //write_graphviz(expression);
  }

  escribirTablaSimbolos();

  fclose(yyin);
  return 0;
}

int yyerror(void)
{
  printf("Error sintáctico\n");
  exit(1);
}
