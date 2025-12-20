/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "syntax_analyzer.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#include "syntax_tree.h"

// external functions from lex
extern int yylex();
extern int yyparse();
extern int yyrestart();
extern FILE * yyin;

// external variables from lexical_analyzer module
extern int lines;
extern char * yytext;
extern int pos_end;
extern int pos_start;

// Global syntax tree
syntax_tree *gt;

// Error reporting
void yyerror(const char *s);

// Helper functions written for you with love
syntax_tree_node *node(const char *node_name, int children_num, ...);

#line 101 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "syntax_analyzer.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ERROR = 3,                      /* ERROR  */
  YYSYMBOL_ADD = 4,                        /* ADD  */
  YYSYMBOL_SUB = 5,                        /* SUB  */
  YYSYMBOL_MUL = 6,                        /* MUL  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_LT = 8,                         /* LT  */
  YYSYMBOL_LTE = 9,                        /* LTE  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_GTE = 11,                       /* GTE  */
  YYSYMBOL_EQ = 12,                        /* EQ  */
  YYSYMBOL_NEQ = 13,                       /* NEQ  */
  YYSYMBOL_ASSIGN = 14,                    /* ASSIGN  */
  YYSYMBOL_SEMICOLON = 15,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 16,                     /* COMMA  */
  YYSYMBOL_LPARENTHESE = 17,               /* LPARENTHESE  */
  YYSYMBOL_RPARENTHESE = 18,               /* RPARENTHESE  */
  YYSYMBOL_LBRACKET = 19,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 20,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 21,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_ELSE = 23,                      /* ELSE  */
  YYSYMBOL_IF = 24,                        /* IF  */
  YYSYMBOL_INT = 25,                       /* INT  */
  YYSYMBOL_RETURN = 26,                    /* RETURN  */
  YYSYMBOL_VOID = 27,                      /* VOID  */
  YYSYMBOL_WHILE = 28,                     /* WHILE  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_INTEGER = 30,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 31,                     /* FLOAT  */
  YYSYMBOL_FLOATPOINT = 32,                /* FLOATPOINT  */
  YYSYMBOL_YYACCEPT = 33,                  /* $accept  */
  YYSYMBOL_program = 34,                   /* program  */
  YYSYMBOL_35_declaration_list = 35,       /* declaration-list  */
  YYSYMBOL_declaration = 36,               /* declaration  */
  YYSYMBOL_37_var_declaration = 37,        /* var-declaration  */
  YYSYMBOL_38_type_specifier = 38,         /* type-specifier  */
  YYSYMBOL_39_fun_declaration = 39,        /* fun-declaration  */
  YYSYMBOL_params = 40,                    /* params  */
  YYSYMBOL_41_param_list = 41,             /* param-list  */
  YYSYMBOL_param = 42,                     /* param  */
  YYSYMBOL_43_compound_stmt = 43,          /* compound-stmt  */
  YYSYMBOL_44_local_declarations = 44,     /* local-declarations  */
  YYSYMBOL_45_statement_list = 45,         /* statement-list  */
  YYSYMBOL_statement = 46,                 /* statement  */
  YYSYMBOL_47_expression_stmt = 47,        /* expression-stmt  */
  YYSYMBOL_48_selection_stmt = 48,         /* selection-stmt  */
  YYSYMBOL_49_iteration_stmt = 49,         /* iteration-stmt  */
  YYSYMBOL_50_return_stmt = 50,            /* return-stmt  */
  YYSYMBOL_expression = 51,                /* expression  */
  YYSYMBOL_var = 52,                       /* var  */
  YYSYMBOL_53_simple_expression = 53,      /* simple-expression  */
  YYSYMBOL_relop = 54,                     /* relop  */
  YYSYMBOL_55_additive_expression = 55,    /* additive-expression  */
  YYSYMBOL_addop = 56,                     /* addop  */
  YYSYMBOL_term = 57,                      /* term  */
  YYSYMBOL_mulop = 58,                     /* mulop  */
  YYSYMBOL_factor = 59,                    /* factor  */
  YYSYMBOL_integer = 60,                   /* integer  */
  YYSYMBOL_float = 61,                     /* float  */
  YYSYMBOL_call = 62,                      /* call  */
  YYSYMBOL_args = 63,                      /* args  */
  YYSYMBOL_64_arg_list = 64                /* arg-list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  10
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   102

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   287


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    81,    81,    84,    85,    88,    89,    92,    93,    96,
      97,    98,   101,   104,   105,   108,   109,   112,   113,   116,
     119,   120,   123,   124,   127,   128,   129,   130,   131,   134,
     135,   138,   139,   142,   145,   146,   149,   150,   153,   154,
     157,   158,   161,   162,   163,   164,   165,   166,   169,   170,
     173,   174,   177,   178,   181,   182,   185,   186,   187,   188,
     189,   192,   194,   196,   199,   200,   203,   204
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ERROR", "ADD", "SUB",
  "MUL", "DIV", "LT", "LTE", "GT", "GTE", "EQ", "NEQ", "ASSIGN",
  "SEMICOLON", "COMMA", "LPARENTHESE", "RPARENTHESE", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "ELSE", "IF", "INT", "RETURN", "VOID",
  "WHILE", "ID", "INTEGER", "FLOAT", "FLOATPOINT", "$accept", "program",
  "declaration-list", "declaration", "var-declaration", "type-specifier",
  "fun-declaration", "params", "param-list", "param", "compound-stmt",
  "local-declarations", "statement-list", "statement", "expression-stmt",
  "selection-stmt", "iteration-stmt", "return-stmt", "expression", "var",
  "simple-expression", "relop", "additive-expression", "addop", "term",
  "mulop", "factor", "integer", "float", "call", "args", "arg-list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-93)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-15)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -18,   -93,   -93,   -93,    10,   -18,   -93,   -93,     4,   -93,
     -93,   -93,    33,   -93,    43,   -14,    38,    31,    57,    60,
     -93,    58,    61,    56,   -18,    64,    62,   -93,   -93,   -93,
     -93,   -93,   -18,   -93,    55,    15,     3,   -93,   -15,   -93,
      66,    -9,    69,    52,   -93,   -93,   -93,   -93,   -93,   -93,
     -93,   -93,    70,    67,   -93,    54,    19,   -93,   -93,   -93,
     -93,    71,   -15,   -93,    72,   -15,   -15,   -15,   -93,   -15,
     -93,   -93,   -93,   -93,   -93,   -93,   -93,   -93,   -15,   -15,
     -93,   -93,   -15,   -93,    73,   -93,    74,   -93,    75,    78,
      76,   -93,   -93,    68,    19,   -93,    25,    25,   -93,   -15,
     -93,    65,   -93,   -93,    25,   -93
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     9,    11,    10,     0,     2,     4,     5,     0,     6,
       1,     3,     0,     7,     0,     0,    11,     0,     0,    13,
      16,     0,    17,     0,     0,     0,     0,    21,    12,    15,
       8,    18,    23,    20,     0,     0,     0,    30,     0,    19,
       0,     0,     0,    38,    61,    62,    25,    22,    24,    26,
      27,    28,     0,    57,    37,    41,    49,    53,    59,    60,
      58,     0,     0,    34,     0,     0,    65,     0,    29,     0,
      50,    51,    42,    43,    44,    45,    46,    47,     0,     0,
      54,    55,     0,    56,     0,    35,     0,    67,     0,    64,
       0,    36,    57,    40,    48,    52,     0,     0,    63,     0,
      39,    31,    33,    66,     0,    32
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -93,   -93,   -93,    85,    63,   -13,   -93,   -93,   -93,    77,
      79,   -93,   -93,   -92,   -93,   -93,   -93,   -93,   -38,   -44,
     -93,   -93,    20,   -93,    18,   -93,    17,   -93,   -93,   -93,
     -93,   -93
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     6,     7,     8,     9,    18,    19,    20,
      46,    32,    35,    47,    48,    49,    50,    51,    52,    53,
      54,    78,    55,    79,    56,    82,    57,    58,    59,    60,
      88,    89
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      61,    17,    38,    64,   101,   102,    63,     1,    38,     2,
      10,    17,   105,     3,    43,    44,    21,    45,    13,    34,
      43,    44,    15,    45,    84,    80,    81,    86,    87,    90,
      37,    91,    38,    12,    92,    92,    27,    39,    92,    40,
      37,    41,    38,    42,    43,    44,    27,    45,    13,    40,
      14,    41,    15,    42,    43,    44,   -14,    45,    70,    71,
      22,   103,    72,    73,    74,    75,    76,    77,     1,    66,
      16,    67,    70,    71,     3,    23,    24,    27,    25,    30,
      26,    69,    31,    62,    36,    68,    65,    85,   104,    83,
      11,    96,    97,    98,    99,    33,   100,    94,    93,    95,
       0,    29,    28
};

static const yytype_int8 yycheck[] =
{
      38,    14,    17,    41,    96,    97,    15,    25,    17,    27,
       0,    24,   104,    31,    29,    30,    30,    32,    15,    32,
      29,    30,    19,    32,    62,     6,     7,    65,    66,    67,
      15,    69,    17,    29,    78,    79,    21,    22,    82,    24,
      15,    26,    17,    28,    29,    30,    21,    32,    15,    24,
      17,    26,    19,    28,    29,    30,    18,    32,     4,     5,
      29,    99,     8,     9,    10,    11,    12,    13,    25,    17,
      27,    19,     4,     5,    31,    18,    16,    21,    20,    15,
      19,    14,    20,    17,    29,    15,    17,    15,    23,    18,
       5,    18,    18,    18,    16,    32,    20,    79,    78,    82,
      -1,    24,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    27,    31,    34,    35,    36,    37,    38,    39,
       0,    36,    29,    15,    17,    19,    27,    38,    40,    41,
      42,    30,    29,    18,    16,    20,    19,    21,    43,    42,
      15,    20,    44,    37,    38,    45,    29,    15,    17,    22,
      24,    26,    28,    29,    30,    32,    43,    46,    47,    48,
      49,    50,    51,    52,    53,    55,    57,    59,    60,    61,
      62,    51,    17,    15,    51,    17,    17,    19,    15,    14,
       4,     5,     8,     9,    10,    11,    12,    13,    54,    56,
       6,     7,    58,    18,    51,    15,    51,    51,    63,    64,
      51,    51,    52,    55,    57,    59,    18,    18,    18,    16,
      20,    46,    46,    51,    23,    46
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    37,    38,
      38,    38,    39,    40,    40,    41,    41,    42,    42,    43,
      44,    44,    45,    45,    46,    46,    46,    46,    46,    47,
      47,    48,    48,    49,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    59,
      59,    60,    61,    62,    63,    63,    64,    64
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     3,     6,     1,
       1,     1,     6,     1,     1,     3,     1,     2,     4,     4,
       2,     0,     2,     0,     1,     1,     1,     1,     1,     2,
       1,     5,     7,     5,     2,     3,     3,     1,     1,     4,
       3,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     4,     1,     0,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: declaration-list  */
