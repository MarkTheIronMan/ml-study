#define CATCH_CONFIG_MAIN
#include "../../catch2/catch.hpp"
#include <iostream>
#include <math.h>
#include <string>

#include "../CCircle.h"
#include "../CLineSegment.h"
#include "../CPoint.h"
#include "../CRectangle.h"
#include "../CTriangle.h"

TEST_CASE("Test circle")
{
	CCircle circle(CPoint(100.0, 100.0), 10.0, "000000", "000000");
	REQUIRE(circle.GetArea() == M_PI * 10.0 * 10.0);
}