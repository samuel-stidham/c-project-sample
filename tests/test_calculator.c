/*
 * Calculator Check suite. To add a suite for new code:
 *   1. Copy this file and rename the suite creator.
 *   2. Declare the creator in suites.h.
 *   3. Register it with srunner_add_suite in runner.c.
 * The CMake glob picks new .c files in tests/ up at the next build.
 *
 * Under this project's flags, use the *_eq_tol and *_ne_tol variants
 * for floating-point assertions. The exact eq/ne variants do not
 * compile because of -Wfloat-equal.
 */
#include "calculator.h"
#include "suites.h"

START_TEST(test_add) {
  ck_assert_int_eq(add(2, 3), 5);
  ck_assert_int_eq(add(-1, 1), 0);
  ck_assert_int_eq(add(-1, -1), -2);
  ck_assert_int_eq(add(-2, -3), -5);
}
END_TEST

START_TEST(test_subtract) {
  ck_assert_int_eq(subtract(5, 3), 2);
  ck_assert_int_eq(subtract(-1, -1), 0);
  ck_assert_int_eq(subtract(-1, 1), -2);
  ck_assert_int_eq(subtract(-5, -3), -2);
}
END_TEST

START_TEST(test_multiply) {
  ck_assert_int_eq(multiply(2, 3), 6);
  ck_assert_int_eq(multiply(-1, 1), -1);
  ck_assert_int_eq(multiply(-1, -1), 1);
  ck_assert_int_eq(multiply(-2, -3), 6);
}
END_TEST

START_TEST(test_divide) {
  ck_assert_double_eq_tol(divide(6, 3), 2.0, 0.000001);
  ck_assert_double_eq_tol(divide(-1, 1), -1.0, 0.000001);
  ck_assert_double_eq_tol(divide(-1, -1), 1.0, 0.000001);
  ck_assert_double_eq_tol(divide(-6, -3), 2.0, 0.000001);
  ck_assert_double_eq_tol(divide(5, 2), 2.5, 0.000001);
  ck_assert_double_eq_tol(divide(5, 0), 0.0, 0.000001);
}
END_TEST

Suite *calculator_suite(void) {
  Suite *s = suite_create("calculator");
  TCase *tc_core = tcase_create("core");

  tcase_add_test(tc_core, test_add);
  tcase_add_test(tc_core, test_subtract);
  tcase_add_test(tc_core, test_multiply);
  tcase_add_test(tc_core, test_divide);
  suite_add_tcase(s, tc_core);
  return s;
}
