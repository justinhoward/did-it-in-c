#include <stdio.h>
#include <stdlib.h>
#include <check.h>
#include "array.h"

START_TEST(is_initializable) {
  Array array;
  array_init(&array, 5);

  ck_assert_int_eq(array.size, 5);
  ck_assert_int_eq(array.used, 0);
}
END_TEST

START_TEST(can_insert_values_at_beginning) {
  Array array;
  array_init(&array, 5);
  array_insert(&array, 0, 2);
  array_insert(&array, 0, 4);
  array_insert(&array, 0, 6);

  ck_assert_int_eq(array.values[0], 6);
  ck_assert_int_eq(array.values[1], 4);
  ck_assert_int_eq(array.values[2], 2);
  ck_assert_int_eq(array.used, 3);
}
END_TEST

START_TEST(can_fit_to_a_value) {

}
END_TEST

START_TEST(can_expand_to_fit_insert) {
  Array array;
  array_init(&array, 1);
  array_insert(&array, 0, 2);
  array_insert(&array, 1, 4);

  ck_assert_int_ge(array.size, 2);
  ck_assert_int_eq(array.values[0], 2);
  ck_assert_int_eq(array.used, 2);
}
END_TEST

START_TEST(can_insert_values) {
  Array array;
  array_init(&array, 10);
  array_insert(&array, 0, 10);
  array_insert(&array, 1, 11);

  ck_assert_int_ge(array.size, 2);
  ck_assert_int_eq(array.values[0], 10);
  ck_assert_int_eq(array.values[1], 11);
  ck_assert_int_eq(array.used, 2);
}
END_TEST

Suite *make_array_suite() {
  Suite *suite;
  TCase *tc_core;

  suite = suite_create("Array");
  tc_core = tcase_create("Core");
  suite_add_tcase(suite, tc_core);

  tcase_add_test(tc_core, is_initializable);
  tcase_add_test(tc_core, can_insert_values_at_beginning);
  tcase_add_test(tc_core, can_fit_to_a_value);
  tcase_add_test(tc_core, can_expand_to_fit_insert);
  tcase_add_test(tc_core, can_insert_values);

  return suite;
}

int main() {
  int n;
  SRunner *sr;

  sr = srunner_create(make_array_suite());

  srunner_run_all(sr, CK_VERBOSE);
  n = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (n == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
