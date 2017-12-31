
/*  A Bison parser, made from parser.y
    by GNU Bison version 1.28  */

#define YYBISON 1  /* Identify Bison output.  */

#define	DATABASE	257
#define	DATABASES	258
#define	TABLE	259
#define	TABLES	260
#define	SHOW	261
#define	CREATE	262
#define	DROP	263
#define	USE	264
#define	PRIMARY	265
#define	KEY	266
#define	NOT	267
#define	NULLL	268
#define	INSERT	269
#define	INTO	270
#define	VALUES	271
#define	DELETE	272
#define	FROM	273
#define	WHERE	274
#define	UPDATE	275
#define	SET	276
#define	SELECT	277
#define	IS	278
#define	INT	279
#define	VARCHAR	280
#define	DESC	281
#define	INDEX	282
#define	AND	283
#define	DATE	284
#define	FLOAT	285
#define	FOREIGN	286
#define	REFERENCES	287
#define	NEQ	288
#define	LTE	289
#define	GTE	290
#define	IDENTIFIER	291
#define	VALUE_INT	292
#define	VALUE_STRING	293
#define	LITERAL	294
#define	LIKE	295
#define	SUM	296
#define	AVG	297
#define	MAX	298
#define	MIN	299

#line 1 "parser.y"

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
#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		181
#define	YYFLAG		-32768
#define	YYNTBASE	55

#define YYTRANSLATE(x) ((unsigned)(x) <= 299 ? yytranslate[x] : 80)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
    48,    54,     2,    49,     2,    50,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,    46,    52,
    51,    53,     2,     2,     2,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     3,     4,     5,     6,
     7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
    27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
    37,    38,    39,    40,    41,    42,    43,    44,    45
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     1,     4,     6,     8,    10,    12,    16,    21,    26,
    30,    34,    42,    47,    51,    58,    65,    73,    81,    89,
    97,    99,   103,   106,   111,   117,   128,   133,   138,   140,
   142,   146,   152,   154,   158,   160,   162,   164,   166,   170,
   174,   178,   182,   187,   189,   193,   195,   197,   199,   201,
   203,   205,   207,   209,   213,   219,   221,   225,   227,   229,
   234,   239,   244,   249,   251,   255,   257,   261,   263,   265
};

static const short yyrhs[] = {    -1,
    55,    56,     0,    57,     0,    58,     0,    59,     0,    60,
     0,     7,     4,    46,     0,     8,     3,    77,    46,     0,
     9,     3,    77,    46,     0,    10,    77,    46,     0,     7,
     6,    46,     0,     8,     5,    78,    47,    61,    48,    46,
     0,     9,     5,    78,    46,     0,    27,    78,    46,     0,
    15,    16,    78,    17,    64,    46,     0,    18,    19,    78,
    20,    67,    46,     0,    21,    78,    22,    72,    20,    67,
    46,     0,    23,    73,    19,    75,    20,    67,    46,     0,
     8,    28,    78,    47,    79,    48,    46,     0,     9,    28,
    78,    47,    79,    48,    46,     0,    62,     0,    61,    49,
    62,     0,    79,    63,     0,    79,    63,    13,    14,     0,
    11,    12,    47,    76,    48,     0,    32,    12,    47,    79,
    48,    33,    78,    47,    79,    48,     0,    25,    47,    38,
    48,     0,    26,    47,    38,    48,     0,    30,     0,    31,
     0,    47,    65,    48,     0,    64,    49,    47,    65,    48,
     0,    66,     0,    65,    49,    66,     0,    38,     0,    39,
     0,    14,     0,    68,     0,    67,    29,    68,     0,    69,
    70,    71,     0,    69,    41,    66,     0,    69,    24,    14,
     0,    69,    24,    13,    14,     0,    79,     0,    78,    50,
    79,     0,    51,     0,    34,     0,    35,     0,    36,     0,
    52,     0,    53,     0,    66,     0,    69,     0,    79,    51,
    66,     0,    72,    49,    79,    51,    66,     0,    54,     0,
    73,    49,    74,     0,    74,     0,    69,     0,    42,    47,
    69,    48,     0,    43,    47,    69,    48,     0,    44,    47,
    69,    48,     0,    45,    47,    69,    48,     0,    78,     0,
    75,    49,    78,     0,    79,     0,    76,    49,    79,     0,
    37,     0,    37,     0,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    55,    59,    65,    69,    73,    77,    83,    89,    93,    97,
   101,   107,   111,   115,   119,   123,   127,   131,   137,   141,
   147,   152,   158,   163,   168,   173,   181,   186,   191,   195,
   201,   206,   212,   217,   223,   227,   231,   237,   242,   248,
   255,   261,   266,   273,   277,   283,   287,   291,   295,   299,
   303,   309,   315,   323,   328,   334,   339,   343,   350,   354,
   358,   362,   366,   372,   377,   383,   388,   394,   400,   406
};
#endif


