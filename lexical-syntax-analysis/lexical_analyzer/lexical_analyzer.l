%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    FILE *fp;

    // Part 1: Define the unique identifiers for each unit in the lexical analyzer

    #define T_eof 0
    #define T_id 1
    #define T_iconst 2
    #define T_rconst 3
    #define T_bconst 4
    #define T_cconst 5
    // Define the relational operators
    #define T_relop 6
    
    // Define the add operators
    
    #define T_addop 7
    
    // Define the logical OR operator
    #define T_or 13

    // Define the logical NOT operator
    #define T_not 15

    // Define the MULDIVAND operators
    #define T_muldivandop 16

    #define T_in 20     // IN

    // Define other lexical units
    #define T_lparen 21 // (
    #define T_rparen 22 // (
    #define T_semi 23   // ;
    #define T_dot 24    // .
    #define T_comma 25  // ,
    #define T_equ 26    // =
    #define T_colon 27  // :
    #define T_lbrack 28 // [
    #define T_rbrack 29 // ]
    #define T_assign 30 // :=
    #define T_dotdot 31 // ..

    // Define the keywords  // Keyword
    #define T_program 32    // PROGRAM
    #define T_const 33      // CONST
    #define T_type 34       // TYPE
    #define T_array 35      // ARRAY
    #define T_set 36        // SET
    #define T_of 37         // OF
    #define T_record 38     // RECORD
    #define T_var 39        // VAR
    #define T_forward 40    // FORWARD
    #define T_function 41   // FUNCTION
    #define T_procedure 42  // PROCEDURE
    #define T_integer 43    // INTEGER
    #define T_real 44       // REAL
    #define T_boolean 45    // BOOLEAN
    #define T_char 46       // CHAR
    #define T_begin 47      // BEGIN
    #define T_end 48        // END
    #define T_if 49         // IF
    #define T_then 50       // THEN
    #define T_else 51       // ELSE
    #define T_while 52      // WHILE
    #define T_do 53         // DO
    #define T_for 54        // FOR
    #define T_downto 55     // DOWNTO
    #define T_to 56         // TO
    #define T_with 57       // WITH
    #define T_read 58       // READ
    #define T_write 59      // WRITE

    // Define strings
    #define T_string 60
    // No need to define comments because they are ignored

    union  {
        unsigned int integer;
        double real;
        char str[1024];
        char character;
        int boolean;
    } yylval;
    char filename[256];
    int lines = 1;
    int errors = 0;
    double binary_to_decimal(const char* binary_string);
    double hex_to_decimal(const char* hex_string);
    void print_error(char *reason);
    
%}

%x STRING
%x COMMENT
%option noyywrap

%%

%{
// Part 2: Define the Regular Expressions for each of the identifiers and keywords
// Because PASC500 is case insensitive, we have to use '?i:' to denote it. 

// We start with the keywords because they can be perceived by the identifiers if we didn't
// search for them at first
%}

(?i:program)    {printf("Keyword: program\n");  return T_program;}
(?i:CONST)      {printf("Keyword: const\n");    return T_const;}
(?i:type)       {printf("Keyword: type\n");     return T_type;}
(?i:array)      {printf("Keyword: array\n");    return T_array;}
(?i:set)        {printf("Keyword: set\n");      return T_set;}
(?i:of)         {printf("Keyword: of\n");       return T_of;}
(?i:record)     {printf("Keyword: record\n");   return T_record;}
(?i:var)        {printf("Keyword: var\n");      return T_var;}
(?i:forward)    {printf("Keyword: forward\n");  return T_forward;}
(?i:function)   {printf("Keyword: function\n"); return T_function;}
(?i:procedure)  {printf("Keyword: procedure\n");return T_procedure;}
(?i:integer)    {printf("Keyword: integer\n");  return T_integer;}
(?i:real)       {printf("Keyword: real\n");     return T_real;}
(?i:boolean)    {printf("Keyword: boolean\n");  return T_boolean;}
(?i:CHAR)       {printf("Keyword: char\n");     return T_char;}
(?i:begin)      {printf("Keyword: begin\n");    return T_begin;}
(?i:end)        {printf("Keyword: end\n");      return T_end;}
(?i:IF)         {printf("Keyword: if\n");       return T_if;}
(?i:then)       {printf("Keyword: then\n");     return T_then;}
(?i:ELSE)       {printf("Keyword: else\n");     return T_else;}
(?i:WHILE)      {printf("Keyword: while\n");    return T_while;}
(?i:DO)         {printf("Keyword: do\n");       return T_do;}
(?i:FOR)        {printf("Keyword: for\n");      return T_for;}
(?i:downto)     {printf("Keyword: downto\n");   return T_downto;}
(?i:to)         {printf("Keyword: to\n");       return T_to;}
(?i:with)       {printf("Keyword: with\n");     return T_with;}
(?i:read)       {printf("Keyword: read\n");     return T_read;}
(?i:write)      {printf("Keyword: write\n");    return T_write;}


