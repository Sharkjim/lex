/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "syntax_analyzer.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include <stdbool.h> 
    #include "hash_table.c"

    extern char filename[256];
    extern FILE* yyin;
    HASH_TABLE *symbol_table;

    int scope = 0; 
    int syntax_errors = 0;
    void yyerror(const char *reason);
    int yylex();

/* Line 371 of yacc.c  */
#line 86 "syntax_analyzer.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_id = 258,
     T_string = 259,
     T_program = 260,
     T_const = 261,
     T_type = 262,
     T_array = 263,
     T_set = 264,
     T_of = 265,
     T_record = 266,
     T_var = 267,
     T_forward = 268,
     T_function = 269,
     T_procedure = 270,
     T_integer = 271,
     T_real = 272,
     T_boolean = 273,
     T_char = 274,
     T_begin = 275,
     T_end = 276,
     T_if = 277,
     T_then = 278,
     T_else = 279,
     T_while = 280,
     T_do = 281,
     T_for = 282,
     T_downto = 283,
     T_to = 284,
     T_with = 285,
     T_read = 286,
     T_write = 287,
     T_iconst = 288,
     T_rconst = 289,
     T_bconst = 290,
     T_cconst = 291,
     T_relop = 292,
     T_addop = 293,
     T_or = 294,
     T_muldivandop = 295,
     T_not = 296,
     T_in = 297,
     T_lparen = 298,
     T_rparen = 299,
     T_semi = 300,
     T_dot = 301,
     T_comma = 302,
     T_equ = 303,
     T_colon = 304,
     T_lbrack = 305,
     T_rbrack = 306,
     T_assign = 307,
     T_dotdot = 308,
     T_eof = 309,
     SETEXPR = 310
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 19 "syntax_analyzer.y"

    unsigned int integer;
    double real;
    char str[1024];
    char character;
    int boolean;


/* Line 387 of yacc.c  */
#line 190 "syntax_analyzer.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

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