#if YYDEBUG != 0 || defined (YYERROR_VERBOSE)

static const char * const yytname[] = {   "$","error","$undefined.","DATABASE",
"DATABASES","TABLE","TABLES","SHOW","CREATE","DROP","USE","PRIMARY","KEY","NOT",
"NULLL","INSERT","INTO","VALUES","DELETE","FROM","WHERE","UPDATE","SET","SELECT",
"IS","INT","VARCHAR","DESC","INDEX","AND","DATE","FLOAT","FOREIGN","REFERENCES",
"NEQ","LTE","GTE","IDENTIFIER","VALUE_INT","VALUE_STRING","LITERAL","LIKE","SUM",
"AVG","MAX","MIN","';'","'('","')'","','","'.'","'='","'<'","'>'","'*'","Program",
"Stmt","SysStmt","DbStmt","TbStmt","IdxStmt","FieldList","Field","Type","ValueLists",
"ValueList","Value","WhereClauseList","WhereClause","Col","Op","Expr","SetClause",
"SelectorList","Selector","TableList","ColumnList","DbName","TbName","ColName", NULL
};
#endif

static const short yyr1[] = {     0,
    55,    55,    56,    56,    56,    56,    57,    58,    58,    58,
    58,    59,    59,    59,    59,    59,    59,    59,    60,    60,
    61,    61,    62,    62,    62,    62,    63,    63,    63,    63,
    64,    64,    65,    65,    66,    66,    66,    67,    67,    68,
    68,    68,    68,    69,    69,    70,    70,    70,    70,    70,
    70,    71,    71,    72,    72,    73,    73,    73,    74,    74,
    74,    74,    74,    75,    75,    76,    76,    77,    78,    79
};

static const short yyr2[] = {     0,
     0,     2,     1,     1,     1,     1,     3,     4,     4,     3,
     3,     7,     4,     3,     6,     6,     7,     7,     7,     7,
     1,     3,     2,     4,     5,    10,     4,     4,     1,     1,
     3,     5,     1,     3,     1,     1,     1,     1,     3,     3,
     3,     3,     4,     1,     3,     1,     1,     1,     1,     1,
     1,     1,     1,     3,     5,     1,     3,     1,     1,     4,
     4,     4,     4,     1,     3,     1,     3,     1,     1,     1
};

static const short yydefact[] = {     1,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     2,     3,     4,     5,     6,     0,     0,     0,     0,     0,
     0,     0,     0,    68,     0,     0,     0,    69,     0,    70,
     0,     0,     0,     0,    56,    59,     0,    58,     0,    44,
     0,     7,    11,     0,     0,     0,     0,     0,     0,    10,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    14,     8,     0,     0,     9,    13,     0,     0,     0,    70,
     0,     0,     0,     0,     0,     0,     0,    64,    57,    45,
     0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
    38,     0,     0,     0,     0,    60,    61,    62,    63,     0,
     0,     0,     0,     0,     0,     0,     0,    29,    30,    23,
     0,     0,    37,    35,    36,     0,    33,    15,     0,     0,
    16,     0,    47,    48,    49,     0,    46,    50,    51,     0,
     0,     0,    54,     0,    65,     0,     0,    12,    22,     0,
     0,     0,    19,    20,    31,     0,     0,    39,     0,    42,
    41,    52,    53,    40,    17,     0,    18,     0,    66,     0,
     0,     0,    24,    34,     0,    43,    55,    25,     0,     0,
    27,    28,    32,    67,     0,     0,     0,     0,    26,     0,
     0
};

