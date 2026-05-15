#include <stdint.h>

struct recoilfuse_state {
  uint64_t output[2];
  uint64_t a;
  uint64_t b;
  uint64_t c;
};

void recoilfuse(struct recoilfuse_state *s) {
  s->a = ((s->a << 29) | (s->a >> 35)) ^ s->b;
  s->b += 11111111111111111;
  s->c = ((s->c << 41) | (s->c >> 23)) + s->a;
  s->output[0] = s->b + s->c;
  s->output[1] = (s->a + s->c) ^ s->b;
}
