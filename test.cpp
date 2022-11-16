/***********************************************************************
 * Source File:
 *    Test : Test runner
 * Author:
 *    Br. Helfrich
 * Summary:
 *    The test runner for all the unit tests
 ************************************************************************/

#include "test.h"
#include "testPosition.h"
#include "testSatellite.h"
#include "testAngle.h"

/*****************************************************************
 * TEST RUNNER
 * Runs all the unit tests
 ****************************************************************/
void testRunner()
{
   //TestPosition().run();
   //testSatellite().run();
   testAngle().run();

   cout << "All Tests have passed.  Success!!!" << endl;

}
