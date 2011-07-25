#include <AD/symbolic/atom.h>

SymbolicAtom:: SymbolicAtom(const char * s) : SymbolicString(s) {}
SymbolicAtom:: SymbolicAtom(const String& s) : SymbolicString(s) {}
SymbolicAtom::~SymbolicAtom() {}

Bool SymbolicAtom::unify (SymbolicExpr *, SymbolicUnifier&) { return false; }
SymbolicExpr *SymbolicAtom::eval  (SymbolicEnvironment&) const { return 0; }

