#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include the implementation under test
// Alternatively, declare prototypes if linking separately
char compare(const char *str1, const char *str2);
void make_str(const char *old_str, char **new_str);

// Lightweight test helpers
static int tests_run = 0;
static int tests_failed = 0;

#define ASSERT_TRUE(msg, expr) do { \
    tests_run++; \
    if (!(expr)) { \
        tests_failed++; \
        printf("[FAIL] %s\n", msg); \
    } else { \
        printf("[PASS] %s\n", msg); \
    } \
} while(0)

#define ASSERT_STREQ(msg, a, b) do { \
    tests_run++; \
    if (strcmp((a), (b)) != 0) { \
        tests_failed++; \
        printf("[FAIL] %s | expected=\"%s\" actual=\"%s\"\n", msg, (b), (a)); \
    } else { \
        printf("[PASS] %s\n", msg); \
    } \
} while(0)

// Prototypes from shlak.c (not exposed via header)
char compare(const char *str1, const char *str2);
void make_str(const char *old_str, char **new_str);

// To link with shlak.c, we declare them here and compile both files together.

static void test_compare_equality() {
    ASSERT_TRUE("compare should return true for equal strings", compare("abc", "abc") == 1);
}

static void test_compare_inequality() {
    ASSERT_TRUE("compare should return false for different strings", compare("abc", "abd") == 0);
}

static void test_make_str_overlap() {
    char *out = NULL;
    make_str("шлакоблок окунь", &out);
    ASSERT_TRUE("make_str should allocate output", out != NULL);
    if (out) {
        ASSERT_STREQ("make_str should join with overlap correctly", out, "шлакоблокунь");
        free(out);
    }
}

static void test_make_str_no_overlap() {
    char *out = NULL;
    make_str("папа мама", &out);
    ASSERT_TRUE("make_str should allocate output (no overlap)", out != NULL);
    if (out) {
        ASSERT_STREQ("make_str should concatenate fully when no overlap", out, "папамама");
        free(out);
    }
}

static void test_make_str_full_overlap_suffix() {
    char *out = NULL;
    make_str("цветок ток", &out);
    ASSERT_TRUE("make_str should allocate output (full overlap)", out != NULL);
    if (out) {
        ASSERT_STREQ("make_str should handle full overlap where second is suffix of first", out, "цветок");
        free(out);
    }
}

static void test_make_str_handles_newline() {
    char *out = NULL;
    make_str("дом мод\n", &out);
    ASSERT_TRUE("make_str should allocate output with newline in input", out != NULL);
    if (out) {
        ASSERT_STREQ("make_str should ignore trailing newline from input", out, "домод");
        free(out);
    }
}

static void test_make_str_multi_byte_utf8() {
    // Ensure multi-byte characters are processed as bytes without corruption
    char *out = NULL;
    make_str("осень неньютоновская", &out);
    ASSERT_TRUE("make_str should allocate output (UTF-8)", out != NULL);
    if (out) {
        ASSERT_STREQ("make_str should handle UTF-8 characters correctly", out, "осеньненьютоновская");
        free(out);
    }
}

int main(void) {
    printf("Running shlak.c unit tests...\n");

    test_compare_equality();
    test_compare_inequality();
    test_make_str_overlap();
    test_make_str_no_overlap();
    test_make_str_full_overlap_suffix();
    test_make_str_handles_newline();
    test_make_str_multi_byte_utf8();

    printf("\nTests run: %d, Failures: %d\n", tests_run, tests_failed);
    return tests_failed ? 1 : 0;
}
