
#include <test.h>
#include <CuTest.h>

void TestCuTestmeFunction(CuTest *tc)
{
	CuAssertTrue(tc, testme() == 3);
	CuAssertTrue(tc, testme() != 3);
}