static const short yydefgoto[] = {     1,
    11,    12,    13,    14,    15,    83,    84,   110,    89,   116,
   117,    90,    91,    92,   130,   154,    71,    37,    38,    77,
   158,    25,    39,    40
};

static const short yypact[] = {-32768,
    64,    80,    60,    72,   -28,     5,    10,     1,    59,     1,
-32768,-32768,-32768,-32768,-32768,     2,    30,   -28,     1,     1,
   -28,     1,     1,-32768,    32,     1,     1,-32768,    70,    31,
    52,    58,    61,    67,-32768,-32768,   -18,-32768,    76,-32768,
    63,-32768,-32768,    79,    74,    82,    85,    86,    87,-32768,
   110,   113,    98,    99,    99,    99,    99,     1,    73,    98,
-32768,-32768,    14,    98,-32768,-32768,    98,    90,    99,-32768,
   -16,    88,    92,    93,    94,    95,   -12,-32768,-32768,-32768,
   126,   132,    20,-32768,    81,    97,   100,    -4,    21,    -7,
-32768,     8,    99,    98,    -4,-32768,-32768,-32768,-32768,    99,
     1,   102,   103,   101,    14,   104,   105,-32768,-32768,   133,
   107,   108,-32768,-32768,-32768,    46,-32768,-32768,   109,    99,
-32768,    84,-32768,-32768,-32768,    -4,-32768,-32768,-32768,   -11,
    -5,   106,-32768,    16,-32768,    98,    98,-32768,-32768,   117,
   120,   145,-32768,-32768,-32768,    -4,    -4,-32768,   146,-32768,
-32768,-32768,-32768,-32768,-32768,    -4,-32768,    71,-32768,   114,
   115,   116,-32768,-32768,    75,-32768,-32768,-32768,    98,   128,
-32768,-32768,-32768,-32768,     1,   118,    98,   121,-32768,   166,
-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,-32768,-32768,-32768,-32768,    65,-32768,-32768,    24,
   -90,   -70,    48,    -2,-32768,-32768,-32768,-32768,   119,-32768,
-32768,    62,    -8,   -47
};


#define	YYLAST		178


static const short yytable[] = {    29,
    58,    41,   113,    93,   133,    72,    36,   100,    24,   113,
    45,    46,    80,    48,    49,    85,    86,    51,    52,    87,
    26,   120,   131,   120,    81,    30,   114,   115,    27,   134,
    59,   122,    94,   114,   115,   151,   101,    28,   121,   152,
   155,   123,   124,   125,   120,    82,   132,    42,   126,    78,
    70,    73,    74,    75,    76,   164,    36,    85,   127,   128,
   129,   157,    18,   180,    19,   167,   118,   104,   105,   119,
     2,     3,     4,     5,    21,    43,    22,    50,     6,    44,
   -69,     7,    47,    16,     8,    17,     9,    20,   159,   160,
    10,    53,   135,   145,   146,    30,   149,   150,    54,    23,
    31,    32,    33,    34,    55,   106,   107,    56,    61,    30,
   108,   109,    35,    57,    31,    32,    33,    34,   168,   169,
    63,   174,   173,   146,    62,    60,    68,   153,    64,   178,
    65,    66,    69,    67,    70,    30,    88,   102,    95,    96,
    97,    98,    99,   103,   111,   142,   138,   112,   136,   137,
   140,   141,   143,   144,   161,   147,   156,   162,   163,   166,
   175,   170,   171,   172,   177,   181,   176,   148,   179,   139,
   165,     0,     0,     0,     0,     0,     0,    79
};

