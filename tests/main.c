#include "arkin_core.h"
#include "arkin_log.h"

#include "test.h"

static void check(ArTestResult res) {
    for (const ArTestCase *c = res.cases; c != NULL; c = c->next) {
        if (c->result.passed) {
            ar_info("%s: passed", c->name);
        } else {
            if (c->result.msg) {
                ar_error("%s: failed at %s:%u (%s)", c->name, c->result.file, c->result.line, c->result.msg);
            } else {
                ar_error("%s: failed at %s:%u", c->name, c->result.file, c->result.line);
            }
        }
    }

    ar_test_result_free(&res);
}

I32 main(void) {
    arkin_init(&(ArkinCoreDesc) {0});

    check(test_core());
    check(test_ll());
    check(test_strings());
    check(test_hash_map());

    arkin_terminate();
    return 0;
}
