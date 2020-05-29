#include "vendor/unity.h"
#include "../src/darts.h"

void setUp(void)
{
}

void tearDown(void)
{
}

static void test_missed_target(void)
{
   coordinate_t landing_position = { -9.0F, 9.0F };
   int expected = 0;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_on_the_outer_circle(void)
{

   coordinate_t landing_position = { 0.0F, 10.0F };
   int expected = 1;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_on_the_middle_circle(void)
{

   coordinate_t landing_position = { -5.0F, 0.0F };
   int expected = 5;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_on_the_inner_circle(void)
{

   coordinate_t landing_position = { 0.0F, -1.0F };
   int expected = 10;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_exactly_on_center(void)
{

   coordinate_t landing_position = { 0.0F, 0.0F };
   int expected = 10;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_near_the_center(void)
{

   coordinate_t landing_position = { -0.1F, -0.1F };
   int expected = 10;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_just_within_the_inner_circle(void)
{

   coordinate_t landing_position = { 0.7F, 0.7F };
   int expected = 10;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_just_outside_the_inner_circle(void)
{

   coordinate_t landing_position = { 0.8F, -0.8F };
   int expected = 5;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_just_within_the_middle_circle(void)
{

   coordinate_t landing_position = { -3.5F, 3.5F };
   int expected = 5;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_just_outside_the_middle_circle(void)
{

   coordinate_t landing_position = { -3.6F, -3.6F };
   int expected = 1;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_just_within_the_outer_circle(void)
{

   coordinate_t landing_position = { -7.0F, 7.0F };
   int expected = 1;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_just_outside_the_outer_circle(void)
{

   coordinate_t landing_position = { 7.1F, -7.1F };
   int expected = 0;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

static void test_asymmetric_position_between_the_inner_and_middle_circles(void)
{

   coordinate_t landing_position = { -0.5F, -4.0F };
   int expected = 5;
   int actual = score(landing_position);
   TEST_ASSERT_EQUAL_UINT8(expected, actual);
}

int main(void)
{
   UnityBegin("test/test_darts.c");

   RUN_TEST(test_missed_target);
   RUN_TEST(test_on_the_outer_circle);
   RUN_TEST(test_on_the_middle_circle);
   RUN_TEST(test_on_the_inner_circle);
   RUN_TEST(test_exactly_on_center);
   RUN_TEST(test_near_the_center);
   RUN_TEST(test_just_within_the_inner_circle);
   RUN_TEST(test_just_outside_the_inner_circle);
   RUN_TEST(test_just_within_the_middle_circle);
   RUN_TEST(test_just_outside_the_middle_circle);
   RUN_TEST(test_just_within_the_outer_circle);
   RUN_TEST(test_just_outside_the_outer_circle);
   RUN_TEST(test_asymmetric_position_between_the_inner_and_middle_circles);

   return UnityEnd();
}
