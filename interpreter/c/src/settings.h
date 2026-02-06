// Global runtime settings
#ifndef CARDINAL_SETTINGS_H
#define CARDINAL_SETTINGS_H

#include <stdbool.h>

// Enable per instruction stepping through the program
extern bool setting_enable_steps;

// Enable printing stack trace after each instruction
extern bool setting_enable_trace;

// Maximum steps to execute before force termination
extern int setting_max_execution_steps;

#endif // !CARDINAL_SETTINGS_H
