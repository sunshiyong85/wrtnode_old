/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#line 26 "parser.y"

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "ast.h"
#include "lexer.h"
#include "parser.h"

#define alloc_op(type, num, str, ...) \
	jp_alloc_op(s, type, num, str, ##__VA_ARGS__, NULL)

#line 22 "parser.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    ParseTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is ParseTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    ParseARG_SDECL     A static variable declaration for the %extra_argument
**    ParseARG_PDECL     A parameter declaration for the %extra_argument
**    ParseARG_STORE     Code to store %extra_argument into yypParser
**    ParseARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 38
#define YYACTIONTYPE unsigned char
#define ParseTOKENTYPE struct jp_opcode *
typedef union {
  int yyinit;
  ParseTOKENTYPE yy0;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 100
#endif
#define ParseARG_SDECL struct jp_state *s;
#define ParseARG_PDECL ,struct jp_state *s
#define ParseARG_FETCH struct jp_state *s = yypParser->s
#define ParseARG_STORE yypParser->s = s
#define YYNSTATE 53
#define YYNRULE 33
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (89)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    34,   14,   13,   24,   23,   28,   22,   38,   21,   37,
 /*    10 */    18,   11,   53,   14,   13,   17,   39,   47,   34,   42,
 /*    20 */    41,   40,    2,   46,   22,   38,   21,   37,   18,    3,
 /*    30 */    34,   87,   26,   27,    4,   20,   22,   38,   21,   37,
 /*    40 */    18,    7,    6,    9,    8,   12,   10,   34,   52,   34,
 /*    50 */    25,   14,   13,   36,   45,   21,   37,   18,   44,   18,
 /*    60 */    19,   50,    1,   16,   48,   49,    5,   15,   48,   34,
 /*    70 */    34,   34,   88,   34,   34,   88,   88,   34,   34,   43,
 /*    80 */    35,   33,   51,   32,   31,   88,   88,   30,   29,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */    26,   12,   13,   29,   30,   31,   32,   33,   34,   35,
 /*    10 */    36,   10,    0,   12,   13,    4,   15,   17,   26,   18,
 /*    20 */    19,   20,   21,   31,   32,   33,   34,   35,   36,    3,
 /*    30 */    26,   24,   25,   26,    2,   31,   32,   33,   34,   35,
 /*    40 */    36,    4,    5,    6,    7,    8,    9,   26,   26,   26,
 /*    50 */    11,   12,   13,   22,   33,   34,   35,   36,   35,   36,
 /*    60 */    14,   11,   16,   27,   28,   15,    1,   27,   28,   26,
 /*    70 */    26,   26,   37,   26,   26,   37,   37,   26,   26,   36,
 /*    80 */    36,   36,   28,   36,   36,   37,   37,   36,   36,
};
#define YY_SHIFT_USE_DFLT (-12)
#define YY_SHIFT_COUNT (26)
#define YY_SHIFT_MIN   (-11)
#define YY_SHIFT_MAX   (65)
static const signed char yy_shift_ofst[] = {
 /*     0 */    39,    1,    1,    1,    1,    1,    1,    1,    1,    1,
 /*    10 */     1,    1,    1,   46,   46,   46,   46,  -11,   37,   50,
 /*    20 */    31,   65,   32,   26,    0,   11,   12,
};
#define YY_REDUCE_USE_DFLT (-27)
#define YY_REDUCE_COUNT (17)
#define YY_REDUCE_MIN   (-26)
#define YY_REDUCE_MAX   (54)
static const signed char yy_reduce_ofst[] = {
 /*     0 */     7,  -26,    4,   -8,   21,   23,   52,   51,   48,   47,
 /*    10 */    45,   44,   43,   40,   36,   54,   54,   22,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */    86,   86,   86,   86,   86,   86,   86,   86,   86,   86,
 /*    10 */    86,   86,   86,   86,   86,   57,   56,   86,   78,   86,
 /*    20 */    86,   69,   66,   63,   86,   86,   86,   55,   65,   77,
 /*    30 */    76,   75,   74,   73,   85,   84,   83,   71,   68,   82,
 /*    40 */    81,   80,   79,   72,   70,   67,   64,   62,   59,   61,
 /*    50 */    60,   58,   54,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  ParseARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void ParseTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "T_AND",         "T_OR",          "T_UNION",     
  "T_EQ",          "T_NE",          "T_GT",          "T_GE",        
  "T_LT",          "T_LE",          "T_NOT",         "T_LABEL",     
  "T_ROOT",        "T_THIS",        "T_DOT",         "T_WILDCARD",  
  "T_BROPEN",      "T_BRCLOSE",     "T_BOOL",        "T_NUMBER",    
  "T_STRING",      "T_POPEN",       "T_PCLOSE",      "error",       
  "input",         "expr",          "path",          "segments",    
  "segment",       "union_exps",    "union_exp",     "or_exps",     
  "or_exp",        "and_exps",      "and_exp",       "cmp_exp",     
  "unary_exp",   
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "input ::= expr",
 /*   1 */ "expr ::= T_LABEL T_EQ path",
 /*   2 */ "expr ::= path",
 /*   3 */ "path ::= T_ROOT segments",
 /*   4 */ "path ::= T_THIS segments",
 /*   5 */ "segments ::= segments segment",
 /*   6 */ "segments ::= segment",
 /*   7 */ "segment ::= T_DOT T_LABEL",
 /*   8 */ "segment ::= T_DOT T_WILDCARD",
 /*   9 */ "segment ::= T_BROPEN union_exps T_BRCLOSE",
 /*  10 */ "union_exps ::= union_exp",
 /*  11 */ "union_exp ::= union_exp T_UNION or_exps",
 /*  12 */ "union_exp ::= or_exps",
 /*  13 */ "or_exps ::= or_exp",
 /*  14 */ "or_exp ::= or_exp T_OR and_exps",
 /*  15 */ "or_exp ::= and_exps",
 /*  16 */ "and_exps ::= and_exp",
 /*  17 */ "and_exp ::= and_exp T_AND cmp_exp",
 /*  18 */ "and_exp ::= cmp_exp",
 /*  19 */ "cmp_exp ::= unary_exp T_LT unary_exp",
 /*  20 */ "cmp_exp ::= unary_exp T_LE unary_exp",
 /*  21 */ "cmp_exp ::= unary_exp T_GT unary_exp",
 /*  22 */ "cmp_exp ::= unary_exp T_GE unary_exp",
 /*  23 */ "cmp_exp ::= unary_exp T_EQ unary_exp",
 /*  24 */ "cmp_exp ::= unary_exp T_NE unary_exp",
 /*  25 */ "cmp_exp ::= unary_exp",
 /*  26 */ "unary_exp ::= T_BOOL",
 /*  27 */ "unary_exp ::= T_NUMBER",
 /*  28 */ "unary_exp ::= T_STRING",
 /*  29 */ "unary_exp ::= T_WILDCARD",
 /*  30 */ "unary_exp ::= T_POPEN or_exps T_PCLOSE",
 /*  31 */ "unary_exp ::= T_NOT unary_exp",
 /*  32 */ "unary_exp ::= path",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  pNew = realloc(p->yystack, newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to Parse and ParseFree.
*/
void *ParseAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  ParseARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from ParseAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void ParseFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int ParseStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   ParseARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   ParseARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 24, 1 },
  { 25, 3 },
  { 25, 1 },
  { 26, 2 },
  { 26, 2 },
  { 27, 2 },
  { 27, 1 },
  { 28, 2 },
  { 28, 2 },
  { 28, 3 },
  { 29, 1 },
  { 30, 3 },
  { 30, 1 },
  { 31, 1 },
  { 32, 3 },
  { 32, 1 },
  { 33, 1 },
  { 34, 3 },
  { 34, 1 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 3 },
  { 35, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 1 },
  { 36, 3 },
  { 36, 2 },
  { 36, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  ParseARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* input ::= expr */
#line 52 "parser.y"
{ s->path = yymsp[0].minor.yy0; }
#line 749 "parser.c"
        break;
      case 1: /* expr ::= T_LABEL T_EQ path */
#line 54 "parser.y"
{ yygotominor.yy0 = yymsp[-2].minor.yy0; yymsp[-2].minor.yy0->down = yymsp[0].minor.yy0; }
#line 754 "parser.c"
        break;
      case 2: /* expr ::= path */
      case 6: /* segments ::= segment */ yytestcase(yyruleno==6);
      case 7: /* segment ::= T_DOT T_LABEL */ yytestcase(yyruleno==7);
      case 8: /* segment ::= T_DOT T_WILDCARD */ yytestcase(yyruleno==8);
      case 12: /* union_exp ::= or_exps */ yytestcase(yyruleno==12);
      case 15: /* or_exp ::= and_exps */ yytestcase(yyruleno==15);
      case 18: /* and_exp ::= cmp_exp */ yytestcase(yyruleno==18);
      case 25: /* cmp_exp ::= unary_exp */ yytestcase(yyruleno==25);
      case 26: /* unary_exp ::= T_BOOL */ yytestcase(yyruleno==26);
      case 27: /* unary_exp ::= T_NUMBER */ yytestcase(yyruleno==27);
      case 28: /* unary_exp ::= T_STRING */ yytestcase(yyruleno==28);
      case 29: /* unary_exp ::= T_WILDCARD */ yytestcase(yyruleno==29);
      case 32: /* unary_exp ::= path */ yytestcase(yyruleno==32);
#line 55 "parser.y"
{ yygotominor.yy0 = yymsp[0].minor.yy0; }
#line 771 "parser.c"
        break;
      case 3: /* path ::= T_ROOT segments */
#line 57 "parser.y"
{ yygotominor.yy0 = alloc_op(T_ROOT, 0, NULL, yymsp[0].minor.yy0); }
#line 776 "parser.c"
        break;
      case 4: /* path ::= T_THIS segments */
#line 58 "parser.y"
{ yygotominor.yy0 = alloc_op(T_THIS, 0, NULL, yymsp[0].minor.yy0); }
#line 781 "parser.c"
        break;
      case 5: /* segments ::= segments segment */
#line 60 "parser.y"
{ yygotominor.yy0 = append_op(yymsp[-1].minor.yy0, yymsp[0].minor.yy0); }
#line 786 "parser.c"
        break;
      case 9: /* segment ::= T_BROPEN union_exps T_BRCLOSE */
      case 30: /* unary_exp ::= T_POPEN or_exps T_PCLOSE */ yytestcase(yyruleno==30);
#line 65 "parser.y"
{ yygotominor.yy0 = yymsp[-1].minor.yy0; }
#line 792 "parser.c"
        break;
      case 10: /* union_exps ::= union_exp */
#line 67 "parser.y"
{ yygotominor.yy0 = yymsp[0].minor.yy0->sibling ? alloc_op(T_UNION, 0, NULL, yymsp[0].minor.yy0) : yymsp[0].minor.yy0; }
#line 797 "parser.c"
        break;
      case 11: /* union_exp ::= union_exp T_UNION or_exps */
      case 14: /* or_exp ::= or_exp T_OR and_exps */ yytestcase(yyruleno==14);
      case 17: /* and_exp ::= and_exp T_AND cmp_exp */ yytestcase(yyruleno==17);
#line 69 "parser.y"
{ yygotominor.yy0 = append_op(yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 804 "parser.c"
        break;
      case 13: /* or_exps ::= or_exp */
#line 72 "parser.y"
{ yygotominor.yy0 = yymsp[0].minor.yy0->sibling ? alloc_op(T_OR, 0, NULL, yymsp[0].minor.yy0) : yymsp[0].minor.yy0; }
#line 809 "parser.c"
        break;
      case 16: /* and_exps ::= and_exp */
#line 77 "parser.y"
{ yygotominor.yy0 = yymsp[0].minor.yy0->sibling ? alloc_op(T_AND, 0, NULL, yymsp[0].minor.yy0) : yymsp[0].minor.yy0; }
#line 814 "parser.c"
        break;
      case 19: /* cmp_exp ::= unary_exp T_LT unary_exp */
#line 82 "parser.y"
{ yygotominor.yy0 = alloc_op(T_LT, 0, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 819 "parser.c"
        break;
      case 20: /* cmp_exp ::= unary_exp T_LE unary_exp */
#line 83 "parser.y"
{ yygotominor.yy0 = alloc_op(T_LE, 0, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 824 "parser.c"
        break;
      case 21: /* cmp_exp ::= unary_exp T_GT unary_exp */
#line 84 "parser.y"
{ yygotominor.yy0 = alloc_op(T_GT, 0, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 829 "parser.c"
        break;
      case 22: /* cmp_exp ::= unary_exp T_GE unary_exp */
#line 85 "parser.y"
{ yygotominor.yy0 = alloc_op(T_GE, 0, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 834 "parser.c"
        break;
      case 23: /* cmp_exp ::= unary_exp T_EQ unary_exp */
#line 86 "parser.y"
{ yygotominor.yy0 = alloc_op(T_EQ, 0, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 839 "parser.c"
        break;
      case 24: /* cmp_exp ::= unary_exp T_NE unary_exp */
#line 87 "parser.y"
{ yygotominor.yy0 = alloc_op(T_NE, 0, NULL, yymsp[-2].minor.yy0, yymsp[0].minor.yy0); }
#line 844 "parser.c"
        break;
      case 31: /* unary_exp ::= T_NOT unary_exp */
#line 95 "parser.y"
{ yygotominor.yy0 = alloc_op(T_NOT, 0, NULL, yymsp[0].minor.yy0); }
#line 849 "parser.c"
        break;
      default:
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  ParseARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 41 "parser.y"

	int i;

	for (i = 0; i < sizeof(tokennames) / sizeof(tokennames[0]); i++)
		if (yy_find_shift_action(yypParser, (YYCODETYPE)i) < YYNSTATE + YYNRULE)
			s->error_code |= (1 << i);

	s->error_pos = s->off;
#line 920 "parser.c"
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  ParseARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  ParseARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "ParseAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void Parse(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  ParseTOKENTYPE yyminor       /* The value for the token */
  ParseARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  ParseARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
      assert( yyact == YY_ERROR_ACTION );
#ifdef YYERRORSYMBOL
      int yymx;
#endif
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
