package main

type Stack []string

func (s *Stack) IsEmpty() bool {
	return len(*s) == 0
}

func (s *Stack) Push(str string) {
	*s = append(*s, str)
}

func (s *Stack) Pop() (string, bool) {
	if s.IsEmpty() {
		return "", false
	} else {
		index := len(*s) - 1
		element := (*s)[index]
		*s = (*s)[:index]
		return element, true
	}
}

func (s *Stack) Peek() int {
	return len(*s) - 1
}

func ValidBraces(str string) bool {
	op := map[string]string{
		"(": ")",
		"[": "]",
		"{": "}",
	}
	var stack Stack
	for _, i := range str {
		el := string(i)
		if el == "(" || el == "[" || el == "{" {
			stack.Push(el)
		} else {
			c, ok := stack.Pop()
			if !ok || op[c] != el {
				return false
			}
		}

	}
	return stack.IsEmpty()
}
