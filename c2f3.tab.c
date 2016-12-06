/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMERO = 258,
     IDENTIF = 259,
     INTEGER = 260,
     STRING = 261,
     PUTS = 262,
     WHILE = 263,
     FOR = 264,
     DO = 265,
     IF = 266,
     ELSE = 267,
     PRINTF = 268,
     RETURN = 269,
     INC = 270,
     DEC = 271,
     EQUALS = 272,
     NOTEQUALS = 273,
     THISPLUS = 274,
     THISTIMES = 275,
     THISDIVIDED = 276,
     THISMINUS = 277,
     GE = 278,
     LE = 279,
     OR = 280,
     AND = 281,
     MAIN = 282,
     SIGNO_UNARIO = 283
   };
#endif
/* Tokens.  */
#define NUMERO 258
#define IDENTIF 259
#define INTEGER 260
#define STRING 261
#define PUTS 262
#define WHILE 263
#define FOR 264
#define DO 265
#define IF 266
#define ELSE 267
#define PRINTF 268
#define RETURN 269
#define INC 270
#define DEC 271
#define EQUALS 272
#define NOTEQUALS 273
#define THISPLUS 274
#define THISTIMES 275
#define THISDIVIDED 276
#define THISMINUS 277
#define GE 278
#define LE 279
#define OR 280
#define AND 281
#define MAIN 282
#define SIGNO_UNARIO 283




/* Copy the first part of user declarations.  */
#line 1 "c2f3.y"
                              // SECCION 1 Declaraciones de C-Yacc
#include <stdio.h>
#include <string.h>             // declaraciones para cadenas
#include <stdlib.h>             // declaraciones para exit ()
#define FF fflush(stdout);      // para forzar la impresion inmediata
char funcion_actual [256] ;     // almacena el nombre de la función actual
char *variable[32] ;            // almacena los nombres de variable de la función actual
int variable_cnt;
char matrix_initiated;
int there_are_matrices;
char *return_expression;

// prototipos de funciones

