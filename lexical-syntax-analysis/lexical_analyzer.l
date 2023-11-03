%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #include "syntax_analyzer.tab.h"
    FILE *fp;

    char filename[256];
    int lines = 1;
    int errors = 0;
    int comment_nesting = 0;
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

(?i:program)    {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_program;}
(?i:CONST)      {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_const;}
(?i:type)       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_type;}
(?i:array)      {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_array;}
(?i:set)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_set;}
(?i:of)         {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_of;}
(?i:record)     {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_record;}
(?i:var)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_var;}
(?i:forward)    {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_forward;}
(?i:function)   {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_function;}
(?i:procedure)  {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_procedure;}
(?i:integer)    {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_integer;}
(?i:real)       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_real;}
(?i:boolean)    {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_boolean;}
(?i:CHAR)       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_char;}
(?i:begin)      {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_begin;}
(?i:end)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_end;}
(?i:IF)         {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_if;}
(?i:then)       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_then;}
(?i:ELSE)       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_else;}
(?i:WHILE)      {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_while;}
(?i:DO)         {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_do;}
(?i:FOR)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_for;}
(?i:downto)     {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_downto;}
(?i:to)         {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_to;}
(?i:with)       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_with;}
(?i:read)       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_read;}
(?i:write)      {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_write;}


%{
    // RCONST
%}

"0b"([1][0-1]*)*"."([0]*[1][0-1]*)                                      {yylval.real = binary_to_decimal(yytext);   return T_rconst;}
"0B"([1][0-1]*)*"."([0]*[1][0-1]*)                                      {yylval.real = binary_to_decimal(yytext);   return T_rconst;}
"0b"([1][0-1]*)*"."([0])                                                {yylval.real = binary_to_decimal(yytext);   return T_rconst;}
"0B"([1][0-1]*)*"."([0])                                                {yylval.real = binary_to_decimal(yytext);   return T_rconst;}

"0h"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0]*[A-Fa-f1-9][A-Fa-f0-9]*)          {yylval.real = hex_to_decimal(yytext);      return T_rconst;}
"0h"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0])                                  {yylval.real = hex_to_decimal(yytext);      return T_rconst;}
"0H"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0]*[A-Fa-f1-9][A-Fa-f0-9]*)          {yylval.real = hex_to_decimal(yytext);      return T_rconst;}
"0H"([A-Fa-f1-9][A-Fa-f0-9]*)*"."([0])                                  {yylval.real = hex_to_decimal(yytext);      return T_rconst;}

([0]|[1-9][0-9]*)?"."(0|[1-9]+[0-9]*)("E"|"e")[-+]?([0]|[1-9][0-9]*)    {yylval.real = strtod(yytext, NULL);        return T_rconst;}
([0]|[1-9][0-9]*)?"."(0|[1-9]+[0-9]*)                                   {yylval.real = strtod(yytext, NULL);        return T_rconst;}
([0]|[1-9][0-9]*)("E"|"e")[-+]?([0]|[[1-9][0-9]*])                      {yylval.real = strtod(yytext, NULL);        return T_rconst;}
[1-9][0-9]*("E"|"e")[-+]?([0]|[1-9][0-9]*)                              {yylval.real = strtod(yytext, NULL);        return T_rconst;}

%{
    // Define rel, add, muldivand and or/not/in operators before the identifiers
%}

"<>"            {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_relop;}
">="            {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_relop;}
"<="            {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_relop;}
">"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_relop;}
"<"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_relop;}

"+"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_addop;}
"-"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_addop;}

"*"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_muldivandop;}
"/"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_muldivandop;}
(?i:mod)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_muldivandop;}
(?i:div)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_muldivandop;}
(?i:and)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_muldivandop;}
(?i:or)         {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_or;}
(?i:not)        {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_not;}
(?i:in)         {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_in;}

%{
    // Define constants before the identifiers
    // BCONST
%}

(?i:TRUE)       {yylval.boolean = 1;    return T_bconst;}
(?i:FALSE)      {yylval.boolean = 0;    return T_bconst;}



[_]?[a-zA-Z][a-zA-Z0-9]*([_]*[a-zA-Z0-9]+)*   {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext)); return T_id;}


%{
    // ICONST
%}

[0]("H"|"h")[A-Fa-f1-9][A-Fa-f0-9]*     {yylval.integer = strtol(yytext + 2, NULL, 16); return T_iconst;}
[0]("B"|"b")[1][01]*                    {yylval.integer = strtol(yytext + 2, NULL, 2);  return T_iconst;}
[1-9][0-9]*                             {yylval.integer = atoi(yytext);                 return T_iconst;}

%{
    // We continue with the other lexical units
%}
"("             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_lparen;}
")"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_rparen;}
";"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_semi;}
"."             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_dot;}
","             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_comma;}
"="             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_equ;}
":"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_colon;}
"["             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_lbrack;}
"]"             {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_rbrack;}
":="            {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_assign;}
".."            {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_dotdot;}
"<<EOF>>"       {memset(yylval.str, 0, 1024); memcpy(yylval.str, yytext, strlen(yytext));   return T_eof;}

%{
/*
We will define the rules for the string above the whitespace, because 
whitespace can be part of a string as well.
*/
%}

"\""                    { /* String started */              memset(yylval.str , 0, 1024); BEGIN(STRING); }
<STRING>"\\""\n"        { /* Changing line */               strcat(yylval.str, " "); lines++;}
<STRING>[^"\\"^"\n"]    { /* Reading normal characters */   strcat(yylval.str, yytext); }
<STRING>"\n"            { /* Can't expect a newline on it's own */ print_error("Strings must change line with \\ !"); lines++;}
<STRING><<EOF>>         { /* Can't expect end of file right now */ print_error("String did not close!");}
<STRING>"\""            { /* String ended */                BEGIN(INITIAL); return T_string;}


%{
    // CCONST
%}

"'"[ -~]"'"                     {yylval.character = yytext[1];  return T_cconst;}
"'""\\"[NnFfTtRrBbVv]"'"        {yylval.character = yytext[1];  return T_cconst;}


[{]                     { /* Comment started */ memset(yylval.str , 0, 1024); BEGIN(COMMENT); }
<COMMENT>[{]            { /* Nested comment start */ ++comment_nesting; strcat(yylval.str, "{"); }
<COMMENT>"\n"           { /* Changing line */   strcat(yylval.str, " "); lines++;}
<COMMENT>[^"}"^"\n"]    { /* Adding the character to the string */ strcat(yylval.str, yytext); }
<COMMENT><<EOF>>        { /* Can't expect end of file right now */ print_error("Comment did not close!"); }
<COMMENT>[}]            { /* Comment ended. Only print it. */ 
                                if (comment_nesting) { --comment_nesting; strcat(yylval.str, "}"); }
                                else { printf("Comment: %s\n", yylval.str); BEGIN(INITIAL); } }

" "|"\t"                {/* Ignore whitespace */}
"\n"                    {/* Ignore whitespace but increment lines*/ lines++;}

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
        printf("We will remove the character and try again.\n");
        yyless(1);
        printf("---- END ----\n");
    }
}