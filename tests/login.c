/*
 * Copyright (c) 2006-2014 Erik Ekman <yarrick@kryo.se>,
 * 2006-2009 Bjorn Andersson <flex@kryo.se>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <check.h>
#include <string.h>

#include "test.h"
#include "login.h"

START_TEST(test_login_hash)
{
	const char good[] = "\xF3\x2F\x12\x6A\xE9\x8E\x82\x6E\x65\x3F\x1F\x5C\x6A\x04\x59\x10";
	const char pass[] = "iodine is the shit";
	int seed;
	login_hash hash;

	seed = 15;

	login_calculate(hash, pass, seed);
	fail_unless(strncmp(hash, good, sizeof(hash)) == 0, NULL);
}
END_TEST

TCase *
test_login_create_tests()
{
	TCase *tc;

	tc = tcase_create("Login");
	tcase_add_test(tc, test_login_hash);

	return tc;
}
