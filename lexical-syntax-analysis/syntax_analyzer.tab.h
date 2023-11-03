/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison interface for Yacc-like parsers in C
   
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

#ifndef YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
# define YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED
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
/* Line 2058 of yacc.c  */
#line 19 "syntax_analyzer.y"

    unsigned int integer;
    double real;
    char str[1024];
    char character;
    int boolean;


/* Line 2058 of yacc.c  */
#line 121 "syntax_analyzer.tab.h"
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

#endif /* !YY_YY_SYNTAX_ANALYZER_TAB_H_INCLUDED  */
