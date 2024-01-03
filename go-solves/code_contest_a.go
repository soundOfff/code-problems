package main

import (
	"fmt"
)

func A() {
	var x int
	fmt.Scanf("%d", &x)
	for i := 0; i < int(x); i++ {
		var str string
		fmt.Scanln(&str)
		switch {
		case str[0] == 'a':
			fmt.Println("YES")
		case str[1] == 'b':
			fmt.Println("YES")
		case str[2] == 'c':
			fmt.Println("YES")
		default:
			fmt.Println("NO")
		}
	}
}
