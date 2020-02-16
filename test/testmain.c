
#include <test.h>
#include <CuTest.h>

void TestCuTestmeFunction(CuTest *tc)
{
	CuAssertTrue(testme() == 3);
}
