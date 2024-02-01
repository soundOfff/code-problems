package main

func HalvesAreAlike(s string) bool {
	lv, rv, i := 0, 0, 0
	for i < len(s)/2 {
		if isVowel(rune(s[i])) {
			lv++
		}
		if isVowel(rune(s[len(s)/2+i])) {
			rv++
		}
		i++
	}

	return lv == rv
}

func isVowel(c rune) bool {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'
}
