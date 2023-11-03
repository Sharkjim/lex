%{
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
%}

%union{
    unsigned int integer;
    double real;
    char str[1024];
    char character;
    int boolean;
}

// keywords
%token <str> T_id T_string T_program T_const T_type T_array T_set T_of T_record T_var T_forward T_function T_procedure T_integer T_real T_boolean T_char T_begin T_end T_if T_then T_else T_while T_do T_for T_downto T_to T_with T_read T_write

// Integer values
%token <integer> T_iconst
// Real values
%token <real> T_rconst
// Boolean values
%token <boolean> T_bconst
// Character values
%token <character> T_cconst

// operators 
%token <str> T_relop T_addop T_or T_muldivandop T_not T_in T_lparen T_rparen T_semi T_dot T_comma T_equ T_colon T_lbrack T_rbrack T_assign T_dotdot T_eof


// Priorities and associativity

%nonassoc SETEXPR
%nonassoc T_in T_relop T_equ
%left T_or T_addop
%left T_muldivandop
%nonassoc T_not
%left T_dot T_lparen T_rparen T_lbrack T_rbrack


// Dangling else
%nonassoc T_then
%nonassoc T_else

%start program

%%


program : header declarations subprograms comp_statement T_dot
        ;

header  : T_program T_id T_semi                { hash_table_insert(symbol_table, $2, NULL, scope);}                 
        ;

declarations: constdefs typedefs vardefs                       
        ;

constdefs: T_const constant_defs T_semi                         
        |                                                       
        ;

constant_defs: constant_defs T_semi T_id T_equ expression       { hash_table_insert(symbol_table, $3, NULL, scope);}
        | T_id T_equ expression                                 { hash_table_insert(symbol_table, $1, NULL, scope);}
        

expression: expression T_relop expression           
        | expression T_equ expression                           
        | expression T_in expression                            
        | expression T_or expression                            
        | expression T_addop expression                         
        | expression T_muldivandop expression                   
        | T_addop expression
        | T_not expression                                      
        | variable                                              
        | T_id T_lparen expressions T_rparen  
        | constant                                             
        | T_lparen expression T_rparen                         
        | setexpression
       

variable: T_id
        | variable T_dot T_id                                   
        | variable T_lbrack expressions T_rbrack                
        ;

expressions: expressions T_comma expression                 
        | expression                                         
        ;

constant: T_iconst                                              
        | T_rconst                                              
        | T_bconst                                              
        | T_cconst                                              
        ;

setexpression: T_lbrack elexpressions T_rbrack %prec SETEXPR
        | T_lbrack T_rbrack %prec SETEXPR
        ;

elexpressions: elexpressions T_comma elexpression
        | elexpression
        ;

elexpression: expression T_dotdot expression 
        | expression 
        ;

typedefs: T_type type_defs T_semi
        |
        ;

type_defs: type_defs T_semi T_id T_equ type_def         {hash_table_insert(symbol_table, $3, NULL, scope);}
        | T_id T_equ type_def                           {hash_table_insert(symbol_table, $1, NULL, scope);}
        ;

type_def: T_array T_lbrack dims T_rbrack T_of typename
        | T_set T_of typename
        | T_record fields T_end
        | T_lparen identifiers T_rparen
        | limit T_dotdot limit
        ;

dims    : dims T_comma limits
        | limits
        ;

limits  : limit T_dotdot limit
        | T_id                        
        ;

limit   : T_addop T_iconst
        | T_addop T_id            
        | T_iconst
        | T_cconst
        | T_bconst
        | T_id                          
        ;

typename: standard_type
        | T_id
        ;

standard_type: T_integer
        | T_real
        | T_boolean
        | T_char
        ;

fields : fields T_semi field
        | field
        ;

field   : identifiers T_colon typename
        ;

identifiers: identifiers T_comma T_id          {hash_table_insert(symbol_table, $3, NULL, scope);} 
        | T_id                                 {hash_table_insert(symbol_table, $1, NULL, scope);}
        ;

vardefs : T_var variable_defs T_semi
        | 
        ;

variable_defs: variable_defs T_semi identifiers T_colon typename
        | identifiers T_colon typename
        ;

subprograms: subprograms subprogram T_semi
        | 
        ;

subprogram: sub_header T_semi T_forward
        | sub_header T_semi {scope++;} declarations subprograms comp_statement {scope--;}
        ;

sub_header: T_function T_id {scope++;} formal_parameters T_colon standard_type           { scope--; hash_table_insert(symbol_table, $2, NULL, scope);}
        | T_procedure T_id {scope++;} formal_parameters                                  { scope--; hash_table_insert(symbol_table, $2, NULL, scope);}
        | T_function T_id  {scope++;}                                                    { scope--; hash_table_insert(symbol_table, $2, NULL, scope);}
        ;

formal_parameters: T_lparen parameter_list T_rparen
        | 
        ;

parameter_list: parameter_list T_semi pass identifiers T_colon typename
        | pass identifiers T_colon typename
        ;

pass    : T_var
        | 
        ;

comp_statement: T_begin statements T_end 
        ;

statements: statements T_semi statement
        | statement
        ;

statement:  assignment
        | if_statement
        | while_statement
        | for_statement
        | with_statement
        | subprogram_call
        | io_statement
        | comp_statement
        |
        ;

assignment: variable T_assign expression
        | variable T_assign T_string
        ;

if_statement: T_if expression T_then statement
        | T_if expression T_then statement T_else statement
        | error {yyerrok; yyclearin; yyerror("Error at if statement.");}
        ;

while_statement: T_while expression T_do statement
        ;

for_statement: T_for T_id T_assign iter_space T_do statement
        ; 

iter_space: expression T_to expression
        | expression T_downto expression
        ;

with_statement: T_with variable T_do statement
        ;

subprogram_call: T_id
        | T_id T_lparen write_list T_rparen
        ;

io_statement: T_read T_lparen read_list T_rparen
        | T_write T_lparen write_list T_rparen
        ;

read_list: read_list T_comma read_item
        | read_item
        ;

read_item: variable
        ;

write_list: write_list T_comma write_item
        | write_item
        ;

write_item: expression
        | T_string
        ;
        

%% 

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

