#include "../Main.h"



TEST(NaturalAdd, simple)
{
	BigNatural one = BigNatural(12);
	BigNatural two = BigNatural(12);

	EXPECT_TRUE(naturalMatch(BigNatural(24), ADD_NN_N(one, two)));

	EXPECT_TRUE(naturalMatch(BigNatural(12), one));
	EXPECT_TRUE(naturalMatch(BigNatural(12), two));
}


TEST(NaturalAdd, oneZero)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural(12);

	EXPECT_TRUE(naturalMatch(BigNatural(12), ADD_NN_N(one, two)));

	EXPECT_TRUE(naturalMatch(BigNatural(), one));
	EXPECT_TRUE(naturalMatch(BigNatural(12), two));
}


TEST(NaturalAdd, bothZero)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural();

	EXPECT_TRUE(naturalMatch(BigNatural(), ADD_NN_N(one, two)));
}

TEST(NaturalAdd, longNum)
{
	BigNatural one = BigNatural(431243214);
	BigNatural two = BigNatural(675475437);

	EXPECT_TRUE(naturalMatch(BigNatural("1106718651"), ADD_NN_N(one, two)));

	EXPECT_TRUE(naturalMatch(BigNatural(431243214), one));
	EXPECT_TRUE(naturalMatch(BigNatural(675475437), two));
}

TEST(NaturalAdd, longlongNum1)
{
	BigNatural one = BigNatural("542356346745243674564321106718651423643657546436");
	BigNatural two = BigNatural("110671865154325432562346436342643634634");

	EXPECT_TRUE(naturalMatch(BigNatural("542356346855915539718646539280997859986301181070"), ADD_NN_N(one, two)));
}

TEST(NaturalAdd, longlongNum2)
{
	BigNatural one = BigNatural("6757234896957823465347563245723465234534756324573215025562381065043652348634542356346855915539718646539280997859986301181070");
	BigNatural two = BigNatural("1654744354432686143526143646487367443561446361435446434644368943463426134262932163456134626134256434626434526342466534246543264634246");

	EXPECT_TRUE(naturalMatch(BigNatural("1654744361189921040483967111834930689284911595970202759217583969025807199306584512090676982481112350166153172881747532106529565815316"), ADD_NN_N(one, two)));
}


//***************************************************************************************

TEST(NaturalCom)
{
	BigNatural one = BigNatural(431243);
	BigNatural two = BigNatural(675463464);

	ASSERT_EQ(1, COM_NN_D(one, two));
	ASSERT_EQ(2, COM_NN_D(two, one));
	ASSERT_EQ(0, COM_NN_D(one, one));
}

//***************************************************************************************


TEST(NaturalDiv, simple1)
{
	BigNatural one = BigNatural(1010);
	BigNatural two = BigNatural(10);

	EXPECT_TRUE(naturalMatch(BigNatural(101), DIV_NN_N(one, two)));

	EXPECT_TRUE(naturalMatch(BigNatural(1010), one));
	EXPECT_TRUE(naturalMatch(BigNatural(10), two));
}


TEST(NaturalDiv, simple2)
{
	BigNatural one = BigNatural(123123);
	BigNatural two = BigNatural(123);

	EXPECT_TRUE(naturalMatch(BigNatural(1001), DIV_NN_N(one, two)));

	EXPECT_TRUE(naturalMatch(BigNatural(123123), one));
	EXPECT_TRUE(naturalMatch(BigNatural(123), two));
}

TEST(NaturalDiv, simple3)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural(10);

	EXPECT_TRUE(naturalMatch(BigNatural(), DIV_NN_N(one, two)));
}

TEST(NaturalDiv, simple4)
{
	BigNatural one = BigNatural(1234);
	BigNatural two = BigNatural(12345);

	EXPECT_TRUE(naturalMatch(BigNatural(), DIV_NN_N(one, two)));
}