static const short yycheck[] = {     8,
    19,    10,    14,    20,    95,    53,     9,    20,    37,    14,
    19,    20,    60,    22,    23,    63,    64,    26,    27,    67,
    16,    29,    93,    29,    11,    37,    38,    39,    19,   100,
    49,    24,    49,    38,    39,   126,    49,    37,    46,   130,
    46,    34,    35,    36,    29,    32,    94,    46,    41,    58,
    37,    54,    55,    56,    57,   146,    59,   105,    51,    52,
    53,    46,     3,     0,     5,   156,    46,    48,    49,    49,
     7,     8,     9,    10,     3,    46,     5,    46,    15,    18,
    50,    18,    21,     4,    21,     6,    23,    28,   136,   137,
    27,    22,   101,    48,    49,    37,    13,    14,    47,    28,
    42,    43,    44,    45,    47,    25,    26,    47,    46,    37,
    30,    31,    54,    47,    42,    43,    44,    45,    48,    49,
    47,   169,    48,    49,    46,    50,    17,   130,    47,   177,
    46,    46,    20,    47,    37,    37,    47,    12,    51,    48,
    48,    48,    48,    12,    48,    13,    46,    48,    47,    47,
    47,    47,    46,    46,    38,    47,    51,    38,    14,    14,
    33,    48,    48,    48,    47,     0,   175,   120,    48,   105,
   147,    -1,    -1,    -1,    -1,    -1,    -1,    59
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "/usr/local/share/bison.simple"
/* This file comes from bison-1.28.  */

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

#ifndef YYSTACK_USE_ALLOCA
#ifdef alloca
#define YYSTACK_USE_ALLOCA
#else /* alloca not defined */
#ifdef __GNUC__
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi) || (defined (__sun) && defined (__i386))
#define YYSTACK_USE_ALLOCA
#include <alloca.h>
#else /* not sparc */
/* We think this test detects Watcom and Microsoft C.  */
/* This used to test MSDOS, but that is a bad idea
   since that symbol is in the user namespace.  */
#if (defined (_MSDOS) || defined (_MSDOS_)) && !defined (__TURBOC__)
#if 0 /* No need for malloc.h, which pollutes the namespace;
	 instead, just don't use alloca.  */
#include <malloc.h>
#endif
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
/* I don't know what this was needed for, but it pollutes the namespace.
   So I turned it off.   rms, 2 May 1997.  */
/* #include <malloc.h>  */
 #pragma alloca
#define YYSTACK_USE_ALLOCA
#else /* not MSDOS, or __TURBOC__, or _AIX */
#if 0
#ifdef __hpux /* haible@ilog.fr says this works for HPUX 9.05 and up,
		 and on HPUX 10.  Eventually we can turn this on.  */
#define YYSTACK_USE_ALLOCA
#define alloca __builtin_alloca
#endif /* __hpux */
#endif
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc */
#endif /* not GNU C */
#endif /* alloca not defined */
#endif /* YYSTACK_USE_ALLOCA not defined */

