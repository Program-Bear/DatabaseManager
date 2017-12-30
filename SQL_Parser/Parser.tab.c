/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Parser.y" /* yacc.c:339  */

    #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <unistd.h>
    #include "SemValue.h"
    #include "SystemManagerInterface.cpp"
    #define YYSTYPE SemValue
    using namespace std;

    extern "C"
    {
        void yyerror(const char*);
        
        int yylex(void);
        
        int yywrap();

        int yyparse(void);
    }

    SystemManagerInterface manager;

#line 90 "Parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "Parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DATABASE = 258,
    DATABASES = 259,
    TABLE = 260,
    TABLES = 261,
    SHOW = 262,
    CREATE = 263,
    DROP = 264,
    USE = 265,
    PRIMARY = 266,
    KEY = 267,
    NOT = 268,
    NULLL = 269,
    INSERT = 270,
    INTO = 271,
    VALUES = 272,
    DELETE = 273,
    FROM = 274,
    WHERE = 275,
    UPDATE = 276,
    SET = 277,
    SELECT = 278,
    IS = 279,
    INT = 280,
    VARCHAR = 281,
    DESC = 282,
    INDEX = 283,
    AND = 284,
    DATE = 285,
    FLOAT = 286,
    FOREIGN = 287,
    REFERENCES = 288,
    NEQ = 289,
    LTE = 290,
    GTE = 291,
    IDENTIFIER = 292,
    VALUE_INT = 293,
    VALUE_STRING = 294,
    LITERAL = 295
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 182 "Parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   149

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  50
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   295

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      42,    43,    49,     2,    44,     2,    45,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      47,    46,    48,     2,     2,     2,     2,     2,     2,     2,
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    53,    60,    64,    68,    72,    78,    87,
      94,   101,   108,   117,   146,   153,   160,   178,   217,   265,
     328,   335,   344,   352,   361,   367,   373,   379,   388,   394,
     400,   405,   412,   418,   425,   431,   438,   443,   448,   455,
     461,   470,   478,   484,   492,   497,   504,   509,   514,   519,
     524,   529,   536,   543,   552,   558,   565,   571,   576,   584,
     590,   597,   603,   610,   617,   624
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DATABASE", "DATABASES", "TABLE",
  "TABLES", "SHOW", "CREATE", "DROP", "USE", "PRIMARY", "KEY", "NOT",
  "NULLL", "INSERT", "INTO", "VALUES", "DELETE", "FROM", "WHERE", "UPDATE",
  "SET", "SELECT", "IS", "INT", "VARCHAR", "DESC", "INDEX", "AND", "DATE",
  "FLOAT", "FOREIGN", "REFERENCES", "NEQ", "LTE", "GTE", "IDENTIFIER",
  "VALUE_INT", "VALUE_STRING", "LITERAL", "';'", "'('", "')'", "','",
  "'.'", "'='", "'<'", "'>'", "'*'", "$accept", "Program", "Stmt",
  "SysStmt", "DbStmt", "TbStmt", "IdxStmt", "FieldList", "Field", "Type",
  "ValueLists", "ValueList", "Value", "WhereClauseList", "WhereClause",
  "Col", "Op", "Expr", "SetClause", "Selector", "TableList", "ColumnList",
  "DbName", "TbName", "ColName", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,    59,    40,    41,    44,    46,    61,    60,    62,    42
};
# endif

#define YYPACT_NINF -83

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-83)))

