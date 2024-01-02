package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func Eraser() {
	in := bufio.NewReader(os.Stdin)
	t := ReadInt(in)

	for i := 0; i < t; i++ {
		nums := ReadArrInt(in)
		k := nums[1]
		var s string
		fmt.Scan(&s)
		c := strings.Count(s, "B")
		idx := strings.Index(s, "B")
		for idx != -1 {
			if idx+k <= len(s) {
				subStr := s[idx : idx+k]
				if strings.Count(subStr, "B") > 0 {
					c--
				}
			}
			s = s[idx+1:]
			idx = strings.Index(s, "B")
		}
		fmt.Println(c)
	}

}
