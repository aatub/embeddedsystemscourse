#include <gtest/gtest.h>
#include "../TimeParser.h"

TEST(TimeParserTest, ValidTimeParsing) {
    EXPECT_EQ(time_parse("000120"), 80);   // 1m 20s = 80s
    EXPECT_EQ(time_parse("000005"), 5);    // 5s
    EXPECT_EQ(time_parse("000000"), 0);    // Alaraja
    EXPECT_EQ(time_parse("235959"), 3599); // Yläraja (59m 59s)
}

TEST(TimeParserTest, BoundaryValueErrors) {
    EXPECT_EQ(time_parse("240000"), ERROR_INVALID_HOURS);   // Tunnit yli 23
    EXPECT_EQ(time_parse("006000"), ERROR_INVALID_MINUTES); // Minuutit yli 59
    EXPECT_EQ(time_parse("000060"), ERROR_INVALID_SECONDS); // Sekunnit yli 59
}

TEST(TimeParserTest, InvalidFormatErrors) {
    EXPECT_EQ(time_parse(nullptr), ERROR_NULL_POINTER);
    EXPECT_EQ(time_parse("12345"), ERROR_INVALID_FORMAT);   // Liian lyhyt
    EXPECT_EQ(time_parse("1234567"), ERROR_INVALID_FORMAT); // Liian pitkä
    EXPECT_EQ(time_parse("00A010"), ERROR_INVALID_FORMAT);  // Kirjaimia
}