#define YYTABLE_NINF -65

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -83,    17,   -83,    65,    18,    34,   -21,    26,     3,    23,
     -29,    23,   -83,   -83,   -83,   -83,   -83,    59,    60,   -21,
      23,    23,   -21,    23,    23,   -83,    61,    23,    23,   -83,
      53,    63,   -83,   -83,   -14,    64,   -83,    62,   -83,   -83,
      69,    57,    70,    73,    74,    75,   -83,    87,    86,    81,
      23,    82,    81,   -83,   -83,    -4,    81,   -83,   -83,    81,
      78,    82,   -83,    28,    76,    37,   -83,   -83,   -83,    99,
     104,     6,   -83,    58,    80,    83,    20,    46,    22,   -83,
      31,    82,    81,    20,    82,    23,    85,    88,    84,    -4,
      89,    90,   -83,   -83,   108,    92,    93,   -83,   -83,   -83,
      42,   -83,   -83,    94,    82,   -83,    79,   -83,   -83,   -83,
     -83,   -83,   -83,    15,    39,    91,   -83,    41,   -83,    81,
      81,   -83,   -83,    97,   100,   110,   -83,   -83,   -83,    20,
      20,   -83,   114,   -83,   -83,   -83,   -83,   -83,    20,   -83,
      52,   -83,    96,    98,   101,   -83,   -83,    54,   -83,   -83,
     -83,    81,   107,   -83,   -83,   -83,   -83,    23,   103,    81,
     106,   -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     3,     4,     5,     6,     7,     0,     0,     0,
       0,     0,     0,     0,     0,    63,     0,     0,     0,    64,
       0,    65,    56,    57,     0,     0,    44,     0,     8,    12,
       0,     0,     0,     0,     0,     0,    11,     0,     0,     0,
       0,     0,     0,    15,     9,     0,     0,    10,    14,     0,
       0,     0,    65,     0,     0,     0,    59,    58,    45,     0,
       0,     0,    22,     0,     0,     0,     0,     0,     0,    39,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    30,    31,    24,     0,     0,    38,    36,    37,
       0,    34,    16,     0,     0,    17,     0,    47,    48,    49,
      46,    50,    51,     0,     0,     0,    54,     0,    60,     0,
       0,    13,    23,     0,     0,     0,    20,    21,    32,     0,
       0,    40,     0,    42,    52,    53,    41,    18,     0,    19,
       0,    61,     0,     0,     0,    25,    35,     0,    43,    55,
      26,     0,     0,    28,    29,    33,    62,     0,     0,     0,
       0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,    40,   -83,
     -83,    12,   -82,   -20,    43,    -6,   -83,   -83,   -83,   -83,
     -83,   -83,    72,    -9,   -46
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,    12,    13,    14,    15,    16,    71,    72,    94,
      77,   100,   101,    78,    79,    80,   113,   136,    63,    34,
      65,   140,    26,    35,    36
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,   116,    37,    64,    33,    50,    68,    69,    31,    73,
      74,    41,    42,    75,    44,    45,    25,     2,    47,    48,
      32,    19,    28,    20,     3,     4,     5,     6,    70,    97,
      51,   134,     7,    62,    97,     8,   115,    22,     9,    23,
      10,    66,    27,    73,    11,    67,    21,   146,    81,    88,
      89,   104,    31,    98,    99,   106,   149,    84,    98,    99,
      29,   114,    24,   105,   117,   107,   108,   109,   104,    17,
     104,    18,    82,   141,   142,    49,   118,   110,   111,   112,
     137,    85,   139,    90,    91,   128,   129,   102,    92,    93,
     103,    40,   132,   133,    43,   150,   151,   155,   129,    55,
      38,    39,    46,    53,    60,   156,    61,   135,   -64,    52,
      54,    86,    56,   160,    57,    58,    87,    59,    62,    31,
      76,   125,    83,    95,   145,   121,    96,   119,   148,   122,
     120,   123,   124,   126,   127,   143,   130,   138,   144,   152,
     157,   153,   147,     0,   154,   159,     0,   131,   158,   161
};

