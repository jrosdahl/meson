#include <stdio.h>

int get_instdep_c_value (void);

int main(void) {
  int val = get_instdep_c_value ();
  if (val != 42) {
    printf("instdep_c value was %i instead of 42\n", val);
    return -1;
  }
  return 0;
}
