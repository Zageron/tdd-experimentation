#include "gmock/gmock.h"
#include "Soundex.h"

// Pseudo Code
// 1. Retain the first letter. Drop all other occurrences of a, e, i, o, u, y, h, w.
//
// 2. Replace consonants with digits(after the first letter) :
//     � b, f, p, v : 1
//     � c, g, j, k, q, s, x, z : 2
//     � d, t : 3
//     � l : 4
//     � m, n : 5
//     � r : 6
//
// 	3. If two adjacent letters encode to the same number, encode them instead
// 	as a single number.Also, do so if two letters with the same number are
// 	separated by h or w(but code them twice if separated by a vowel).This
// 	rule also applies to the first letter.
//
// 	4. Stop when you have a letter and three digits.Zero - pad if needed.

using namespace testing;

class SoundexEncoding : public Test
{
public:
	Soundex soundex;
};


TEST_F(SoundexEncoding, RetainsSoleLetterOfOneLetterWord)
{
	ASSERT_THAT(soundex.encode("A"), Eq("A000"));
}

TEST_F(SoundexEncoding, PadsWithZerosToEnsureThreeDigits)
{
	ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SoundexEncoding, ReplacesConsonantsWithAppropriateDigits)
{
	ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SoundexEncoding, IgnoresNonAlphabetics)
{
	ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SoundexEncoding, ReplacesMultipleConsonantsWithDigits)
{
	ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SoundexEncoding, LimitsLengthToFourCharacters)
{
	ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(Soundex::MaxCodeLength));
}

TEST_F(SoundexEncoding, IgnoresVowelLikeLetters)
{
	ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SoundexEncoding, CombinesDuplicateEncodings)
{
	ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
	ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
	ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));

	ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SoundexEncoding, UppercaseFirstLetter)
{
	ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SoundexEncoding, IgnoresCaseWhenEncodingConsonants)
{
	ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

TEST_F(SoundexEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicates1st)
{
	ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}

TEST_F(SoundexEncoding, DoesNotCombineDuplicatedEncodingsSeparatedByVowels)
{
	ASSERT_THAT(soundex.encode("Jbob"), Eq("J110"));
}
