package main

func LongestPalindrome(s string) string {
	start, maxLen, l := 0, 0, len(s)
	for i := 0; i < l; i++ {
		expand(s, i, i, &start, &maxLen)
		expand(s, i, i+1, &start, &maxLen)
	}
	return s[start : start+maxLen]
}

func expand(s string, l, r int, start, maxLen *int) {
	for l >= 0 && r < len(s) && s[l] == s[r] {
		l, r = l-1, r+1
	}
	if r-l-1 > *maxLen {
		*maxLen = r - l - 1
		*start = l + 1
	}
}