TEST(NaturalDiv, simple5)
{
	BigNatural one = BigNatural(111);
	BigNatural two = BigNatural(9);

	EXPECT_TRUE(naturalMatch(BigNatural(12), DIV_NN_N(one, two)));

	EXPECT_TRUE(naturalMatch(BigNatural(111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(9), two));
}

TEST(NaturalDiv, sameNum)
{
	BigNatural one = BigNatural(6534);
	BigNatural two = BigNatural(6534);

	EXPECT_TRUE(naturalMatch(BigNatural(1), DIV_NN_N(one, two)));

	EXPECT_TRUE(naturalMatch(BigNatural(6534), one));
	EXPECT_TRUE(naturalMatch(BigNatural(6534), two));
}

TEST(NaturalDiv, longN)
{
	//541 ��, �����, ������ 50 - 101 ��
	BigNatural one = BigNatural("5643254356794356347856349785634757346250000793456934563475643927532479853247659000002347865893465734265000003427535732453425");
	BigNatural two = BigNatural("999347892657005623478");

	EXPECT_TRUE(naturalMatch(BigNatural("5646936765724710346765354105282115601580392966454306025003439601568983107160357473047041278182670944053"), DIV_NN_N(one, two)));
}


//***************************************************************************************


TEST(NaturalMul, NotZeroFactor)
{
	BigNatural one = BigNatural(1111);
	BigNatural two = BigNatural(6534);

	EXPECT_TRUE(naturalMatch(BigNatural(5555), MUL_ND_N(one, 5)));
	EXPECT_TRUE(naturalMatch(BigNatural(58806), MUL_ND_N(two, 9)));

	EXPECT_TRUE(naturalMatch(BigNatural(1111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(6534), two));
}


TEST(NaturalMul, ZeroFactor)
{
	BigNatural one = BigNatural(1111);
	BigNatural two = BigNatural(6534);

	EXPECT_TRUE(naturalMatch(BigNatural(), MUL_ND_N(one, 0)));
	EXPECT_TRUE(naturalMatch(BigNatural(), MUL_ND_N(two, 0)));

	EXPECT_TRUE(naturalMatch(BigNatural(1111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(6534), two));
}


TEST(NaturalMul, TenGegree)
{
	BigNatural one = BigNatural(1111);
	BigNatural two = BigNatural(6534);

	EXPECT_TRUE(naturalMatch(BigNatural(111100), MUL_Nk_N(one, 2)));
	EXPECT_TRUE(naturalMatch(BigNatural(65340), MUL_Nk_N(two, 1)));


	EXPECT_TRUE(naturalMatch(BigNatural(1111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(6534), two));
}


TEST(NaturalMul, TenGegreeNull)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural();

	EXPECT_TRUE(naturalMatch(BigNatural(), MUL_Nk_N(one, 2)));
	EXPECT_TRUE(naturalMatch(BigNatural(), MUL_Nk_N(two, 1)));
}

TEST(NaturalMul, twoNatural)
{
	BigNatural one = BigNatural(1111);
	BigNatural two = BigNatural(6534);

	EXPECT_TRUE(naturalMatch(BigNatural(7259274), MUL_NN_N(one, two)));


	EXPECT_TRUE(naturalMatch(BigNatural(1111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(6534), two));
}


TEST(NaturalMul, twoNaturalLong)
{
	BigNatural one = BigNatural("5643254356794356347856349785634757346250000793456934563475643927532479853247659000002347865893465734265000003427535732453425");
	BigNatural two = BigNatural("5646936765724710346765354105282115601580392966454306025003439601568983107160357473047041278182670944053");

	EXPECT_TRUE(naturalMatch(BigNatural("31867100505718203227018683872026797101240233857709169043000065574165912341505095909125400551460799723327768541305598276597631326991814812732917964400192211385668660844738694537394430251229674798340365142456375499807974603231525"), MUL_NN_N(one, two)));

}

//***************************************************************************************

TEST(NaturalSub, simple1)
{
	BigNatural one = BigNatural(1111);
	BigNatural two = BigNatural(6534);

	EXPECT_TRUE(naturalMatch(BigNatural(5423), SUB_NN_N(one, two)));


	EXPECT_TRUE(naturalMatch(BigNatural(1111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(6534), two));
}

TEST(NaturalSub, zero)
{
	BigNatural one = BigNatural(1111);
	BigNatural two = BigNatural();

	EXPECT_TRUE(naturalMatch(BigNatural(1111), SUB_NN_N(one, two)));


	EXPECT_TRUE(naturalMatch(BigNatural(1111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(), two));
}


TEST(NaturalSub, bothZero)
{
	BigNatural one = BigNatural();
	BigNatural two = BigNatural();

	EXPECT_TRUE(naturalMatch(BigNatural(), SUB_NN_N(one, two)));
}


TEST(NaturalSub, resultZero)
{
	BigNatural one = BigNatural(1111);
	BigNatural two = BigNatural(1111);

	EXPECT_TRUE(naturalMatch(BigNatural(), SUB_NN_N(one, two)));


	EXPECT_TRUE(naturalMatch(BigNatural(1111), one));
	EXPECT_TRUE(naturalMatch(BigNatural(1111), two));
}

TEST(NaturalSub, longNum)
{
	BigNatural one = BigNatural("31867100505718203227018683872026797101240233857709169043000065574165912341505095909125400551460799723327768541305598276597631326991814812732917964400192211385668660844738694537394430251229674798340365142456375499807974603231525");
	BigNatural two = BigNatural("690430000655741659123415050959091254005514607318671005057182032270186838720214607997233277685413055982765976313269918148127329179644001922113856686608447386945373944302512296747983403651424563754998079746032315256797101240233857709169043000065574165912341505095909125400551460799");

	EXPECT_TRUE(naturalMatch(BigNatural("690430000655741659123415050959091254005514607318670973190081526551983611701530735970436176445179198273596933313204343982214987674548092796713305225808724059176832638704235699116656411836611830837033679553820929588136256501539320314738791770390775825547199048720409317425948229274"), SUB_NN_N(one, two)));
}


//***************************************************************************************

TEST(NaturalMod, simple1)
{
	BigNatural one = BigNatural(55);
	BigNatural two = BigNatural(11);

	EXPECT_TRUE(naturalMatch(BigNatural(0), MOD_NN_N(one, two)));
}

TEST(NaturalMod, simple2)
{
	BigNatural one = BigNatural(5);
	BigNatural two = BigNatural(6);

	EXPECT_TRUE(naturalMatch(BigNatural(5), MOD_NN_N(one, two)));
}

TEST(NaturalMod, simple3)
{
	BigNatural one = BigNatural(3);
	BigNatural two = BigNatural(2);

	EXPECT_TRUE(naturalMatch(BigNatural(1), MOD_NN_N(one, two)));
}





