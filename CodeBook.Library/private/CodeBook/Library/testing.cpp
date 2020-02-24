#include <CodeBook/Library/CodeBook.Library.hpp>

#pragma warning(disable : 4146 4267 4244 4624 4291 4996)

#include "clang/AST/ASTConsumer.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendAction.h"
#include "clang/Tooling/Tooling.h"

#include <memory>
#include <sstream>
#include <string>

namespace CodeBook {
namespace Library {

struct Data
{
   std::string symbol;
   std::string source;
   std::string output;
};

using namespace clang;

class FindNamedClassVisitor : public RecursiveASTVisitor<FindNamedClassVisitor>
{
public:
   explicit FindNamedClassVisitor(ASTContext * Context, std::shared_ptr<Data> data)
      : Context(Context)
      , m_data{data}
   {
   }

   bool VisitCXXRecordDecl(CXXRecordDecl * Declaration)
   {
      std::stringstream str;

      if (Declaration->getQualifiedNameAsString() == m_data->symbol)
      {
         FullSourceLoc FullLocation = Context->getFullLoc(Declaration->getBeginLoc());
         if (FullLocation.isValid())
         {
            str << "Found declaration [" << this->m_data->symbol << "] at "
                << FullLocation.getSpellingLineNumber() << ":"
                << FullLocation.getSpellingColumnNumber() << "\n";
         }
         else
         {
            str << "Did NOT find the location of declaration [" << this->m_data->symbol << "]\n";
         }
      }
      else
      {
         str << "Did NOT find any declaration [" << this->m_data->symbol << "]\n";
      }

      this->m_data->output = str.str();

      return true;
   }

private:
   ASTContext * Context;
   std::shared_ptr<Data> m_data;
};

class FindNamedClassConsumer : public clang::ASTConsumer
{
public:
   explicit FindNamedClassConsumer(ASTContext * Context, std::shared_ptr<Data> data)
      : Visitor(Context, data)
   {
   }

   virtual void HandleTranslationUnit(clang::ASTContext & Context)
   {
      Visitor.TraverseDecl(Context.getTranslationUnitDecl());
   }

private:
   FindNamedClassVisitor Visitor;
};

class FindNamedClassAction : public clang::ASTFrontendAction
{
public:
   FindNamedClassAction(std::shared_ptr<Data> data)
      : m_data{data}
   {
   }

   virtual std::unique_ptr<clang::ASTConsumer> CreateASTConsumer(clang::CompilerInstance & Compiler, llvm::StringRef InFile)
   {
      return std::unique_ptr<clang::ASTConsumer>(new FindNamedClassConsumer(&Compiler.getASTContext(), this->m_data));
   }

private:
   std::shared_ptr<Data> m_data;
};

CODE_BOOK_x_LIBRARY_x_API std::string Testing(const std::string & symbol, const std::string & source)
{
   auto data = std::make_shared<Data>();
   data->symbol = symbol;
   data->source = source;
   clang::tooling::runToolOnCode(std::make_unique<FindNamedClassAction>(data), data->source);
   return data->output;
}

}   // namespace Library
}   // namespace CodeBook
