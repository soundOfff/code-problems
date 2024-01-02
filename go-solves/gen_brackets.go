package main

func BalancedParens(n int) []string {
	var answer []string

	generate(n, n, "", &answer)

	return answer
}

func generate(left, right int, s string, answer *[]string) {
	if left == 0 && right == 0 {
		*answer = append(*answer, s)
	}
	if left > right || left < 0 || right < 0 {
		return
	}
	s += "{"
	generate(left-1, right, s, answer)
	s = s[:len(s)-1]
	s += "}"
	generate(left, right-1, s, answer)
	s = s[:len(s)-1]
}
