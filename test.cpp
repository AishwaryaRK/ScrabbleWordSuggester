
#include <cppunit/extensions/HelperMacros.h>

using namespace CPPUNIT_NS;
class ScrabbleTestSuite : public CppUnit::TestCase
{
  public:
      ScrabbleTestSuite()
      {
          CPPUNIT_TEST(ScrabbleTestSuite::getScoreTest)

      }
  private:
    void getScoreTest();

};

void ScrabbleTestSuite::getScoreTest()
{
    CPPUNIT_ASSERT(1+1==2);
}
