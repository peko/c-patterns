#include "cat_state.h"

extern void to_sleep(cat_state_p state);
void cat_state_init(cat_state_p state) {
    to_sleep(state);
};
