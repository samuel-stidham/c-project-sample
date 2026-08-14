#ifndef SUITES_H
#define SUITES_H

#include <check.h>

/* Declare one creator per suite file, then register it in runner.c. */
Suite *calculator_suite(void);

#endif /* SUITES_H */