#ifdef YYSTACK_USE_ALLOCA
#define YYSTACK_ALLOC alloca
#else
#define YYSTACK_ALLOC malloc
#endif

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	goto yyacceptlab
#define YYABORT 	goto yyabortlab
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Define __yy_memcpy.  Note that the size argument
   should be passed with type unsigned int, because that is what the non-GCC
   definitions require.  With GCC, __builtin_memcpy takes an arg
   of type size_t, but it can handle unsigned int.  */

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(TO,FROM,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (to, from, count)
     char *to;
     char *from;
     unsigned int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *to, char *from, unsigned int count)
{
  register char *t = to;
  register char *f = from;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 217 "/usr/local/share/bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#ifdef __cplusplus
#define YYPARSE_PARAM_ARG void *YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#else /* not __cplusplus */
#define YYPARSE_PARAM_ARG YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#endif /* not __cplusplus */
#else /* not YYPARSE_PARAM */
#define YYPARSE_PARAM_ARG
#define YYPARSE_PARAM_DECL
#endif /* not YYPARSE_PARAM */

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
#ifdef YYPARSE_PARAM
int yyparse (void *);
#else
int yyparse (void);
#endif
#endif

int
yyparse(YYPARSE_PARAM_ARG)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;
  int yyfree_stacks = 0;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  if (yyfree_stacks)
	    {
	      free (yyss);
	      free (yyvs);
#ifdef YYLSP_NEEDED
	      free (yyls);
#endif
	    }
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
#ifndef YYSTACK_USE_ALLOCA
      yyfree_stacks = 1;
#endif
      yyss = (short *) YYSTACK_ALLOC (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss, (char *)yyss1,
		   size * (unsigned int) sizeof (*yyssp));
      yyvs = (YYSTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs, (char *)yyvs1,
		   size * (unsigned int) sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) YYSTACK_ALLOC (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls, (char *)yyls1,
		   size * (unsigned int) sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 56 "parser.y"
{
                            /* do nothing */
                        ;
    break;}
case 2:
#line 60 "parser.y"
{

                        ;
    break;}
case 3:
#line 66 "parser.y"
{

                        ;
    break;}
case 4:
#line 70 "parser.y"
{

                        ;
    break;}
case 5:
#line 74 "parser.y"
{

                        ;
    break;}
case 6:
#line 78 "parser.y"
{

                        ;
    break;}
case 7:
#line 84 "parser.y"
{
                            manager.showDatabases();
                        ;
    break;}
case 8:
#line 90 "parser.y"
{
                            manager.createDatabase(yyvsp[-1].id);
                        ;
    break;}
case 9:
#line 94 "parser.y"
{
                            manager.dropDatabase(yyvsp[-1].id);
                        ;
    break;}
case 10:
#line 98 "parser.y"
{
                            manager.useDatabase(yyvsp[-1].id);
                        ;
    break;}
case 11:
#line 102 "parser.y"
{
                            manager.showTables();
                        ;
    break;}
case 12:
#line 108 "parser.y"
{
                            manager.createTable(yyvsp[-4].id, yyvsp[-2].schemaList);
                        ;
    break;}
case 13:
#line 112 "parser.y"
{
                            manager.dropTable(yyvsp[-1].id);
                        ;
    break;}
case 14:
#line 116 "parser.y"
{
                            manager.descTable(yyvsp[-1].id);
                        ;
    break;}
case 15:
#line 120 "parser.y"
{
                            manager.insertIntoTable(yyvsp[-3].id, yyvsp[-1].valuesList);
                        ;
    break;}
case 16:
#line 124 "parser.y"
{
                            manager.deleteFromTable(yyvsp[-3].id, yyvsp[-1].condList);
                        ;
    break;}
case 17:
#line 128 "parser.y"
{
                            manager.updateTable(yyvsp[-5].id, yyvsp[-3].setList, yyvsp[-1].condList);                      
                        ;
    break;}
case 18:
#line 132 "parser.y"
{
                            manager.selectFromTable(yyvsp[-5].selectorList, yyvsp[-3].tableList, yyvsp[-1].condList);
                        ;
    break;}
case 19:
#line 138 "parser.y"
{
                            manager.createIndex(yyvsp[-4].id, yyvsp[-2].id);
                        ;
    break;}
case 20:
#line 142 "parser.y"
{
                            manager.dropIndex(yyvsp[-4].id, yyvsp[-2].id);
                        ;
    break;}
case 21:
#line 148 "parser.y"
{
                            yyval.schemaList.clear();
                            yyval.schemaList.push_back(yyvsp[0].schemaEntry);
                        ;
    break;}
case 22:
#line 153 "parser.y"
{
                            yyval.schemaList.push_back(yyvsp[0].schemaEntry);
                        ;
    break;}
case 23:
#line 159 "parser.y"
{
                            yyval.schemaEntry = SchemaEntry(yyvsp[-1].id, yyvsp[0].dataType, yyvsp[0].length, false);
                            yyval.schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        ;
    break;}
case 24:
#line 164 "parser.y"
{
                            yyval.schemaEntry = SchemaEntry(yyvsp[-3].id, yyvsp[-2].dataType, yyvsp[-2].length, true);
                            yyval.schemaEntry.entrykind = SchemaEntry::NORMAL_KIND;
                        ;
    break;}
case 25:
#line 169 "parser.y"
{
                            yyval.schemaEntry.primaryKeyList = yyvsp[-1].columnList;
                            yyval.schemaEntry.entrykind = SchemaEntry::PRIMARY_KIND;
                        ;
    break;}
case 26:
#line 174 "parser.y"
{
                            yyval.schemaEntry.foreignKey = yyvsp[-6].id;
                            yyval.schemaEntry.foreignAttr = Attr(yyvsp[-3].id, yyvsp[-1].id);
                            yyval.schemaEntry.entrykind = SchemaEntry::FOREIGN_KIND;
                        ;
    break;}
case 27:
#line 182 "parser.y"
{
                            yyval.dataType = "int";
                            yyval.length = yyvsp[-1].length;
                        ;
    break;}
case 28:
#line 187 "parser.y"
{
                            yyval.dataType = "varchar";
                            yyval.length = yyvsp[-1].length;
                        ;
    break;}
case 29:
#line 192 "parser.y"
{
                            yyval.dataType = "date";
                        ;
    break;}
case 30:
#line 196 "parser.y"
{
                            yyval.dataType = "float";
                        ;
    break;}
case 31:
#line 202 "parser.y"
{
                            yyval.valuesList.clear();
                            yyval.valuesList.push_back(yyvsp[-1].values);
                        ;
    break;}
case 32:
#line 207 "parser.y"
{
                            yyval.valuesList.push_back(yyvsp[-1].values);
                        ;
    break;}
case 33:
#line 213 "parser.y"
{
                            yyval.values.clear();
                            yyval.values.push_back(yyvsp[0].value);
                        ;
    break;}
case 34:
#line 218 "parser.y"
{
                            yyval.values.push_back(yyvsp[0].value);
                        ;
    break;}
case 35:
#line 224 "parser.y"
{
                            yyval.value = Value(Value::VALUE_INT_TYPE, yyvsp[0].length, "");
                        ;
    break;}
case 36:
#line 228 "parser.y"
{
                            yyval.value = Value(Value::VALUE_STRING_TYPE, yyvsp[-1].length, yyvsp[0].literal);
                        ;
    break;}
case 37:
#line 232 "parser.y"
{
                            yyval.value = Value(Value::VALUE_NULL_TYPE, 0, "");
                        ;
    break;}
case 38:
#line 238 "parser.y"
{
                            yyval.condList.clear();
                            yyval.condList.push_back(yyvsp[0].cond);
                        ;
    break;}
case 39:
#line 243 "parser.y"
{
                            yyval.condList.push_back(yyvsp[0].cond);
                        ;
    break;}
case 40:
#line 249 "parser.y"
{
                            yyval.cond = Condition(Condition::COL_EXPR_TYPE);
                            yyval.cond.col = yyvsp[-2].col;
                            yyval.cond.optr = yyvsp[-1].optr;
                            yyval.cond.expr = yyvsp[0].expr;
                        ;
    break;}
case 41:
#line 256 "parser.y"
{
                			yyval.cond = Condition(Condition::COL_LIKE_VALUE_TYPE);
                			yyval.cond.col = yyvsp[-2].col;
                			yyval.cond.value = yyvsp[0].value;
                		;
    break;}
case 42:
#line 262 "parser.y"
{
                            yyval.cond = Condition(Condition::COL_IS_NULL_TYPE);
                            yyval.cond.col = yyvsp[-2].col;
                        ;
    break;}
case 43:
#line 267 "parser.y"
{
                            yyval.cond = Condition(Condition::COL_IS_NOT_NULL_TYPE);
                            yyval.cond.col = yyvsp[-3].col;
                        ;
    break;}
case 44:
#line 274 "parser.y"
{
                            yyval.col = Attr("", yyvsp[0].id);
                        ;
    break;}
case 45:
#line 278 "parser.y"
{
                            yyval.col = Attr(yyvsp[-2].id, yyvsp[0].id);
                        ;
    break;}
case 46:
#line 284 "parser.y"
{
                            yyval.optr = "=";
                        ;
    break;}
case 47:
#line 288 "parser.y"
{
                            yyval.optr = "<>";
                        ;
    break;}
case 48:
#line 292 "parser.y"
{
                            yyval.optr = "<=";
                        ;
    break;}
case 49:
#line 296 "parser.y"
{
                            yyval.optr = ">=";
                        ;
    break;}
case 50:
#line 300 "parser.y"
{
                            yyval.optr = "<";
                        ;
    break;}
case 51:
#line 304 "parser.y"
{
                            yyval.optr = ">";
                        ;
    break;}
case 52:
#line 310 "parser.y"
{
                            yyval.expr = Expr();
                            yyval.expr.dataType = Expr::VALUE_EXPR_TYPE;
                            yyval.expr.value = yyvsp[0].value;
                        ;
    break;}
case 53:
#line 316 "parser.y"
{
                            yyval.expr = Expr();
                            yyval.expr.dataType = Expr::COL_EXPR_TYPE;
                            yyval.expr.col = yyvsp[0].col;
                        ;
    break;}
case 54:
#line 324 "parser.y"
{
                            yyval.setList.clear();
                            yyval.setList.push_back(Set(yyvsp[-2].id, yyvsp[0].value));
                        ;
    break;}
case 55:
#line 329 "parser.y"
{
                            yyval.setList.push_back(Set(yyvsp[-2].id, yyvsp[0].value));
                        ;
    break;}
case 56:
#line 335 "parser.y"
{
                            yyval.selectorList.clear();
                            yyval.selectorList.push_back(Selector(Selector::SELECTOR_ALL_TYPE));
                        ;
    break;}
case 57:
#line 340 "parser.y"
{
                            yyval.selectorList.push_back(yyvsp[0].selector);
                        ;
    break;}
case 58:
#line 344 "parser.y"
{
            				yyval.selectorList.clear();
            				yyval.selectorList.push_back(yyvsp[0].selector);
            			;
    break;}
case 59:
#line 351 "parser.y"
{
                            yyval.selector = Selector(Selector::SELECTOR_COL_TYPE, yyvsp[0].col);                      
                        ;
    break;}
case 60:
#line 355 "parser.y"
{
                            yyval.selector = Selector(Selector::SELECTOR_SUM_TYPE, yyvsp[-1].col);
                        ;
    break;}
case 61:
#line 359 "parser.y"
{
                            yyval.selector = Selector(Selector::SELECTOR_AVG_TYPE, yyvsp[-1].col);
                        ;
    break;}
case 62:
#line 363 "parser.y"
{
                            yyval.selector = Selector(Selector::SELECTOR_MAX_TYPE, yyvsp[-1].col);
                        ;
    break;}
case 63:
#line 367 "parser.y"
{
                            yyval.selector = Selector(Selector::SELECTOR_MIN_TYPE, yyvsp[-1].col);
                        ;
    break;}
case 64:
#line 373 "parser.y"
{
                            yyval.tableList.clear();
                            yyval.tableList.push_back(yyvsp[0].id);
                        ;
    break;}
case 65:
#line 378 "parser.y"
{
                            yyval.tableList.push_back(yyvsp[0].id);
                        ;
    break;}
case 66:
#line 384 "parser.y"
{
                            yyval.columnList.clear();
                            yyval.columnList.push_back(yyvsp[0].id);
                        ;
    break;}
case 67:
#line 389 "parser.y"
{
                            yyval.columnList.push_back(yyvsp[0].id);
                        ;
    break;}
case 68:
#line 395 "parser.y"
{
                            yyval.id = yyvsp[0].id;
                        ;
    break;}
case 69:
#line 401 "parser.y"
{
                            yyval.id = yyvsp[0].id;
                        ;
    break;}
case 70:
#line 407 "parser.y"
{
                            yyval.id = yyvsp[0].id;
                        ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 543 "/usr/local/share/bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;

 yyacceptlab:
  /* YYACCEPT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 0;

 yyabortlab:
  /* YYABORT comes here.  */
  if (yyfree_stacks)
    {
      free (yyss);
      free (yyvs);
#ifdef YYLSP_NEEDED
      free (yyls);
#endif
    }
  return 1;
}
#line 413 "parser.y"


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

