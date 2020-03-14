#include "pch.h"
#include "..\mp2-lab5-list\mp2-lab5-list\TPolynomial.h"
TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}
TEST(TPolynomial, can_create_polynomial)
{
    ASSERT_NO_THROW(TPolynomial pol);
}
TEST(TPolynomial, can_create_copied_polynomial)
{
    TPolynomial pol;
    ASSERT_NO_THROW(TPolynomial pol1(pol));
}
TEST(TPolynomial, copied_polynomial_is_equal_to_original)
{
    TMonomial mon;
    mon.coeff = -2;
    mon.px = 3;
    mon.py = 4;
    mon.pz = 5;
    TPolynomial pol;
    pol += mon;
    TPolynomial pol1(pol);
    EXPECT_EQ(pol1, pol);
}
TEST(TPolynomial, can_add_monomial)
{
    TMonomial mon;
    mon.coeff = 1;
    mon.px = 1;
    mon.py = 1;
    mon.pz = 1;
    TPolynomial pol;
    ASSERT_NO_THROW(pol += mon);
}
TEST(TPolynomial, last_monomial_can_be_erased)
{
    TMonomial mon1, mon2;
    mon1.coeff = 1;
    mon1.px = 1;
    mon1.py = 1;
    mon1.pz = 1;
    mon2.coeff = 3;
    mon2.px = 4;
    mon2.py = 5;
    mon2.pz = 6;

    TPolynomial pol;
    pol += mon1;
    ASSERT_NO_THROW(pol -= mon1);
}
TEST(TPolynomial, can_multiply_by_monomial)
{
    TMonomial mon1, mon2, mon3, mon4, mon5;
    TPolynomial pol1, pol2;

    mon1.coeff = 1;
    mon1.px = 1;
    mon1.py = 2;
    mon1.pz = 3;
    mon2.coeff = 3;
    mon2.px = 4;
    mon2.py = 5;
    mon2.pz = 6;

    pol1 += mon1;
    pol1 += mon2;

    mon3.coeff = 4;
    mon3.px = 7;
    mon3.py = 8;
    mon3.pz = 9;

    pol1 *= mon3;

    mon4.coeff = 12;
    mon4.px = 11;
    mon4.py = 13;
    mon4.pz = 15;
    mon5.coeff = 4;
    mon5.px = 8;
    mon5.py = 10;
    mon5.pz = 12;
    pol2 += mon4;
    pol2 += mon5;
    EXPECT_EQ(pol1, pol2);
}