#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

#include "../Pong.hpp"

using namespace CppUnit;
using namespace std;

//-----------------------------------------------------------------------------

class TestArkanoid : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestArkanoid);
    CPPUNIT_TEST(testmoveVausLeft);
    CPPUNIT_TEST(testmoveVausRight);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testmoveVausLeft(void);
    void testmoveVausRight(void);
    void testMultiply(void);

private:

   MapGame *mp;
};

//-----------------------------------------------------------------------------


/* TestmoveVausRight and TestmoveVausLeft
 * check if the line of the mocking matrix is false where it is not the Vaus
 * and true where the Vaus it is
 *
 * */
void
TestArkanoid::testmoveVausRight(void)
{
	int startL = mp->vaus.lastL, startR = mp->vaus.lastR;
	bool result_test = true;

	mp->moveVaus(RIGHT);

	for (int i =  0; i < startL; i++)
			if (mp->matrix.matrix[1][i].state)
				result_test = false;

	for (int i = (startL + 1); i <= startR + 1; i++)
		if (!mp->matrix.matrix[1][i].state)
			result_test = false;

	for (int i = (startR + 2); i<ROWS; i++)
		if (mp->matrix.matrix[1][i].state)
			result_test = false;

    CPPUNIT_ASSERT(result_test);
}


void
TestArkanoid::testmoveVausLeft(void)
{
	int startL = mp->vaus.lastL, startR = mp->vaus.lastR;
	bool result_test = true;

	mp->moveVaus(RIGHT);

	for (int i =  0; i < startL; i++)
			if (mp->matrix.matrix[1][i].state)
				result_test = false;

	for (int i = (startL + 1); i <= startR + 1; i++)
		if (!mp->matrix.matrix[1][i].state)
			result_test = false;

	for (int i = (startR + 2); i<ROWS; i++)
		if (mp->matrix.matrix[1][i].state)
			result_test = false;

    CPPUNIT_ASSERT(result_test);
}

void TestArkanoid::setUp(void)
{
    mp = new MapGame();
}

void TestArkanoid::tearDown(void)
{
    delete mp;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestArkanoid );

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest ());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // Output XML for Jenkins CPPunit plugin
    ofstream xmlFileOut("cppTestBasicMathResults.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}
