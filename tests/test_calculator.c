#include <check.h>
#include <stdlib.h>
#include "calculator.h"

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
    Suite *s;
    TCase *tc_core;

    s = suite_create("Calculator");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_add);
    tcase_add_test(tc_core, test_subtract);
    tcase_add_test(tc_core, test_multiply);
    tcase_add_test(tc_core, test_divide);

    suite_add_tcase(s, tc_core);

    return s;
}

int main(void) {
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = calculator_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
