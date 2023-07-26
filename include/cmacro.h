#ifndef _C_MACRO_H__
#define _C_MACRO_H__

#define _ARG16(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, ...) _15
#define HAS_COMMA(...) _ARG16(__VA_ARGS__, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0)
#define _TRIGGER_PARENTHESIS_(...) ,

#define _ARGCNT1(...) 0
#define _ARGCNT0(...) _ARG16(__VA_ARGS__, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0)

#define NARGS(...) EXCONCAT(_ARGCNT,ISEMPTY(__VA_ARGS__))(__VA_ARGS__)
 
#define _ISEMPTY(_0, _1, _2, _3) HAS_COMMA(PASTE5(_IS_EMPTY_CASE_, _0, _1, _2, _3))
#define ISEMPTY(...) _ISEMPTY(						\
	/* test if there is just one argument, eventually an empty	\
	 * one */							\
	HAS_COMMA(__VA_ARGS__),						\
	/* test if _TRIGGER_PARENTHESIS_ together with the argument	\
	 * adds a comma */						\
	HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__),			\
	/* test if the argument together with a parenthesis		\
	 * adds a comma */						\
	HAS_COMMA(__VA_ARGS__ (/*empty*/)),				\
	/* test if placing it between _TRIGGER_PARENTHESIS_ and the	\
	 * parenthesis adds a comma */					\
	HAS_COMMA(_TRIGGER_PARENTHESIS_ __VA_ARGS__ (/*empty*/))	\
)

#define PASTE5(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define _IS_EMPTY_CASE_0001 ,

#define CONCAT(A, B) A ## B
#define EXCONCAT(A, B) CONCAT(A, B)

#endif
