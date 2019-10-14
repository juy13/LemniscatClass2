#include <gtest/gtest.h>
#include "LemniscatClass.h"

TEST(LemConst, DefConst) 
{
	LemniscatClass a1;
	const double err = 0.0001;
	ASSERT_EQ(1, a1.get_c());
	ASSERT_NEAR(1.2732, a1.SqLem(), err);
}

TEST(LemConst, InitConst)
{
	const double err = 0.001;
	double c = 5;
	LemniscatClass aa2(c);
	ASSERT_EQ(5, aa2.get_c());
	ASSERT_NEAR(31.831, aa2.SqLem(), err);
}

TEST(LemConst, TestExc)
{
	LemniscatClass a3;
	ASSERT_ANY_THROW(LemniscatClass a3(-10));
	LemniscatClass a4;
	ASSERT_ANY_THROW(a3.set_c(-2));
	ASSERT_ANY_THROW(a4.RadOfRad(-2));
	ASSERT_ANY_THROW(a4.SqPolarSec(0));
}

TEST(LemConst, Setters)
{
	LemniscatClass a5;
	const double err = 0.001;
	a5.set_c(5);
	ASSERT_EQ(5, a5.get_c());
	ASSERT_NEAR(31.831, a5.SqLem(), err);
}
TEST(LemMethods, Parameters) 
{
	LemniscatClass a;
	const double err = 0.001;
	ASSERT_NEAR(1.2732, a.SqLem(), err);
	ASSERT_NEAR(0.391, a.Len2Cent(1), err);
	ASSERT_NEAR(1.704, a.RadOfAngle(1), err);
	ASSERT_NEAR(0.666, a.RadOfRad(1), err);
	ASSERT_NEAR(1.310, a.Len2Cent(34), err);
	ASSERT_NEAR(0.486, a.RadOfAngle(57), err);
	ASSERT_NEAR(6.666, a.RadOfRad(0.1), err);
	ASSERT_NEAR(0.496, a.SqPolarSec(60), err);
	a.set_c(100);
	ASSERT_NEAR(12732.395, a.SqLem(), err);
	ASSERT_NEAR(120.073, a.Len2Cent(10), err);
	ASSERT_NEAR(49.357, a.RadOfAngle(15), err);
	ASSERT_NEAR(4444.444, a.RadOfRad(1.5), err);
	ASSERT_NEAR(3737.889, a.SqPolarSec(30), err);
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}