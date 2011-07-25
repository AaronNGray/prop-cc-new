#include <AD/symbolic/string.h>

SymbolicString:: SymbolicString() {}
SymbolicString:: SymbolicString(const char * s) : string(s) {}
SymbolicString:: SymbolicString(const String& s) : string(s) {}
SymbolicString::~SymbolicString() {}

Bool SymbolicString::unify (SymbolicExpr *, SymbolicUnifier&) { return false; }
SymbolicExpr *SymbolicString::eval  (SymbolicEnvironment&) const { return 0; }