%{
    // RCONST
%}

"0b"([1][0-1]*)*"."([0]*[1][0-1]*)   {yylval.real = binary_to_decimal(yytext); printf("Real binary: %lf\n", yylval.real); return T_rconst;}
"0b"([1][0-1]*)*"."([0])   {yylval.real = binary_to_decimal(yytext); printf("Real binary: %lf\n", yylval.real); return T_rconst;}
"0B"([1][0-1]*)*"."([0]*[1][0-1]*)   {yylval.real = binary_to_decimal(yytext); printf("Real binary: %lf\n", yylval.real); return T_rconst;}
"0B"([1][0-1]*)*"."([0])   {yylval.real = binary_to_decimal(yytext); printf("Real binary: %lf\n", yylval.real); return T_rconst;}
"0h"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0]*[A-Fa-f1-9][A-Fa-f0-9]*)   {yylval.real = hex_to_decimal(yytext); printf("Real hex: %lf\n", yylval.real); return T_rconst;}
"0h"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0])   {yylval.real = hex_to_decimal(yytext); printf("Real hex: %lf\n", yylval.real); return T_rconst;}
"0H"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0]*[A-Fa-f1-9][A-Fa-f0-9]*)   {yylval.real = hex_to_decimal(yytext); printf("Real hex: %lf\n", yylval.real); return T_rconst;}
"0H"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0])   {yylval.real = hex_to_decimal(yytext); printf("Real hex: %lf\n", yylval.real); return T_rconst;}
([0]|[1-9][0-9]*)?"."(0|[1-9]+[0-9]*)("E"|"e")[-+]?([0]|[1-9][0-9]*)  {yylval.real = strtod(yytext, NULL); printf("Real: %lf\n", yylval.real); return T_rconst;}
([0]|[1-9][0-9]*)?"."(0|[1-9]+[0-9]*)           {yylval.real = strtod(yytext, NULL); printf("Real: %lf\n", yylval.real); return T_rconst;}
([0]|[1-9][0-9]*)("E"|"e")[-+]?([0]|[[1-9][0-9]*])  {yylval.real = strtod(yytext, NULL); printf("Real: %lf\n", yylval.real); return T_rconst;}
[1-9][0-9]*("E"|"e")[-+]?([0]|[1-9][0-9]*)     {yylval.real = strtod(yytext, NULL); printf("Real: %lf\n", yylval.real); return T_rconst;}

%{
    // Define rel, add, muldivand and or/not/in operators before the identifiers
%}

"<>"            {printf("Not equal\n");                 return T_relop;}
">="            {printf("Greater than or equal to\n");  return T_relop;}
"<="            {printf("Less than or equal to\n");     return T_relop;}
">"             {printf("Greater than\n");              return T_relop;}
"<"             {printf("Less than\n");                 return T_relop;}
"+"             {printf("Plus\n");                      return T_addop;}
"-"             {printf("Minus\n");                     return T_addop;}
"*"             {printf("Times\n");                     return T_muldivandop;}
"/"             {printf("Divided\n");                   return T_muldivandop;}
(?i:mod)        {printf("Modulo\n");                    return T_muldivandop;}
(?i:div)        {printf("Dividor\n");                   return T_muldivandop;}
(?i:and)        {printf("AND\n");                       return T_muldivandop;}
(?i:or)         {printf("OR\n");                        return T_or;}
(?i:not)        {printf("NOT\n");                       return T_not;}
(?i:in)         {printf("IN\n");                        return T_in;}