static const yytype_int16 yycheck[] =
{
       9,    83,    11,    49,    10,    19,    52,    11,    37,    55,
      56,    20,    21,    59,    23,    24,    37,     0,    27,    28,
      49,     3,    19,     5,     7,     8,     9,    10,    32,    14,
      44,   113,    15,    37,    14,    18,    82,     3,    21,     5,
      23,    50,    16,    89,    27,    51,    28,   129,    20,    43,
      44,    29,    37,    38,    39,    24,   138,    20,    38,    39,
      37,    81,    28,    41,    84,    34,    35,    36,    29,     4,
      29,     6,    44,   119,   120,    22,    85,    46,    47,    48,
      41,    44,    41,    25,    26,    43,    44,    41,    30,    31,
      44,    19,    13,    14,    22,    43,    44,    43,    44,    42,
      41,    41,    41,    41,    17,   151,    20,   113,    45,    45,
      41,    12,    42,   159,    41,    41,    12,    42,    37,    37,
      42,    13,    46,    43,    14,    41,    43,    42,    14,    89,
      42,    42,    42,    41,    41,    38,    42,    46,    38,    43,
      33,    43,   130,    -1,    43,    42,    -1,   104,   157,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    51,     0,     7,     8,     9,    10,    15,    18,    21,
      23,    27,    52,    53,    54,    55,    56,     4,     6,     3,
       5,    28,     3,     5,    28,    37,    72,    16,    19,    37,
      73,    37,    49,    65,    69,    73,    74,    73,    41,    41,
      72,    73,    73,    72,    73,    73,    41,    73,    73,    22,
      19,    44,    45,    41,    41,    42,    42,    41,    41,    42,
      17,    20,    37,    68,    74,    70,    73,    65,    74,    11,
      32,    57,    58,    74,    74,    74,    42,    60,    63,    64,
      65,    20,    44,    46,    20,    44,    12,    12,    43,    44,
      25,    26,    30,    31,    59,    43,    43,    14,    38,    39,
      61,    62,    41,    44,    29,    41,    24,    34,    35,    36,
      46,    47,    48,    66,    63,    74,    62,    63,    73,    42,
      42,    41,    58,    42,    42,    13,    41,    41,    43,    44,
      42,    64,    13,    14,    62,    65,    67,    41,    46,    41,
      71,    74,    74,    38,    38,    14,    62,    61,    14,    62,
      43,    44,    43,    43,    43,    43,    74,    33,    73,    42,
      74,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    50,    51,    51,    52,    52,    52,    52,    53,    54,
      54,    54,    54,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    59,    59,
      59,    59,    60,    60,    61,    61,    62,    62,    62,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    69,    69,    70,
      70,    71,    71,    72,    73,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     1,     1,     1,     3,     4,
       4,     3,     3,     7,     4,     3,     6,     6,     7,     7,
       7,     7,     1,     3,     2,     4,     5,    10,     4,     4,
       1,     1,     3,     5,     1,     3,     1,     1,     1,     1,
       3,     3,     3,     4,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     5,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 49 "Parser.y" /* yacc.c:1646  */
    {
                            /* do nothing */
                            //cout << "Program : /* empty */" << endl;
                        }
#line 1365 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 54 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Program : Program Stmt" << endl;
                            cout << ">>>>Context End" << endl;
                        }
#line 1374 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 61 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Stmt : SysStmt ';'" << endl;
                        }
#line 1382 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 65 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Stmt : DbStmt ';'" << endl;
                        }
#line 1390 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 69 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Stmt : TbStmt ';'" << endl;
                        }
#line 1398 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 73 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Stmt : IdxStmt ';'" << endl;
                        }
#line 1406 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 79 "Parser.y" /* yacc.c:1646  */
    {
                            manager.showDatabases();

                            //cout << "SysStmt : SHOW DATABASES" << endl;
                            //cout << ">>>>SystemManager::showDataBases() called" << endl;
                        }
#line 1417 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 88 "Parser.y" /* yacc.c:1646  */
    {
                            manager.createDatabase((yyvsp[-1]).id);

                            //cout << "DbStmt : CREATE DATABASE DbName" << endl;
                            //cout << ">>>>SystemManager::createDataBase(" << $3.id << ") called" << endl;
                        }
