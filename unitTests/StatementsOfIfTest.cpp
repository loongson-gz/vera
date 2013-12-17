#include "FixtureOfIfStatements.h"
#include <structures/StatementOfIf.h>

using namespace Vera::Structures;

namespace Testing
{

TEST_F(FixtureOfIfStatements, getIfTokens_givenCollectionWithValidSentenceIfWithoutElse_returnStatementWithAssociatedTokens)
{
  //Arrange
  Tokens::TokenSequence inputCollection = getSubCollection(0, 21, collection_);
  Tokens::TokenSequence tokensExpected = getSubCollection(0, 2, collection_);

  Statement response;
  Tokens::TokenSequence::const_iterator begin = inputCollection.begin();
  Tokens::TokenSequence::const_iterator end = inputCollection.end();

  //Act

  StatementOfIf ifSentence(response, begin, end);

  //Asserts

  EXPECT_EQ(tokensExpected.size(), response.tokenSequence_.size());
  ASSERT_TRUE(tokensExpected == response.tokenSequence_);
}

TEST_F(FixtureOfIfStatements, getArgumentStatementFromConditionalSentence_givenCollectionWithValidSentenceIf_returnStatementAssociatedToConditionalSentence)
{
  //Arrange
  Tokens::TokenSequence inputCollection = getSubCollection(0, 21, collection_);
  Tokens::TokenSequence tokensExpected = getSubCollection(2, 3, collection_);

  Statement response;
  Tokens::TokenSequence::const_iterator begin = inputCollection.begin();
  Tokens::TokenSequence::const_iterator end = inputCollection.end();

  //Act

  StatementOfIf ifSentence(response, begin, end);
  const Statement& arguments = ifSentence.getArgumentStatementFromConditionalSentence();

  //Asserts
  EXPECT_EQ(tokensExpected.size(), arguments.tokenSequence_.size());
  ASSERT_TRUE(tokensExpected == arguments.tokenSequence_);
}

TEST_F(FixtureOfIfStatements, getStatementIfScope_givenCollectionWithValidSentenceIf_returnAssociatedScope)
{
  //Arrange
  Tokens::TokenSequence inputCollection = getSubCollection(0, 21, collection_);
  Tokens::TokenSequence tokensExpected = getSubCollection(5, 16, inputCollection);

  Statement response;
  Tokens::TokenSequence::const_iterator begin = inputCollection.begin();
  Tokens::TokenSequence::const_iterator end = inputCollection.end();

  //Act
  StatementOfIf ifSentence(response, begin, end);
  const Statement& scope = ifSentence.getStatementIfScope();

  //Asserts
  ASSERT_TRUE(ifScope_ == scope);
}

TEST_F(FixtureOfIfStatements, getStatementElseScope_givenCollectionWithValidSentenceElse_returnAssociatedScope)
{
  //Arrange
  Statement response;
  Tokens::TokenSequence::const_iterator begin = collection_.begin();
  Tokens::TokenSequence::const_iterator end = collection_.end();

  //Act
  StatementOfIf ifSentence(response, begin, end);
  const Statement& scope = ifSentence.getStatementElseScope();

  //Asserts
  ASSERT_TRUE(elseScope_ == scope);
}

TEST_F(FixtureOfIfStatements, getIfTokens_givenCollectionWithValidSentenceIfAndElse_returnStatementWithAssociatedTokens)
{
  //Arrange
  Statement response;
  Tokens::TokenSequence::const_iterator begin = collection_.begin();
  Tokens::TokenSequence::const_iterator end = collection_.end();

  //Act

  StatementOfIf ifSentence(response, begin, end);

  //Asserts

  EXPECT_EQ(ifTokens_.size(), response.tokenSequence_.size());
  ASSERT_TRUE(ifTokens_ == response.tokenSequence_);
}

} // Testing namespace
