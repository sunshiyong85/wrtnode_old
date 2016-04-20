FILE(REMOVE_RECURSE
  "lemon"
  "parser.h"
  "parser.out"
  "parser.c"
  "contrib/lemon"
  "CMakeFiles/jsonpath.dir/main.c.o"
  "CMakeFiles/jsonpath.dir/ast.c.o"
  "CMakeFiles/jsonpath.dir/lexer.c.o"
  "CMakeFiles/jsonpath.dir/parser.c.o"
  "CMakeFiles/jsonpath.dir/matcher.c.o"
  "jsonpath.pdb"
  "jsonpath"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang C)
  INCLUDE(CMakeFiles/jsonpath.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