#line 1428 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 95 "Parser.y" /* yacc.c:1646  */
    {
                            manager.dropDatabase((yyvsp[-1]).id);

                            //cout << "DbStmt : DROP DATABASE DbName" << endl;
                            //cout << ">>>>SystemManager::dropDataBase(" << $3.id << ") called" << endl;
                        }
#line 1439 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 102 "Parser.y" /* yacc.c:1646  */
    {
                            manager.useDatabase((yyvsp[-1]).id);

                            //cout << "DbStmt : USE DbName" << endl;
                            //cout << ">>>>SystemManager::use(" << $2.id << ") called" << endl;
                        }
#line 1450 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 109 "Parser.y" /* yacc.c:1646  */
    {
                            manager.showTables();

                            //cout << "DbStmt : SHOW TABLES" << endl;
                            //cout << ">>>>SystemManager::showTables() called" << endl;
                        }
#line 1461 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 118 "Parser.y" /* yacc.c:1646  */
    {
                            manager.createTable((yyvsp[-4]).id, (yyvsp[-2]).schemaList);

                            //cout << "TbStmt : CREATE TABLE '(' FieldList ')'" << endl;
                            /*cout << ">>>>SystemManager::createTable(" << $3.id << ", FieldList) called" << endl;
                            cout << ">>>>FieldList.size: " << $5.schemaList.size() << endl;
                            for (SchemaEntry se : $5.schemaList)
                            {
                                cout << ">>>>    " << se.field << " " << se.type << " " << se.length << " " << se.notNull << endl;
                                
                                if (se.entrykind == SchemaEntry::PRIMARY_KIND)
                                {
                                    cout << ">>>>        primaryKeyList.size: " << se.primaryKeyList.size() << endl;

                                    for (auto name : se.primaryKeyList)
                                    {
                                        cout << ">>>>            primaryKey: " << name << endl;
                                    } 
                                }

                                if (se.entrykind == SchemaEntry::FOREIGN_KIND)
                                {
                                    cout << ">>>>        foreignKey: " << se.foreignKey << endl;
                                    cout << ">>>>        foreignAttr.tbname: " << se.foreignAttr.tbname << endl;
                                    cout << ">>>>        foreignAttr.attrname: " << se.foreignAttr.attrname << endl;
                                }
                            }*/
                        }
#line 1494 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 147 "Parser.y" /* yacc.c:1646  */
    {
                            manager.dropTable((yyvsp[-1]).id);

                            //cout << "TbStmt : DROP TABLE TbName" << endl;
                            //cout << ">>>>SystemManager::dropTable(" << $3.id << ") called" << endl;
                        }
#line 1505 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 154 "Parser.y" /* yacc.c:1646  */
    {
                            manager.descTable((yyvsp[-1]).id);

                            //cout << "TbStmt : DESC TbName" << endl;
                            //cout << ">>>>SystemManager::desc(" << $2.id << ") called" << endl;
                        }
#line 1516 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 161 "Parser.y" /* yacc.c:1646  */
    {
                            manager.insertIntoTable((yyvsp[-3]).id, (yyvsp[-1]).valuesList);

                            //cout << "TbStmt : INSERT INTO TbName VALUES ValueLists" << endl;
                            /*cout << ">>>>SystemManager::insertIntoTableWithValues(" << $3.id << ", ValueLists) called" << endl;
                            cout << ">>>>ValueLists.size: " << $5.valuesList.size() << endl;

                            for (auto values : $5.valuesList)
                            {
                                cout << ">>>>    ValueList.size: " << values.size() << endl;

                                for (auto value : values)
                                {
                                    cout << ">>>>        " << value.type << " " << value.integer << " " << value.literal << endl;
                                }
                            }*/
                        }