/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 218 "syntax_analyzer.tab.c"

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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   303

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  120
/* YYNRULES -- Number of states.  */
#define YYNSTATES  235

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   310

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    13,    17,    21,    22,    28,    32,
      36,    40,    44,    48,    52,    56,    59,    62,    64,    69,
      71,    75,    77,    79,    83,    88,    92,    94,    96,    98,
     100,   102,   106,   109,   113,   115,   119,   121,   125,   126,
     132,   136,   143,   147,   151,   155,   159,   163,   165,   169,
     171,   174,   177,   179,   181,   183,   185,   187,   189,   191,
     193,   195,   197,   201,   203,   207,   211,   213,   217,   218,
     224,   228,   232,   233,   237,   238,   245,   246,   253,   254,
     259,   260,   264,   268,   269,   276,   281,   283,   284,   288,
     292,   294,   296,   298,   300,   302,   304,   306,   308,   310,
     311,   315,   319,   324,   331,   333,   338,   345,   349,   353,
     358,   360,   365,   370,   375,   379,   381,   383,   387,   389,
     391
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    58,    59,    82,    92,    46,    -1,     5,
       3,    45,    -1,    60,    69,    80,    -1,     6,    61,    45,
      -1,    -1,    61,    45,     3,    48,    62,    -1,     3,    48,
      62,    -1,    62,    37,    62,    -1,    62,    48,    62,    -1,
      62,    42,    62,    -1,    62,    39,    62,    -1,    62,    38,
      62,    -1,    62,    40,    62,    -1,    38,    62,    -1,    41,
      62,    -1,    63,    -1,     3,    43,    64,    44,    -1,    65,
      -1,    43,    62,    44,    -1,    66,    -1,     3,    -1,    63,
      46,     3,    -1,    63,    50,    64,    51,    -1,    64,    47,
      62,    -1,    62,    -1,    33,    -1,    34,    -1,    35,    -1,
      36,    -1,    50,    67,    51,    -1,    50,    51,    -1,    67,
      47,    68,    -1,    68,    -1,    62,    53,    62,    -1,    62,
      -1,     7,    70,    45,    -1,    -1,    70,    45,     3,    48,
      71,    -1,     3,    48,    71,    -1,     8,    50,    72,    51,
      10,    75,    -1,     9,    10,    75,    -1,    11,    77,    21,
      -1,    43,    79,    44,    -1,    74,    53,    74,    -1,    72,
      47,    73,    -1,    73,    -1,    74,    53,    74,    -1,     3,
      -1,    38,    33,    -1,    38,     3,    -1,    33,    -1,    36,
      -1,    35,    -1,     3,    -1,    76,    -1,     3,    -1,    16,
      -1,    17,    -1,    18,    -1,    19,    -1,    77,    45,    78,
      -1,    78,    -1,    79,    49,    75,    -1,    79,    47,     3,
      -1,     3,    -1,    12,    81,    45,    -1,    -1,    81,    45,
      79,    49,    75,    -1,    79,    49,    75,    -1,    82,    83,
      45,    -1,    -1,    85,    45,    13,    -1,    -1,    85,    45,
      84,    59,    82,    92,    -1,    -1,    14,     3,    86,    89,
      49,    76,    -1,    -1,    15,     3,    87,    89,    -1,    -1,
      14,     3,    88,    -1,    43,    90,    44,    -1,    -1,    90,
      45,    91,    79,    49,    75,    -1,    91,    79,    49,    75,
      -1,    12,    -1,    -1,    20,    93,    21,    -1,    93,    45,
      94,    -1,    94,    -1,    95,    -1,    96,    -1,    97,    -1,
      98,    -1,   100,    -1,   101,    -1,   102,    -1,    92,    -1,
      -1,    63,    52,    62,    -1,    63,    52,     4,    -1,    22,
      62,    23,    94,    -1,    22,    62,    23,    94,    24,    94,
      -1,     1,    -1,    25,    62,    26,    94,    -1,    27,     3,
      52,    99,    26,    94,    -1,    62,    29,    62,    -1,    62,
      28,    62,    -1,    30,    63,    26,    94,    -1,     3,    -1,
       3,    43,   105,    44,    -1,    31,    43,   103,    44,    -1,
      32,    43,   105,    44,    -1,   103,    47,   104,    -1,   104,
      -1,    63,    -1,   105,    47,   106,    -1,   106,    -1,    62,
      -1,     4,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    65,    68,    71,    72,    75,    76,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    91,    94,    95,    96,    99,   100,   103,   104,   105,
     106,   109,   110,   113,   114,   117,   118,   121,   122,   125,
     126,   129,   130,   131,   132,   133,   136,   137,   140,   141,
     144,   145,   146,   147,   148,   149,   152,   153,   156,   157,
     158,   159,   162,   163,   166,   169,   170,   173,   174,   177,
     178,   181,   182,   185,   186,   186,   189,   189,   190,   190,
     191,   191,   194,   195,   198,   199,   202,   203,   206,   209,
     210,   213,   214,   215,   216,   217,   218,   219,   220,   221,
     224,   225,   228,   229,   230,   233,   236,   239,   240,   243,
     246,   247,   250,   251,   254,   255,   258,   261,   262,   265,
     266
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_id", "T_string", "T_program",
  "T_const", "T_type", "T_array", "T_set", "T_of", "T_record", "T_var",
  "T_forward", "T_function", "T_procedure", "T_integer", "T_real",
  "T_boolean", "T_char", "T_begin", "T_end", "T_if", "T_then", "T_else",
  "T_while", "T_do", "T_for", "T_downto", "T_to", "T_with", "T_read",
  "T_write", "T_iconst", "T_rconst", "T_bconst", "T_cconst", "T_relop",
  "T_addop", "T_or", "T_muldivandop", "T_not", "T_in", "T_lparen",
  "T_rparen", "T_semi", "T_dot", "T_comma", "T_equ", "T_colon", "T_lbrack",
  "T_rbrack", "T_assign", "T_dotdot", "T_eof", "SETEXPR", "$accept",
  "program", "header", "declarations", "constdefs", "constant_defs",
  "expression", "variable", "expressions", "constant", "setexpression",
  "elexpressions", "elexpression", "typedefs", "type_defs", "type_def",
  "dims", "limits", "limit", "typename", "standard_type", "fields",
  "field", "identifiers", "vardefs", "variable_defs", "subprograms",
  "subprogram", "$@1", "sub_header", "$@2", "$@3", "$@4",
  "formal_parameters", "parameter_list", "pass", "comp_statement",
  "statements", "statement", "assignment", "if_statement",
  "while_statement", "for_statement", "iter_space", "with_statement",
  "subprogram_call", "io_statement", "read_list", "read_item",
  "write_list", "write_item", YY_NULL
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    58,    59,    60,    60,    61,    61,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    62,    63,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    71,    71,    71,    71,    71,    72,    72,    73,    73,
      74,    74,    74,    74,    74,    74,    75,    75,    76,    76,
      76,    76,    77,    77,    78,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    84,    83,    86,    85,    87,    85,
      88,    85,    89,    89,    90,    90,    91,    91,    92,    93,
      93,    94,    94,    94,    94,    94,    94,    94,    94,    94,
      95,    95,    96,    96,    96,    97,    98,    99,    99,   100,
     101,   101,   102,   102,   103,   103,   104,   105,   105,   106,
     106
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     3,     3,     3,     0,     5,     3,     3,
       3,     3,     3,     3,     3,     2,     2,     1,     4,     1,
       3,     1,     1,     3,     4,     3,     1,     1,     1,     1,
       1,     3,     2,     3,     1,     3,     1,     3,     0,     5,
       3,     6,     3,     3,     3,     3,     3,     1,     3,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     3,     1,     3,     0,     5,
       3,     3,     0,     3,     0,     6,     0,     6,     0,     4,
       0,     3,     3,     0,     6,     4,     1,     0,     3,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     3,     4,     6,     1,     4,     6,     3,     3,     4,
       1,     4,     4,     4,     3,     1,     1,     3,     1,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     6,     0,     1,     0,    72,    38,     3,
       0,     0,     0,     0,    68,     0,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     4,    22,    27,    28,
      29,    30,     0,     0,     0,     0,     8,    17,    19,    21,
       0,    76,    78,   104,    22,     0,     0,     0,     0,     0,
       0,     0,    98,     0,    90,    91,    92,    93,    94,    95,
      96,    97,    71,    74,     2,     0,    37,    66,     0,     0,
       0,    15,    16,     0,    32,    36,     0,    34,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,    81,    83,
       0,     0,     0,     0,    22,     0,     0,     0,     0,    88,
       0,    73,     6,    55,     0,     0,     0,    52,    54,    53,
       0,     0,    40,     0,     0,     0,     0,    67,    26,     0,
      20,     0,     0,    31,     9,    13,    12,    14,    11,    10,
      23,     0,     7,    87,     0,    79,   120,   119,     0,   118,
       0,     0,     0,     0,   116,     0,   115,     0,   101,   100,
      89,    72,     0,     0,     0,    63,     0,    51,    50,     0,
       0,     0,    65,    57,    58,    59,    60,    61,    70,    56,
       0,    18,     0,    35,    33,    24,    86,     0,     0,     0,
     111,     0,   102,   105,     0,     0,   109,   112,     0,   113,
       0,    49,     0,    47,     0,    42,    43,     0,     0,    44,
      45,    39,     0,    25,    82,    87,     0,    77,   117,     0,
       0,     0,     0,   114,    75,     0,     0,     0,    62,    64,
      69,     0,     0,   103,   108,   107,   106,    46,     0,    48,
       0,    85,    41,     0,    84
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,     8,    11,   137,    37,   119,    38,
      39,    76,    77,    14,    24,   112,   192,   193,   113,   168,
     169,   154,   155,   156,    26,    69,    12,    20,   102,    21,
      87,    89,    88,   134,   177,   178,    52,    53,    54,    55,
      56,    57,    58,   185,    59,    60,    61,   145,   146,   138,
     139
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -150
static const yytype_int16 yypact[] =
{
      27,    31,    45,    46,    15,  -150,    58,  -150,    62,  -150,
      33,    78,     8,    87,    79,   150,   128,   134,   153,   202,
     126,   131,   133,   130,   136,   187,  -150,   149,  -150,  -150,
    -150,  -150,   150,   150,   150,    83,   246,   -39,  -150,  -150,
     146,   154,  -150,  -150,    77,   150,   150,   199,   201,   166,
     169,    99,  -150,    -5,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,   206,  -150,    39,   212,  -150,    55,   175,
     150,   174,  -150,   234,  -150,   204,   -37,  -150,   150,   150,
     150,   150,   150,   150,   218,   150,   150,   182,  -150,   182,
     105,    57,   121,   176,  -150,   -17,   201,   105,   132,  -150,
     202,  -150,    46,  -150,   180,   216,   187,  -150,  -150,  -150,
       2,   187,  -150,   192,   207,   255,   251,   187,   246,   -32,
    -150,   150,   150,  -150,   253,   174,   174,  -150,   253,   253,
    -150,    11,   246,   244,   213,  -150,  -150,   246,    56,  -150,
     186,   186,   150,   186,   -39,    66,  -150,    67,  -150,   246,
    -150,  -150,     3,   251,     6,  -150,    95,  -150,  -150,    81,
      21,    39,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
     103,  -150,   150,   246,  -150,  -150,  -150,   -19,   187,   219,
    -150,   105,   236,  -150,   211,   235,  -150,  -150,   201,  -150,
       8,   210,    41,  -150,   222,  -150,  -150,   187,   251,  -150,
    -150,  -150,   251,   246,  -150,   244,   115,  -150,  -150,   186,
     150,   150,   186,  -150,  -150,     3,   254,    21,  -150,  -150,
    -150,   187,   251,  -150,   246,   246,  -150,  -150,   251,  -150,
     125,  -150,  -150,   251,  -150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,  -150,   163,  -150,  -150,   -15,   -11,   181,  -150,
    -150,  -150,   155,  -150,  -150,   118,  -150,    65,  -139,  -149,
     102,  -150,    90,   -24,  -150,  -150,   138,  -150,  -150,  -150,
    -150,  -150,  -150,   208,  -150,    91,   -10,  -150,   -97,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,   110,   203,
     122
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -111
static const yytype_int16 yytable[] =
{
      36,    68,    22,   150,   195,   157,   191,    84,    51,   143,
     122,    85,   171,   194,   123,   172,    99,    71,    72,    73,
      75,   200,    17,    18,   103,   204,   205,   196,    19,    84,
      91,    92,     1,    85,     4,   158,   107,    95,   108,   109,
     100,   110,   103,   182,   183,     5,   186,   104,   105,   219,
     106,   197,     6,   220,   107,   118,   108,   109,   172,   110,
       9,    10,   175,   124,   125,   126,   127,   128,   129,    13,
     118,   132,   107,   231,   108,   109,   194,   110,   229,   232,
     140,    15,   111,   149,   234,   144,    27,   159,   215,    51,
      23,    25,   216,   170,    78,    79,    80,    81,  -110,    82,
     180,  -110,   115,   181,   116,    83,   173,    75,    27,   136,
     187,   189,   223,   188,   181,   226,    28,    29,    30,    31,
      90,    32,  -110,    16,    33,   199,    34,   184,   115,    51,
      51,    40,    51,    35,    74,    27,   148,    41,    28,    29,
      30,    31,   115,    32,   198,    84,    33,   141,    34,    85,
     115,    98,   202,    27,   206,    35,    42,   203,    78,    79,
      80,    81,   115,    82,   222,    28,    29,    30,    31,    83,
      32,    62,   115,    33,   233,    34,    63,   144,    65,    64,
     214,    66,    35,    28,    29,    30,    31,    43,    32,    44,
      67,    33,    70,    34,    86,   224,   225,   230,    51,   -80,
      35,    51,    93,    43,    94,    44,    19,   -99,    45,    96,
     -99,    46,    97,    47,    81,   114,    48,    49,    50,   101,
     117,   130,    19,   -99,    45,   133,   153,    46,   142,    47,
     152,   -99,    48,    49,    50,   164,   165,   166,   167,   210,
     211,    78,    79,    80,    81,   160,    82,   -99,    78,    79,
      80,    81,    83,    82,   163,   161,   176,   121,   162,    83,
     209,   212,   179,   -55,   228,   151,   131,   164,   165,   166,
     167,    78,    79,    80,    81,   217,    82,   174,   120,   201,
     227,   207,    83,    78,    79,    80,    81,   218,    82,   190,
    -111,    79,    80,    81,    83,  -111,   221,   135,   213,     0,
     147,  -111,     0,   208
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-150)))

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-111)))

