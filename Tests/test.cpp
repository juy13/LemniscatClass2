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
	/*ASSERT_NEAR(a.getC()*a.getC() / 2 * sin(2 * 1), a.areaA(1), err);
	ASSERT_NEAR(0.5*a.getC()*a.getC(), a.area(), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 34))), a.dist(34), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 57) / (3 * cos(2 * 57)))), a.radA(57), err);
	ASSERT_NEAR(2 * a.getC()*a.getC() / (3 * 0.1), a.radR(0.1), err);
	ASSERT_NEAR(a.getC()*a.getC() / 2 * sin(2 * 0.002), a.areaA(0.002), err);
	a.setC(100);
	ASSERT_NEAR(0.5*a.getC()*a.getC(), a.area(), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 1))), a.dist(1), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 1) / (3 * cos(2 * 1)))), a.radA(1), err);
	ASSERT_NEAR(2 * a.getC()*a.getC() / (3 * 1), a.radR(1), err);
	ASSERT_NEAR(a.getC()*a.getC() / 2 * sin(2 * 1), a.areaA(1), err);
	ASSERT_NEAR(0.5*a.getC()*a.getC(), a.area(), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 34))), a.dist(34), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 57) / (3 * cos(2 * 57)))), a.radA(57), err);
	ASSERT_NEAR(2 * a.getC()*a.getC() / (3 * 0.1), a.radR(0.1), err);
	ASSERT_NEAR(a.getC()*a.getC() / 2 * sin(2 * 0.002), a.areaA(0.002), err);
	a.setC(0.1);
	ASSERT_NEAR(0.5*a.getC()*a.getC(), a.area(), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 1))), a.dist(1), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 1) / (3 * cos(2 * 1)))), a.radA(1), err);
	ASSERT_NEAR(2 * a.getC()*a.getC() / (3 * 1), a.radR(1), err);
	ASSERT_NEAR(a.getC()*a.getC() / 2 * sin(2 * 1), a.areaA(1), err);
	ASSERT_NEAR(0.5*a.getC()*a.getC(), a.area(), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 34))), a.dist(34), err);
	ASSERT_NEAR(sqrt(abs(2 * a.getC()*a.getC()*cos(2 * 57) / (3 * cos(2 * 57)))), a.radA(57), err);
	ASSERT_NEAR(2 * a.getC()*a.getC() / (3 * 0.1), a.radR(0.1), err);
	*///ASSERT_NEAR(a.getC()*a.getC() / 2 * sin(2 * 0.002), a.areaA(0.002), err);
}


int main(int argc, char* argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}