#line 1538 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 179 "Parser.y" /* yacc.c:1646  */
    {
                            manager.deleteFromTable((yyvsp[-3]).id, (yyvsp[-1]).condList);

                            //cout << "TbStmt : DELETE FROM TbName WHERE WhereClause" << endl;
                            /*cout << ">>>>SystemManager::deleteFromTableWhere(" << $3.id << ", WhereClauseList) called" << endl;
                            cout << ">>>>WhereClauseList.size: " << $5.condList.size() << endl;

                            for (Condition cond : $5.condList)
                            {
                                if (cond.condType == Condition::COL_EXPR_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_EXPR_TYPE" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname;
                                    cout << " " << cond.optr << " ";
                            
                                    if (cond.expr.dataType == Expr::COL_EXPR_TYPE)
                                    {
                                        cout << cond.expr.col.tbname << "." << cond.expr.col.attrname << endl;
                                    }
                                    else
                                    {
                                        cout << cond.expr.value.type << " " << cond.expr.value.integer << " " << cond.expr.value.literal << endl;
                                    }
                            
                                }
                                else if (cond.condType == Condition::COL_IS_NULL_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_IS_NULL" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NULL" << endl;
                             
                                }
                                else if (cond.condType == Condition::COL_IS_NOT_NULL_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_IS_NOT_NULL" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NOT NULL" << endl;
                                }
                            }*/
                        }
#line 1581 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 218 "Parser.y" /* yacc.c:1646  */
    {
                            manager.updateTable((yyvsp[-5]).id, (yyvsp[-3]).setList, (yyvsp[-1]).condList);

                            //cout << "TbStmt : UPDATE TbName SET SetClause WHERE WhereClause" << endl;
                            /*cout << ">>>>SystemManager::updateTableSetWhere(" << $2.id << ", SetClause , WhereClauseList) called" << endl;
                            
                            cout << ">>>>SetClause.size: " << $4.setList.size() << endl;

                            for (Set set : $4.setList)
                            {
                                cout << ">>>>    " << set.colName << " = ";
                                cout << set.value.type << " " << set.value.integer << " " << set.value.literal << endl;
                            }

                            cout << ">>>>WhereClauseList.size: " << $6.condList.size() << endl;

                            for (Condition cond : $6.condList)
                            {
                                if (cond.condType == Condition::COL_EXPR_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_EXPR_TYPE" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname;
                                    cout << " " << cond.optr << " ";
                            
                                    if (cond.expr.dataType == Expr::COL_EXPR_TYPE)
                                    {
                                        cout << cond.expr.col.tbname << "." << cond.expr.col.attrname << endl;
                                    }
                                    else
                                    {
                                        cout << cond.expr.value.type << " " << cond.expr.value.integer << " " << cond.expr.value.literal << endl;
                                    }
                            
                                }
                                else if (cond.condType == Condition::COL_IS_NULL_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_IS_NULL" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NULL" << endl;
                             
                                }
                                else if (cond.condType == Condition::COL_IS_NOT_NULL_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_IS_NOT_NULL" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NOT NULL" << endl;
                                }
                            }*/                            
                        }
