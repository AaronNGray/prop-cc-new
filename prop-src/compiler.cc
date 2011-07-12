///////////////////////////////////////////////////////////////////////////////
//  This file is generated automatically using Prop (version 2.4.0),
//  last updated on Jul 1, 2011.
//  The original source file is "compiler.pcc".
///////////////////////////////////////////////////////////////////////////////

#line 1 "compiler.pcc"
///////////////////////////////////////////////////////////////////////////////
//
//  The file implements the class Compiler and this is the main entry
//  point of the Prop -> C++ translator.
//
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ir.h"
#include "ast.h"
#include "type.h"
#include "compiler.h"
#include "options.h"


///////////////////////////////////////////////////////////////////////////////
//
//  Constructor and destructor
//
///////////////////////////////////////////////////////////////////////////////

Compiler:: Compiler( TyOpt opt, int embedded_tags)
    : DatatypeCompiler( opt, embedded_tags) {}
Compiler::~Compiler() {}

///////////////////////////////////////////////////////////////////////////////
//
//  Emit header info
//
///////////////////////////////////////////////////////////////////////////////

void Compiler::emit_header( const char * text, int n)
{
  header.emit( text, n);
}

void Compiler::emit_header_text()
{
  const char * header_text = header.text();
  if (header_text)
    pr( "%s", header_text);
}

///////////////////////////////////////////////////////////////////////////////
//
//  Additional printing method
//
///////////////////////////////////////////////////////////////////////////////

std::va_list Compiler::printer( char fmt, va_list arg)
{
  
#line 52 "compiler.pcc"
#line 57 "compiler.pcc"
{
  switch (fmt) {
    case '&': {
#line 55 "compiler.pcc"
     gen( va_arg( arg, Decls)); 
#line 55 "compiler.pcc"
    } break;
    case 'D': {
#line 56 "compiler.pcc"
     gen( va_arg( arg, Decl)); 
#line 56 "compiler.pcc"
    } break;
    case 'm': {
#line 54 "compiler.pcc"
     MatchCompiler::gen( va_arg( arg, Match)); 
#line 54 "compiler.pcc"
    } break;
    default: {
#line 57 "compiler.pcc"
     bug( "undefined print format '%%%c'\n", (int)fmt); 
#line 57 "compiler.pcc"
    }
  }
}
#line 58 "compiler.pcc"
#line 58 "compiler.pcc"

  return arg;
}

///////////////////////////////////////////////////////////////////////////////
//
//  Top level code generation method
//
///////////////////////////////////////////////////////////////////////////////

void Compiler::generate(Decls ds)
{
  // generate the quark literals
  if ( quark_map.size() > 0)
  {
    pr(
        "%^%/"
        "%^//  Quark literals"
        "%^%/"
      );

    foreach_entry (e, quark_map)
    {
      Id name  = (Id) quark_map.key( e);
      Id quark = (Id) quark_map.value( e);
      pr ("%^static const Quark %s(%s);\n", quark, name);
    }
  }

  // now generate the main program.
  gen( ds);

  // finally, generate any outstanding rewriters
  gen_rewriters();

  // if the visualization is on then print GDL
  if (options.visualization)
    print_definitions_as_GDL();
}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a list of declarations.
//
///////////////////////////////////////////////////////////////////////////////