static const yytype_int16 yycheck[] =
{
      15,    25,    12,   100,   153,     3,     3,    46,    19,    26,
      47,    50,    44,   152,    51,    47,    21,    32,    33,    34,
      35,   160,    14,    15,     3,    44,    45,    21,    20,    46,
      45,    46,     5,    50,     3,    33,    33,    48,    35,    36,
      45,    38,     3,   140,   141,     0,   143,     8,     9,   198,
      11,    45,     6,   202,    33,    70,    35,    36,    47,    38,
      45,     3,    51,    78,    79,    80,    81,    82,    83,     7,
      85,    86,    33,   222,    35,    36,   215,    38,   217,   228,
      23,    48,    43,    98,   233,    96,     3,   111,    47,   100,
       3,    12,    51,   117,    37,    38,    39,    40,    21,    42,
      44,    24,    47,    47,    49,    48,   121,   122,     3,     4,
      44,    44,   209,    47,    47,   212,    33,    34,    35,    36,
      43,    38,    45,    45,    41,    44,    43,   142,    47,   140,
     141,     3,   143,    50,    51,     3,     4,     3,    33,    34,
      35,    36,    47,    38,    49,    46,    41,    26,    43,    50,
      47,    52,    49,     3,   178,    50,     3,   172,    37,    38,
      39,    40,    47,    42,    49,    33,    34,    35,    36,    48,
      38,    45,    47,    41,    49,    43,    45,   188,    48,    46,
     190,    45,    50,    33,    34,    35,    36,     1,    38,     3,
       3,    41,    43,    43,    48,   210,   211,   221,   209,    45,
      50,   212,     3,     1,     3,     3,    20,    21,    22,    43,
      24,    25,    43,    27,    40,     3,    30,    31,    32,    13,
      45,     3,    20,    21,    22,    43,    10,    25,    52,    27,
      50,    45,    30,    31,    32,    16,    17,    18,    19,    28,
      29,    37,    38,    39,    40,    53,    42,    45,    37,    38,
      39,    40,    48,    42,     3,    48,    12,    53,     3,    48,
      24,    26,    49,    53,    10,   102,    85,    16,    17,    18,
      19,    37,    38,    39,    40,    53,    42,   122,    44,   161,
     215,   179,    48,    37,    38,    39,    40,   197,    42,   151,
      37,    38,    39,    40,    48,    42,   205,    89,   188,    -1,
      97,    48,    -1,   181
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     5,    57,    58,     3,     0,     6,    59,    60,    45,
       3,    61,    82,     7,    69,    48,    45,    14,    15,    20,
      83,    85,    92,     3,    70,    12,    80,     3,    33,    34,
      35,    36,    38,    41,    43,    50,    62,    63,    65,    66,
       3,     3,     3,     1,     3,    22,    25,    27,    30,    31,
      32,    63,    92,    93,    94,    95,    96,    97,    98,   100,
     101,   102,    45,    45,    46,    48,    45,     3,    79,    81,
      43,    62,    62,    62,    51,    62,    67,    68,    37,    38,
      39,    40,    42,    48,    46,    50,    48,    86,    88,    87,
      43,    62,    62,     3,     3,    63,    43,    43,    52,    21,
      45,    13,    84,     3,     8,     9,    11,    33,    35,    36,
      38,    43,    71,    74,     3,    47,    49,    45,    62,    64,
      44,    53,    47,    51,    62,    62,    62,    62,    62,    62,
       3,    64,    62,    43,    89,    89,     4,    62,   105,   106,
      23,    26,    52,    26,    63,   103,   104,   105,     4,    62,
      94,    59,    50,    10,    77,    78,    79,     3,    33,    79,
      53,    48,     3,     3,    16,    17,    18,    19,    75,    76,
      79,    44,    47,    62,    68,    51,    12,    90,    91,    49,
      44,    47,    94,    94,    62,    99,    94,    44,    47,    44,
      82,     3,    72,    73,    74,    75,    21,    45,    49,    44,
      74,    71,    49,    62,    44,    45,    79,    76,   106,    24,
      28,    29,    26,   104,    92,    47,    51,    53,    78,    75,
      75,    91,    49,    94,    62,    62,    94,    73,    10,    74,
      79,    75,    75,    49,    75
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
        case 3:
/* Line 1792 of yacc.c  */
#line 65 "syntax_analyzer.y"
    { hash_table_insert(symbol_table, (yyvsp[(2) - (3)].str), NULL, scope);}
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 75 "syntax_analyzer.y"
    { hash_table_insert(symbol_table, (yyvsp[(3) - (5)].str), NULL, scope);}
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 76 "syntax_analyzer.y"
    { hash_table_insert(symbol_table, (yyvsp[(1) - (3)].str), NULL, scope);}
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 125 "syntax_analyzer.y"
    {hash_table_insert(symbol_table, (yyvsp[(3) - (5)].str), NULL, scope);}
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 126 "syntax_analyzer.y"
    {hash_table_insert(symbol_table, (yyvsp[(1) - (3)].str), NULL, scope);}
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 169 "syntax_analyzer.y"
    {hash_table_insert(symbol_table, (yyvsp[(3) - (3)].str), NULL, scope);}
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 170 "syntax_analyzer.y"
    {hash_table_insert(symbol_table, (yyvsp[(1) - (1)].str), NULL, scope);}
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 186 "syntax_analyzer.y"
    {scope++;}
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 186 "syntax_analyzer.y"
    {scope--;}
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 189 "syntax_analyzer.y"
    {scope++;}
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 189 "syntax_analyzer.y"
    { scope--; hash_table_insert(symbol_table, (yyvsp[(2) - (6)].str), NULL, scope);}
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 190 "syntax_analyzer.y"
    {scope++;}
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 190 "syntax_analyzer.y"
    { scope--; hash_table_insert(symbol_table, (yyvsp[(2) - (4)].str), NULL, scope);}
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 191 "syntax_analyzer.y"
    {scope++;}
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 191 "syntax_analyzer.y"
    { scope--; hash_table_insert(symbol_table, (yyvsp[(2) - (3)].str), NULL, scope);}
    break;

  case 104:
/* Line 1792 of yacc.c  */
#line 230 "syntax_analyzer.y"
    {yyerrok; yyclearin; yyerror("Error at if statement.");}
    break;


/* Line 1792 of yacc.c  */
#line 1744 "syntax_analyzer.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
		      yytoken, &yylval);
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
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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


