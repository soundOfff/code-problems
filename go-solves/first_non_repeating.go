package main

import "strings"

func FirstNonRepeating(str string) string {
	letters := map[string]int{}
	letter := 99999999

	if len(str) == 0 {
		return ""
	}

	for i, s := range str {
		el := strings.ToLower(string(s))
		if _, ok := letters[el]; ok {
			delete(letters, el)
		} else {
			letters[el] = i
		}
	}

	if len(letters) == 0 {
		return ""
	}

	for _, idx := range letters {
		if idx < letter {
			letter = idx
		}
	}
	return string(str[letter])

}