void Compiler::gen( Decls ds)
{
  Bool line_prefix = true;
  Bool line_suffix = true;
  
#line 108 "compiler.pcc"
#line 120 "compiler.pcc"
{
  for (;;) {
    if (ds) {
#line 111 "compiler.pcc"
      
      
#line 112 "compiler.pcc"
#line 115 "compiler.pcc"
      {
        Decl _V1 = ds->_1;
        if (_V1) {
          switch (_V1->tag__) {
            case a_Decl::tag_TYPEEXPdecl: {
#line 114 "compiler.pcc"
             line_suffix = line_prefix; line_prefix = false; 
#line 114 "compiler.pcc"
              } break;
            default: {
              L2:; 
#line 115 "compiler.pcc"
             line_suffix = line_prefix; line_prefix = true; 
#line 115 "compiler.pcc"
              } break;
          }
        } else { goto L2; }
      }
#line 116 "compiler.pcc"
#line 116 "compiler.pcc"
      
      
            gen( ds->_1, line_prefix, line_suffix);
            ds = ds->_2;
          
#line 120 "compiler.pcc"
    } else { goto L1; }
  }
  L1:;
}
#line 121 "compiler.pcc"
#line 121 "compiler.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate one declaration.
//
///////////////////////////////////////////////////////////////////////////////

void Compiler::gen( Decl d, Bool line_prefix, Bool line_suffix)
{
  
#line 132 "compiler.pcc"
#line 212 "compiler.pcc"
{
  if (d) {
    switch (d->tag__) {
      case a_Decl::tag_OPAQUEdecl: {
#line 134 "compiler.pcc"
       pr ("%C",((Decl_OPAQUEdecl *)d)->OPAQUEdecl); 
#line 134 "compiler.pcc"
        } break;
      case a_Decl::tag_DATATYPEdecl: {
#line 135 "compiler.pcc"
       gen_datatype(((Decl_DATATYPEdecl *)d)->_1,((Decl_DATATYPEdecl *)d)->_2,((Decl_DATATYPEdecl *)d)->_3,((Decl_DATATYPEdecl *)d)->_4); 
#line 135 "compiler.pcc"
        } break;
      case a_Decl::tag_INSTANTIATEdecl: {
#line 136 "compiler.pcc"
       instantiate_datatypes(((Decl_INSTANTIATEdecl *)d)->_1,((Decl_INSTANTIATEdecl *)d)->_2);
#line 136 "compiler.pcc"
        } break;
      case a_Decl::tag_CLASSDEFdecl: {
#line 150 "compiler.pcc"
       ((Decl_CLASSDEFdecl *)d)->CLASSDEFdecl->gen_class_definition(*this); 
#line 150 "compiler.pcc"
        } break;
      case a_Decl::tag_INFERENCEdecl: {
#line 143 "compiler.pcc"
       gen_inference_rules(((Decl_INFERENCEdecl *)d)->_1, ((Decl_INFERENCEdecl *)d)->_2); 
#line 143 "compiler.pcc"
        } break;
      case a_Decl::tag_REWRITEdecl: {
#line 137 "compiler.pcc"
       gen_rewrite(((Decl_REWRITEdecl *)d)->_1, ((Decl_REWRITEdecl *)d)->_2, ((Decl_REWRITEdecl *)d)->_3); 
#line 137 "compiler.pcc"
        } break;
      case a_Decl::tag_REWRITINGdecl: {
#line 138 "compiler.pcc"
       gen_rewriting(((Decl_REWRITINGdecl *)d)->_1,((Decl_REWRITINGdecl *)d)->_2,((Decl_REWRITINGdecl *)d)->_3,((Decl_REWRITINGdecl *)d)->_4,((Decl_REWRITINGdecl *)d)->_5,((Decl_REWRITINGdecl *)d)->_6); 
#line 138 "compiler.pcc"
        } break;
      case a_Decl::tag_REPLACEMENTdecl: {
#line 147 "compiler.pcc"
       gen_replacement(((Decl_REPLACEMENTdecl *)d)->_1,((Decl_REPLACEMENTdecl *)d)->_2); 
#line 147 "compiler.pcc"
        } break;
      case a_Decl::tag_CUTREWRITEdecl: {
#line 148 "compiler.pcc"
       gen_cutreplacement(((Decl_CUTREWRITEdecl *)d)->_1,((Decl_CUTREWRITEdecl *)d)->_2); 
#line 148 "compiler.pcc"
        } break;
      case a_Decl::tag_FAILREWRITEdecl: {
#line 149 "compiler.pcc"
       gen_failrewrite(((Decl_FAILREWRITEdecl *)d)->FAILREWRITEdecl); 
#line 149 "compiler.pcc"
        } break;
      case a_Decl::tag_INJECTdecl: {
        if (((Decl_INJECTdecl *)d)->direction) {
          
#line 184 "compiler.pcc"
          
          pr( " if (i__) insert_alpha(%i,fact__); else remove_alpha(%i,fact__); ",
              ((Decl_INJECTdecl *)d)->node_number, ((Decl_INJECTdecl *)d)->node_number);
          
#line 187 "compiler.pcc"
        } else {
          
#line 189 "compiler.pcc"
          
          pr( " if (i__) insert_beta(%i,f__); else remove_beta(%i,f__); ",
              ((Decl_INJECTdecl *)d)->node_number, ((Decl_INJECTdecl *)d)->node_number);
          
#line 192 "compiler.pcc"
        }
        } break;
      case a_Decl::tag_GOTOdecl: {
#line 181 "compiler.pcc"
       pr ("%^goto %s;\n", ((Decl_GOTOdecl *)d)->GOTOdecl); 
#line 181 "compiler.pcc"
        } break;
      case a_Decl::tag_SETSTATEdecl: {
#line 182 "compiler.pcc"
       pr ("s__ = %i;", ((Decl_SETSTATEdecl *)d)->SETSTATEdecl); 
#line 182 "compiler.pcc"
        } break;
      case a_Decl::tag_SYNTAXdecl: {
#line 141 "compiler.pcc"
       gen_parser(((Decl_SYNTAXdecl *)d)->_1,((Decl_SYNTAXdecl *)d)->_2); 
#line 141 "compiler.pcc"
        } break;
      case a_Decl::tag_ATTRIBUTEGRAMMARdecl: {
#line 142 "compiler.pcc"
       gen_attribute_grammar(((Decl_ATTRIBUTEGRAMMARdecl *)d)->_1,((Decl_ATTRIBUTEGRAMMARdecl *)d)->_2); 
#line 142 "compiler.pcc"
        } break;
      case a_Decl::tag_FUNdecl: {
#line 139 "compiler.pcc"
       gen_fun_def(((Decl_FUNdecl *)d)->FUNdecl); 
#line 139 "compiler.pcc"
        } break;
      case a_Decl::tag_MATCHdecl: {
#line 140 "compiler.pcc"
       gen_match_stmt(((Decl_MATCHdecl *)d)->_1,((Decl_MATCHdecl *)d)->_2,((Decl_MATCHdecl *)d)->_3,((Decl_MATCHdecl *)d)->_4); 
#line 140 "compiler.pcc"
        } break;
      case a_Decl::tag_SETLSTMTdecl: {
#line 144 "compiler.pcc"
       gen_setl(((Decl_SETLSTMTdecl *)d)->SETLSTMTdecl); 
#line 144 "compiler.pcc"
        } break;
      case a_Decl::tag_SETLDEFdecl: {
#line 145 "compiler.pcc"
       gen_setl(((Decl_SETLDEFdecl *)d)->SETLDEFdecl); 
#line 145 "compiler.pcc"
        } break;
      case a_Decl::tag_CLASSOFdecl: {
#line 152 "compiler.pcc"
        
        
#line 153 "compiler.pcc"
#line 177 "compiler.pcc"
        {
          Ty _V2 = lookup_ty(((Decl_CLASSOFdecl *)d)->CLASSOFdecl);
          if (_V2) {
            switch (_V2->tag__) {
              case a_Ty::tag_TYCONty: {
                if (boxed(((Ty_TYCONty *)_V2)->_1)) {
                  switch (((Ty_TYCONty *)_V2)->_1->tag__) {
                    case a_TyCon::tag_DATATYPEtycon: {
#line 156 "compiler.pcc"
                     pr( "a_%s", ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V2)->_1)->id); 
#line 156 "compiler.pcc"
                      } break;
                    default: {
                      L3:; 
#line 177 "compiler.pcc"
                    error ("%Ltype %s has unknown class: %T\n",((Decl_CLASSOFdecl *)d)->CLASSOFdecl, _V2); 
#line 177 "compiler.pcc"
                      } break;
                  }
                } else { goto L3; }
                } break;
              default: { goto L3; } break;
            }
          } else {
#line 158 "compiler.pcc"
            
            
#line 159 "compiler.pcc"
#line 173 "compiler.pcc"
            {
              Cons _V3 = find_cons(((Decl_CLASSOFdecl *)d)->CLASSOFdecl);
              if (_V3) {
                if (
#line 163 "compiler.pcc"
                (_V3->opt & OPTunboxed)
#line 163 "compiler.pcc"
) {
                  
                  if (_V3->ty) {
#line 164 "compiler.pcc"
                  error ("%Lthe class representation of constructor %s has been elided\n", ((Decl_CLASSOFdecl *)d)->CLASSOFdecl); 
#line 164 "compiler.pcc"
                  } else {
                    L4:; 
#line 162 "compiler.pcc"
                  error ("%Lconstructor %s is not a class\n", ((Decl_CLASSOFdecl *)d)->CLASSOFdecl); 
#line 162 "compiler.pcc"
                  }
                } else {
                  
                  if (_V3->alg_ty) {
                    switch (_V3->alg_ty->tag__) {
                      case a_Ty::tag_TYCONty: {
                        if (_V3->ty) {
                          if (boxed(((Ty_TYCONty *)_V3->alg_ty)->_1)) {
                            switch (((Ty_TYCONty *)_V3->alg_ty)->_1->tag__) {
                              case a_TyCon::tag_DATATYPEtycon: {
                                L5:; 
#line 166 "compiler.pcc"
                                
                                if (((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V3->alg_ty)->_1)->opt & OPTsubclassless)
                                  pr ("a_%s", ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V3->alg_ty)->_1)->id);
                                else
                                  pr ("%s_%S", ((TyCon_DATATYPEtycon *)((Ty_TYCONty *)_V3->alg_ty)->_1)->id, _V3->name);
                                
#line 171 "compiler.pcc"
                                } break;
                              default: {
                                L6:; 
#line 173 "compiler.pcc"
                              error ("%Ltype or constructor %s is undefined\n", ((Decl_CLASSOFdecl *)d)->CLASSOFdecl); 
#line 173 "compiler.pcc"
                                } break;
                            }
                          } else { goto L6; }
                        } else { goto L4; }
                        } break;
                      default: {
                        L7:; 
                        if (_V3->ty) { goto L6; } else { goto L4; }
                        } break;
                    }
                  } else { goto L7; }
                }
              } else { goto L6; }
            }
#line 174 "compiler.pcc"
#line 174 "compiler.pcc"
            
            
#line 175 "compiler.pcc"
          }
        }
#line 178 "compiler.pcc"
#line 178 "compiler.pcc"
        
        
#line 179 "compiler.pcc"
        } break;
      case a_Decl::tag_TYPEEXPdecl: {
#line 180 "compiler.pcc"
       pr ("%t", ((Decl_TYPEEXPdecl *)d)->TYPEEXPdecl,""); 
#line 180 "compiler.pcc"
        } break;
      case a_Decl::tag_EXPdecl: {
        if (((Decl_EXPdecl *)d)->exp) {
          switch (((Decl_EXPdecl *)d)->exp->tag__) {
            case a_Exp::tag_THISSYNexp:
            case a_Exp::tag_SYNexp: {
#line 198 "compiler.pcc"
             pr( "%e", ((Decl_EXPdecl *)d)->exp); 
#line 198 "compiler.pcc"
              } break;
            default: {
              L8:; 
#line 200 "compiler.pcc"
             pr( "%^%s%e%s", (((Decl_EXPdecl *)d)->prefix ? ((Decl_EXPdecl *)d)->prefix : ""),((Decl_EXPdecl *)d)->exp, (((Decl_EXPdecl *)d)->suffix ? ((Decl_EXPdecl *)d)->suffix : "")); 
#line 200 "compiler.pcc"
              } break;
          }
        } else { goto L8; }
        } break;
      case a_Decl::tag_MARKEDdecl: {
#line 202 "compiler.pcc"
        
        line = ((Decl_MARKEDdecl *)d)->_1.begin_line;
        file = ((Decl_MARKEDdecl *)d)->_1.file_name;
        if (line_prefix)
          pr ("%#",line,file);
        gen(((Decl_MARKEDdecl *)d)->_2);
        line = ((Decl_MARKEDdecl *)d)->_1.end_line;
        if (line_suffix)
          pr ("%#",line,file);
        
#line 211 "compiler.pcc"
        } break;
      default: {
#line 212 "compiler.pcc"
       bug("Unimplemented feature"); 
#line 212 "compiler.pcc"
        } break;
    }
  } else {
#line 133 "compiler.pcc"
   /* skip */ 
#line 133 "compiler.pcc"
  }
}
#line 213 "compiler.pcc"
#line 213 "compiler.pcc"

}