/* Line 2055 of yacc.c  */
#line 270 "syntax_analyzer.y"
 

extern int lines;

void yyerror(const char *reason) {
    printf("Error in line %d:\n", lines);
    printf("%s\n", reason);
    FILE *fp2 = fopen(filename, "r");
    int i;
    char line[1024];
    for (i=1; i<=lines; i++)
    {
        memset(line, 0, 1024);
        fgets(line, 1024, fp2);
    }
    printf("%s\n", line);
    syntax_errors++;
    fclose(fp2);
    
    // We can only give five chances
    if (syntax_errors == 5)
    {
        printf("Too many errors to handle.\n");
        printf("---- END ----\n");
        exit(1);
    }
    else 
    {
        printf("---- END ----\n");
    }
}

int main(int argc, char** argv)
{
        int out;
        if(argc<2)
        {
                printf("No input file!\n");
                exit(1);
        }
		
	yyin = fopen(argv[1],"r");
        strcpy(filename, argv[1]);

        if (yyin == NULL) 
        {
                printf("File not found!\n");
                exit(1);
        }
    
        if((symbol_table=hash_table_create(16, NULL)) == false) 
        {
                fprintf(stderr, "ERROR: hash_table_create() failed\n");
                exit(EXIT_FAILURE);
        }

        //yydebug = 1;
        out=yyparse();
        printf("Syntax analyzer started.\n");
    

        if (out == 0) 
        {
                printf("Syntax analyzer finished succesfully.\n");
                fclose(yyin);
                printf("File closed succesfully\n");
                return(0);
        }
        else 
        {
                printf("Syntax analyzer failed\n");
                hash_table_destroy(symbol_table);
                fclose(yyin);
                printf("File closed succesfully\n");
                return(1);
        }
}