#line 1633 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 266 "Parser.y" /* yacc.c:1646  */
    {
                            manager.selectFromTable((yyvsp[-5]).selectorList, (yyvsp[-3]).tableList, (yyvsp[-1]).condList);

                            //cout << "TbStmt : SELECT Selector FROM TableList WHERE WhereClause" << endl;
                            /*cout << ">>>>SystemManager::SelectFromTableWhere(Selector, TableList , WhereClauseList) called" << endl;

                            cout << ">>>>Selector.size: " << $2.selectorList.size() << endl;

                            for (Selector se : $2.selectorList)
                            {
                                if (se.selectorType == Selector::SELECTOR_ALL_TYPE)
                                {
                                    cout << ">>>>    *" << endl;
                                }
                                else
                                {
                                    cout << ">>>>    " << se.col.tbname << "." << se.col.attrname << endl;
                                }
                            }

                            cout << ">>>>TableList.size: " << $4.tableList.size() << endl;

                            for (string s : $4.tableList)
                            {
                                cout << ">>>>    " << s << endl;
                            }

                            cout << ">>>>WhereClauseList.size: " << $6.condList.size() << endl;

                            for (Condition cond : $6.condList)
                            {
                                if (cond.condType == Condition::COL_EXPR_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_EXPR_TYPE" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname;
                                    cout << " " << cond.optr << " ";
                            
                                    if (cond.expr.dataType == Expr::COL_EXPR_TYPE)
                                    {
                                        cout << cond.expr.col.tbname << "." << cond.expr.col.attrname << endl;
                                    }
                                    else
                                    {
                                        cout << cond.expr.value.type << " " << cond.expr.value.integer << " " << cond.expr.value.literal << endl;
                                    }
                            
                                }
                                else if (cond.condType == Condition::COL_IS_NULL_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_IS_NULL" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NULL" << endl;
                             
                                }
                                else if (cond.condType == Condition::COL_IS_NOT_NULL_TYPE)
                                {
                                    cout << ">>>>WhereClause: COL_IS_NOT_NULL" << endl;
                                    cout << ">>>>    " << cond.col.tbname << "." << cond.col.attrname << " IS NOT NULL" << endl;
                                }
                            }*/  
                        }
#line 1698 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 329 "Parser.y" /* yacc.c:1646  */
    {
                            manager.createIndex((yyvsp[-4]).id, (yyvsp[-2]).id);

                            //cout << "IdxStmt : CREATE INDEX TbName '(' ColName ')'" << endl;
                            //cout << ">>>>SystemManager::createIndex(" << $3.id << ", " << $5.id << ") called" << endl;
                        }
#line 1709 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 336 "Parser.y" /* yacc.c:1646  */
    {
                            manager.dropIndex((yyvsp[-4]).id, (yyvsp[-2]).id);

                            //cout << "IdxStmt : DROP INDEX TbName '(' ColName ')'" << endl;
                            //cout << ">>>>SystemManager::dropIndex(" << $3.id << ", " << $5.id << ") called" << endl;
                        }
#line 1720 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 345 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "FieldList : Field" << endl;
                            (yyval).schemaList.clear();
                            (yyval).schemaList.push_back((yyvsp[0]).schemaEntry);
                            //cout << ">>>>>>>>" << $1.schemaEntry.field << " " << $1.schemaEntry.type << " " << $1.schemaEntry.length << " " << $1.schemaEntry.notNull << endl;
                            //cout << $$.schemaList.size() << endl;
                        }
#line 1732 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 353 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "FieldList : FieldList ',' Field" << endl;
                            (yyval).schemaList.push_back((yyvsp[0]).schemaEntry);
                            //cout << ">>>>>>>>" << $3.schemaEntry.field << " " << $3.schemaEntry.type << " " << $3.schemaEntry.length << " " << $3.schemaEntry.notNull << endl;
                            //cout << $$.schemaList.size() << " -> " << $1.schemaList.size() << endl;
                        }
#line 1743 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 362 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Field : ColName Type" << endl;
                            (yyval).schemaEntry = SchemaEntry((yyvsp[-1]).id, (yyvsp[0]).dataType, (yyvsp[0]).length, false);
                            (yyval).schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        }
#line 1753 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 368 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Field : ColName Type NOT NULLL" << endl;
                            (yyval).schemaEntry = SchemaEntry((yyvsp[-3]).id, (yyvsp[-2]).dataType, (yyvsp[-2]).length, true);
                            (yyval).schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        }
#line 1763 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 374 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Field : PRIMARY KEY '(' ColumnList ')'" << endl;
                            (yyval).schemaEntry.primaryKeyList = (yyvsp[-1]).columnList;
                            (yyval).schemaEntry.entrykind = SchemaEntry::PRIMARY_KIND;
                        }
