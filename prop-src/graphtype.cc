///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "graphtype.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "graphtype.pcc"
///////////////////////////////////////////////////////////////////////////////
//
// This file implements the graph type generator
//
///////////////////////////////////////////////////////////////////////////////

#include "ast.h"
#include "graphtype.h"
#include "type.h"

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create a graph type definition.
//
///////////////////////////////////////////////////////////////////////////////

GraphTypeDef::GraphTypeDef
    (Id id, Inherits i, TyQual q, NodeDefs nodes, EdgeDefs edges, Decls b)
    : ClassDefinition(GRAPHTYPE_CLASS, id, 
#line 19 "graphtype.pcc"
#line 19 "graphtype.pcc"
nil_1_
#line 19 "graphtype.pcc"
#line 19 "graphtype.pcc"
,
	  add_inherit("GraphType",
#line 20 "graphtype.pcc"
#line 20 "graphtype.pcc"
nil_1_
#line 20 "graphtype.pcc"
#line 20 "graphtype.pcc"
,i,PUBLICscope,QUALvirtualdestr), q, b),
      node_defs(nodes), edge_defs(edges)
{
  add_type( id, 
#line 23 "graphtype.pcc"
#line 23 "graphtype.pcc"
nil_1_
#line 23 "graphtype.pcc"
#line 23 "graphtype.pcc"
, TYCONty( GRAPHtycon( this), 
#line 23 "graphtype.pcc"
#line 23 "graphtype.pcc"
nil_1_
#line 23 "graphtype.pcc"
#line 23 "graphtype.pcc"
));
}

GraphTypeDef::~GraphTypeDef() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create a node type definition.
//
///////////////////////////////////////////////////////////////////////////////

NodeDef::NodeDef( GraphTypeDef * g, Id id, Ty ty, Id hash, Id eq, LabTys attribs)
    : G(g), node_name(id), node_type(ty), hash_fun(hash), eq_fun(eq),
      attributes(attribs), rep(UNBASEDrep)
{
  if (hash_fun == 0)
    hash_fun = "hash";
  if (eq_fun == 0)
    eq_fun = "equal";
}

NodeDef::~NodeDef() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to create an edge type definition.
//
///////////////////////////////////////////////////////////////////////////////

EdgeDef::EdgeDef( GraphTypeDef * G,
		          Id id, NodeDef* a, NodeDef* b,
                  GraphIndexing i, LabTys attribs)
    : graph(G), edge_name(id), domain_type(a), range_type(b), indexing(i),
      attributes(attribs), ops(NOgop)
     {}

EdgeDef::~EdgeDef() {}

void GraphTypeDef::set_nodes( NodeDefs n) { node_defs = n; }
void GraphTypeDef::set_edges( EdgeDefs e) { edge_defs = e; }
void GraphTypeDef::set_body( Decls b) { class_body = b; }

///////////////////////////////////////////////////////////////////////////////
//
//  Method to lookup a node definition by name
//
///////////////////////////////////////////////////////////////////////////////