#line 81 "syntax_analyzer.y"
                                 {(yyval.node) = node( "program", 1, (yyvsp[0].node)); gt->root = (yyval.node);}
#line 1224 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 3: /* declaration-list: declaration-list declaration  */
#line 84 "syntax_analyzer.y"
                                                             {(yyval.node) = node( "declaration-list", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1230 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 4: /* declaration-list: declaration  */
#line 85 "syntax_analyzer.y"
                                                            {(yyval.node) = node( "declaration-list", 1, (yyvsp[0].node));}
#line 1236 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 5: /* declaration: var-declaration  */
#line 88 "syntax_analyzer.y"
                                {(yyval.node) = node( "declaration", 1, (yyvsp[0].node));}
#line 1242 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 6: /* declaration: fun-declaration  */
#line 89 "syntax_analyzer.y"
                                                {(yyval.node) = node( "declaration", 1, (yyvsp[0].node));}
#line 1248 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 7: /* var-declaration: type-specifier ID SEMICOLON  */
#line 92 "syntax_analyzer.y"
                                                    {(yyval.node) = node( "var-declaration", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1254 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 8: /* var-declaration: type-specifier ID LBRACKET INTEGER RBRACKET SEMICOLON  */
#line 93 "syntax_analyzer.y"
                                                                              {(yyval.node) = node( "var-declaration", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1260 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 9: /* type-specifier: INT  */
#line 96 "syntax_analyzer.y"
                            {(yyval.node) = node( "type-specifier", 1, (yyvsp[0].node));}
#line 1266 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 10: /* type-specifier: FLOAT  */
#line 97 "syntax_analyzer.y"
                                              { (yyval.node) = node( "type-specifier", 1, (yyvsp[0].node)); }
#line 1272 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 11: /* type-specifier: VOID  */
#line 98 "syntax_analyzer.y"
                                             {(yyval.node) = node( "type-specifier", 1, (yyvsp[0].node));}
#line 1278 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 12: /* fun-declaration: type-specifier ID LPARENTHESE params RPARENTHESE compound-stmt  */
#line 101 "syntax_analyzer.y"
                                                                                       {(yyval.node) = node( "fun-declaration", 6, (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1284 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 13: /* params: param-list  */
#line 104 "syntax_analyzer.y"
                           {(yyval.node) = node( "params", 1, (yyvsp[0].node));}
#line 1290 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 14: /* params: VOID  */
#line 105 "syntax_analyzer.y"
                             {(yyval.node) = node( "params", 1, (yyvsp[0].node));}
#line 1296 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 15: /* param-list: param-list COMMA param  */
#line 108 "syntax_analyzer.y"
                                               {(yyval.node) = node( "param-list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1302 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 16: /* param-list: param  */
#line 109 "syntax_analyzer.y"
                                      {(yyval.node) = node( "param-list", 1, (yyvsp[0].node));}
#line 1308 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 17: /* param: type-specifier ID  */
#line 112 "syntax_analyzer.y"
                                  {(yyval.node) = node( "param", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1314 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 18: /* param: type-specifier ID LBRACKET RBRACKET  */
#line 113 "syntax_analyzer.y"
                                                            {(yyval.node) = node( "param", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1320 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 19: /* compound-stmt: LBRACE local-declarations statement-list RBRACE  */
#line 116 "syntax_analyzer.y"
                                                                        {(yyval.node) = node( "compound-stmt", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1326 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 20: /* local-declarations: local-declarations var-declaration  */
#line 119 "syntax_analyzer.y"
                                                                   {(yyval.node) = node( "local-declarations", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1332 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 21: /* local-declarations: %empty  */
#line 120 "syntax_analyzer.y"
        {(yyval.node) = node( "local-declarations",0);}
#line 1338 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 22: /* statement-list: statement-list statement  */
#line 123 "syntax_analyzer.y"
                                                 {(yyval.node) = node( "statement-list", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1344 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 23: /* statement-list: %empty  */
#line 124 "syntax_analyzer.y"
        {(yyval.node) = node("statement-list", 0);}
#line 1350 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 24: /* statement: expression-stmt  */
#line 127 "syntax_analyzer.y"
                                {(yyval.node) = node("statement", 1, (yyvsp[0].node));}
#line 1356 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 25: /* statement: compound-stmt  */
#line 128 "syntax_analyzer.y"
                                              {(yyval.node) = node("statement", 1, (yyvsp[0].node));}
#line 1362 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 26: /* statement: selection-stmt  */
#line 129 "syntax_analyzer.y"
                                               {(yyval.node) = node("statement", 1, (yyvsp[0].node));}
#line 1368 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 27: /* statement: iteration-stmt  */
#line 130 "syntax_analyzer.y"
                                               {(yyval.node) = node("statement", 1, (yyvsp[0].node));}
#line 1374 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 28: /* statement: return-stmt  */
#line 131 "syntax_analyzer.y"
                                            {(yyval.node) = node("statement", 1, (yyvsp[0].node));}
#line 1380 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 29: /* expression-stmt: expression SEMICOLON  */
#line 134 "syntax_analyzer.y"
                                             {(yyval.node) = node("expression-stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1386 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 30: /* expression-stmt: SEMICOLON  */
#line 135 "syntax_analyzer.y"
                                                  {(yyval.node) = node("expression-stmt", 1, (yyvsp[0].node));}
#line 1392 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 31: /* selection-stmt: IF LPARENTHESE expression RPARENTHESE statement  */
#line 138 "syntax_analyzer.y"
                                                                        {(yyval.node) = node("selection-stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1398 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 32: /* selection-stmt: IF LPARENTHESE expression RPARENTHESE statement ELSE statement  */
#line 139 "syntax_analyzer.y"
                                                                                                       {(yyval.node) = node("selection-stmt", 7, (yyvsp[-6].node), (yyvsp[-5].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1404 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 33: /* iteration-stmt: WHILE LPARENTHESE expression RPARENTHESE statement  */
#line 142 "syntax_analyzer.y"
                                                                           {(yyval.node) = node("iteration-stmt", 5, (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1410 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 34: /* return-stmt: RETURN SEMICOLON  */
#line 145 "syntax_analyzer.y"
                                 {(yyval.node) = node("return-stmt", 2, (yyvsp[-1].node), (yyvsp[0].node));}
#line 1416 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 35: /* return-stmt: RETURN expression SEMICOLON  */
#line 146 "syntax_analyzer.y"
                                                            {(yyval.node) = node("return-stmt", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1422 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 36: /* expression: var ASSIGN expression  */
#line 149 "syntax_analyzer.y"
                                      {(yyval.node) = node("expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1428 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 37: /* expression: simple-expression  */
#line 150 "syntax_analyzer.y"
                                                  {(yyval.node) = node("expression", 1, (yyvsp[0].node));}
#line 1434 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 38: /* var: ID  */
#line 153 "syntax_analyzer.y"
           {(yyval.node) = node("var", 1, (yyvsp[0].node));}
#line 1440 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 39: /* var: ID LBRACKET expression RBRACKET  */
#line 154 "syntax_analyzer.y"
                                                        {(yyval.node) = node("var", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1446 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 40: /* simple-expression: additive-expression relop additive-expression  */
#line 157 "syntax_analyzer.y"
                                                                      {(yyval.node) = node("simple-expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1452 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 41: /* simple-expression: additive-expression  */
#line 158 "syntax_analyzer.y"
                                                                    {(yyval.node) = node("simple-expression", 1, (yyvsp[0].node));}
#line 1458 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 42: /* relop: LT  */
#line 161 "syntax_analyzer.y"
                   {(yyval.node) = node("relop", 1, (yyvsp[0].node));}
#line 1464 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 43: /* relop: LTE  */
#line 162 "syntax_analyzer.y"
                            {(yyval.node) = node("relop", 1, (yyvsp[0].node));}
#line 1470 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 44: /* relop: GT  */
#line 163 "syntax_analyzer.y"
                           {(yyval.node) = node("relop", 1, (yyvsp[0].node));}
#line 1476 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 45: /* relop: GTE  */
#line 164 "syntax_analyzer.y"
                            {(yyval.node) = node("relop", 1, (yyvsp[0].node));}
#line 1482 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 46: /* relop: EQ  */
#line 165 "syntax_analyzer.y"
                           {(yyval.node) = node("relop", 1, (yyvsp[0].node));}
#line 1488 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 47: /* relop: NEQ  */
#line 166 "syntax_analyzer.y"
                            {(yyval.node) = node("relop", 1, (yyvsp[0].node));}
#line 1494 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 48: /* additive-expression: additive-expression addop term  */
#line 169 "syntax_analyzer.y"
                                                       {(yyval.node) = node("additive-expression", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1500 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 49: /* additive-expression: term  */
#line 170 "syntax_analyzer.y"
                                                     {(yyval.node) = node("additive-expression", 1, (yyvsp[0].node));}
#line 1506 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 50: /* addop: ADD  */
#line 173 "syntax_analyzer.y"
                    {(yyval.node) = node("addop", 1, (yyvsp[0].node));}
#line 1512 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 51: /* addop: SUB  */
#line 174 "syntax_analyzer.y"
                            {(yyval.node) = node("addop", 1, (yyvsp[0].node));}
#line 1518 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 52: /* term: term mulop factor  */
#line 177 "syntax_analyzer.y"
                          {(yyval.node) = node("term", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1524 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 53: /* term: factor  */
#line 178 "syntax_analyzer.y"
                       {(yyval.node) = node("term", 1, (yyvsp[0].node));}
#line 1530 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 54: /* mulop: MUL  */
#line 181 "syntax_analyzer.y"
                    {(yyval.node) = node("mulop", 1, (yyvsp[0].node));}
#line 1536 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 55: /* mulop: DIV  */
#line 182 "syntax_analyzer.y"
                            {(yyval.node) = node("mulop", 1, (yyvsp[0].node));}
#line 1542 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 56: /* factor: LPARENTHESE expression RPARENTHESE  */
#line 185 "syntax_analyzer.y"
                                                   {(yyval.node) = node("factor", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1548 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 57: /* factor: var  */
#line 186 "syntax_analyzer.y"
                            {(yyval.node) = node("factor", 1, (yyvsp[0].node));}
#line 1554 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 58: /* factor: call  */
#line 187 "syntax_analyzer.y"
                             {(yyval.node) = node("factor", 1, (yyvsp[0].node));}
#line 1560 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 59: /* factor: integer  */
#line 188 "syntax_analyzer.y"
                                {(yyval.node) = node("factor", 1, (yyvsp[0].node));}
#line 1566 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 60: /* factor: float  */
#line 189 "syntax_analyzer.y"
                              {(yyval.node) = node("factor", 1, (yyvsp[0].node));}
#line 1572 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 61: /* integer: INTEGER  */
#line 192 "syntax_analyzer.y"
                  {(yyval.node) = node("integer", 1, (yyvsp[0].node));}
#line 1578 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 62: /* float: FLOATPOINT  */
#line 194 "syntax_analyzer.y"
                     {(yyval.node) = node("float", 1, (yyvsp[0].node));}
#line 1584 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 63: /* call: ID LPARENTHESE args RPARENTHESE  */
#line 196 "syntax_analyzer.y"
                                        {(yyval.node) = node("call", 4, (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1590 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 64: /* args: arg-list  */
#line 199 "syntax_analyzer.y"
                 {(yyval.node) = node("args", 1, (yyvsp[0].node));}
#line 1596 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 65: /* args: %empty  */
#line 200 "syntax_analyzer.y"
                {(yyval.node) = node("args", 0);}
#line 1602 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 66: /* arg-list: arg-list COMMA expression  */
#line 203 "syntax_analyzer.y"
                                          {(yyval.node) = node("arg-list", 3, (yyvsp[-2].node), (yyvsp[-1].node), (yyvsp[0].node));}
#line 1608 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;

  case 67: /* arg-list: expression  */
#line 204 "syntax_analyzer.y"
                                   {(yyval.node) = node("arg-list", 1, (yyvsp[0].node));}
#line 1614 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"
    break;


#line 1618 "/home/skapeach/Desktop/2025ustc-jianmu-compiler/build/src/parser/syntax_analyzer.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 207 "syntax_analyzer.y"


/// 错误报告函数
void yyerror(const char * s)
{
    fprintf(stderr, "error at line %d column %d: %s (unexpected token: %s)\n", 
            lines, pos_start, s, yytext);
}

/// Parse input from file `input_path`, and prints the parsing results
/// to stdout.  If input_path is NULL, read from stdin.
///
/// This function initializes essential states before running yyparse().
syntax_tree *parse(const char *input_path)
{
    if (input_path != NULL) {
        if (!(yyin = fopen(input_path, "r"))) {
            fprintf(stderr, "[ERR] Open input file %s failed.\n", input_path);
            exit(1);
        }
    } else {
        yyin = stdin;
    }

    lines = pos_start = pos_end = 1;
    gt = new_syntax_tree();
    yyrestart(yyin);
    yyparse();
    return gt;
}

/// A helper function to quickly construct a tree node.
///
/// e.g. $$ = node("program", 1, $1);
syntax_tree_node *node(const char *name, int children_num, ...)
{
    syntax_tree_node *p = new_syntax_tree_node(name);
    syntax_tree_node *child;
    // 这里表示 epsilon结点是通过 children_num == 0 来判断的
    if (children_num == 0) {
        child = new_syntax_tree_node("epsilon");
        syntax_tree_add_child(p, child);
    } else {
        va_list ap;
        va_start(ap, children_num);
        for (int i = 0; i < children_num; ++i) {
            child = va_arg(ap, syntax_tree_node *);
            syntax_tree_add_child(p, child);
        }
        va_end(ap);
    }
    return p;
}