#line 1773 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 380 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Field : FOREIGN KEY '(' ColName ')' REFERENCES TbName '(' ColName ')'" << endl;
                            (yyval).schemaEntry.foreignKey = (yyvsp[-6]).id;
                            (yyval).schemaEntry.foreignAttr = Attr((yyvsp[-3]).id, (yyvsp[-1]).id);
                            (yyval).schemaEntry.entrykind = SchemaEntry::FOREIGN_KIND;
                        }
#line 1784 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 389 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Type : INT '(' VALUE_INT ')'" << endl;
                            (yyval).dataType = "int";
                            (yyval).length = (yyvsp[-1]).length;
                        }
#line 1794 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 395 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Type : VARCHAR '(' VALUE_INT ')'" << endl;
                            (yyval).dataType = "varchar";
                            (yyval).length = (yyvsp[-1]).length;
                        }
#line 1804 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 401 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Type : DATE" << endl;
                            (yyval).dataType = "date";
                        }
#line 1813 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 406 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Type : FLOAT" << endl;
                            (yyval).dataType = "float";
                        }
#line 1822 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 413 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "ValueLists : '(' ValueList ')'" << endl;
                            (yyval).valuesList.clear();
                            (yyval).valuesList.push_back((yyvsp[-1]).values);
                        }
#line 1832 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 419 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "ValueLists : ValueLists ',' '(' ValueList ')'" << endl;
                            (yyval).valuesList.push_back((yyvsp[-1]).values);
                        }
#line 1841 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 426 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "ValueList : Value" << endl;
                            (yyval).values.clear();
                            (yyval).values.push_back((yyvsp[0]).value);
                        }
#line 1851 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 432 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "ValueList : ValueList ',' Value" << endl;
                            (yyval).values.push_back((yyvsp[0]).value);
                        }
#line 1860 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 439 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Value : VALUE_INT" << endl;
                            (yyval).value = Value(Value::VALUE_INT_TYPE, (yyvsp[0]).length, "");
                        }
#line 1869 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 444 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Value : VALUE_STRING" << endl;
                            (yyval).value = Value(Value::VALUE_STRING_TYPE, (yyvsp[-1]).length, (yyvsp[0]).literal);
                        }
#line 1878 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 449 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Value : NULLL" << endl;
                            (yyval).value = Value(Value::VALUE_NULL_TYPE, 0, "");
                        }
#line 1887 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 456 "Parser.y" /* yacc.c:1646  */
    {
                            (yyval).condList.clear();
                            (yyval).condList.push_back((yyvsp[0]).cond);
                            //cout << $$.condList.size() << endl;
                        }
#line 1897 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 462 "Parser.y" /* yacc.c:1646  */
    {
                            
                            (yyval).condList.push_back((yyvsp[0]).cond);
                            //cout << $$.condList.size() << endl;

                        }
#line 1908 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 471 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "WhereClause : Col Op Expr" << endl;
                            (yyval).cond = Condition(Condition::COL_EXPR_TYPE);
                            (yyval).cond.col = (yyvsp[-2]).col;
                            (yyval).cond.optr = (yyvsp[-1]).optr;
                            (yyval).cond.expr = (yyvsp[0]).expr;
                        }
#line 1920 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 479 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "WhereClause : Col IS NULLL" << endl;
                            (yyval).cond = Condition(Condition::COL_IS_NULL_TYPE);
                            (yyval).cond.col = (yyvsp[-2]).col;
                        }
#line 1930 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 485 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "WhereClause : Col IS NOT NULLL" << endl;
                            (yyval).cond = Condition(Condition::COL_IS_NOT_NULL_TYPE);
                            (yyval).cond.col = (yyvsp[-3]).col;
                        }
#line 1940 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 493 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Col : ColName" << endl;
                            (yyval).col = Attr("", (yyvsp[0]).id);
                        }