NodeDef * GraphTypeDef::lookup_node (Id id)
{
  for_each (NodeDef *, n, node_defs)
  {
    if (n->node_name == id)
      return n;
  }
  error( "%Lnode %s is not defined in graphtype %s\n", id, class_name);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to lookup an edge definition by name
//
///////////////////////////////////////////////////////////////////////////////

EdgeDef * GraphTypeDef::lookup_edge (Id id)
{
  for_each (EdgeDef *, e, edge_defs)
  {
    if (e->edge_name == id)
      return e;
  }
  error("%Ledge %s is not defined in graphtype %s\n", id, class_name);
  return 0;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to choose a representation for the graph type.
//
///////////////////////////////////////////////////////////////////////////////

void GraphTypeDef::choose_representation()
{
  for_each (EdgeDef *, e, edge_defs)
    e->choose_representation();
  for_each (NodeDef *, n, node_defs)
    n->choose_representation();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the graph type internals.
//
///////////////////////////////////////////////////////////////////////////////

void GraphTypeDef::gen_class_predefinition( CodeGen& C)
{
  choose_representation();

  C.pr(
        "%^%/"
        "%^//"
        "%^//  Internal representation of nodes in graphtype %s"
        "%^//"
        "%^%/",
        class_name
      );

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Generate any forward declarations from the node definitions
  //
  ////////////////////////////////////////////////////////////////////////////
  {
    for_each( NodeDef *, n, node_defs)
      n->generate_forward_decls(C);
  }

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Generate the representation for the nodes
  //
  ////////////////////////////////////////////////////////////////////////////
  {
    for_each(NodeDef *, n, node_defs)
      n->generate_representation(C);
  }

  C.pr(
        "%^%/"
        "%^//"
        "%^//  Definition of graphtype %s"
        "%^//"
        "%^%/",
        class_name
      );
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the interface methods
//
///////////////////////////////////////////////////////////////////////////////

void GraphTypeDef::gen_class_interface( CodeGen& C)
{
  ////////////////////////////////////////////////////////////////////////////
  //
  //  Generate forward type definitions
  //
  ////////////////////////////////////////////////////////////////////////////
  {
    C.pr("%-%^public:%+");
    for_each(NodeDef *, n, node_defs)
    {
      C.pr(
            "%^typedef %s_%s_node * %s;"
            "%^class %s_set {"
            "%^public:"
            "%^  friend class %s_iterator;"
            "%^  const GraphType::Link& link;"
            "%^  long offset;"
            "%^  %s_set(const GraphType::Link& l, long n = 0)"
            "%^    : link(l), offset(n) {}"
            "%^  Bool is_empty() const { return link.is_empty(); }"
            "%^  operator Bool () const { return link.is_empty(); }"
            "%^};"
            "%^class %s_iterator {"
            "%^  long offset;"
            "%^  const GraphType::Link * cursor, * sentinel;"
            "%^public:"
            "%^  %s_iterator(const %s_set& s) : "
            "%^    offset(s.offset), cursor(s.link.next),"
            "%^      sentinel(&s.link) {}"
            "%^  operator Bool () const { return cursor != sentinel; }"
            "%^  %s operator * () const"
            "%^    { return (%s)(((char *)cursor) - offset); }"
            "%^  %s operator -> () const"
            "%^    { return (%s)(((char *)cursor) - offset); }"
            "%^  void operator ++ () { cursor = cursor->next; }"
            "%^  void operator ++ (int) { cursor = cursor->next; }"
            "%^};",
            class_name, n->name(), n->name(),
            n->name(), n->name(),
            n->name(), n->name(),
            n->name(), n->name(),
            n->name(), n->name(),
            n->name(), n->name()
          );
    }
  }

  ////////////////////////////////////////////////////////////////////////////
  //
  //  Generate the interface methods for the nodes
  //
  ////////////////////////////////////////////////////////////////////////////
  {
    for_each (NodeDef *, n, node_defs)
      n->generate_interface(C);
  }

  ////////////////////////////////////////////////////////////////////////////
  //  Generate the interface methods for the edges
  ////////////////////////////////////////////////////////////////////////////
  {
    for_each(EdgeDef *, e, edge_defs)
      e->generate_interface(C);
  }
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate the graph type implementation.
//
///////////////////////////////////////////////////////////////////////////////

void GraphTypeDef::gen_class_implementation( CodeGen& C)
{
  gen_init_graph(C);
  gen_lookup_node(C);
  gen_insert_node(C);
  gen_remove_node(C);
}

void GraphTypeDef::gen_init_graph( CodeGen& C) {}
void GraphTypeDef::gen_lookup_node( CodeGen& C) {}
void GraphTypeDef::gen_insert_node( CodeGen& C) {}
void GraphTypeDef::gen_remove_node( CodeGen& C) {}

#line 254 "graphtype.pcc"
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
