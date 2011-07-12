///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "documentation.pcc".
///////////////////////////////////////////////////////////////////////////////

#define PROP_PARSER_USED
#include <propdefs.h>
#line 1 "documentation.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the source documentation features.
//
///////////////////////////////////////////////////////////////////////////////

#include <cstring>
#include <cstdlib>
#include "parser.h"

void PropParser::emit_doc()
{
  doc.emit(lexbuf.text(), lexbuf.length());
}
#line 15 "documentation.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 0
Number of ifs generated      = 0
Number of switches generated = 0
Number of labels             = 0
Number of gotos              = 0
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
