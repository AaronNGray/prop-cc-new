///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "grsgen.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "grsgen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  This file implements the graph rewriting system compiler.
//
///////////////////////////////////////////////////////////////////////////////

#include "ir.h"
#include "ast.h"
#include "type.h"
#include "grsgen.h"

#line 12 "grsgen.pcc"
#line 12 "grsgen.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype GraphRewritingRule
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype GRSPat
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype GRSConclusion
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<GraphRewritingRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<GRSPat>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Interface specification of datatype List<GRSConclusion>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype GraphRewritingRule
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"
a_GraphRewritingRule::a_GraphRewritingRule (GRSPat x_lhs, GRSConclusions x_rhs)
 : lhs(x_lhs), rhs(x_rhs)
{
}
a_GraphRewritingRule * GRSrule (GRSPat x_lhs, GRSConclusions x_rhs)
{
  return new a_GraphRewritingRule (x_lhs, x_rhs);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype GRSPat
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"
GRSPat_EDGEgpat::GRSPat_EDGEgpat (Id x_1, a_List<Pat> *  x_2)
 : a_GRSPat(tag_EDGEgpat), _1(x_1), _2(x_2)
{
}
a_GRSPat * EDGEgpat (Id x_1, a_List<Pat> *  x_2)
{
  return new GRSPat_EDGEgpat (x_1, x_2);
}
GRSPat_GUARDgpat::GRSPat_GUARDgpat (Exp x_GUARDgpat)
 : a_GRSPat(tag_GUARDgpat), GUARDgpat(x_GUARDgpat)
{
}
a_GRSPat * GUARDgpat (Exp x_GUARDgpat)
{
  return new GRSPat_GUARDgpat (x_GUARDgpat);
}
GRSPat_NOTgpat::GRSPat_NOTgpat (GRSPat x_NOTgpat)
 : a_GRSPat(tag_NOTgpat), NOTgpat(x_NOTgpat)
{
}
a_GRSPat * NOTgpat (GRSPat x_NOTgpat)
{
  return new GRSPat_NOTgpat (x_NOTgpat);
}
GRSPat_ANDgpat::GRSPat_ANDgpat (GRSPat x_1, GRSPat x_2)
 : a_GRSPat(tag_ANDgpat), _1(x_1), _2(x_2)
{
}
a_GRSPat * ANDgpat (GRSPat x_1, GRSPat x_2)
{
  return new GRSPat_ANDgpat (x_1, x_2);
}
GRSPat_ORgpat::GRSPat_ORgpat (GRSPat x_1, GRSPat x_2)
 : a_GRSPat(tag_ORgpat), _1(x_1), _2(x_2)
{
}
a_GRSPat * ORgpat (GRSPat x_1, GRSPat x_2)
{
  return new GRSPat_ORgpat (x_1, x_2);
}
GRSPat_FORALLgpat::GRSPat_FORALLgpat (Id x_1, GRSPat x_2)
 : a_GRSPat(tag_FORALLgpat), _1(x_1), _2(x_2)
{
}
a_GRSPat * FORALLgpat (Id x_1, GRSPat x_2)
{
  return new GRSPat_FORALLgpat (x_1, x_2);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype GRSConclusion
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"
GRSConclusion_ADDEDGEaction::GRSConclusion_ADDEDGEaction (Id x_1, a_List<Exp> *  x_2)
 : a_GRSConclusion(tag_ADDEDGEaction), _1(x_1), _2(x_2)
{
}
a_GRSConclusion * ADDEDGEaction (Id x_1, a_List<Exp> *  x_2)
{
  return new GRSConclusion_ADDEDGEaction (x_1, x_2);
}
GRSConclusion_DELETEEDGEaction::GRSConclusion_DELETEEDGEaction (Id x_1, a_List<Exp> *  x_2)
 : a_GRSConclusion(tag_DELETEEDGEaction), _1(x_1), _2(x_2)
{
}
a_GRSConclusion * DELETEEDGEaction (Id x_1, a_List<Exp> *  x_2)
{
  return new GRSConclusion_DELETEEDGEaction (x_1, x_2);
}
GRSConclusion_ADDNODEaction::GRSConclusion_ADDNODEaction (Exp x_ADDNODEaction)
 : a_GRSConclusion(tag_ADDNODEaction), ADDNODEaction(x_ADDNODEaction)
{
}
a_GRSConclusion * ADDNODEaction (Exp x_ADDNODEaction)
{
  return new GRSConclusion_ADDNODEaction (x_ADDNODEaction);
}
GRSConclusion_DELETENODEaction::GRSConclusion_DELETENODEaction (Exp x_DELETENODEaction)
 : a_GRSConclusion(tag_DELETENODEaction), DELETENODEaction(x_DELETENODEaction)
{
}
a_GRSConclusion * DELETENODEaction (Exp x_DELETENODEaction)
{
  return new GRSConclusion_DELETENODEaction (x_DELETENODEaction);
}
GRSConclusion_EMBEDDEDaction::GRSConclusion_EMBEDDEDaction (a_List<Decl> *  x_EMBEDDEDaction)
 : a_GRSConclusion(tag_EMBEDDEDaction), EMBEDDEDaction(x_EMBEDDEDaction)
{
}
a_GRSConclusion * EMBEDDEDaction (a_List<Decl> *  x_EMBEDDEDaction)
{
  return new GRSConclusion_EMBEDDEDaction (x_EMBEDDEDaction);
}


///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<GraphRewritingRule>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<GraphRewritingRule>;
template a_List<GraphRewritingRule> * list_1_(GRSConclusion x_1, a_List<GRSConclusion> *  x_2);
template a_List<GraphRewritingRule> * list_1_(GRSConclusion x_list_1_);
template int boxed(const a_List<GraphRewritingRule> *);
template int untag(const a_List<GraphRewritingRule> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<GRSPat>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<GRSPat>;
template a_List<GRSPat> * list_1_(GraphRewritingRule x_1, a_List<GraphRewritingRule> *  x_2);
template a_List<GRSPat> * list_1_(GraphRewritingRule x_list_1_);
template int boxed(const a_List<GRSPat> *);
template int untag(const a_List<GRSPat> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

///////////////////////////////////////////////////////////////////////////////
//
// Instantiation of datatype List<GRSConclusion>
//
///////////////////////////////////////////////////////////////////////////////
#line 12 "grsgen.pcc"
#ifdef PROP_EXPLICIT_TEMPLATE_INSTANTIATION
template class a_List<GRSConclusion>;
template a_List<GRSConclusion> * list_1_(GRSPat x_1, a_List<GRSPat> *  x_2);
template a_List<GRSConclusion> * list_1_(GRSPat x_list_1_);
template int boxed(const a_List<GRSConclusion> *);
template int untag(const a_List<GRSConclusion> *);
#endif /* PROP_EXPLICIT_TEMPLATE_INSTANTIATION */

#line 15 "grsgen.pcc"
#line 15 "grsgen.pcc"


///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor for the graph rewriting compiler
//
///////////////////////////////////////////////////////////////////////////////

GraphRewritingCompiler::GraphRewritingCompiler() {}
GraphRewritingCompiler::~GraphRewritingCompiler() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a GRS.
//
///////////////////////////////////////////////////////////////////////////////

void GraphRewritingCompiler::gen_graph_rewriting_system
   ( Id name, LabTys args, GraphRewritingRules rules)
{
}
#line 36 "grsgen.pcc"
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