int createVariable(char *variable_id);
int createArray(char *variable_id, int size);
char *getScopeVariableId(char *variable_id);
int createMatrix(char *id, int x, int y);



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

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 22 "c2f3.y"
{                               // El tipo de la pila tiene caracter dual
    int valor ;                   // - valor numerico de un NUMERO
    char *cadena ;                // - para pasar los nombres de IDENTIFES
}
/* Line 193 of yacc.c.  */
#line 178 "c2f3.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 191 "c2f3.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   479

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  195

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,     2,     2,    37,    30,     2,
      40,    41,    35,    33,    47,    34,     2,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    44,
      31,    28,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,    29,    43,     2,     2,     2,     2,
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
      25,    26,    27,    39
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,     8,     9,    10,    11,    24,    25,
      28,    29,    38,    39,    40,    46,    47,    56,    57,    69,
      70,    74,    77,    78,    80,    84,    91,   101,   106,   109,
     112,   116,   120,   124,   128,   134,   137,   138,   145,   146,
     155,   156,   164,   165,   166,   180,   181,   182,   187,   188,
     189,   195,   197,   201,   205,   209,   213,   217,   221,   225,
     229,   233,   236,   239,   242,   245,   248,   252,   256,   260,
     264,   268,   272,   274,   275,   279,   280,   284,   286,   291,
     299,   301,   305,   307,   312,   313,   316,   317
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      49,     0,    -1,    57,    50,    55,    -1,    -1,    -1,    -1,
      -1,     4,    40,    51,    54,    41,    42,    57,    52,    61,
      43,    53,    50,    -1,    -1,     5,     4,    -1,    -1,    27,
      40,    41,    42,    56,    57,    61,    43,    -1,    -1,    -1,
       5,     4,    44,    58,    57,    -1,    -1,     5,     4,    45,
       3,    46,    44,    59,    57,    -1,    -1,     5,     4,    45,
       3,    46,    45,     3,    46,    44,    60,    57,    -1,    -1,
      62,    44,    61,    -1,    63,    61,    -1,    -1,    78,    -1,
       4,    28,    73,    -1,     4,    45,    73,    46,    28,    73,
      -1,     4,    45,    73,    46,    45,    73,    46,    28,    73,
      -1,     7,    40,     6,    41,    -1,     4,    15,    -1,     4,
      16,    -1,     4,    19,    73,    -1,     4,    22,    73,    -1,
       4,    20,    73,    -1,     4,    21,    73,    -1,    13,    40,
       6,    69,    41,    -1,    14,    73,    -1,    -1,     8,    73,
      64,    42,    61,    43,    -1,    -1,    10,    65,    42,    61,
      43,     8,    73,    44,    -1,    -1,    11,    73,    66,    42,
      61,    43,    71,    -1,    -1,    -1,     9,    40,    62,    44,
      67,    73,    44,    68,    62,    41,    42,    61,    43,    -1,
      -1,    -1,    47,    73,    70,    69,    -1,    -1,    -1,    72,
      12,    42,    61,    43,    -1,    74,    -1,    73,    33,    73,
      -1,    73,    34,    73,    -1,    73,    35,    73,    -1,    73,
      36,    73,    -1,    73,    30,    73,    -1,    73,    29,    73,
      -1,    73,    37,    73,    -1,    73,    32,    73,    -1,    73,
      31,    73,    -1,     4,    15,    -1,     4,    16,    -1,    15,
       4,    -1,    16,     4,    -1,    38,    73,    -1,    73,    17,
      73,    -1,    73,    18,    73,    -1,    73,    24,    73,    -1,
      73,    23,    73,    -1,    73,    26,    73,    -1,    73,    25,
      73,    -1,    77,    -1,    -1,    75,    33,    77,    -1,    -1,
      76,    34,    77,    -1,     4,    -1,     4,    45,    73,    46,
      -1,     4,    45,    73,    46,    45,    73,    46,    -1,     3,
      -1,    40,    73,    41,    -1,    78,    -1,     4,    40,    79,
      41,    -1,    -1,    73,    80,    -1,    -1,    47,    73,    80,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    79,    80,    85,    93,    80,    97,    98,
     104,   104,   111,   117,   117,   119,   119,   121,   121,   125,
     126,   127,   130,   131,   132,   133,   134,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   147,   147,   149,   149,
     152,   152,   155,   156,   155,   161,   162,   162,   166,   167,
     167,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   195,   196,   196,   197,   197,   200,   201,   208,
     210,   211,   212,   215,   223,   224,   227,   228
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMERO", "IDENTIF", "INTEGER", "STRING",
  "PUTS", "WHILE", "FOR", "DO", "IF", "ELSE", "PRINTF", "RETURN", "INC",
  "DEC", "EQUALS", "NOTEQUALS", "THISPLUS", "THISTIMES", "THISDIVIDED",
  "THISMINUS", "GE", "LE", "OR", "AND", "MAIN", "'='", "'|'", "'&'", "'<'",
  "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "SIGNO_UNARIO", "'('",
  "')'", "'{'", "'}'", "';'", "'['", "']'", "','", "$accept", "program",
  "functions", "@1", "@2", "@3", "parameters", "main", "@4", "vars", "@5",
  "@6", "@7", "codigo", "sentencia", "flujo", "@8", "@9", "@10", "@11",
  "@12", "formatting", "@13", "else_block", "@14", "expresion", "termino",
  "@15", "@16", "operando", "funcall", "arguments", "more_arguments", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    61,   124,
      38,    60,    62,    43,    45,    42,    47,    37,    33,   283,
      40,    41,   123,   125,    59,    91,    93,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    48,    49,    50,    51,    52,    53,    50,    54,    54,
      56,    55,    57,    58,    57,    59,    57,    60,    57,    61,
      61,    61,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    62,    64,    63,    65,    63,
      66,    63,    67,    68,    63,    69,    70,    69,    71,    72,
      71,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    74,    75,    74,    76,    74,    77,    77,    77,
      77,    77,    77,    78,    79,    79,    80,    80
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     0,     0,     0,     0,    12,     0,     2,
       0,     8,     0,     0,     5,     0,     8,     0,    11,     0,
       3,     2,     0,     1,     3,     6,     9,     4,     2,     2,
       3,     3,     3,     3,     5,     2,     0,     6,     0,     8,
       0,     7,     0,     0,    13,     0,     0,     4,     0,     0,
       5,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     2,     3,     3,     3,     3,
       3,     3,     1,     0,     3,     0,     3,     1,     4,     7,
       1,     3,     1,     4,     0,     2,     0,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      12,     0,     0,     3,     0,     1,     0,     0,    13,     0,
       4,     0,     2,    12,     0,     8,     0,    14,     0,     0,
       0,     0,    15,     0,     9,     0,    10,    12,     0,    12,
      12,    16,     0,     5,    19,    17,    19,     0,     0,    73,
       0,    38,    73,     0,    73,     0,     0,    19,    23,    12,
       0,    28,    29,    73,    73,    73,    73,    73,    73,    73,
       0,    80,    77,     0,     0,    73,    73,    36,    51,     0,
       0,    72,    82,    22,     0,    40,     0,    35,    11,    19,
      21,    18,     6,    30,    32,    33,    31,    24,    86,     0,
       0,     0,    61,    62,    73,    63,    64,    65,     0,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,     0,     0,     0,     0,    19,     0,
      45,    20,     3,    73,    85,    83,     0,    27,     0,    81,
      66,    67,    69,    68,    71,    70,    57,    56,    60,    59,
      52,    53,    54,    55,    58,    19,    77,    74,    76,    42,
       0,    19,    73,     0,     7,    86,    73,    73,    78,     0,
      73,     0,     0,    46,    34,    87,    25,     0,    73,    37,
       0,    73,    48,    45,     0,     0,    43,     0,    41,     0,
      47,    73,    79,    22,    39,     0,    26,     0,    19,     0,
       0,    19,    50,     0,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     7,    15,    36,   122,    20,    12,    30,     3,
      13,    27,    49,    45,    46,    47,   114,    74,   119,   160,
     183,   153,   173,   178,   179,    67,    68,    69,    70,    71,
      72,    89,   124
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -71
static const yytype_int16 yypact[] =
{
       9,     7,    23,    27,   -11,   -71,    19,    20,   -71,    78,
     -71,    42,   -71,     9,    40,    82,    55,   -71,    -2,    93,
      57,    58,   -71,    96,   -71,    61,   -71,     9,    59,     9,
       9,   -71,    60,   -71,    44,   -71,    44,   164,    68,    91,
      69,   -71,    91,    72,    91,    80,    71,    44,   -71,     9,
      85,   -71,   -71,    91,    91,    91,    91,    91,    86,    91,
     115,   -71,    -8,   128,   130,    91,    91,   343,   -71,   102,
     103,   -71,   -71,    22,    94,   343,   132,   343,   -71,    44,
     -71,   -71,   -71,   343,   343,   343,   343,   343,   141,    98,
     182,    99,   -71,   -71,    91,   -71,   -71,   -71,   322,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    91,    91,   100,     6,     6,    97,    44,   104,
     101,   -71,    27,    91,   -71,   -71,   -23,   -71,   206,   -71,
     442,   442,    43,    43,   364,   385,   406,   427,    43,    43,
      56,    56,   -71,   -71,   -71,    44,   -15,   -71,   -71,   -71,
     107,    44,    91,   106,   -71,   141,    91,    91,   110,   108,
      91,   136,   109,   343,   -71,   -71,   343,   230,    91,   -71,
     278,    91,   133,   101,   134,   254,   -71,   300,   -71,   148,
     -71,    91,   -71,    22,   -71,   119,   343,   122,    44,   126,
     138,    44,   -71,   139,   -71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,    47,   -71,   -71,   -71,   -71,   -71,   -71,    11,
     -71,   -71,   -71,   -35,   -70,   -71,   -71,   -71,   -71,   -71,
     -71,    14,   -71,   -71,   -71,   -38,   -71,   -71,   -71,   -66,
     -34,   -71,    34
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -85
static const yytype_int16 yytable[] =
{
      48,    50,    48,   117,    75,   156,    77,    92,    93,    61,
     146,     4,    80,    48,     1,    83,    84,    85,    86,    87,
      88,    90,   157,     5,    17,    58,    37,    97,    98,    38,
      94,     6,    58,     8,     9,    43,    44,    94,    31,    48,
      33,    34,    22,    23,   121,    48,    66,    11,    37,   147,
     148,    38,    39,    40,    41,    42,   128,    43,    44,    10,
      81,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   109,   110,   111,   112,
     113,    14,    16,   150,    48,   155,    18,    19,   -22,    61,
      62,   111,   112,   113,    61,    62,    21,    24,    25,    28,
      26,    63,    64,    29,    35,    32,    63,    64,    60,    73,
     159,    48,    76,   187,   163,    79,   162,    48,   166,   167,
     -75,    91,   170,    78,    65,   -75,    66,   -84,    82,    65,
     175,    66,    95,   177,    96,   115,   118,   116,   120,   125,
     127,   149,   145,   186,   171,   -49,   151,   164,   152,    48,
     161,   169,   172,   190,    48,   168,   193,    48,    99,   100,
     185,   188,   181,   189,   101,   102,   103,   104,   191,   154,
     105,   106,   107,   108,   109,   110,   111,   112,   113,    51,
      52,   192,   194,    53,    54,    55,    56,   180,   123,   165,
       0,     0,    57,     0,     0,     0,     0,     0,     0,    99,
     100,     0,     0,     0,    58,   101,   102,   103,   104,    59,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
       0,     0,     0,    99,   100,     0,     0,     0,   126,   101,
     102,   103,   104,     0,     0,   105,   106,   107,   108,   109,
     110,   111,   112,   113,     0,     0,     0,    99,   100,     0,
       0,     0,   158,   101,   102,   103,   104,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
       0,    99,   100,     0,     0,     0,   174,   101,   102,   103,
     104,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,    99,   100,     0,     0,     0,
     182,   101,   102,   103,   104,     0,     0,   105,   106,   107,
     108,   109,   110,   111,   112,   113,     0,    99,   100,     0,
       0,     0,   176,   101,   102,   103,   104,     0,     0,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,    99,
     100,     0,     0,     0,   184,   101,   102,   103,   104,     0,
       0,   105,   106,   107,   108,   109,   110,   111,   112,   113,
      99,   100,     0,   129,     0,     0,   101,   102,   103,   104,
       0,     0,   105,   106,   107,   108,   109,   110,   111,   112,
     113,    99,   100,     0,     0,     0,     0,   101,   102,     0,
     104,     0,     0,   105,   106,   107,   108,   109,   110,   111,
     112,   113,    99,   100,     0,     0,     0,     0,   101,   102,
       0,     0,     0,     0,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    99,   100,     0,     0,     0,     0,   101,
     102,     0,     0,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,    99,   100,     0,     0,     0,     0,
     101,   102,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,   101,   102,     0,     0,     0,
       0,     0,     0,   107,   108,   109,   110,   111,   112,   113
};

static const yytype_int16 yycheck[] =
{
      34,    36,    36,    73,    42,    28,    44,    15,    16,     3,
       4,     4,    47,    47,     5,    53,    54,    55,    56,    57,
      58,    59,    45,     0,    13,    40,     4,    65,    66,     7,
      45,     4,    40,    44,    45,    13,    14,    45,    27,    73,
      29,    30,    44,    45,    79,    79,    40,    27,     4,   115,
     116,     7,     8,     9,    10,    11,    94,    13,    14,    40,
      49,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,    33,    34,    35,    36,
      37,     3,    40,   118,   118,   123,    46,     5,    44,     3,
       4,    35,    36,    37,     3,     4,    41,     4,    41,     3,
      42,    15,    16,    42,    44,    46,    15,    16,    40,    40,
     145,   145,    40,   183,   152,    44,   151,   151,   156,   157,
      34,     6,   160,    43,    38,    34,    40,    41,    43,    38,
     168,    40,     4,   171,     4,    33,    42,    34,     6,    41,
      41,    44,    42,   181,     8,    12,    42,    41,    47,   183,
      43,    43,    43,   188,   188,    45,   191,   191,    17,    18,
      12,    42,    28,    41,    23,    24,    25,    26,    42,   122,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    15,
      16,    43,    43,    19,    20,    21,    22,   173,    47,   155,
      -1,    -1,    28,    -1,    -1,    -1,    -1,    -1,    -1,    17,
      18,    -1,    -1,    -1,    40,    23,    24,    25,    26,    45,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    17,    18,    -1,    -1,    -1,    46,    23,
      24,    25,    26,    -1,    -1,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    17,    18,    -1,
      -1,    -1,    46,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    17,    18,    -1,    -1,    -1,    46,    23,    24,    25,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    -1,    -1,    -1,    17,    18,    -1,    -1,    -1,
      46,    23,    24,    25,    26,    -1,    -1,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    -1,    17,    18,    -1,
      -1,    -1,    44,    23,    24,    25,    26,    -1,    -1,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    17,
      18,    -1,    -1,    -1,    44,    23,    24,    25,    26,    -1,
      -1,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      17,    18,    -1,    41,    -1,    -1,    23,    24,    25,    26,
      -1,    -1,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    17,    18,    -1,    -1,    -1,    -1,    23,    24,    -1,
      26,    -1,    -1,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    17,    18,    -1,    -1,    -1,    -1,    23,    24,
      -1,    -1,    -1,    -1,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    17,    18,    -1,    -1,    -1,    -1,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    37,    17,    18,    -1,    -1,    -1,    -1,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    37,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    49,    57,     4,     0,     4,    50,    44,    45,
      40,    27,    55,    58,     3,    51,    40,    57,    46,     5,
      54,    41,    44,    45,     4,    41,    42,    59,     3,    42,
      56,    57,    46,    57,    57,    44,    52,     4,     7,     8,
       9,    10,    11,    13,    14,    61,    62,    63,    78,    60,
      61,    15,    16,    19,    20,    21,    22,    28,    40,    45,
      40,     3,     4,    15,    16,    38,    40,    73,    74,    75,
      76,    77,    78,    40,    65,    73,    40,    73,    43,    44,
      61,    57,    43,    73,    73,    73,    73,    73,    73,    79,
      73,     6,    15,    16,    45,     4,     4,    73,    73,    17,
      18,    23,    24,    25,    26,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    64,    33,    34,    62,    42,    66,
       6,    61,    53,    47,    80,    41,    46,    41,    73,    41,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    42,     4,    77,    77,    44,
      61,    42,    47,    69,    50,    73,    28,    45,    46,    61,
      67,    43,    61,    73,    41,    80,    73,    73,    45,    43,
      73,     8,    43,    70,    46,    73,    44,    73,    71,    72,
      69,    28,    46,    68,    44,    12,    73,    62,    42,    41,
      61,    42,    43,    61,    43
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
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
#line 76 "c2f3.y"
    { ; ;}
    break;

  case 3:
#line 79 "c2f3.y"
    { variable_cnt = 0; ;}
    break;

  case 4:
#line 80 "c2f3.y"
    {
                                                            strcpy (funcion_actual, (yyvsp[(1) - (2)].cadena)) ;
                                                            variable_cnt = 0;
                                                        ;}
    break;

  case 5:
#line 85 "c2f3.y"
    {
                                                            if(strcmp("", (yyvsp[(4) - (7)].cadena))) {
                                                                char * id = malloc(64*sizeof(char));
                                                                if (id == NULL) { perror("Error at malloc\n");}
                                                                sprintf(id, "%s", (yyvsp[(4) - (7)].cadena));
                                                                printf("%s !\n", getScopeVariableId(id));
                                                            }
                                                        ;}
    break;

  case 6:
#line 93 "c2f3.y"
    { printf (" ;\n"); ;}
    break;

  case 8:
#line 97 "c2f3.y"
    { sprintf((yyval.cadena), ""); ;}
    break;

  case 9:
#line 98 "c2f3.y"
    {
                                                                            sprintf((yyval.cadena), "%s", (yyvsp[(2) - (2)].cadena));
                                                                            createVariable((yyvsp[(2) - (2)].cadena));
                                                                        ;}
    break;

  case 10:
#line 104 "c2f3.y"
    {
                                                sprintf (funcion_actual, "main");
                                                variable_cnt = 0;
                                            ;}
    break;

  case 11:
#line 108 "c2f3.y"
    { printf (" ;\n"); ;}
    break;

  case 12:
#line 111 "c2f3.y"
    {
                                                    if(strcmp(funcion_actual, "global")) {
                                                        printf (": %s \n", funcion_actual);

                                                    }
                                                ;}
    break;

  case 13:
#line 117 "c2f3.y"
    { createVariable((yyvsp[(2) - (3)].cadena)); ;}
    break;

  case 15:
#line 119 "c2f3.y"
    { createArray((yyvsp[(2) - (6)].cadena), atoi((yyvsp[(4) - (6)].cadena))); ;}
    break;

  case 17:
#line 121 "c2f3.y"
    { createMatrix((yyvsp[(2) - (9)].cadena), atoi((yyvsp[(4) - (9)].cadena)), atoi((yyvsp[(7) - (9)].cadena))); ;}
    break;

  case 19:
#line 125 "c2f3.y"
    { ; ;}
    break;

  case 20:
#line 126 "c2f3.y"
    { ; ;}
    break;

  case 21:
#line 127 "c2f3.y"
    { ; ;}
    break;

  case 22:
#line 130 "c2f3.y"
    { ; ;}
    break;

  case 23:
#line 131 "c2f3.y"
    { printf("%s\n", (yyvsp[(1) - (1)].cadena)) ;}
    break;

  case 24:
#line 132 "c2f3.y"
    { printf("%s %s ! \n", (yyvsp[(3) - (3)].cadena), getScopeVariableId((yyvsp[(1) - (3)].cadena))); ;}
    break;

  case 25:
#line 133 "c2f3.y"
    { printf("%s %s %s CELLS + ! \n", (yyvsp[(6) - (6)].cadena), getScopeVariableId((yyvsp[(1) - (6)].cadena)), (yyvsp[(3) - (6)].cadena)); ;}
    break;

  case 26:
#line 135 "c2f3.y"
    { printf("%s %s %s %s ! \n", (yyvsp[(9) - (9)].cadena), (yyvsp[(3) - (9)].cadena), (yyvsp[(6) - (9)].cadena), getScopeVariableId((yyvsp[(1) - (9)].cadena))); ;}
    break;

  case 27:
#line 136 "c2f3.y"
    { printf (".\" %s \"\n", (yyvsp[(3) - (4)].cadena)); ;}
    break;

  case 28:
#line 137 "c2f3.y"
    { printf("%s @ 1 + %s !\n", getScopeVariableId((yyvsp[(1) - (2)].cadena)), getScopeVariableId((yyvsp[(1) - (2)].cadena))); ;}
    break;

  case 29:
#line 138 "c2f3.y"
    { printf("%s @ 1 - %s !\n", getScopeVariableId((yyvsp[(1) - (2)].cadena)), getScopeVariableId((yyvsp[(1) - (2)].cadena))); ;}
    break;

  case 30:
#line 139 "c2f3.y"
    { printf("%s %s @ + %s !\n", (yyvsp[(3) - (3)].cadena), getScopeVariableId((yyvsp[(1) - (3)].cadena)), getScopeVariableId((yyvsp[(1) - (3)].cadena))); ;}
    break;

  case 31:
#line 140 "c2f3.y"
    { printf("%s %s @ - %s !\n", (yyvsp[(3) - (3)].cadena), getScopeVariableId((yyvsp[(1) - (3)].cadena)), getScopeVariableId((yyvsp[(1) - (3)].cadena))); ;}
    break;

  case 32:
#line 141 "c2f3.y"
    { printf("%s %s @ * %s !\n", (yyvsp[(3) - (3)].cadena), getScopeVariableId((yyvsp[(1) - (3)].cadena)), getScopeVariableId((yyvsp[(1) - (3)].cadena))); ;}
    break;

  case 33:
#line 142 "c2f3.y"
    { printf("%s %s @ / %s !\n", (yyvsp[(3) - (3)].cadena), getScopeVariableId((yyvsp[(1) - (3)].cadena)), getScopeVariableId((yyvsp[(1) - (3)].cadena))); ;}
    break;

  case 35:
#line 144 "c2f3.y"
    { printf("%s\n", (yyvsp[(2) - (2)].cadena)); ;}
    break;

  case 36:
#line 147 "c2f3.y"
    { printf("begin %s while\n", (yyvsp[(2) - (2)].cadena)) ; ;}
    break;

  case 37:
#line 148 "c2f3.y"
    { printf("repeat\n") ; ;}
    break;

  case 38:
#line 149 "c2f3.y"
    { printf("begin\n") ; ;}
    break;

  case 39:
#line 151 "c2f3.y"
    { printf("%s while repeat\n", (yyvsp[(7) - (8)].cadena)) ; ;}
    break;

  case 40:
#line 152 "c2f3.y"
    { printf("%s if\n", (yyvsp[(2) - (2)].cadena)) ; ;}
    break;

  case 42:
#line 155 "c2f3.y"
    { ; ;}
    break;

  case 43:
#line 156 "c2f3.y"
    { printf("begin %s while\n", (yyvsp[(6) - (7)].cadena)) ; ;}
    break;

  case 44:
#line 157 "c2f3.y"
    { printf("repeat\n") ; ;}
    break;

  case 46:
#line 162 "c2f3.y"
    { printf ("%s .\n", (yyvsp[(2) - (2)].cadena)) ; ;}
    break;

  case 48:
#line 166 "c2f3.y"
    { printf ( " then\n" ) ; ;}
    break;

  case 49:
#line 167 "c2f3.y"
    { printf ( " else " ) ; ;}
    break;

  case 50:
#line 168 "c2f3.y"
    { printf ( " then\n" ) ; ;}
    break;

  case 51:
#line 171 "c2f3.y"
    { sprintf((yyval.cadena), "%s", (yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 52:
#line 172 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s +", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 53:
#line 173 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s -", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 54:
#line 174 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s *", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 55:
#line 175 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s /", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 56:
#line 176 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s and", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 57:
#line 177 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s or", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 58:
#line 178 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s mod", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 59:
#line 179 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s >", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 60:
#line 180 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s <", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 61:
#line 181 "c2f3.y"
    { sprintf((yyval.cadena), "%s @", getScopeVariableId((yyvsp[(1) - (2)].cadena))); ;}
    break;

  case 62:
#line 182 "c2f3.y"
    { sprintf((yyval.cadena), "%s @", getScopeVariableId((yyvsp[(1) - (2)].cadena))); ;}
    break;

  case 63:
#line 183 "c2f3.y"
    { sprintf((yyval.cadena), "%s @ 1 +", getScopeVariableId((yyvsp[(2) - (2)].cadena))); ;}
    break;

  case 64:
#line 184 "c2f3.y"
    { sprintf((yyval.cadena), "%s @ 1 -", getScopeVariableId((yyvsp[(2) - (2)].cadena))); ;}
    break;

  case 65:
#line 185 "c2f3.y"
    { sprintf((yyval.cadena), "%s 0=", (yyvsp[(2) - (2)].cadena)); ;}
    break;

  case 66:
#line 186 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s =", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 67:
#line 187 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s = 0=", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 68:
#line 188 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s <=", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 69:
#line 189 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s >=", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 70:
#line 190 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s and", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 71:
#line 191 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s or", (yyvsp[(1) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 72:
#line 195 "c2f3.y"
    { (yyval.cadena) = (yyvsp[(1) - (1)].cadena); ;}
    break;

  case 73:
#line 196 "c2f3.y"
    { ; ;}
    break;

  case 74:
#line 196 "c2f3.y"
    { sprintf((yyval.cadena), "%s", (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 75:
#line 197 "c2f3.y"
    { ; ;}
    break;

  case 76:
#line 197 "c2f3.y"
    { sprintf((yyval.cadena), "%s negate", (yyvsp[(3) - (3)].cadena)); ;}
    break;

  case 77:
#line 200 "c2f3.y"
    { sprintf((yyval.cadena), "%s @", getScopeVariableId((yyvsp[(1) - (1)].cadena))); ;}
    break;

  case 78:
#line 201 "c2f3.y"
    {
                                                        char* aux = malloc(64*sizeof(char));
                                                        if (aux == NULL) { perror("Error at malloc\n");}
                                                        sprintf(aux, "%s", (yyvsp[(3) - (4)].cadena));
                                                        sprintf((yyval.cadena), "%s %s CELLS + @", getScopeVariableId((yyvsp[(1) - (4)].cadena)), aux);
                                                        free(aux);
                                                    ;}
    break;

  case 79:
#line 209 "c2f3.y"
    { sprintf((yyval.cadena), "%s %s %s @", (yyvsp[(3) - (7)].cadena), (yyvsp[(6) - (7)].cadena), getScopeVariableId((yyvsp[(1) - (7)].cadena))); ;}
    break;

  case 80:
#line 210 "c2f3.y"
    { sprintf((yyval.cadena), "%s", (yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 81:
#line 211 "c2f3.y"
    { sprintf((yyval.cadena), "%s", (yyvsp[(2) - (3)].cadena)); ;}
    break;

  case 82:
#line 212 "c2f3.y"
    { sprintf((yyval.cadena), "%s", (yyvsp[(1) - (1)].cadena)); ;}
    break;

  case 83:
#line 215 "c2f3.y"
    {
                                                        char* aux = malloc(64*sizeof(char));
                                                        if (aux == NULL) { perror("Error at malloc\n"); }
                                                        sprintf(aux, "%s", (yyvsp[(1) - (4)].cadena));
                                                        sprintf((yyval.cadena), "%s%s", (yyvsp[(3) - (4)].cadena), aux);
                                                    ;}
    break;

  case 84:
#line 223 "c2f3.y"
    { sprintf((yyval.cadena), ""); ;}
    break;

  case 85:
#line 224 "c2f3.y"
    { sprintf((yyval.cadena), "%s%s ", (yyvsp[(1) - (2)].cadena), (yyvsp[(2) - (2)].cadena)); ;}
    break;

  case 86:
#line 227 "c2f3.y"
    { sprintf((yyval.cadena), ""); ;}
    break;

  case 87:
#line 228 "c2f3.y"
    { sprintf((yyval.cadena), " %s%s", (yyvsp[(2) - (3)].cadena), (yyvsp[(3) - (3)].cadena)); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2028 "c2f3.tab.c"
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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
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


#line 231 "c2f3.y"

                            // SECCION 4    Codigo en C
int n_linea = 1 ;

int yyerror (mensaje)
char *mensaje ;
{
    fprintf (stderr, "%s en la linea %d\n", mensaje, n_linea) ;
    printf ( "bye\n") ;
    exit(1);
}

char *mi_malloc (int nbytes)       // reserva n bytes de memoria dinamica
{
    char *p ;
    static long int nb = 0;        // sirven para contabilizar la memoria
    static int nv = 0 ;            // solicitada en total

    p = malloc (nbytes) ;
    if (p == NULL) {
        fprintf (stderr, "No queda memoria para %d bytes mas\n", nbytes) ;
        fprintf (stderr, "Reservados %ld bytes en %d llamadas\n", nb, nv) ;
        exit (0) ;
    }
    nb += (long) nbytes ;
    nv++ ;

    return p ;
}


/***************************************************************************/
/********************** Seccion de Palabras Reservadas *********************/
/***************************************************************************/

typedef struct s_pal_reservadas { // para las palabras reservadas de C
    char *nombre ;
    int token ;
} t_reservada ;


t_reservada pal_reservadas [] = { // define las palabras reservadas y los
    {"main",        MAIN},           // y los token asociados
    {"int",         INTEGER},
    {"puts",        PUTS},
    {"while",       WHILE},
    {"for",         FOR},
    {"do",          DO},
    {"if",          IF},
    {"else",        ELSE},
    {"printf",      PRINTF},
    {"return",      RETURN},
    {"++",          INC},
    {"--",          DEC},
    {"+=",          THISPLUS},
    {"-=",          THISMINUS},
    {"*=",          THISTIMES},
    {"/=",          THISDIVIDED},
    {"==",          EQUALS},
    {"!=",          NOTEQUALS},
    {">=",          GE},
    {"<=",          LE},
    {"||",          OR},
    {"&&",          AND},
    {NULL,          0}               // para marcar el fin de la tabla
} ;

t_reservada *busca_pal_reservada (char *nombre_simbolo)
{                                  // Busca n_s en la tabla de pal. res.
                                   // y devuelve puntero a registro (simbolo)
    int i ;
    t_reservada *sim ;

    i = 0 ;
    sim = pal_reservadas ;
    while (sim [i].nombre != NULL) {
        if (strcmp (sim [i].nombre, nombre_simbolo) == 0) {
            return &(sim [i]);
        }
        i++ ;
    }

    return NULL ;
}


/***************************************************************************/
/******************* Seccion del Analizador Lexicografico ******************/
/***************************************************************************/

char *genera_cadena (char *nombre)     // copia el argumento a un
{                                      // string en memoria dinamica
    char *p ;
    int l;
    l = strlen (nombre)+1 ;
    p = (char *) mi_malloc (l) ;
    strcpy (p, nombre);
    return p ;
}


int yylex ()
{
    int i ;
    unsigned char c ;
    unsigned char cc ;
    char ops_expandibles [] = "=!<>&|%+-*/" ;
    char cadena [256] ;
    t_reservada *simbolo ;

    do {
        c = getchar () ;
        if (c == '#') {	// Ignora las líneas que empiezan por #  (#define, #include)
            do {		//	OJO que puede funcionar mal si una linea contiene #
                c = getchar () ;
            } while (c != '\n') ;
        }

        if (c == '\"') {
            i = 0 ;
            do {
                c = getchar () ;
                if (c != '\"') {cadena [i++] = c ;}
            } while (c != '\"' && i < 254) ;
            cadena [i] = '\0' ;
            yylval.cadena = genera_cadena (cadena) ;
            return (STRING) ;
         }

        if (c == '/') {	// Si la linea contiene un / puede ser inicio de comentario
            cc = getchar () ;
            if (cc != '/') {   // Si el siguiente char es /  es un comentario, pero...
                if (cc == '*') {
                    while (c != '*' || cc != '/') {
                        c = cc;
                        cc = getchar ();
                    }
                    c = getchar ();
                } else {
                    ungetc (cc, stdin) ;
                }
            } else {
                c = getchar () ;	// ...
                if (c == '@') {	// Si es la secuencia //@  ==> transcribimos la linea
                    do {		// Se trata de codigo inline (Codigo Forth embebido en C)
                        c = getchar () ;
                        putchar (c) ;
                    } while (c != '\n') ;
                } else {		// ==> comentario, ignorar la linea
                    while (c != '\n') {
                        c = getchar () ;
                    }
                }
            }
        }

        if (c == '\n')
            n_linea++ ;

    } while (c == ' ' || c == '\n' || c == 10 || c == 13 || c == '\t') ;

    if (c == '\"') {
        i = 0 ;
        do {
            c = getchar () ;
            cadena [i++] = c ;
        } while (c != '\"' && i < 255) ;
        if (i == 256) {
            printf ("AVISO: string con mas de 255 caracteres en linea %d\n", n_linea) ;
        }		 	// habria que leer hasta el siguient " , pero, y si falta?
        cadena [--i] = '\0' ;
        yylval.cadena = genera_cadena (cadena) ;
        return (STRING) ;
    }

    if (c == '.' || (c >= '0' && c <= '9')) {
        i = 0 ;
        while (( (c >= '0' && c <= '9') || c == '_') && i < 255) {
            cadena [i++] = c ;
            c = getchar () ;
        }
        cadena [i] = '\0' ;
        ungetc (c, stdin) ;

        yylval.cadena = genera_cadena (cadena) ;
        simbolo = busca_pal_reservada (yylval.cadena) ;
        if (simbolo == NULL) {    // no es palabra reservada -> NUMERO
            /*printf ("\nDEV: NUMERO %s\n", yylval.cadena) ;    // PARA DEPURAR*/
            return (NUMERO) ;
        } else {
            /*printf ("\nDEV: OTRO %s\n", yylval.cadena) ;       // PARA DEPURAR*/
            return (simbolo->token) ;
        }
    }

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        i = 0 ;
        while (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                (c >= '0' && c <= '9') || c == '_') && i < 255) {

            cadena [i++] = tolower (c) ;
            c = getchar () ;
        }
        cadena [i] = '\0' ;
        ungetc (c, stdin) ;
        yylval.cadena = genera_cadena (cadena) ;
        simbolo = busca_pal_reservada (yylval.cadena) ;
        if (simbolo == NULL) {    // no es palabra reservada -> identificador
            /*printf ("\nDEV: IDENTIF %s\n", yylval.cadena) ;    // PARA DEPURAR*/
            return (IDENTIF) ;
        } else {
            /*printf ("\nDEV: OTRO %s\n", yylval.cadena) ;       // PARA DEPURAR*/
            return (simbolo->token) ;
        }
    }

    if (strchr (ops_expandibles, c) != NULL) { // busca c en ops_expandibles
        cc = getchar () ;
        sprintf (cadena, "%c%c", (char) c, (char) cc) ;
        simbolo = busca_pal_reservada (cadena) ;
        if (simbolo == NULL) {
            ungetc (cc, stdin) ;
            yylval.cadena = NULL ;
            return (c) ;
        } else {
            yylval.cadena = genera_cadena (cadena) ; // aunque no se use
            return (simbolo->token) ;
        }
    }

//    printf ("\nDEV: LITERAL %d #%c#\n", (int) c, c) ;      // PARA DEPURAR
    if (c == EOF || c == 255 || c == 26) {
        //printf ("tEOF ") ;                                // PARA DEPURAR
        return (0) ;
    }

    return c ;
}

int storeVariableId(char *variable_id)
{

    // copy variable name into local variable names storage
    sprintf(variable[variable_cnt], "%s", variable_id);

    // update the variable names storage pointer
    variable_cnt++;

    return 0; // success
}


int createVariable(char *variable_id)
{
    // store variable name in list
    storeVariableId(variable_id);

    // translate the declaration to forth
    printf ("variable %s\n", getScopeVariableId(variable_id));

    return 0; // success
}

int createArray(char *variable_id, int size)
{
    // store variable name in list
    storeVariableId(variable_id);

    // translate the declaration to forth
    printf("variable %s %d cells allot\n", getScopeVariableId(variable_id), size);

    return 0; // success
}

int createMatrix(char *id, int x, int y)
{
    storeVariableId(id);

    if(!there_are_matrices) {
        // declare aux function to create matrices only when necessary
        printf(": matrix-n-m ( #rows #cols -- )\nCREATE DUP , * ALLOT\nDOES> ( member: row col -- addr )\nROT OVER @ * + +  CELL+ ;\n");
        there_are_matrices = 1;
    }

    printf("%d %d matrix-n-m %s\n", x, y, getScopeVariableId(id));
    return 0; // success
}

char *getScopeVariableId(char *variable_id)
{
    int i, is_local = 0;
    char *nombre_completo = malloc(256*sizeof(char));

    // iterate over the stored names to obtain a match
    for (i = 0; i < variable_cnt; i++) {
        if(!strcmp(variable_id, variable[i])) {
            is_local = 1;
            break;
        }
    }

    if(is_local) { // when it is a local variable, print the function suffix
        sprintf (nombre_completo, "%s_%s", variable_id, funcion_actual);
    } else { // when it is a global variable, print the global suffix
        sprintf (nombre_completo, "%s_global", variable_id);
    }

    return nombre_completo; // success
}

int main ()
{
    int i;
    for(i = 0; i < 32; i++) {
        variable[i] = malloc(32*sizeof(char));
    }
    // initialize scope variable count
    variable_cnt = 0;
    // initialize global flag for matrices
    there_are_matrices = 0;
    // set global scope as default
    sprintf (funcion_actual, "global");
    yyparse () ;
    for(i = 0; i < 32; i++) {
        free(variable[i]);
    }
}