%{
    // Define constants before the identifiers
    // BCONST
%}

(?i:TRUE)       {printf("Boolean constant: True\n");  return T_bconst;}
(?i:FALSE)      {printf("Boolean constant: False\n"); return T_bconst;}

%{
    // Identifiers

    // [_?]:                optional _ in the beginning
    // [a-zA-z]:            single letter character
    // [_a-zA-Z0-9]*        more
    // ([_]*[a-zA-Z0-9]+)*  underscore(s) with more digits following

%}

[_]?[a-zA-Z][a-zA-Z0-9]*([_]*[a-zA-Z0-9]+)*   {printf("Identifier: %s\n", yytext); return T_id;}


%{
    // ICONST
%}

[0]("H"|"h")[A-Fa-f1-9][A-Fa-f0-9]*     {yylval.integer = strtol(yytext + 2, NULL, 16); printf("Integer constant: %d\n", yylval.integer); return T_iconst;}
[0]("B"|"b")[1][01]*                    {yylval.integer = strtol(yytext + 2, NULL, 2); printf("Integer constant: %d\n", yylval.integer); return T_iconst;}
[1-9][0-9]*                         {yylval.integer = atoi(yytext); printf("Integer constant: %d\n", yylval.integer); return T_iconst;}

%{
    // We continue with the other lexical units
%}
"("             {printf("Left parenthesis\n");  return T_lparen;}
")"             {printf("Right parenthesis\n"); return T_rparen;}
";"             {printf("Semicolon\n");         return T_semi;}
"."             {printf("Dot\n");               return T_dot;}
","             {printf("Comma\n");             return T_comma;}
"="             {printf("Equal sign\n");        return T_equ;}
":"             {printf("Colon\n");             return T_colon;}
"["             {printf("Left bracket\n");      return T_lbrack;}
"]"             {printf("Right bracket\n");     return T_rbrack;}
":="            {printf("Assign\n");            return T_assign;}
".."            {printf("Dot dot\n");           return T_dotdot;}
"<<EOF>>"       {printf("End-of-file\n");       return T_eof;}

%{
    // We will define the rules for the string above the whitespace, because
    // whitespace can be part of a string as well.
%}

"\""                    { /* String started */ memset(yylval.str , 0, 1024); BEGIN(STRING); }
<STRING>"\\""\n"        { /* Changing line */ strcat(yylval.str, " "); lines++;}
<STRING>[^"\\"^"\n"]    { /* Reading normal characters */ strcat(yylval.str, yytext); }
<STRING>"\n"            { /* Can't expect a newline on it's own */ print_error("Strings must change line with \\ !"); lines++;}
<STRING><<EOF>>         { /* Can't expect end of file right now */ print_error("String did not close!");}
<STRING>"\""            { /* String ended */ printf("\nString: %s\n", yylval.str); BEGIN(INITIAL); return T_string;}


%{
    // CCONST
%}

"'"[ -~]"'"                     {printf("Character constant: %s\n", yytext);    return T_cconst;}
"'""\\"[NnFfTtRrBbVv]"'"        {printf("Special character constant\n");        return T_cconst;}




[{]                     { /* Comment started */ memset(yylval.str , 0, 1024); BEGIN(COMMENT); }
<COMMENT>"\n"           { /* Changing line */   strcat(yylval.str, " "); lines++;}
<COMMENT>[^"}"^"\n"]    { /* Adding the character to the string */strcat(yylval.str, yytext); }
<COMMENT><<EOF>>        { /* Can't expect end of file right now */ print_error("Comment did not close!"); }
<COMMENT>[}]            { /* Comment ended. Only print it. */ printf("Comment: %s\n", yylval.str); BEGIN(INITIAL);}

