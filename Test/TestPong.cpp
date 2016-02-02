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

class TestPong : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestPong);
    CPPUNIT_TEST(testmovePad1Left);
    CPPUNIT_TEST(testmovePad1Right);
    CPPUNIT_TEST(testmoveBall);
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp(void);
    void tearDown(void);

protected:
    void testmovePad1Left(void);
    void testmovePad1Right(void);
    void testmoveBall(void);
    void modBall(DirectionBall db);
    void testMultiply(void);

private:

   MapGame *mp;
};

//-----------------------------------------------------------------------------
/* Testing the ball moves correctly int the matrix in any Direction */
void
TestPong::modBall(DirectionBall db)
{
	mp->ball.dirB = db;
	mp->moveBall();
}

void
TestPong::testmoveBall(void)
{
	 int startx = Pad1X + 1;
     int starty = (Pad_yL + Pad_yR) / 2;

     modBall(N);

     CPPUNIT_ASSERT(mp->ball.x == (startx + 1) && (mp->ball.y == starty) );

     modBall(S);

     CPPUNIT_ASSERT(mp->ball.x == (startx) && (mp->ball.y == starty) );

     modBall(NR);

     CPPUNIT_ASSERT(mp->ball.x == (startx + 1) && (mp->ball.y == starty + 1) );

     modBall(SL);

     CPPUNIT_ASSERT(mp->ball.x == (startx) && (mp->ball.y == starty));

     modBall(NL);

     CPPUNIT_ASSERT(mp->ball.x == (startx + 1) && (mp->ball.y == starty - 1));

     modBall(SR);

     CPPUNIT_ASSERT(mp->ball.x == (startx) && (mp->ball.y == starty) );
}
/* TestmoveVausRight and TestmoveVausLeft
 * check if the line of the mocking matrix is false where it is not the Pad1
 * and true where the Pad1 it is
 *
 * */
void
TestPong::testmovePad1Right(void)
{
	int startL = mp->pad1.lastL, startR = mp->pad1.lastR;
	bool result_test = true;

	mp->movePad1(RIGHT);

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
TestPong::testmovePad1Left(void)
{
	int startL = mp->pad1.lastL, startR = mp->pad1.lastR;
	bool result_test = true;

	mp->movePad1(RIGHT);

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

void TestPong::setUp(void)
{
    mp = new MapGame();
}

void TestPong::tearDown(void)
{
    delete mp;
}

//-----------------------------------------------------------------------------

CPPUNIT_TEST_SUITE_REGISTRATION( TestPong );

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