#line 1949 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 498 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Col : TbName '.' ColName" << endl;
                            (yyval).col = Attr((yyvsp[-2]).id, (yyvsp[0]).id);
                        }
#line 1958 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 505 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Op : '='" << endl;
                            (yyval).optr = "=";
                        }
#line 1967 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 510 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Op : '<>'" << endl;
                            (yyval).optr = "<>";
                        }
#line 1976 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 515 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Op : '<='" << endl;
                            (yyval).optr = "<=";
                        }
#line 1985 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 520 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Op : '>='" << endl;
                            (yyval).optr = ">=";
                        }
#line 1994 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 525 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Op : '<'" << endl;
                            (yyval).optr = "<";
                        }
#line 2003 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 530 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Op : '>'" << endl;
                            (yyval).optr = ">";
                        }
#line 2012 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 537 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Expr : Value" << endl;
                            (yyval).expr = Expr();
                            (yyval).expr.dataType = Expr::VALUE_EXPR_TYPE;
                            (yyval).expr.value = (yyvsp[0]).value;
                        }
#line 2023 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 544 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Expr : Col" << endl;
                            (yyval).expr = Expr();
                            (yyval).expr.dataType = Expr::COL_EXPR_TYPE;
                            (yyval).expr.col = (yyvsp[0]).col;
                        }
#line 2034 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 553 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "SetClause : ColName '=' Value" << endl;
                            (yyval).setList.clear();
                            (yyval).setList.push_back(Set((yyvsp[-2]).id, (yyvsp[0]).value));
                        }
#line 2044 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 559 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "SetClause : SetClause ',' ColName '=' Value" << endl;
                            (yyval).setList.push_back(Set((yyvsp[-2]).id, (yyvsp[0]).value));
                        }
#line 2053 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 566 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Selector : '*'" << endl;
                            (yyval).selectorList.clear();
                            (yyval).selectorList.push_back(Selector::SELECTOR_ALL_TYPE);
                        }
#line 2063 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 572 "Parser.y" /* yacc.c:1646  */
    {
                            (yyval).selectorList.clear();
                            (yyval).selectorList.push_back(Selector(Selector::SELECTOR_COL_TYPE, (yyvsp[0]).col));                            
                        }
#line 2072 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 577 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "Selector : SubSelector Col" << endl;
                            (yyval).selectorList.push_back(Selector(Selector::SELECTOR_COL_TYPE, (yyvsp[0]).col));

                        }
#line 2082 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 585 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "TableList : TbName" << endl;
                            (yyval).tableList.clear();
                            (yyval).tableList.push_back((yyvsp[0]).id);
                        }
#line 2092 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 591 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "TableList : TableList ',' TbName" << endl;
                            (yyval).tableList.push_back((yyvsp[0]).id);
                        }
#line 2101 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 598 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "ColumnList : ColName" << endl;
                            (yyval).columnList.clear();
                            (yyval).columnList.push_back((yyvsp[0]).id);
                        }
#line 2111 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 604 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "ColumnList : ColumnList ',' ColName" << endl;
                            (yyval).columnList.push_back((yyvsp[0]).id);
                        }
#line 2120 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 611 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "DbName : " << $1 << endl;
                            (yyval).id = (yyvsp[0]).id;
                        }
#line 2129 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 618 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "TbName : " << $1 << endl;
                            (yyval).id = (yyvsp[0]).id;
                        }
#line 2138 "Parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 625 "Parser.y" /* yacc.c:1646  */
    {
                            //cout << "ColName : " << $1 << endl;
                            (yyval).id = (yyvsp[0]).id;
                        }
#line 2147 "Parser.tab.c" /* yacc.c:1646  */
    break;


#line 2151 "Parser.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 632 "Parser.y" /* yacc.c:1906  */


/////////////////////////////////////////////////////////////////////////////
// programs section
void yyerror(const char *s)
{
    cout << "yyerror: " << s << endl;
}


int main()
{
    yyparse();
    return 0;
}