" "|"\t"           {/* Ignore whitespace */}
"\n"               {/* Ignore whitespace but increment lines*/ lines++;}

[0]                     {yylval.integer = 0;            return T_iconst;}


.                       {print_error("Unrecognized character!");}

%% 


double binary_to_decimal(const char* binary_string) {
    // Skip the "0b" prefix
    const char* binary_digits = binary_string + 2;

    // Find the position of the decimal point, if present
    const char* decimal_point = strchr(binary_digits, '.');

    // Calculate the length of the integer part
    int integer_length = decimal_point ? decimal_point - binary_digits : strlen(binary_digits);

    // Convert the integer part to decimal
    double decimal = 0;
    for (int i = 0; i < integer_length; i++) {
        if (binary_digits[i] == '1') {
            decimal += pow(2, integer_length - i - 1);
        }
    }

    // If decimal point exists, calculate the fractional part
    if (decimal_point) {
        int fractional_length = strlen(decimal_point + 1);

        for (int i = 0; i < fractional_length; i++) {
            if (binary_digits[integer_length + 1 + i] == '1') {
                decimal += pow(2, -i - 1);
            }
        }
    }

    return decimal;
}

double hex_to_decimal(const char* hex_string) {
    // Skip the "0h" prefix
    const char* hex_digits = hex_string + 2;

    // Find the position of the decimal point, if present
    const char* decimal_point = strchr(hex_digits, '.');

    // Calculate the length of the integer part
    int integer_length = decimal_point ? decimal_point - hex_digits : strlen(hex_digits);

    // Convert the integer part to decimal
    double decimal = 0;
    for (int i = 0; i < integer_length; i++) {
        char hex_digit = hex_digits[i];

        // Convert hexadecimal digit to decimal
        int decimal_digit;
        if (hex_digit >= '0' && hex_digit <= '9') {
            decimal_digit = hex_digit - '0';
        } else if (hex_digit >= 'A' && hex_digit <= 'F') {
            decimal_digit = hex_digit - 'A' + 10;
        } else if (hex_digit >= 'a' && hex_digit <= 'f') {
            decimal_digit = hex_digit - 'a' + 10;
        } else {
            // Invalid hexadecimal digit
            return 0;
        }

        decimal += decimal_digit * pow(16, integer_length - i - 1);
    }

    // If decimal point exists, calculate the fractional part
    if (decimal_point) {
        int fractional_length = strlen(decimal_point + 1);

        for (int i = 0; i < fractional_length; i++) {
            char hex_digit = hex_digits[integer_length + 1 + i];

            // Convert hexadecimal digit to decimal
            int decimal_digit;
            if (hex_digit >= '0' && hex_digit <= '9') {
                decimal_digit = hex_digit - '0';
            } else if (hex_digit >= 'A' && hex_digit <= 'F') {
                decimal_digit = hex_digit - 'A' + 10;
            } else if (hex_digit >= 'a' && hex_digit <= 'f') {
                decimal_digit = hex_digit - 'a' + 10;
            } else {
                // Invalid hexadecimal digit
                return 0;
            }

            decimal += decimal_digit * pow(16, -i - 1);
        }
    }

    return decimal;
}

void print_error(char *reason)
{
    printf("----ERROR----\n");
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
    errors++;
    fclose(fp2);
    // We can only give one chance
    if (errors == 2)
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


int main(int argc, char *argv[])
{
    int token;

    if (argc < 2)
    {
        do {
            token = yylex();
            printf("token value: %d\n", token);
        } while (token!=T_eof);
    }
    else 
    {
        memcpy(filename, argv[1], strlen(argv[1]));
        fp = fopen(argv[1], "r");
        yyin = fopen(argv[1], "r");
        do {
            token = yylex();
            printf("Token value: %d\n", token);
        }   while (token != T_eof);
        fclose(yyin);
    }
    return 0;
}

