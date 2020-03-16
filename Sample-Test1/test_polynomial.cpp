#include "pch.h"
#include "..\mp2-lab5-list\mp2-lab5-list\TPolynomial.h"
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
TEST(TPolynomial, can_add_polynomial)
{
    TMonomial mon1, mon2, mon3, mon4;
    TPolynomial pol1, pol2, pol3;
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

    mon3.coeff = -1;
    mon3.px = 1;
    mon3.py = 2;
    mon3.pz = 3;
    mon4.coeff = 12;
    mon4.px = 5;
    mon4.py = 5;
    mon4.pz = 6;
    pol2 += mon4;
    pol2 += mon3;
    pol3 += mon2;
    pol3 += mon4;
    pol1 += pol2;
    EXPECT_EQ(pol1, pol3);
}
TEST(TPolynomial, last_monomial_can_be_cancelled_out)
{
    TMonomial mon1, mon2, mon3, mon4;
    TPolynomial pol1, pol2, pol3;
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
    cout << "pol1 = " << pol1 << endl;

    mon3.coeff = -1;
    mon3.px = 1;
    mon3.py = 2;
    mon3.pz = 3;

    pol2 += mon3;
    cout << "pol2 = " << pol2 << endl;
    pol1 += pol2;
    pol3 += mon2;
    cout << "pol3 = " << pol3 << endl;
    cout << "pol1 + pol2 = " << pol1 << endl;
    EXPECT_EQ(pol1, pol3);
}
TEST(TPolynomial, first_monomial_can_be_cancelled_out)
{
    TMonomial mon1, mon2, mon3, mon4;
    TPolynomial pol1, pol2, pol3;
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
    cout << "pol1 = " << pol1 << endl;

    mon3.coeff = -3;
    mon3.px = 4;
    mon3.py = 5;
    mon3.pz = 6;

    pol2 += mon3;
    cout << "pol2 = " << pol2 << endl;
    pol1 += pol2;
    pol3 += mon1;
    cout << "pol3 = " << pol3 << endl;
    cout << "pol1 + pol2 = " << pol1 << endl;
    EXPECT_EQ(pol1, pol3);
}
TEST(TPolynomial, first_monomial_can_be_cancelled_out)
{
    TMonomial mon1, mon2, mon3, mon4, mon5, mon6, mon8, mon9;
    TPolynomial pol1, pol2, pol3;
    mon1.coeff = 4;
    mon1.px = 3;
    mon1.py = 3;
    mon1.pz = 3;
    mon2.coeff = 7;
    mon2.px = 2;
    mon2.py = 1;
    mon2.pz = 4;
    mon3.coeff = -3;
    mon3.px = 1;
    mon3.py = 2;
    mon3.pz = 3;
    mon4.coeff = -1;
    mon4.px = 1;
    mon4.py = 2;
    mon4.pz = 1;
    mon5.coeff = -6;
    mon5.px = 0;
    mon5.py = 4;
    mon5.pz = 1;
    pol1 += mon1;
    pol1 += mon2;
    pol1 += mon3;
    pol1 += mon4;
    pol1 += mon5;
    cout << "pol1 = " << pol1 << endl;


    pol2 += mon3;
    cout << "pol2 = " << pol2 << endl;
    pol1 += pol2;
    pol3 += mon1;
    cout << "pol3 = " << pol3 << endl;
    cout << "pol1 + pol2 = " << pol1 << endl;
    EXPECT_EQ(pol1, pol3);
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
TEST(TPolynomial, can_multiply_by_polynomial)
{
    TMonomial mon1, mon2, mon3, mon4, mon5, mon6, mon7;
    TPolynomial pol1, pol2, pol3;

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
    cout << pol1 << endl;

    mon3.coeff = 4;
    mon3.px = 7;
    mon3.py = 8;
    mon3.pz = 9;
    mon4.coeff = -5;
    mon4.px = 10;
    mon4.py = 11;
    mon4.pz = 12;

    pol2 += mon3;
    pol2 += mon4;
    cout << pol2 << endl;

    mon5.coeff = 4;
    mon5.px = 8;
    mon5.py = 10;
    mon5.pz = 12;
    mon6.coeff = 7;
    mon6.px = 11;
    mon6.py = 13;
    mon6.pz = 15;
    mon7.coeff = -15;
    mon7.px = 14;
    mon7.py = 16;
    mon7.pz = 18;
    pol3 += mon5;
    pol3 += mon6;
    pol3 += mon7;
    cout << pol3 << endl;

    EXPECT_EQ(pol1 * pol2, pol3);
}