///////////////////////////////////////////////////////////////////////////////
//
//  Method to generate a report.
//
///////////////////////////////////////////////////////////////////////////////

std::ostream& Compiler::print_report(std::ostream& f)
{
  f << "------------------------------- Statistics -------------------------------"
    << "\nMerge matching rules         = " << (options.merge_match ?  "yes" : "no")
    << "\nNumber of DFA nodes merged   = " << merges
    << "\nNumber of ifs generated      = " << ifs
    << "\nNumber of switches generated = " << switches
    << "\nNumber of labels             = " << goto_labels
    << "\nNumber of gotos              = " << gotos
    << "\nAdaptive matching            = " << (options.adaptive_matching ? "enabled" : "disabled")
    << "\nFast string matching         = " << (options.fast_string_match ? "enabled" : "disabled")
    << "\nInline downcasts             = " << (options.inline_casts ? "enabled" : "disabled")
    << "\n"
       "--------------------------------------------------------------------------"
       "\n"
       ;
  return f;
}
#line 240 "compiler.pcc"
/*
------------------------------- Statistics -------------------------------
Merge matching rules         = yes
Number of DFA nodes merged   = 398
Number of ifs generated      = 14
Number of switches generated = 8
Number of labels             = 7
Number of gotos              = 10
Adaptive matching            = enabled
Fast string matching         = disabled
Inline downcasts             = enabled
--------------------------------------------------------------------------
*/
