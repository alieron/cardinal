#include "settings.h"
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

static void print_usage(void) {
  puts("Usage: cardinal [OPTIONS] [FILE]\n"
       "A Cardinal interpreter in C\n\n"
       " -h, --help           Show this help and exit.\n"
       " -s, --steps          Step through execution, pause after each "
       "instruction\n"
       " -t, --trace          Show stack trace after each instruction.\n"
       " -l, --limit steps    Set maximum execution steps, default = "
       "1,000,000.\n");
}

int main(int argc, char *argv[]) {
  // Long options
  static struct option long_options[] = {{"help", no_argument, 0, 'h'},
                                         {"step", no_argument, 0, 's'},
                                         // {"trace", no_argument, 0, 't'},
                                         {"limit", required_argument, 0, 'l'},
                                         {0, 0, 0, 0}};

  int opt, option_index = 0;

  while ((opt = getopt_long(argc, argv, "hstl:", long_options,
                            &option_index)) != -1) {
    switch (opt) {
    case 'h':
      print_usage();
      return EXIT_SUCCESS;
    case 's':
      setting_enable_steps = true;
      break;
    case 't':
      setting_enable_trace = true;
      break;
    case 'l':
      setting_max_execution_steps = atol(optarg);
      if (setting_max_execution_steps <= 0) {
        fprintf(stderr, "Error: Step limit must be positive\n");
        return EXIT_FAILURE;
      }
      break;
    default:
      print_usage();
      return EXIT_FAILURE;
    }
  }

  if (optind >= argc) {
    fprintf(stderr, "Error: No program file specified\n");
    exit(EXIT_FAILURE);
  }

  printf("name argument = %s\n", argv[optind]);

  exit(EXIT_SUCCESS);
}
